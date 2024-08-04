#ifndef _MYGYROSENSOR_H_
#define _MYGYROSENSOR_H_

#include "GyroSensor.h"
#include "AnglerVelocity.h"
#include "GyroAngle.h"
#include "Measure.h"
#include "TurnAngle.h"

#include "Clock.h"

#include "spike.h"

using namespace ev3api;

class MyGyroSensor : public Measure
{
    public:
        MyGyroSensor(AnglerVelocity* angv,
                    GyroAngle* ga);
        void update();
        void reset();
        void execInit();
        void execUpdate();
        

    private:
        AnglerVelocity *mAnglerVelocity;
        GyroAngle *mGyroAngle;
        TurnAngle *mTurnAngle;

        float angvel;
        float gang;
        float base_gang;

        double gang_v;
        double ang_v[3];
        double offset[3];

        enum State {
            UNDEFINED,
            INIT,
            RUNNING
        };

        State mState;
        int init_cnt;

        Clock *clk;

};

#endif
