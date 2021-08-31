#include "ColorBlock.h"

ColorBlock::ColorBlock(int n, Color c)
:Block(n)
{
    color = c;
}

Color ColorBlock::getColor()
{
    return color;    //オブジェクトの属性である色の情報をリターン
}