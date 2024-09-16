#ifndef __POLLING_H__
#define __POLLING_H__

#include "MyColorSensor.h"
#include "Odometry.h"
#include "MyGyroSensor.h"
#include "MySonarSensor.h"

class Polling
{
    public:
        Polling(MyColorSensor *col,
                Odometry *odo,
                MyGyroSensor *gyro,
                MySonarSensor *sonar);
        void run();

    private:
        MyColorSensor *mColor;
        Odometry *mOdo;
        MyGyroSensor *mGyro;
        MySonarSensor *mSonar;

};

#endif

