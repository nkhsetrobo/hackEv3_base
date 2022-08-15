#include "TurnWalker.h"
#include "math.h"

extern Length *gLength;

TurnWalker::TurnWalker(Odometry *odo,
                                     SpeedControl *scon)
    : SimpleWalker(odo, scon)
{
    mPid->debug=true;
    mPid->debug_char = '%';

    mPFactor = 30;
    mIFactor = 10;
    mDFactor = 0.2;
    mOffset= -10;
#if defined(MAKE_SIM)
    mPFactor = 40;
    mIFactor = 5;
    mDFactor = 0.5;
    mOffset= 0;

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
