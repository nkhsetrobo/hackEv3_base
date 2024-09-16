#ifndef _SECTION_H_
#define _SECTION_H_

#include "LineTracer.h"
#include "SimpleWalker.h"
#include "VirtualLineTracer.h"
#include "VirtualLineTracer2.h"

#include "Walker.h"
#include "Judge.h"
#include "LengthJudge.h"
#include "TurnAngleJudge.h"
#include "BrightnessJudge.h"
#include "ColorJudge.h"
#include "Stop.h"





class Section {
    public:
        Section();
        ~Section();
        virtual bool run();
        virtual void init();

        Walker *selectWalker(int no);
        Judge *selectJudge(int no);
        Judge *createAbnormalJudge();
        int getAbnormalFlag();
		void changeAcc(float a);    //加速度を変更する

        enum WALKER_NO {
            WNONE,
            WALKER,
            TRACER,
            VIRTUAL,
            VIRTUAL2
        };
            enum JUDGE_NO {
            JNONE,
            LENGTH,
            TURNANGLE,
            BRIGHTNESS,
            COLOR,
            STOP
        };

    protected:
        Walker *mWalker;
        Judge *mJudge;
        Judge * aJudge;

        bool first;
        bool first2;

    private:
        int abnormal_flag = 0;


};

#endif
