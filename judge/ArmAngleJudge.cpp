#include "ArmAngleJudge.h"
#include "util.h"

ArmAngleJudge::ArmAngleJudge()
{
    mStartAngle = 0.0;
    mFinAngle = 0.0;
}

void ArmAngleJudge::init()
{
    mStartAngle = mArmAngle->getValue();
    mFinAngle += mStartAngle;
}

void ArmAngleJudge::setFinAngle(float finangle)
{
    // msg_log("aaaa");
    //mFinAngle = mStartAngle + finangle;
    mFinAngle =  finangle;
}

bool ArmAngleJudge::run()
{
    /*static char buf[256];
    sprintf(buf," %f,%f",mArmAngle->getValue(),mFinAngle);
    msg_log(buf);*/

   //printf(" %f,%f\n",mArmAngle->getValue(),mFinAngle);

    if(mFinAngle >= mStartAngle)
    {
        if(mFinAngle <= mArmAngle->getValue())
        {
            return true;
        }
    }
    else{
        if(mFinAngle >= mArmAngle->getValue())
        {
            return true;
        }
    }

    return false;
}