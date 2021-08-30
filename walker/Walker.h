#ifndef WALKER_H_
#define WALKER_H_

#include "Odometry.h"
#include "Brightness.h"
#include "PID.h"
#include "XPosition.h"
#include "YPosition.h"

extern Brightness *gBrightness;
extern XPosition *gXPosition;
extern YPosition *gYPosition;
extern TurnAngle *gTurnAngle;

class Walker
{
public:
    Walker(Odometry *odo);

    virtual void init();
    virtual void run();
    virtual void printInfo();



protected:
    Odometry *mOdo;
    PID *mPid;

    Brightness *mBright;
    XPosition *mXPosition;
    YPosition *mYPosition;
    TurnAngle *mTurnAngle;

private:
};
#endif
