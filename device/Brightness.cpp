#include "Brightness.h"
#include "ev3api.h"

Brightness::Brightness()
    : Measure()
{

}

float Brightness::getValue()
{
    return mLpf->getFillteredValue();
}

void Brightness::update(float br)
{
    mLpf->addValue(br);
    mBrightness = br;
   // printf("bright %f\n",mLpf->getFillteredValue());
}