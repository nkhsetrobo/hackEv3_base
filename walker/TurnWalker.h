#ifndef _TURN_WALKER_H_
#define _TURN_WALKER_H_

#include "SimpleWalker.h"
#include "PID.h"


class TurnWalker : public SimpleWalker{
    public:
    TurnWalker(Odometry *odo,
                    SpeedControl *scon);

    void run();
    void init();
    void setParam(float turn);


    private:
        float mTurn;
        float mTargetSpeed;
        float mPFactor;
        float mIFactor;
        float mDFactor;

        float mStartPos;

        float offset;


};


#endif