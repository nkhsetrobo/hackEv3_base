/******************************************************************************
 *  SimpleWalker.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Class SimpleWalker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "SimpleWalker.h"
#include "Walker.h"
#include "util.h"
// 定数宣言
/**
 * コンストラクタ
 * @param gyroSensor ジャイロセンサ
 * @param leftWheel  左モータ
 * @param rightWheel 右モータ
 * @param balancer   バランサ
 */
SimpleWalker::SimpleWalker(
                        Odometry *odo,
                        SpeedControl *scon
                       ):
        Walker(odo),
        mSpeedControl(scon),
        mForward(0),
        mTurn(0),
        mBreake_flag(false),
        mMode_flag(false)
{
}

void SimpleWalker::init() {

   // printf("SimpleWalker init %f,%d\n",mForward,mTurn);

    if(mMode_flag)
        setCommandV(mForward,mTurn);
    else
        setCommand(mForward,mTurn);

}



void SimpleWalker::run() {
    static float speed=0;

    mForward = mSpeedControl->getPwm();
   static const int MAXPWM=80;
    if (mTurn>MAXPWM) mTurn = MAXPWM;
    if (mTurn<-MAXPWM) mTurn = -MAXPWM;
    int diff = 0;

  
    float pwm_l = mForward + mTurn;      // <2>
    float pwm_r = mForward - mTurn;      // <2>

    if(pwm_l>MAXPWM) {
        pwm_r = (int)((float)MAXPWM*pwm_r/pwm_l);
        pwm_l=MAXPWM;
    }
    if(pwm_l<-MAXPWM) {
        pwm_r = (int)((float)-MAXPWM*pwm_r/pwm_l);
        pwm_l=-MAXPWM;
    }

    if(pwm_r>MAXPWM) {
        //printf("%f,%f ",pwm_l,pwm_r);
        pwm_l = (int)((float)MAXPWM*pwm_l/pwm_r);
        pwm_r=MAXPWM;
        //printf("->%f,%f \n",pwm_l,pwm_r);
    }
    if(pwm_r<-MAXPWM) {
        pwm_l = (int)((float)-MAXPWM*pwm_l/pwm_r);
        pwm_r=-MAXPWM;
    }
    


    if(pwm_r>100) pwm_r=100;
    if(pwm_l>100) pwm_l=100;
    if(pwm_r<-100) pwm_r=-100;
    if(pwm_l<-100) pwm_l=-100;

//    if(pwm_l!=0 && pwm_r!=0) printf("* %f,%f \n",pwm_l,pwm_r);
    mOdo->setPwm(pwm_l,pwm_r);
}

/**
 * PWM値を設定する
 * @param forward 前進値
 * @param turn    旋回値
 */
void SimpleWalker::setCommand(int forward, int turn) {
    mForward = forward;
    mSpeedControl->resetParam();
    mSpeedControl->setTargetSpeed(forward);
    mTurn    = turn;
    //mMode_flag = false;
    mSpeedControl->setMode(false);
    mOdo->setBrake(true);
    mMode_flag=false;
}

void SimpleWalker::setCommandV(float forward, int turn)
{
    mForward = forward;
    mSpeedControl->setTargetSpeed(forward);
    mSpeedControl->setBreak(false);
    
    if (forward==0) {
        mSpeedControl->setBreak(true);
        mForward=0;
    }
    mTurn    = turn;
    mSpeedControl->setMode(true);
    mOdo->setBrake(false);
    mMode_flag=true;

}

void SimpleWalker::resetParam()
{
    mSpeedControl->resetParam();
}



