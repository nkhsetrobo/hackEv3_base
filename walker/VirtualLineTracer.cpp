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
    setBias(mCurve);
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

    float sx= mXPosition->getvalue();
    float sy = mYPosition->getvalue();
    float ang = mTurnAngle->getValue();

    cx = sx - mround * sin((ang / 180) * M_PI);
    cy = sy + mround * cos((ang / 180) * M_PI);

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();

    printf("Vinit %f,%f,%f,  %f,%f,%f\n", sx,sy, ang, cx,cy,mround );
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

    //if( basedistance>  fabs(mround) + 2.0 ) basedistance = fabs(mround) +2.0;
    //else if ( basedistance < fabs(mround) - 2.0 ) basedistance = fabs(mround) -2.0;

    //static char buf[100];
    //printf("%f,\n", basedistance);
    //printf("VT:%f\n",basedistance);
}

float VirtualLineTracer::calcDistance()
{
    double angle = mTurnAngle->getValue();
    float noze=2.0;
    co = noze*cos((angle/180)* M_PI);
    si = noze*sin((angle/180)* M_PI);

    double dist=0;
    if(mTargetSpeed<0){

        dist = sqrt((ax-co-cx)*(ax-co-cx)+(ay-si-cy)*(ay-si-cy));
            
        }
    else{
        dist = sqrt((ax+co-cx)*(ax+co-cx)+(ay+si-cy)*(ay+si-cy));
    }
   printf("VTcalc %f,%f,%f,%f, %f,%f, %f,%f\n", ax,ay,co,si,cx,cy,dist,angle);
        
    return dist;
}

float VirtualLineTracer::calcTurn()
{

    float val1_turn = mPid->getOperation(basedistance);
    float turn = val1_turn;
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
    mTurn += mBias;

    setCommandV((int)mTargetSpeed, (int)mTurn);
    SimpleWalker::run();
}

void VirtualLineTracer::setBias(float curve)
{
    mBias = curve;
}