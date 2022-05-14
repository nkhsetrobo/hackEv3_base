#include "LowPassFilter.h"

LowPassFilter::LowPassFilter()
{
    prev=0.0;
    mRate = 0.4;
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
void LowPassFilter::setPrev(float p)
{
    prev = p;
}


