#include "ArmWalker.h"
#include "Walker.h"
#include "util.h"
extern ArmWalker *gArmWalker;

ArmWalker::ArmWalker(Odometry *odo,
                    SpeedControl *scon):
    Walker(odo),
    mSpeedControl(scon)
{
    mArmAngle = gArmAngle;

    ap = 0;
    mTarget = 0.0;
    mPFactor = 0.0;
    mIFactor = 0.0;
    mDFactor = 0.0;
    kind = 1;
    stop_flag = 0;
}

void ArmWalker::setPwm(float target, float kp, float ki, float kd)
{
    mTarget = target;
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;
   // printf("set arm pwm %f\n",target);

#if defined(MAKE_SIM)
    int base_angle=-50;
#else
    int base_angle=0;
#endif

    mPid->setLimit(20);
    mPid->setTarget(base_angle+mTarget);
    mPid->setKp(mPFactor);
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
}

void ArmWalker::run()
{
    if(stop_flag == 0){
       // printf("arm target %f\n",mTarget);
        ap = (int)mPid->getOperation(mArmAngle->getValue());
        mOdo->setArmpwm(ap);
    }
}

void ArmWalker::init()
{
    gArmWalker->setPwm(mTarget,mPFactor,mIFactor,mDFactor);
}

void ArmWalker::setFlag(int f)
{
    stop_flag = f;
}