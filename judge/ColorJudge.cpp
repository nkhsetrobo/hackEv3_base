#include "ColorJudge.h"
#include <cmath>  
#include "util.h"

ColorJudge::ColorJudge()
{
    hue = 0.0;
    satu = 0.0;
    num = 0;
}
void ColorJudge::setColor(float h, float s)
{
    hue = h;
    satu = s;
}
bool ColorJudge::run()
{
    /*奈良岡追加箇所*/
    if (fabs(hue - mHsvHue->getValue()) >= 180)
    {
        num = 360 - (fabs(hue - mHsvHue->getValue()));
    }
    else
    {
        num = fabs(hue - mHsvHue->getValue());
    }

    //if (fabs(hue - num) >= sa2 && fabs(hue - num)<= sa1)
    if (num <= sa)
    {
        printf("%d\n", (int)num);
        if ((mHsvSatu->getValue()) >= satu)
        {
            printf("Value = %f  satu = %f\n", (mHsvSatu->getValue()), satu);
            return true;
        }
    }
    else
    {
        printf("%d\n", (int)num);
        return false;
    }

    return false;
}