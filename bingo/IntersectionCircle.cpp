#include "IntersectionCircle.h"

IntersectionCircle::IntersectionCIrcle(int n, int c)
:PassingCircle()
{
    inter_circle_num = n;    //引数で受け取った番号を交点サークルナンバーにする
    color = c;    //引数で受け取った番号を色情報として格納する
}

int IntersectionCircle::getColor()    //色を取得する
{
    return color;
}