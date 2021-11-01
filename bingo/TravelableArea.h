#ifndef _TRAVELABLE_AREA_H_
#define _TRAVELABLE_AREA_H_

//#include "BingoArea.h"
#include "Block.h"
#include "Struct.h"

class BingoArea;

class TravelableArea
{
public:
    TravelableArea(gameCoordinates c_coordinates);    //コンストラクタ
    gameCoordinates getCoordinates();    //座標を取得する
    
protected:
    gameCoordinates coordinates;    //座標

private:
    Block *block;
};

#endif