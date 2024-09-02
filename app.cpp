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
#include "PipeComm.h"
#include "thread_main.h"

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

PipeComm *gPcomm;
PipeComm *gPcomm2;

float gStart;
float gStartAngle;


char gRecive=-1;
FILE *rcv_pipe_fp=nullptr;
FILE *send_pipe_fp=nullptr;
char rcv_data;

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
  gPcomm = new PipeComm("run2cam","cam2run");
  gPcomm2 = new PipeComm("run2cam_b","cam2run_b");

  //gArmWalker->setPwm(-50,1,0,0);

//   printf("rcv pipe open\n");
//  rcv_pipe_fp = fopen("cam2run","rw");
//   // rcv_pipe_fp = open("cam2run",);
//   printf("send pipe open\n");
//   send_pipe_fp = fopen("run2cam","w");

//   printf("pipe opened\n");

  init_f("hackEv3_base");
  
}
static void user_system_destroy() {

  delete gColor;
  delete gPolling;

}

void mainloop();

void main_task(intptr_t unused) {
  user_system_create();


  sta_cyc(POLLING_CYC);
  sta_cyc(TRACER_CYC);
  // act_tsk(RCV_TASK);
  // act_tsk(SEND_TASK);
 // act_tsk(THREAD_TASK);
  act_tsk(PIPE_OPEN_TASK);
  // thread_main();
  // printf("thread start\n");

  slp_tsk();

  stp_cyc(POLLING_CYC);
  stp_cyc(TRACER_CYC);
  stp_cyc(SEND_RCV_CYC2);

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

void pipe_open_task(intptr_t unused){

  gPcomm->open();
  gPcomm2->open();
  ext_tsk();

}

void recieve_task(intptr_t unused) {
  printf("recieve_task start\n");  

  //pipe_id = open("pipe",O_RDWR | O_NONBLOCK);
  //FILE *fp = fopen("cam2run","r+");
  FILE *fp = rcv_pipe_fp;
  printf("recieve pipe id %d\n",pipe_id);  
  if(fp!=nullptr)  {
    //fprintf(fp,"@a");
    //while (1) {
     //   printf("recv loop\n");
        char c;
        c=fgetc(fp);
        //int err = read(pipe_id,&c,1);
        //if(err<0) continue;
        switch (c) {
          case 'r':
          case 'b':
          case 'x':
            gRecive=c;
        }
        printf("RECV:%c\n",gRecive);
        // tslp_tsk(10000);
   // }
  } else {
    printf("recieve pipe open error..\n");
  }
  printf("recieve_task end\n");  

  ext_tsk();

}

void send_task(intptr_t unused) {

  printf("send task\n");  
  // FILE *fp = fopen("run2cam","w");
  FILE *fp = send_pipe_fp;
  fprintf(fp,"c\n");
  fflush(fp);
  // fclose(fp);
  printf("send task end\n");  
  ext_tsk();
}

void send_rcv_task(intptr_t unused)
{
    printf("send rcv task\n");
    char *res = gPcomm->request();
    printf("send rcv task end %s\n",res);  
    ext_tsk();
}
void send_rcv_task2(intptr_t unused)
{
    printf("send rcv task 2\n");
    char *res = gPcomm2->request();
    printf("send rcv task2end %s\n",res);  
    ext_tsk();
}

static char get_rcv_data()
{
  return rcv_data;
}

void tracer_task(intptr_t unused) {
    static int cnt=0;
    static SYSTIM lasttime;
    SYSTIM sttime,edtime;
    get_tim(&sttime);
    // printf("%d\n",(int)sttime);
    msg_logbuf[cnt][0]=sttime;
    if(sttime-lasttime>11000) {
       printf("delay time TRACER_TAASK %d-%d %d\n",(int)lasttime,(int)sttime,(int)(sttime-lasttime));
    }
    


    //printf("tracer\n");
    hub_button_t mask;
    hub_button_is_pressed(&mask);

    if (mask&HUB_BUTTON_BT) {
     printf("pressed BT button\n");
      wup_tsk(MAIN_TASK);  // 左ボタン押下でメインを起こす
    } else {
    //gPolling->run();


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
    get_tim(&edtime);
    lasttime=edtime;
    if(edtime-sttime>10000) {
       printf("over time TRACER_TAASK %d-%d %d\n",(int)sttime,(int)edtime,(int)(edtime-sttime));
    }
    
  ext_tsk();

}




void thread_task(intptr_t unused) {
  printf("start thread\n");
  // cv::Mat frame; //取得したフレーム
  //   // while(1) {
  //   //     printf("exec thread\n");
  //   //     usleep(10*1000);
  //   // }
  // thread_main();
  ext_tsk();
}
