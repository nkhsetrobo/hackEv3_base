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
    if(mFinAngle >= mStartAngle)
    {
        if(mFinAngle <= mTailAngle->getValue())
        {
            return true;
        }
    }
    else{
        if(mFinAngle >= mTailAngle->getValue())
        {
            return true;
        }
    }

    return false;
}