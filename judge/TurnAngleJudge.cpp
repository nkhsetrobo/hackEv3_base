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

    printf("angle run %f : %f->%f\n", mTurnAngle->getValue(),mStartAngle,mFinishAngle);

    if (mFinishAngle >= mStartAngle)
    {
        if (mTurnAngle->getValue() >= mFinishAngle)
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

        if (mTurnAngle->getValue() <= mFinishAngle)
        {
            //printf("turn angle judge -\n");
            return true;
        }
        return false;
    }
}

void TurnAngleJudge::init()
{

    if (update == Judge::UPDATE)
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