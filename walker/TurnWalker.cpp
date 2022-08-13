#include "TurnWalker.h"
#include "math.h"

extern Length *gLength;

TurnWalker::TurnWalker(Odometry *odo,
                                     SpeedControl *scon)
    : SimpleWalker(odo, scon)
{
    mPid->debug=true;
    mPid->debug_char = '%';

    mPFactor = 50;
    mIFactor = 5;
    mDFactor = 1.0;
}

void TurnWalker::setParam(float turn)
{

    mTurn = turn;
    mPid->setTarget(0);

    mPid->setKp(mPFactor);
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);

    mPid->resetParam();
}

void TurnWalker::init()
{
    mPid->setTarget(0);

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();

    mStartPos = gLength->getValue();

}


void TurnWalker::run(){
    
    float len = gLength->getValue();

    float op = mPid->getOperation(len-mStartPos);
    printf("len %f op %f turn %f\n",len-mStartPos,op,mTurn);

    setCommandV((int)op, (int)mTurn);
    SimpleWalker::run();
}
