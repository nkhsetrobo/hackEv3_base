#ifdef _COLOR_BLOCK_H_
#define _COLOR_BLOCK_H_

#include "Block.h"

class ColorBlock : public Block
{
public:
    ColorBlock(int n, Color c);    //コンストラクタ
    Color getColor();    //色を取得する

private:
    enum Color
    {
        blue,   //青
        red,    //赤
        green,  //緑
        yellow  //黄
    };
    Color color;    //色
}

#endif