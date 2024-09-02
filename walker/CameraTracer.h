/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_CMERATRACER_H_
#define EV3_APP_CMERATRACER_H_

#include "SimpleWalker.h"
#include "PID.h"
#include "Odometry.h"
#include "SpeedControl.h"
#include "PipeComm.h"

class CameraTracer : public SimpleWalker{
public:
    CameraTracer(Odometry *odo,
            SpeedControl *scon);
    ~CameraTracer();
    void run();
    void init();

    void setParam(float speed,float target,float kp, float ki, float kd);
                       


private:
    float calcTurn(float val1);

    float mSpeed;

    int mTargetSpeed;
    float mTarget;
    float mPFactor;
    float mIFactor;
    float mDFactor;

    PipeComm *mPcomm;
    PID *mPid2;

};

#endif  // EV3_APP_LINETRACER_H_
