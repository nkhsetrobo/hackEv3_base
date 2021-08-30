#include "ColorBlock.h"

ColorBlock::ColorBlock(int i, int c)
:Block(i)
{
    color = c;
}

int ColorBlock::getColor()
{
    return color;    //オブジェクトの属性である色の情報をリターン
}