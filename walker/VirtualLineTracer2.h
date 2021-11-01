#ifndef _VIRTUAL_LINETRACER2_H_
#define _VIRTUAL_LINETRACER2_H_

#include "SimpleWalker.h"
#include "PID.h"


class VirtualLineTracer2 : public SimpleWalker{
    public:
    VirtualLineTracer2(Odometry *odo,
                    SpeedControl *scon);
    void setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp);
    void setsPosition(float x,float y);
    void setfPosition(float x,float y);
    void setRelaTurnAngle(float angle,float dangle);
    void setAbsTurnAngle(float angle);
    void setLimit(float limit);
    void setvangle(bool a);
    void setBias(float curve);

    void init();
    void run();

    private:
    void setBaseDistance();
    float calcdistance();
    float calcTurn();
    void setnPosition();


    float sx;
    float sy;
    float fx;
    float fy;
    float nx;
    float ny;
    float basedistance;

    float mTarget;
    float mTargetSpeed;
    float mPFactor;
    float mIFactor;
    float mDFactor;
    float mCurve;
    float mAngleKp;
    float mLimit;
    float angle2;

    // for debug
    bool flag=false;
    bool aflag=false;

    float mBias;

};


#endif