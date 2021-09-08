#ifndef _PASSING_CIRCLE_H_
#define _PASSING_CIRCLE_H_

#include "TravelableArea.h"

class PassingCircle : public TravelableArea
{
public:
    PassingCircle(gameCoordiantes c_coordinates);    //コンストラクタ
protected:
    static const double r;    //半径
};

#endif