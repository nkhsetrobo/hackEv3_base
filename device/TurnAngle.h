#ifndef __TURNANGLE_H__
#define __TURNANGLE_H__
#include "Measure.h"

#define M_PI 3.14159265358979323846

class TurnAngle : public Measure
{
    public:
        TurnAngle();
        float getValue();
        void update(float angle);
        void reset();

    private:
        float mAngle;
        bool mAngleDeg;
};

#endif

