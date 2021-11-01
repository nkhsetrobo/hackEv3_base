#include "Walker.h"

Walker::Walker( Odometry *odo):
    mOdo(odo)
{
    mPid = new PID();

    mBright = gBrightness;
    mTurnAngle = gTurnAngle;
    mXPosition = gXPosition;
    mYPosition = gYPosition;
}


void Walker::run()
{

}

void Walker::printInfo()
{
    msg_log("Walker");
}

void Walker::init(){

}