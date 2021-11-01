#ifndef _VIRTUAL_LINETRACER_H_
#define _VIRTUAL_LINETRACER_H_

#include "SimpleWalker.h"
#include "PID.h"


class VirtualLineTracer : public SimpleWalker{
    public:
    VirtualLineTracer(Odometry *odo,
                    SpeedControl *scon);
    void setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp);
    void setCenterPosition(float centerx,float centery);
    void setLimit(float limit);
    void setRound(float round);
    void init();
    void setLupdate(bool a);

    void setBias(float curve);

    void run();

    private:
    void setBaseDistance();
    float calcDistance();
    float calcTurn();


    float cx;
    float cy;
    float ax;
    float ay;
    float basedistance;
    float currentdistance;
    float mTarget;
    float mTargetSpeed;
    float mPFactor;
    float mIFactor;
    float mDFactor;
    float mCurve;
    float mAngleKp;
    float mLimit;
    float round;
    float mround;
    bool uflag;

        float mBias;
    double co;
    double si;
    
};


#endif