#include "TurnAngleJudge.h"
#include "util.h"

extern float gStartAngle;

TurnAngleJudge::TurnAngleJudge()
{
    mStartAngle = 0.0;
    mFinishAngle = 0.0;
}

void TurnAngleJudge::setFinishAngle(float finangle)
{
    mFinishAngle = finangle;
}

bool TurnAngleJudge::run()
{

    //printf("angle run %f : %f->%f\n", mTurnAngle->getValue(),mStartAngle,mFinishAngle);
    //printf("angle run %f : %f->%f\n", mGyroAngle->getValue(),mStartAngle,mFinishAngle);

    double angle = mTurnAngle->getValue();
    //double angle = mGyroAngle->getValue();
    if (mFinishAngle >= mStartAngle)
    {
        if (angle >= mFinishAngle)
        {
          //  printf("turn angle judge +\n");

            return true;
        }

        return false;
    }
    else
    {
        /*static char buf[256];
        sprintf(buf, "%f,%f,%f,\n", mTurnAngle->getValue(), mStartAngle, mFinishAngle);
        msg_log(buf);*/

        if (angle <= mFinishAngle)
        {
            //printf("turn angle judge -\n");
            return true;
        }
        return false;
    }
}

void TurnAngleJudge::init()
{

    if (update == Judge::UPDATE || update == Judge::UPDATEALL)
    {

        gStartAngle = mTurnAngle->getValue();
        mStartAngle = gStartAngle;
        mFinishAngle = mFinishAngle + gStartAngle;
    }
    else{
        mStartAngle=mTurnAngle->getValue();
        mFinishAngle=mFinishAngle+gStartAngle;
    }
}

void TurnAngleJudge::setupdate(Judge::JUDGE_MODE a)
{
    update = a;
}