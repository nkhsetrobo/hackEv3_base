#include "GyroAngle.h"
#include "util.h"

GyroAngle::GyroAngle()
    :Measure()
{

}

float GyroAngle::getValue()
{
    /*static char buf[256];
    sprintf(buf,"return:%f ",gAngle);
    msg_log(buf);*/

    return gAngle;
}

void GyroAngle::update(float ga)
{
    gAngle = -ga;

    //printf("gyro update %f\n",ga);
    /*static char buf[256];
    sprintf(buf,"update:%f\n",gAngle);
    msg_log(buf);*/
}