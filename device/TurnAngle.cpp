#include "TurnAngle.h"
#include "ev3api.h"
TurnAngle::TurnAngle()
    : Measure(),
    mAngleDeg(true)
{
}

float TurnAngle::getValue()
{
    return mAngleDeg?mAngle*180/M_PI:mAngle;
}

void TurnAngle::update(float angle)
{
    mAngle = angle;
    //printf("TurnAngle angle %f\n",mAngle*180/M_PI);
}