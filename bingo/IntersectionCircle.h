#ifndef _INTERSECTION_CIRCLE_H_
#define _INTERSECTION_CIRCLE_H_

#include "PassingCircle.h"
#include "Enum.h"
#include "Struct.h"

class IntersectionCircle : public PassingCircle
{
public:
    IntersectionCircle(int n, color c, gameCoordinates c_coordinates);    //コンストラクタ
    color getColor();    //色を取得する

private:
    int inter_circle_num;    //交点サークルナンバー
    color inter_color;    //色
};

#endif