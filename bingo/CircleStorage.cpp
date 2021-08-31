#include "CircleStorage.h"

const double CircleStorage::r = 110;   //半径
const int  CircleStorage::dot_r = 30;    //点線半径

CircleStorage::CircleStorage(int n, Color c_color, gameCoordinates c_coordinates)
:BlockStorage(n, c_coordinates)    //コンストラクタ
{
    color = c_color;
    power_block_move = false;
}

Color CircleStorage::getColor()    //色を取得する
{
    return color;    //取得した色をリターン
}