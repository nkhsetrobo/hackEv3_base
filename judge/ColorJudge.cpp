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
    //static char buf[256];
    //sprintf(buf, " %f,%f,\n", mHsvHue->getValue(), mHsvSatu->getValue());
    //msg_log(buf);
    printf("color %f,%f,\n", mHsvHue->getValue(), mHsvSatu->getValue());

    num = hue - mHsvHue->getValue();
 
    if (fabs(num) > 180)
    {
        num = fabs(num)-180;
    }
    else
    {
        num = fabs(num);
    }

   //printf(" %f ,%f , value %f,%f, %f\n",hue,satu, mHsvHue->getValue(), mHsvSatu->getValue(),num);

    if (num >= sa2 && num <= sa1)
    {

        // if(fabs(satu - mHsvSatu->getValue()) >= sa4 && fabs(satu - mHsvSatu->getValue()) <= sa3)
        // {

        //     return true;
        // }

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