#ifndef _SONNER_STATUS_JUDGE_H_
#define _SONNER_STATUS_JUDGE_H_
#include "Judge.h"

class SonerStatusJudge : public Judge
{
    public:
        SonerStatusJudge();
        float status();

    private:
        float mMinValue;

};
#endif
