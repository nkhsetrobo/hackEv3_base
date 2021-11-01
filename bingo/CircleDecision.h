#ifndef _CIRCLE_DECISION_H_
#define _CIRCLE_DECISION_H_

#include "BingoSectionManager.h"
#include "RouteDecision.h"
#include "Constant.h"
#include "Struct.h"

class CircleDecision : public RouteDecision
{
public:
    CircleDecision();    //コンストラクタ
    int routeDecision();    //ルートを決定する
	void finishRun();    //状態遷移(circle_decision->block_decision)
private:
    BingoSectionManager *bsm;
};

#endif
