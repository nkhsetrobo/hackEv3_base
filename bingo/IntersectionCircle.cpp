#include "IntersectionCircle.h"

IntersectionCircle::IntersectionCIrcle(int n, color c, gameCoordiantes c_coordinates)
:PassingCircle(c_coordinates)
{
    inter_circle_num = n;    //引数で受け取った番号を交点サークルナンバーにする
    inter_color = c;    //引数で受け取った番号を色情報として格納する
}

color IntersectionCircle::getColor()    //色を取得する
{
    return inter_color;
}