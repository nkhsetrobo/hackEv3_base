#ifndef _PASSING_CIRCLE_H_
#define _PASSING_CIRCLE_H_

#include "TravelableArea.h"

class PassingCircle : public TravelableArea
{
public:
    PassingCircle();    //コンストラクタ
private:
    static const double r;    //半径
};

#endif