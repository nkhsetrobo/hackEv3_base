#ifndef __VELOCITY_H__
#define __VELOCITY_H__
#include "Measure.h"

#include "HackEv3.h"
#define M_PI 3.14159265358979323846

static const int MAX_CNT=25;  // 0.25s
#if defined(MAKE_RASPIKE) 
static const float DELTA=0.01;
#else
static const float DELTA=0.004;
#endif

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

