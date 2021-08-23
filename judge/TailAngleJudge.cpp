#include "TailAngleJudge.h"
#include "util.h"

TailAngleJudge::TailAngleJudge()
{
    mStartAngle = 0.0;
    mFinAngle = 0.0;
}

void TailAngleJudge::init()
{
    mStartAngle = mTailAngle->getValue();
}

void TailAngleJudge::setFinAngle(float finangle)
{
    mFinAngle = mStartAngle + finangle;
}

bool TailAngleJudge::run()
{
    /*static char buf[256];
    sprintf(buf," %f,%f,%f",mStartAngle,mFinAngle,mTailAngle->getValue());
    msg_log(buf);*/
    if(mFinAngle >= mStartAngle)
    {
        if(mFinAngle <= mTailAngle->getValue())
        {
            //printf("tail angle judge +\n");
            return true;
        }
    }
    else{
        if(mFinAngle >= mTailAngle->getValue())
        {
            //printf("tail angle judge -\n");
            return true;
        }
    }

    return false;
}