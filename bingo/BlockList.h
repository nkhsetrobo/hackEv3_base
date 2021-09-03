#ifndef _BLOCK_LIST_H_
#define _BLOCK_LIST_H_

#include "RouteDecision.h"
#include "Enum.h"

/*typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordiantes;*/

/*typedef struct runInfo    //走行体情報
{
    Direction direction;    //方向
    gameCoordinates rb_coordinates;    //走行体座標
} runInfo;*/

/*ここに移動パターンのパラメータの構造体を定義する*/

/*
typedef struct PassList
{
    スタート座標
    目的地座標
    移動コスト
    移動パラメータの配列
} PassList;
}
*/

class BlockList
{
public:
    double getCost(gameCoordinates rb_coordiantes, gameCoordinates goal_coordinates);    //コストを取得する
    void getParam(/*パラメータ型*/ *wp, gameCoordiantes rb_coordinates, gameCoordinates goal_coordinates);    //移動パラメータを取得する
private:
    double cost;    //移動コスト
    PassList pass_list[320];    //初期値の設定必要(パラメータ担当がやってくれている)
    /*パラメータ型*/ wp[];    //移動パラメータの配列(サイズはまだ知らない)

    RouteDecision *routeDecision;    //関連
};

#endif