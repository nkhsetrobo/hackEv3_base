#include "CircleStorage.h"

const double CircleStorage::r = 110;   //半径
const int  CircleStorage::dot_r = 30;    //点線半径

CircleStorage::CircleStorage()
:BlockStorage()
{
    //コンストラクタ
}

int CircleStorage::getColor()    //色を取得する
{
    return color;    //取得した色をリターン
}