#ifndef _CIRCLE_DECISION_H_
#define _CIRCLE_DECISION_H_

#include "RouteDecision.h"
#include "Constant.h"

class CircleCoordinates : public RouteDecision
{
public:
    CircleDecision();    //コンストラクタ
    int routeDecision();    //ルートを決定する
};

#endif