#include "LengthJudge.h"
#include "util.h"

extern float gStart;
extern float gStartAngle;

LengthJudge::LengthJudge()
{

    float mStartlength = 0;
    float mFinishlength = 0;
}
void LengthJudge::setFinLength2()
{
     mFinishlength = mFinishlength + mStartlength;
}

void LengthJudge::setFinLength(float finlength)
{
    //終了値

    mFinishlength = finlength;
     

}
bool LengthJudge::run()
{
    //printf("%f,%f\n",mFinishlength,mStartlength);

    if (mFinishlength >= mStartlength)
    {
        if (mLength->getValue() >= mFinishlength)
        {
           // printf("length judge\n");
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (mLength->getValue() < mFinishlength)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void LengthJudge::init()
{
    if (update == Judge::UPDATEALL) {
        gStartAngle = mTurnAngle->getValue();
        update = Judge::UPDATE;
    }
    if(update == Judge::UPDATE){
        gStart = mLength->getValue(); // 更新
        mStartlength=mLength->getValue();
        mFinishlength = mFinishlength + gStart; // 現在地からの距離
       // printf("update: %f,%f,%f\n",gStart,mStartlength,mFinishlength);
    }
    else{
        mStartlength=mLength->getValue();
        mFinishlength = mFinishlength + gStart; //　以前の値からの距離
        //printf("%f:%f\n",gStart,mFinishlength );
       // printf("unupdate: %f,%f,%f\n",gStart,mStartlength,mFinishlength);
    }
    // syslog(LOG_NOTICE,"LengthJudge::init %d,%d",(int)mStartlength,(int)mFinishlength);

}

void LengthJudge::setupdate(Judge::JUDGE_MODE a){
        update=a;

}