#include "Polling.h"

Polling::Polling(MyColorSensor *col,
                 Odometry *odo,
                 MyGyroSensor *gyro,
                 MySonarSensor *sonar):
    mColor(col),
    mOdo(odo),
    mGyro(gyro),
    mSonar(sonar)
{

}

void Polling::run()
{
    mColor->update();
    mGyro->update();
    mOdo->update();
    mSonar->update();    
}
