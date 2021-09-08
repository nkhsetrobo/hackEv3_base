#ifndef _COLOR_BLOCK_H_
#define _COLOR_BLOCK_H_

#include "Block.h"
#include "Enum.h"
#include "Struct.h"

class ColorBlock : public Block
{
public:
    ColorBlock(int n, color c, TravelableArea *i_circle);    //コンストラクタ
    color getColor();    //色を取得する
    gameCoordinates getCoordinates();    //座標を取得する

private:
    color b_color;    //色
    TravelableArea *circle;
};

#endif