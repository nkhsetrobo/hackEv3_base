#ifdef _COLOR_BLOCK_H_
#define _COLOR_BLOCK_H_

#include "Block.h"

class ColorBlock : public Block
{
public:
    ColorBlock(int i, int c);    //コンストラクタ
    int getColor();    //色を取得する

private:
    int color;    //色
}

#endif