#include "TurnWalker.h"
#include "math.h"

extern Length *gLength;

TurnWalker::TurnWalker(Odometry *odo,
                                     SpeedControl *scon)
    : SimpleWalker(odo, scon)
{
    mPid->debug=true;
    mPid->debug_char = '%';

    mPFactor = 28;
    mIFactor = 10;
    mDFactor = 0.1;
    mOffset= -10;
#if defined(MAKE_SIM)
    mPFactor = 80;
    mIFactor = 5;
    mDFactor = 2.0;
    mOffset= -20;

#else
#endif

}

void TurnWalker::setParam(float turn,float offset)
{

    mTurn = turn;
    mOffset = offset;
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
   // printf("len %f op %f turn %f\n",len-mStartPos,op,mTurn);

    setCommandV((int)(op+mOffset), (int)mTurn);
    SimpleWalker::run();
}
