/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "SimpleWalker.h"
#include "PID.h"
#include "Odometry.h"
#include "SpeedControl.h"

class LineTracer : public SimpleWalker{
public:
    LineTracer(Odometry *odo,
            SpeedControl *scon);
    void run();
    void init();

    void setParam(float speed,float target,float kp, float ki, float kd);
    void setParam(float speed,float target,float kp, float ki, float kd,float angleTarget,float angleKp);
                       
    void setEdgeMode(bool isLeftEdge);
    bool getEdgeMode();
    void changeEdgeMode();
    void setLimit(float limit);

    bool isLeftEdge();
  
    void setBias(float curve);
    void addBias(float add);

    void printInfo();

    static const int LEFTEDGE;
    static const int RIGHTEDGE;


private:
    float calcTurn(float val1);

    float mSpeed;

    int mTargetSpeed;
    float mTarget;
    float mPFactor;
    float mIFactor;
    float mDFactor;

    float mAngleKp;
    bool mLeftEdge;
    float mCurve;


    float mBias;

    int mLimit;  
};

#endif  // EV3_APP_LINETRACER_H_
