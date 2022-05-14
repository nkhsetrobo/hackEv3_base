#include "SonerJudge.h"
#include "util.h"

SonerJudge::SonerJudge()
{
    mDir = 1;
    mLen = 0;
}

void SonerJudge::setLength(float len,int d)
{
    mDir = d;
    mLen = len;
}

bool SonerJudge::run()
{
   // static char buf[256];
   // printf(" %d  %d %f\n",mSoner,mDir,mSoner->getValue());
   // msg_log(buf);

    float len = mSoner->getValue();

    if(mDir<0) {
        if(mLen<=len) 
            return true;
    } else {
        if(mLen>=len) 
            return true;
    }
    return false;
}