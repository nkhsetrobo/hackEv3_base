/******************************************************************************
 *  SimpleWaker.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class SimpleWaker
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_UNIT_SIMPLE_H_
#define EV3_UNIT_SIMPLE_H_

#include "Walker.h"
#include "Motor.h"
#include "Odometry.h"
#include "PID.h"
#include "SpeedControl.h"

class SimpleWalker : public Walker {
public:
    SimpleWalker(
                Odometry *odo,
                SpeedControl *scon
                );

    virtual void run();
    virtual void init();
    void setCommand(int forward, int turn);    //パラメータを設定する
    void setCommandV(float forward, int turn);
    void resetParam();

protected:

    float mForward;
    int mTurn;

    bool mBreake_flag;
    bool mMode_flag;//setComandVだとtrue、setComandだとfalse

    SpeedControl *mSpeedControl;

private:

};

#endif  // EV3_UNIT_SimpleWaker_H_
