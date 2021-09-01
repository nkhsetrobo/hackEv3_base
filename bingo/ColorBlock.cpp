#include "ColorBlock.h"

ColorBlock::ColorBlock(int n, Color c, IntersectionCircle i_circle)
:Block(n)
{
    color = c;
    circle = i_circle;

}

Color ColorBlock::getColor()
{
    return color;    //オブジェクトの属性である色の情報をリターン
}