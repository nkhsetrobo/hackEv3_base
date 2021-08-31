#ifndef _TRAVELABLE_AREA_H_
#define _TRAVELABLE_AREA_H_

#include "BingoArea.h"
#include "Block.h"

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

class TravelableArea
{
public:
    TravelableArea(gameCoordinates c_coordinates);    //コンストラクタ
    gameCoordinates getCoordinates();    //座標を取得する
private:
    gameCoordinates coordinates;    //座標
    BingoArea *bingo_area;
    Block *block;
};

#endif