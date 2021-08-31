#include "IntersectionCircle.h"

IntersectionCircle::IntersectionCIrcle(int n, Color c, gameCoordiantes c_coordinates)
:PassingCircle(c_coordinates)
{
    inter_circle_num = n;    //引数で受け取った番号を交点サークルナンバーにする
    color = c;    //引数で受け取った番号を色情報として格納する
}

Color IntersectionCircle::getColor()    //色を取得する
{
    return color;
}