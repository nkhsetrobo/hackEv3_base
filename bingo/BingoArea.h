#ifndef _BINGO_AREA_H_
#define _BINGO_AREA_H_

#include "RouteDecision.h"
#include "RunningBody.h"
#include "Block.h"
#include "TravelableArea.h"

enum Direction    //方向
{
    north,    //北
    east,    //東
    south,    //南
    west    //西
};

enum Color    //色
{
    blue,    //青
    red,    //赤
    green,    //緑
    yellow    //黄
};

enum object    //コース内要素
{
    block,    //ブロック
    storage    //ブロック置き場
};

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

typedef struct runInfo    //走行体情報
{
    Direction direction;    //方向
    gameCoordinates game_coordinates;    //ゲーム内座標
} runInfo;

class BingoArea
{
public:
    BingoArea();    //コンストラクタ
    void initCircleBlock();    //交点サークル、ブロックの初期化
    void initStorage();    //ブロック置き場の初期化
    gameCoordinates objCoordinates(object object_type, int objrct_num);    //コース内要素座標を問い合わせる
    runInfo runningInformation();    //走行体情報を問い合わせる
    Color circleColor(gameCoordinates pass_coordinates);    //交点サークルの色を問い合わせる
    int blockColor(int block_num);    //ブロックの色を問い合わせる
    bool objSuccsesPass(object object_type, int object_num);    //コース内要素が有効移動成立しているか問い合わせる
    gameCoordinates relativeCoordinates(gameCoordinates coordinates, Direction rb_direction);    //相対座標系に変換する
    gameCoordinates absoluteCoordinates(gameCoordinates coordinates, Direction rb_direction);    //絶対座標系に変換する
    bool coordinatesConparison(gameCoordiantes pass_coordinates, gameCoordiantes g_coordinates);    //座標比較同値ならtrue
    static const int INTERSECTION_CIRCLE_COUNT;    //交点サークルの個数
    static const int BLOCK_COUNT;    //ブロックの個数
    static const int STORAGE_COUNT;    //ブロック置き場の個数
    
private:
    RouteDecision* routeDecision;
    RunningBody* run_body;
    TravelableArea* object_management_array[34];
    int intersection_circle[16];
    int storage[9];
    int block[9];
};

#endif