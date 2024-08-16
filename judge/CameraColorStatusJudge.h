#ifndef _CAMERA_COLOR_STATUS_JUDGE_H_
#define _CAMERA_COLOR_STATUS_JUDGE_H_
#include "Judge.h"
#include "PipeComm.h"

class CameraColorStatusJudge : public Judge
{
    public:
        CameraColorStatusJudge();
        virtual float status();

    protected:
            PipeComm *mPcomm;

};
#endif