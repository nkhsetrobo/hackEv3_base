#ifndef _TAIL_ANGLE_JUDGE_H_
#define _TAIL_ANGLE_JUDGE_H_

#include "Judge.h"

class TailAngleJudge : public Judge
{
    public :
        TailAngleJudge();
        void init();
        void setFinAngle(float finangle);
        bool run();

    private : 
        float mStartAngle;
        float mFinAngle;

};

#endif
