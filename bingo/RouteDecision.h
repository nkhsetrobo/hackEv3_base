#ifndef _ROUTE_DECISION_H_
#define _ROUTE_DECISION_H_

#include "BingoSectionManager.h"
#include "BingoArea.h"
#include "BlockList.h"
#include "Enum.h"
#include "Struct.h"

class RouteDecition
{
public:
    RouteDecition();    //コンストラクタ
    void passParam(wParam3 *wp);    //移動パラメータを問い合わせる
    int passColor(gameCoordiantes pass_coordinates);    //通過座標の色情報を問い合わせる
    bool minCompare(int now_minCost, int cost);    //最小コストを比較
    virtual int routeDecision();    //ルートを決定する(仮想関数)

private:
    runInfo run_info;    //走行体情報
    int num;
    int minCost = 999;    //最小移動コスト
    runInfo run_info;    //走行体情報
    gameCoordinates goal_coordinates;    //目標地点座標
    //wParam3 wp[100];    //パラメータ(いらない可能性あり)

    BingoArea *bingo_area;
    BingoSectionManager *bingo_manager;
    BlockList *block_list;
};

#endif