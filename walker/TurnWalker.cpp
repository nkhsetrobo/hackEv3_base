#include "TurnWalker.h"
#include "math.h"

extern Length *gLength;

TurnWalker::TurnWalker(Odometry *odo,
                                     SpeedControl *scon)
    : SimpleWalker(odo, scon)
{
    mPid->debug=true;
    mPid->debug_char = '%';
    mLpf=new LowPassFilter();
    mLpf->setRate(0.8);

    mPFactor = 20;
    mIFactor = 25;
    mDFactor = 2.5;
    mOffset= 0;
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
    mLpf->reset(0);
}

void TurnWalker::init()
{
    mPid->setTarget(0);

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();

    mStartPos = gLength->getValue();
    mLpf->reset(mStartPos);

    printf("reset TuenWalker\n");

}


void TurnWalker::run(){
    
    float len = gLength->getValue();
    mLpf->addValue(len);
    len = mLpf->getFillteredValue();

    float op = mPid->getOperation(len-mStartPos);
   // printf("len %f op %f turn %f\n",len-mStartPos,op,mTurn);

    setCommandV((int)(op+mOffset), (int)mTurn);
    SimpleWalker::run();
}
