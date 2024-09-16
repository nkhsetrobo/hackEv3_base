#include "XPosition.h"

XPosition::XPosition()
    : Measure()
{
}

float XPosition::getvalue()
{
    return mXPosition;
}

void XPosition::update(float x)
{
    mXPosition = x;
}
