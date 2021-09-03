#include "ColorBlock.h"

ColorBlock::ColorBlock(int n, color c, IntersectionCircle *i_circle)
:Block(n)
{
    b_color = c;
    circle = i_circle;

}

color ColorBlock::getColor()
{
    return b_color;    //オブジェクトの属性である色の情報をリターン
}