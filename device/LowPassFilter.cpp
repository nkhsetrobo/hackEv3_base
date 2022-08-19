#include "LowPassFilter.h"

LowPassFilter::LowPassFilter()
{
    prev=0.0;
    mRate = 0.8;
}
LowPassFilter::~LowPassFilter()
{
}

void LowPassFilter::addValue(float value)
{
    prev = prev*mRate + value*(1-mRate);
}

float LowPassFilter::getFillteredValue()
{    
    return prev;
}

void LowPassFilter::setRate(float rate)
{
    mRate = rate;
}

void LowPassFilter::reset()
{
    reset(0.0);
}

void LowPassFilter::reset(float ini)
{
    prev=ini;
}