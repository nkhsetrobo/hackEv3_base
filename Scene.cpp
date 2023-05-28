#include "Scene.h"
#include "util.h"
#include "ev3api.h"
//#include "etroboc_ext.h"
#include "Clock.h"
#include "HackEv3.h"

extern Motor       *gLeftWheel;
extern Motor       *gRightWheel;
extern MyColorSensor *gColor;
extern MyGyroSensor *gGyro;
extern Odometry *gOdo;
extern ArmWalker *gArmWalker;

extern float gKp;
extern float gKd;

Scene::Scene() : mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    mSlm = new SlalomSectionManager();
    //mGsm = new GarageSectionManager();
    mBsm = new BlockSectionManager();

    mColorSensor = gColor;
}

bool Scene::run()
{
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case CALIB:
            execCalib();
            break;
        case START:
            execStart();
            break;
        case INIT_SPEED:
            initSpeed();
            break;
        case SPEED:
            execSpeed();
            break;
        case INIT_BINGO:
            initBingo();
            break;
        case BINGO:
            execBingo();
            break;
        case INIT_SLALOM:
            initSlalom();
            break;
        case SLALOM:
            execSlalom();
            break;
        case INIT_GARAGE:
            initGarage();
            break;
        case GARAGE:
            execGarage();
            break;
        case FINISH:
            execEnd();
            break;
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
 //   Bingo *mBingo = new Bingo();
 //     mBingo->get(); 
//    tslp_tsk(1000*1000U);
  //  printf("wait end.\n");


   // int diff =arm_target - arm_cnt;
   // gArm->setPWM(diff*4.0);

    gArmWalker->setPwm(0, 0,0,0); // シミュレータ対策

#if !defined(MAKE_SIM)
    msg_log("Press Left Button to caribration.\n");
    mState = CALIB;
    gArmWalker->setPwm(0, 4,0,0);
#else
   // ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
    mState = START;
#endif
}

void Scene::execCalib()
{
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        int volt = ev3_battery_voltage_mV();
        printf("battery %d\n",volt);
        mColorSensor->calibMax();
        gGyro->reset();


    }
    if(ev3_button_is_pressed(RIGHT_BUTTON))
    {
        printf("Press Touch Button to start.\n");
        mState = START;
    }

}
void Scene::execStart()
{
    static int cnt=0;
    //printf("press %d\n",ev3_touch_sensor_is_pressed(EV3_PORT_1));
    // とりあえず動かすだけなので、設計に基づいて書き直そう
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        gKp -= 0.05;
    }
    if(ev3_button_is_pressed(RIGHT_BUTTON))
    {
        gKp += 0.05;

    }
    if(ev3_button_is_pressed(UP_BUTTON))
    {
        gKd += 0.005;
    }
    if(ev3_button_is_pressed(DOWN_BUTTON))
    {
        gKd-=0.005;
    }
    //static char buf[256];
    //sprintf(buf,"KP %f, Kd%f",gKp,gKd);
    //msg_log_l(buf,5);
#if defined(MAKE_RASPIKE)
    if(ev3_button_is_pressed(ENTER_BUTTON))
    {       
            gGyro->reset();
            gOdo->reset();

            mState=INIT_SPEED;
    }
#else
    if(ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {       
            gGyro->reset();
            gOdo->reset();
                //gArmWalker->setPwm(0, 4,0,0);

            mState=INIT_SPEED;
    }
#endif

}
void Scene::execSpeed()
{
    static int cnt=0;
    // if(cnt<500) {
    //     cnt++;
    //     return;
    // }
    if (mSsm->run())
    {
        delete mSsm;
        // msg_log("test length");

        //BlockSectionManager::msArea->initBlockFromApi();

#if defined(PRIMARY)    
    mState = INIT_SLALOM;
#else
    mState = INIT_BINGO;
#endif
        // mState = FINISH;
    }
}

void Scene::initBingo(){
    mBsm->init();
    mState=BINGO;
}

void Scene::execBingo()
{  

    if(mBsm->run()){
       // delete mBsm;
        // msg_log("Tail test");
        if(mBsm->getError()!=0) {
            gLeftWheel->setPWM(0);
            gRightWheel->setPWM(0);
          Clock clock;
            ev3_led_set_color(LED_RED );
            clock.sleep(10000);
            mState = FINISH;
        } else
            mState = INIT_BINGO;
    }
}

void Scene::initSlalom(){
    printf("initSlalom\n");

    mSlm->init();
    mState=SLALOM;
}
void Scene::initSpeed(){


    mSsm->init();
    mState = SPEED;
}

void Scene::execSlalom()
{
    if(mSlm->run()){
        delete mSlm;
        // msg_log("Tail test");
        
        mState = FINISH;
    }
}
void Scene::initGarage()
{
    mGsm->init();
    mState=GARAGE;
}
void Scene::execGarage()
{
}
void Scene::execEnd()
{
    // msg_log("finish!");
    //ETRoboc_notifyCompletedToSimulator();

} 
