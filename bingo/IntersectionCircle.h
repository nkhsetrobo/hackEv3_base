#ifndef _INTERSECTION_CIRCLE_H_
#define _INTERSECTION_CIRCLE_H_

#include "PassingCircle.h"

class IntersectionCircle : public PassingCircle
{
public:
    IntersectionCircle(int n, Color c, gameCoordinates c_coordinates);    //コンストラクタ
    Color getColor();    //色を取得する

private:
    enum Color
    {
        blue,   //青
        red,    //赤
        green,  //緑
        yellow  //黄
    };
    int inter_circle_num;    //交点サークルナンバー
    Color color;    //色
};

#endif