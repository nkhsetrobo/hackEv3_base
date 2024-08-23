#ifndef _CAMERA_CARRY_STATUS_JUDGE_H_
#define _CAMERA_CARRY_STATUS_JUDGE_H_
#include "Judge.h"
#include "PipeComm.h"

class CameraCarryStatusJudge : public Judge
{
    public:
        CameraCarryStatusJudge();
        float status();
        void init();

    protected:
            PipeComm *mPcomm;

};
#endif