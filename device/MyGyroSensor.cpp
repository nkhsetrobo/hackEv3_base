#include "MyGyroSensor.h"

MyGyroSensor::MyGyroSensor(ePortS port)
    : mPort(port)
{
    mGyro = new GyroSensor(mPort);
    AnglerVelocity = 0.0;
}

void MyGyroSensor::update()
{
    AnglerVelocity = mGyro->getAnglerVelocity();
}

float MyGyroSensor::getValue()
{
    return AnglerVelocity;
}
