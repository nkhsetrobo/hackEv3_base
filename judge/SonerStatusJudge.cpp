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
    printf("Soner Status %f:%f\n",len,mMinValue);
 
    return mMinValue;

}