#ifndef __SPEED_CONTROL_H__
#define __SPEED_CONTROL_H__

#include "PID.h"
#include "Odometry.h"
#include "Velocity.h"

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
		void changeAcc(float a);	//加速度変更

    private:
        PID *mPid;
        Odometry *mOdo;
        Velocity *mVelo;

        double mTargetSpeed;
        int mForward; //現在PWM値
        double mCurrentSpeed;
		double bai;

        bool mBreake_flag;
        bool mMode_flag;//setComandVだとtrue、setComandだとfalse
        int mCnt=0;


};
#endif
