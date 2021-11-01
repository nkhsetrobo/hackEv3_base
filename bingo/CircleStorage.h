#ifndef _CIRCLE_STORAGE_H_
#define _CIRCLE_STORAGE_H_

#include "BlockStorage.h"
#include "Enum.h"
#include "Struct.h"

class CircleStorage : public BlockStorage
{
public:
    CircleStorage(int n, color c_color, gameCoordinates c_coordinates);    //コンストラクタ
    color getColor();    //色を取得する
private:
    color cs_color;    //色情報
    static const double r;    //半径
    bool power_block_move;    //パワーブロック有効移動成立
    static const int dot_r;    //点線半径
};

#endif
