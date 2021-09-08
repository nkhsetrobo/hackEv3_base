#ifndef _CENTER_STRAGE_H_
#define _CENTER_STRAGE_H_

#include "Struct.h"
#include "BlockStorage.h"

class CenterStorage : public BlockStorage
{
public:
    CenterStorage(int n, gameCoordinates c_coordinates);    //コンストラクタ
private:
    static const double r;    //半径
};
#endif