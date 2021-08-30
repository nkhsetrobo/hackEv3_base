#ifndef _CIRCLE_DECISION_H_
#define _CIRCLE_DECISION_H_

#include "RouteDecision.h"

class CircleCoordinates : public RouteDecision
{
public:
    CircleDecision();    //コンストラクタ
    int route_decision();    //ルートを決定する
};

#endif