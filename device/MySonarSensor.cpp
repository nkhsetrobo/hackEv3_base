#include "MySonarSensor.h"

MySonarSensor::MySonarSensor(ePortS port)
    : mPort(port)
{
    mSonar = new SonarSensor(mPort);
    distance = 0.0;
}

void MySonarSensor::update()
{
    distance = mSonar->getDistance();
//printf("%d   %f\n",mSonar,distance);
}

float MySonarSensor::getValue()
{
    //printf("getVal   %f\n",distance);
    return distance;
}
