#ifndef _JUDGE_H_
#define _JUDGE_H_

#include "HsvHue.h" 
#include "HsvSatu.h"
#include "Brightness.h"
#include "Length.h"
#include "TurnAngle.h"
#include "TailAngle.h"



class Judge{
    public:
    Judge();
    virtual bool run();
    virtual void init();
    int detection_abnormal();

    enum  JUDGE_MODE
    {
        UPDATE,
        UNUPDATE
    };

    protected:
    HsvHue *mHsvHue;
    HsvSatu *mHsvSatu;
    Brightness *mBrightness;
    Length *mLength;
    TurnAngle *mTurnAngle;
    TailAngle *mTailAngle;



};


#endif