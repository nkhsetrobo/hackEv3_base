#ifndef _BLOCKSTORAGE_H_
#define _BLOCKSTORAGE_H_

#include "TravelableArea.h"

class BlockStorage : public TravelableArea
{
public:
	BlockStorage(int n, gameCoordinates c_coordinates);

private:
	int BS_number;     //ブロック置き場ナンバー
	bool b_succses_pass;    //有効移動成立
	Block *brock;
};
