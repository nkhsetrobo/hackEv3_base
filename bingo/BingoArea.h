#ifndef _BINGO_AREA_H_
#define _BINGO_AREA_H_

//#include "RouteDecision.h"
#include "RunningBody.h"
//#include "Block.h"
#include "TravelableArea.h"
#include "IntersectionCircle.h"
#include "CenterStorage.h"
#include "ColorBlock.h"
#include "CircleStorage.h"
#include "Enum.h"
#include "Constant.h"
#include "Struct.h"
#include "etroboc_ext.h"

class RouteDecision;
//class TravelableArea;
//class CircleStorage;
//class RunningBody;
class Block;
//class IntersectionCircle;
//class CenterStorage;
//class ColorBlock;

class BingoArea
{
public:
    BingoArea();    //コンストラクタ
    void initCircleBlock();    //交点サークル、ブロックの初期化
    void initStorage();    //ブロック置き場の初期化
    gameCoordinates objCoordinates(object object_type, int objrct_num);    //コース内要素座標を問い合わせる
    runInfo runningInformation();    //走行体情報を問い合わせる
    color circleColor(gameCoordinates pass_coordinates);    //交点サークルの色を問い合わせる
    color blockColor(int block_num);    //ブロックの色を問い合わせる
    bool objSuccsesPass(object object_type, int object_num);    //コース内要素が有効移動成立しているか問い合わせる
    gameCoordinates relativeCoordinates(gameCoordinates coordinates, direction rb_direction);    //相対座標系に変換する
    gameCoordinates absoluteCoordinates(gameCoordinates coordinates, direction rb_direction);    //絶対座標系に変換する
    bool coordinatesConparison(gameCoordinates pass_coordinates, gameCoordinates g_coordinates);    //座標比較同値ならtrue
    void updateRunInfo(gameCoordinates new_coordinates, direction new_direction, direction old_direction);    //走行体情報を更新する
    direction convertDirection(direction run_direction, direction relative_direction);    //相対座標系における方向を絶対座標系に変換する

private:
    RunningBody* run_body;
    TravelableArea *object_management_array[INTERSECTION_CIRCLE_COUNT + STORAGE_COUNT];
    Block *block_management_array[BLOCK_COUNT];
    int intersection_circle[INTERSECTION_CIRCLE_COUNT];
    int storage[STORAGE_COUNT];
};

#endif