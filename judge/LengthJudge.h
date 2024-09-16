#ifndef _LENGTHJUDGE_H_
#define _LENGTHJUDGE_H_

#include "Judge.h"
class LengthJudge : public Judge{
    public:
    LengthJudge();
    void setFinLength2();
    void setFinLength(float finlength);
    bool run();
    void init();
    void setupdate(Judge::JUDGE_MODE a);
    

    private:
    float mStartlength;
    float mFinishlength;
    
    Judge::JUDGE_MODE update;
    



};



#endif