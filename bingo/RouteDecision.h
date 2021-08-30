#ifndef _ROUTE_DECISION_H_
#define _ROUTE_DECISION_H_

#include "BingoSectionManager.h"
#include "BingoArea.h"
#include "BlockList.h"

/*typedef struct _Param2    //パラメータの構造体
{
    int mwalker;
    int front;   //前進量
    int turn;    //旋回量
    Coordinates coordinates;    //目標地点
    float speed;    //目標速度
    float x;    //中心x座標
    float y;    //中心y座標
    float radius;    //旋回半径
    float mjudge;
    float atai;    //値
    gameCoordinates p_coordinates;    //通過座標
    int mcolor;    //色
    float sat;    //彩度
} wParam3; */

typedef struct Coordinates    //座標
{
    int x;    //x座標
    int y;    //y座標
} Coordinates;

typedef struct gameCoordinates
{
    double x;
    double y;
} gameCoordinates;

typedef struct runInfo    //走行体情報
{
    gameCoordinates game_coordinates;    //ゲーム内座標
    Direction direction;    //方向
} runInfo;

class RouteDecition
{
public:
    RouteDecition();    //コンストラクタ
    void pass_param(wParam3 *wp);    //移動パラメータを問い合わせる
    int pass_Color(gameCoordiantes pass_coordinates);    //通過座標の色情報を問い合わせる
    bool minCompare(int now_minCost, int cost);    //最小コストを比較
    virtual int route_decision();    //ルートを決定する(仮想関数)

private:
    enum Dicrection    //方向
    {
        north,    //北
        east,    //東
        south,    //南
        west    //西
    }
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