#ifndef _MYGYROSENSOR_H_
#define _MYGYROSENSOR_H_

#include "GyroSensor.h"

using namespace ev3api;

class MyGyroSensor
{
    public:
        MyGyroSensor(ePortS port);
        void update();
        float getValue();


    private:
        ePortS mPort;
        GyroSensor *mGyro;

        float AnglerVelocity;

};

#endif
