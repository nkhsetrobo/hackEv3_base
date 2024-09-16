#ifndef _TAIL_ANGLE_H_
#define _TAIL_ANGLE_H_

#include "Measure.h"

class TailAngle : public Measure
{
    public : 
        TailAngle();
        float getValue();
        void update(float tail);
    
    private :
        float mTailAngle;
};

#endif
