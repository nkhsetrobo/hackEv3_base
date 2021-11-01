#ifndef _TAILWALKER_H_
#define _TAILWALKER_H_

#include "Walker.h"
#include "Motor.h"
#include "Odometry.h"
#include "SpeedControl.h"

class TailWalker : public Walker
{
    public:
        TailWalker(Odometry *odo,
                    SpeedControl *scon);
        void setPwm(float tailp);
        void run();
    
    protected:
        SpeedControl *mSpeedControl;

    private:
        int tp;

};

#endif
