#ifndef _MOTION_GENERATION_H_
#define _MOTION_GENERATION_H_

#include "BingoSectionManager.h"

class MotionGeneration
{
    public:
    MotionGeneration();
    void GenerateMotion();
    
    Motionname *motionname(int no);

        enum MOTION_NO {
            STRAIGHT,
            TURNRIGHT,
            TURNLEFT,
            BACK
        };
}