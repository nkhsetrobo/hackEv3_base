#ifdef _COLOR_BLOCK_H_
#define _COLOR_BLOCK_H_

#include "Block.h"

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

enum Color    //色
{
    blue,    //青
    red,    //赤
    green,    //緑
    yellow    //黄
};

class ColorBlock : public Block
{
public:
    ColorBlock(int n, Color c, IntersectionCircle i_circle);    //コンストラクタ
    Color getColor();    //色を取得する

private:
    Color color;    //色
    IntersectionCircle circle;
}

#endif