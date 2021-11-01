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
        if ((mHsvSatu->getValue()) >= satu)
        {
            return true;
        }
    }
    else
    {
        return false;
    }

    return false;
}
