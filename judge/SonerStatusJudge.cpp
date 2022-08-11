#include "SonerStatusJudge.h"

SonerStatusJudge::SonerStatusJudge()
{
    mMinValue = 100;
}

float SonerStatusJudge::status()
{

    float len = mSoner->getValue();

    if(len>0 && mMinValue>len) {
        mMinValue = len;
    }
 
    return mMinValue;

}