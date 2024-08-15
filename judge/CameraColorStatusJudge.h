#ifndef _CAMERA_COLOR_STATUS_JUDGE_H_
#define _CAMERA_COLOR_STATUS_JUDGE_H_
#include "Judge.h"


class CameraColorStatusJudge : public Judge
{
    public:
        CameraColorStatusJudge();
        virtual float status();

    protected:
        int color[4];
        int color_id;

        bool first;

};
#endif