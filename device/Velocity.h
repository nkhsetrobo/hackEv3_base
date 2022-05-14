#ifndef __VELOCITY_H__
#define __VELOCITY_H__
#include "Measure.h"

#include "HackEv3.h"
#define M_PI 3.14159265358979323846

static const int MAX_CNT=25;  // 0.25s
static const float DELTA=0.01;
<<<<<<< Updated upstream
=======
//static const float DELTA=0.016666;
>>>>>>> Stashed changes

class Velocity : public Measure
{
    public:
        Velocity();
        float getValue();
        void update(float cnt1,float cnt2);
    private:
        float mVelocity;

        float mCounts1[MAX_CNT];
        float mCounts2[MAX_CNT];
        int mCounts_idx=0;

};

#endif

