#ifndef __SPEED_CONTROL_H__
#define __SPEED_CONTROL_H__

#include "PID.h"
#include "Odometry.h"
#include "Velocity.h"

#include "Clock.h"
class SpeedControl
{
    public:
        SpeedControl(Odometry *odo, Velocity *v);
        void setTargetSpeed(double speed);
        int getPwm();
        void resetParam();
        void setMode(bool mode);
        void setBreak(bool brk);
        double getCurrentFwd();
        double getCurrentSpeed();
        int accel(int target);

    private:
        PID *mPid;
        Odometry *mOdo;
        Velocity *mVelo;

        double mTargetSpeed;
        int mForward; //現在PWM値
        double mCurrentSpeed;

        bool mBreake_flag;
        bool mMode_flag;//setComandVだとtrue、setComandだとfalse
        int mCnt=0;
     double mAcc=0.5;
     double mPow=0;

     Clock *mClock;

};
#endif
