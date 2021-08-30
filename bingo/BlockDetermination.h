#ifndef _BLOCK_DETERMINATION_H_
#define _BLOCK_DETERMINATION_H_

#include "RouteDecision.h"

class BlockDetermination : public RouteDecision
{
public:
    BlockDetermination();    //コンストラクタ
    int route_decision();    //ルートを決定する
};