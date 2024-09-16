#include "TailWalker.h"
#include "Walker.h"
#include "util.h"

TailWalker::TailWalker(Odometry *odo,
                        SpeedControl *scon):
    Walker(odo),
    mSpeedControl(scon)

{
    tp = 0.0;   
}

void TailWalker::setPwm(float tailp)
{
    tp = (int)tailp;
}

void TailWalker::run()
{
    mOdo->setTailpwm(tp);
}