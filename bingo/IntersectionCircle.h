#ifndef _INTERSECTION_CIRCLE_H_
#define _INTERSECTION_CIRCLE_H_

#include "PassingCircle.h"

class IntersectionCircle : public PassingCircle
{
public:
    IntersectionCircle(int n, int c);    //コンストラクタ
    int getColor();    //色を取得する

private:
    int inter_circle_num;    //交点サークルナンバー
    int color;    //色
};

#endif