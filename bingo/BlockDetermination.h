#ifndef _BLOCK_DETERMINATION_H_
#define _BLOCK_DETERMINATION_H_

#include "RouteDecision.h"
#include "Constant.h"

class BlockDetermination : public RouteDecision
{
public:
    BlockDetermination();    //コンストラクタ
    int routeDecision();    //ルートを決定する
	void finishRun();    //状態を遷移する(block_decision->circle_decision)
};

#endif
