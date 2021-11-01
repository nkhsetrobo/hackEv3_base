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
}

float MySonarSensor::getValue()
{
    return distance;
}
