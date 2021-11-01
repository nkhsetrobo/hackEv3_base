#include "YPosition.h"

YPosition::YPosition()
    : Measure()
{
}

float YPosition::getvalue()
{
    return mYPosition;
}

void YPosition::update(float y)
{
    mYPosition = y;
}
