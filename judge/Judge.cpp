#include "Judge.h"
#include "app.h"




extern HsvHue *gHue;
extern HsvSatu *gSatu;
extern Brightness *gBrightness;
extern Length *gLength;
extern TurnAngle *gTurnAngle;
extern TailAngle *gTailAngle;

Judge::Judge(){
    mHsvHue = gHue;
    mHsvSatu = gSatu;
    mBrightness = gBrightness;
    mLength = gLength;
    mTurnAngle = gTurnAngle;
    mTailAngle = gTailAngle;
}

bool Judge::run(){
    return true;
}

void Judge::init(){
}



