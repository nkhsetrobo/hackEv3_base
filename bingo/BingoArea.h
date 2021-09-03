#ifndef _BINGO_AREA_H_
#define _BINGO_AREA_H_

#include "RouteDecision.h"
#include "RunningBody.h"
#include "Block.h"
#include "TravelableArea.h"
#include "Enum.h"

#define INTERSECTION_CIRCLE_COUNT 16    //交点サークルの個数
#define BLOCK_COUNT 9    //ブロックの個数
#define STORAGE_COUNT 9    //ブロック置き場の個数

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
    bool coordinatesConparison(gameCoordinates pass_coordinates, gameCoordinates g_coordinates);    //座標比較同値ならtrue
    
private:
    RunningBody* run_body;
    TravelableArea* object_management_array[34];
    int intersection_circle[16];
    int storage[9];
    int block[9];
};

#endif