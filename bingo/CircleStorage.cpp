#include "CircleStorage.h"

const double CircleStorage::r = 110;   //半径
const int  CircleStorage::dot_r = 30;    //点線半径

CircleStorage::CircleStorage(int n, Color c_color, gameCoordinates c_coordinates)
:BlockStorage(n, c_coordinates)    //コンストラクタ
{
    color = c_color;
    power_block_move = false;
}

color CircleStorage::getColor()    //色を取得する
{
    return cs_color;    //取得した色をリターン
}