#include "VirtualLineTracer.h"
#include "math.h"
#define M_PI 3.14159265358979323846

VirtualLineTracer::VirtualLineTracer(Odometry *odo,
                                     SpeedControl *scon)
    : SimpleWalker(odo, scon)
{
    cx = 0;
    cy = 0;
    ax = 0;
    ay = 0;
    basedistance = 0;
    currentdistance = 0;
    mTarget = 0;
    mTargetSpeed = 0;
    mPFactor = 0;
    mIFactor = 0;
    mDFactor = 0;
    mLimit = 100;
    co=0;
    si=0;

    mPid->debug=true;
    mPid->debug_char = 'V';

    mLpf = new LowPassFilter();

}

void VirtualLineTracer::setParam(float speed, float kp, float ki, float kd, float angleTarget, float angleKp)
{

    mTargetSpeed = speed;

    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

    mPid->setTarget(fabs(mround));

    mPid->setKp(mPFactor);
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);

    mCurve = angleTarget;
    mAngleKp = angleKp;

    currentdistance = calcDistance();

    mPid->resetParam();
}

void VirtualLineTracer::setRound(float round)
{
    mround = round;
}

void VirtualLineTracer::init()
{

    cx = mXPosition->getvalue() - mround * sin((mTurnAngle->getValue() / 180) * M_PI);
    cy = mYPosition->getvalue() + mround * cos((mTurnAngle->getValue() / 180) * M_PI);

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();
    ax = mXPosition->getvalue();
    ay = mYPosition->getvalue();
    basedistance = calcDistance();
    mLpf->setRate(0.1);
    mLpf->setPrev(basedistance);

   // printf("Virurl %f,%f,%f\n",  cx,cy,mround );
}

void VirtualLineTracer::setCenterPosition(float centerx, float centery)
{
    cx = centerx;
    cy = centery;
}

void VirtualLineTracer::setBaseDistance()
{
    ax = mXPosition->getvalue();
    ay = mYPosition->getvalue();
    basedistance = calcDistance();
    mLpf->addValue(basedistance);
    basedistance = mLpf->getFillteredValue();


    //static char buf[100];
  // printf("VT:%f\n",basedistance);
}

float VirtualLineTracer::calcDistance()
{
   //printf("%f,%f,%f,%f,%f\n", ax,ay,cx,cy,mTurnAngle->getValue());
    float noze=3.0;
    co = noze*cos((mTurnAngle->getValue()/180)* M_PI);
    si = noze*sin((mTurnAngle->getValue()/180)* M_PI);

    if(mTargetSpeed<0){
        return  sqrt((ax-co-cx)*(ax-co-cx)+(ay-si-cy)*(ay-si-cy));
            
        }
    else{
        return  sqrt((ax+co-cx)*(ax+co-cx)+(ay+si-cy)*(ay+si-cy));
    }
    
        
}

float VirtualLineTracer::calcTurn()
{

    float val1_turn = mPid->getOperation(basedistance);
    setBias(-mForward * (1 - mCurve) / (1 + mCurve) * mAngleKp);
    float turn = val1_turn + mBias;
    return turn;
}
void VirtualLineTracer::setLimit(float limit)
{
    mLimit = limit;
    mPid->setLimit(limit);
}


void VirtualLineTracer::run(){
    

    setBaseDistance();

    if (mTargetSpeed > 0)
    {
        if (mround < 0)
        {
            mTurn = -(calcTurn());
        }
        else
        {
            mTurn = (calcTurn());
        }
    }
    else
    {
        if (mround < 0)
        {
            mTurn = (calcTurn());
        }
        else
        {
            mTurn = -(calcTurn());
        }
    }

    setCommandV((int)mTargetSpeed, (int)mTurn);
    SimpleWalker::run();
}

void VirtualLineTracer::setBias(float curve)
{
    mBias = curve;
}