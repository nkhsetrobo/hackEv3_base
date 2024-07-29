// tag::walker_def[]

#include "fcntl.h"
#include "unistd.h"

#include "spike.h"

#include "app.h"

#include "util.h"

#include "Motor.h"

#include "Polling.h"
#include "MyColorSensor.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"
#include "Odometry.h"
#include "Velocity.h"
#include "HsvHue.h"
#include "HsvSatu.h"
#include "SimpleWalker.h"
#include "SpeedControl.h"
#include "LineTracer.h"
#include "MyGyroSensor.h"
#include "MySonarSensor.h"
#include "TailAngle.h"
#include "ArmWalker.h"
#include "ArmAngle.h"
#include "AnglerVelocity.h"
#include "GyroAngle.h"
#include "TouchSensor.h"

#include "Scene.h"

using namespace ev3api;

int log_max=30000;
int log_idx=0;

float msg_logbuf[30000][10];


pup_motor_t * gLeftWheel;
pup_motor_t * gRightWheel;

pup_motor_t  *gArm;
Motor       *gTail;

Polling *gPolling;
MyColorSensor *gColor;

Brightness *gBrightness;
HsvHue *gHue;
HsvSatu *gSatu;
XPosition *gXPosition;
YPosition *gYPosition;
MyGyroSensor *gGyro;
MySonarSensor *gSonar;

Odometry *gOdo;
Length *gLength;
TurnAngle *gTurnAngle;
Velocity *gVelocity;
TailAngle *gTailAngle;
ArmAngle *gArmAngle;
AnglerVelocity *gAnglerVelocity;
GyroAngle *gGyroAngle;

SpeedControl *gSpeed;
SimpleWalker *gWalker;
LineTracer *gTracer;
ArmWalker *gArmWalker;

Scene *gScene;
float gStart;
float gStartAngle;

int pipe_id;

static void user_system_create() {
  // gLeftWheel = new Motor(PORT_C,false,LARGE_MOTOR);
  // gRightWheel = new Motor(PORT_B,false,LARGE_MOTOR);
  gLeftWheel = pup_motor_get_device(PBIO_PORT_ID_E);
  gRightWheel = pup_motor_get_device(PBIO_PORT_ID_B);
  gArm = pup_motor_get_device(PBIO_PORT_ID_A);
  pup_motor_setup(gLeftWheel,PUP_DIRECTION_COUNTERCLOCKWISE,true);
  pup_motor_setup(gRightWheel,PUP_DIRECTION_CLOCKWISE,true);  
  pup_motor_setup(gArm,PUP_DIRECTION_CLOCKWISE,true);  

  gBrightness = new Brightness();
  gHue = new HsvHue();
  gSatu = new HsvSatu();
  gAnglerVelocity = new AnglerVelocity();
  gGyroAngle = new GyroAngle();

  gColor = new MyColorSensor(PBIO_PORT_ID_C,gBrightness,gHue,gSatu);
  gLength = new Length();
  gTurnAngle = new TurnAngle();
  gVelocity = new Velocity();
  gXPosition = new XPosition();
  gYPosition = new YPosition();
  gSonar = new MySonarSensor(PORT_3);
  gTailAngle = new TailAngle();
  gArmAngle = new ArmAngle();
  gGyro = new MyGyroSensor(gAnglerVelocity,gGyroAngle);

  gOdo = new Odometry(gLeftWheel,gRightWheel,gLength,gTurnAngle,gVelocity,gXPosition,gYPosition,gArm,gArmAngle);

  gSpeed = new SpeedControl(gOdo,gVelocity);  
  gWalker = new SimpleWalker(gOdo,gSpeed); 
  gTracer = new LineTracer(gOdo,gSpeed);
  gArmWalker = new ArmWalker(gOdo,gSpeed);



  gPolling = new Polling(gColor,gOdo,gGyro,gSonar);

  gScene = new Scene();

  //gArmWalker->setPwm(-50,1,0,0);

  
  init_f("hackEv3_base");
  
}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;

}

void mainloop();

void main_task(intptr_t unused) {
  user_system_create();

 // sta_cyc(POLLING_CYC);
  sta_cyc(TRACER_CYC);
  act_tsk(RCV_TASK);
  // 周期タスクを使わないなら
  /*
  while(true) {
    mainloop();
  }
  */

  slp_tsk();

//  stp_cyc(POLLING_CYC);
  stp_cyc(TRACER_CYC);

 pup_motor_set_power(gLeftWheel,0);
 pup_motor_set_power(gRightWheel,0);

  //msg_out();

  ext_tsk();

  user_system_destroy();
}
// end::main_task[]

void polling_task(intptr_t unused) {

    gPolling->run();

    
    Measure *m = gBrightness;
    float br = m->getValue(); 
    float len = gLength->getValue();
    float turn = gTurnAngle->getValue();
    float v = gVelocity->getValue();
    float h = gHue->getValue();
    float s = gSatu->getValue();

    pup_color_rgb_t rgb = gColor->getRgb();
    
    //printf("polling %f,%f,%f \n",br);
    //static char buf[100];
    //printf("len , bri,H,S r,g,b, turn, v : %3.3f,  %7.4f,  %5.1f, %3.2f, %d,%d,%d  , %4.2f, %4.2f \n",len,br,h,s,  rgb.r, rgb.g,rgb.b ,turn,v);
    //msg_log(buf);

   //fprintf(fp,"len , bri,H,S r,g,b, turn, v : %3.3f,  %7.4f,  %5.1f, %3.2f, %d,%d,%d  , %4.2f, %4.2f \n",len,br,h,s,  rgb.r, rgb.g,rgb.b ,turn,v);

}
void recieve_task(intptr_t unused) {

  //pipe_id = open("pipe",O_RDWR | O_NONBLOCK);
  printf("recieve pipe id %d\n",pipe_id);  
  FILE *fp = fopen("pipe","r");
  //fprintf(fp,"@a");
//  while (1) {
      char c;
      c=fgetc(fp);
      //int err = read(pipe_id,&c,1);
      //if(err<0) continue;
      printf("%c\n",c);  
  //}

  ext_tsk();

}

void tracer_task(intptr_t unused) {
/*    static int cnt=0;
    SYSTIM sttime,edtime;
    get_tim(&sttime);
    msg_logbuf[cnt][0]=sttime;
*/
    //printf("tracer\n");
    hub_button_t mask;
    hub_button_is_pressed(&mask);

    if (mask&HUB_BUTTON_BT) {
      printf("pressed BT button\n");
      wup_tsk(MAIN_TASK);  // 左ボタン押下でメインを起こす
    } else {
    gPolling->run();


#if !defined(MAKE_RASPIKE)
    //gArmWalker->run();
#endif
      bool fin = gScene->run();
      if(fin) {
          wup_tsk(MAIN_TASK);  // 終了でメインを起こす
      }
    }
  //  for(int i=0;i<10;i++) 
  //   printf("tracer\n");

  /*get_tim(&edtime);
  msg_logbuf[cnt++][1]=edtime;
  if(cnt==100) {
    for(int i=0;i<100;i++) 
      printf("%f,%f %f\n",msg_logbuf[i][0],msg_logbuf[i][1],msg_logbuf[i][1]-msg_logbuf[i][0]);
  }
  if(cnt>1000)cnt=0;
*/
  ext_tsk();

}
