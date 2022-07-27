#include "Scene.h"
#include "util.h"
#include "ev3api.h"
//#include "etroboc_ext.h"
#include "Clock.h"

extern Motor       *gLeftWheel;
extern Motor       *gRightWheel;
extern MyColorSensor *gColor;


Scene::Scene() : mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    mSlm = new SlalomSectionManager();
    mGsm = new GarageSectionManager();
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
//    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);
//    tslp_tsk(1000*1000U);
  //  printf("wait end.\n");

    mState = CALIB;
}

void Scene::execCalib()
{
    if(ev3_button_is_pressed(LEFT_BUTTON))
    {
        mColorSensor->calibMax();
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
    if(ev3_button_is_pressed(ENTER_BUTTON))
    {       
            mState=INIT_SPEED;
    }

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

        BlockSectionManager::msArea->initBlockFromApi();

       mState = INIT_BINGO;
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
    if(mGsm->run()){
        delete mGsm;
        mState = INIT_SLALOM;
        // mState = FINISH;
    }
}
void Scene::execEnd()
{
    // msg_log("finish!");
    //ETRoboc_notifyCompletedToSimulator();

} 
