#ifndef _ROUTE_DECISION_H_
#define _ROUTE_DECISION_H_

//#include "BingoSectionManager.h"
#include "BingoArea.h"
#include "BlockList.h"
#include "Enum.h"
#include "Struct.h"
//#include "Scene.h"

//class BingoArea;
class BingoSectionManager;
//class Scene;

class RouteDecision
{
public:
    RouteDecision();    //コンストラクタ
    void passParam(mParam *p);    //移動パラメータを問い合わせる
    int passColor(gameCoordinates pass_coordinates);    //通過座標の色情報を問い合わせる
    bool minCompare(double now_min_cost, double cost);    //最小コストを比較
    virtual int routeDecision();    //ルートを決定する(仮想関数)
	void initList();    //移動パターンリストの初期化

protected:
    runInfo run_info;
    int num;
    double min_cost = 999;    //最小移動コスト
    gameCoordinates goal_coordinates;    //目標地点座標
	gameCoordinates ri_coordinates;    //相対座標
    passList wp[100];    //paramを含む拡張版パラメータ
    mParam *p;    //自分たちのパラメータ
    BingoSectionManager *bingo_manager;
    BlockList *block_list;
    passList pass_list;
	BingoArea *bingo_area;
};
#endif

