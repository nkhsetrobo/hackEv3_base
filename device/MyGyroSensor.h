#ifndef _MYGYROSENSOR_H_
#define _MYGYROSENSOR_H_

#include "GyroSensor.h"
#include "AnglerVelocity.h"
#include "GyroAngle.h"
#include "Measure.h"
#include "TurnAngle.h"

#include "Clock.h"

using namespace ev3api;

class MyGyroSensor : public Measure
{
    public:
        MyGyroSensor(ePortS port,
                    AnglerVelocity* angv,
                    GyroAngle* ga);
        void update();
        void reset();

    private:
        ePortS mPort;
        GyroSensor *mGyro;
        AnglerVelocity *mAnglerVelocity;
        GyroAngle *mGyroAngle;
        TurnAngle *mTurnAngle;

        float angvel;
        float gang;
        float base_gang;

        double gang_v;

        Clock *clk;

};

#endif
