#ifndef _CIRCLE_STORAGE_H_
#define _CIRCLE_STORAGE_H_

#include "BlockStorage.h"
#include "Enum.h"
#include "Struct.h"

class CircleStorage : public BlockStorage
{
public:
    CircleStorage(int n, Color color, gameCoordinates c_coordinates);    //コンストラクタ
    Color getColor();    //色を取得する
private:
    Color color;    //色情報
    static const double r = 110;    //半径
    bool power_block_move;    //パワーブロック有効移動成立
    static const int dot_r = 30;    //点線半径
}

#endif