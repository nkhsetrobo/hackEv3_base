#ifndef _ROUTE_DECISION_H_
#define _ROUTE_DECISION_H_

//#include "BingoSectionManager.h"
#include "BingoArea.h"
#include "BlockList.h"
#include "Enum.h"
#include "Struct.h"

class BingoSectionManager;

class RouteDecition
{
public:
    RouteDecition();    //コンストラクタ
    void passParam(mparam *p);    //移動パラメータを問い合わせる
    int passColor(gameCoordinates pass_coordinates);    //通過座標の色情報を問い合わせる
    bool minCompare(int now_min_cost, int cost);    //最小コストを比較
    virtual int routeDecision();    //ルートを決定する(仮想関数)

private:
    int num;
    int min_cost = 999;    //最小移動コスト
    gameCoordinates goal_coordinates;    //目標地点座標
    passList wp[100];    //paramを含む拡張版パラメータ
    mparam p[100];    //自分たちのパラメータ
    BingoArea *bingo_area;
    BingoSectionManager *bingo_manager;
    BlockList *block_list;
};

#endif