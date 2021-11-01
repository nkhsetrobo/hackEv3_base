#ifndef _MYSONARSENSOR_H_
#define _MYSONARSENSOR_H_

#include "SonarSensor.h"

using namespace ev3api;

class MySonarSensor
{
    public:
        MySonarSensor(ePortS port);
        void update();
        float getValue();
    
    private:
        ePortS mPort;
        SonarSensor *mSonar;
        float distance;
        
};

#endif
