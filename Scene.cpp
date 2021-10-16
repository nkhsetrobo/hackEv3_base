#include "Scene.h"

#include "ev3api.h"

//#include "Bingo.h"

#include "etroboc_ext.h"

extern Motor       *gArm;

BingoSectionManager *Scene::mBsm;

Scene::Scene():
    mState(UNDEFINED)
{
    mSsm = new SpeedSectionManager();
    mBsm = new BingoSectionManager();
}

bool Scene::run()
{
    printf("%d\n", mState);
    switch(mState) {
        case UNDEFINED:
            execUndefined();
            break;
        case START:
            execStart();
            break;
        case SPEED:
            execSpeed();
            break;
        case INIT_SPEED:
            initSpeed();
            break;
        case BINGO:
            execBingo();
            break;
        case INIT_BINGO:
            initBingo();
            break;
        case END:
            finish();
        default:
            return true;
    }
    return false;
}

void Scene::execUndefined()
{
    msg_log("Press Touch Button to start.");
 //   Bingo *mBingo = new Bingo();
 //     mBingo->get();


    ev3_sensor_config(EV3_PORT_1, TOUCH_SENSOR);

    mState=START;
    //mState = INIT_BINGO;
}
void Scene::execStart()
{
    // とりあえず動かすだけなので、設計に基づいて書き直そう
    if (ev3_touch_sensor_is_pressed(EV3_PORT_1) == 1)
    {
        mState=INIT_SPEED;
    }
}
void Scene::execSpeed()
{
    //ev3_motor_stop(EV3_PORT_A,true);
    //ev3_motor_set_power(EV3_PORT_A,0);
    if(mSsm->run()) {
        delete mSsm;
         msg_log("test length");
        mState = INIT_BINGO;
    }
}
void Scene::initSpeed(){


    mSsm->init();
    mState = SPEED;


}

void Scene::execBingo()
{
    return;
    if(mBsm->run()/*実行するメッセージをゲーム管理に送る*/)
    {
        delete mBsm;
         msg_log("test length2");
        mState = END;
    }
}

void Scene::initBingo()
{
    mBsm->initBingo();
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    printf("aiueoaiueoaiueo\n");
    mState = BINGO;

}

void Scene::finish()
{
    ETRoboc_notifyCompletedToSimulator();
}
