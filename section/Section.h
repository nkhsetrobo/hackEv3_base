#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"
#include "VirtualLineTracer.h"
#include "VirtualLineTracer2.h"
#include "TailWalker.h"
#include "ArmWalker.h"

#include "Walker.h"
#include "Judge.h"
#include "LengthJudge.h"
#include "TurnAngleJudge.h"
#include "BrightnessJudge.h"
#include "ColorJudge.h"
#include "TailAngleJudge.h"
#include "ArmAngleJudge.h"
#include "Stop.h"
#include "SonerJudge.h"
#include "SonerStatusJudge.h"
#include "ColorStatusJudge.h"

class Section
{
public:
    Section();
    ~Section();
    virtual bool run();
    virtual void init();

    Walker *selectWalker(int no);
    Judge *selectJudge(int no);
    Judge *selectStatusJudge(int no);
    Judge *selectJudgePtr(int no);
    Judge *getJudge();
    int getError();
    float getStatus();
    void setID(int id);
    int getID();

    enum WALKER_NO
    {
        WNONE,
        WALKER,
        TRACER,
        VIRTUAL,
        VIRTUAL2,
        TAIL,
        ARM,
        WEND=-1
    };
    enum JUDGE_NO
    {
        JNONE,
        LENGTH,
        TURNANGLE,
        BRIGHTNESS,
        COLOR,
        TAILANGLE,
        ARMANGLE,
        STOP,
        SONER,
        SONERSTATUS,
        COLORSTATUS,
        JEND=-1
    };

protected:
    Walker *mWalker;
    Judge *mJudge;
    Judge *mEmergencyJudge;
    Judge *mStatusJudge;
    bool debug;

private:
    bool first;
    bool first2;

    bool emergency;
    int error_code;
    float status;

    int id;
};

#endif
