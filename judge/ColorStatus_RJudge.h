#ifndef _COLOR_STATUS_R_JUDGE_H_
#define _COLOR_STATUS_R_JUDGE_H_
#include "ColorStatusJudge.h"
#include "HackEv3.h"


class ColorStatus_RJudge : public ColorStatusJudge
{
    public:
        ColorStatus_RJudge();
        float status();

    private:
        bool mOtherCol;
};
#endif
