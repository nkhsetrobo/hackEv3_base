#ifndef _COLOR_STATUS_JUDGE_H_
#define _COLOR_STATUS_JUDGE_H_
#include "Judge.h"
#include "HackEv3.h"


class ColorStatusJudge : public Judge
{
    public:
        ColorStatusJudge();
        virtual float status();
        float subhue(float h1, float h2);

    protected:
        int color[4];
        int color_id;

};
#endif
