#ifndef _COLOR_H_
#define _COLOR_H_
#include "Judge.h"

class ColorJudge :public Judge
{
    public:
    ColorJudge();
    void setColor(float h,float s);
    bool run();

    private:
    float hue;
    float satu;
    float sa = 25;  //色の誤差
    float num;
};

#endif



