#ifndef _BLOCKSTORAGE_H_
#define _BLOCKSTORAGE_H_

#include "TravelableArea.h"

class BlockStorage : public TravelableArea
{
public:
	BlockStorage(int n, gameCoordinates c_coordinates);
	bool getSuccsesPass();
	void effectiveMovementJudgement();

protected:
	int bs_number;     //ブロック置き場ナンバー

private:
	Block *brock;
	TravelableArea *travelable_area;
	bool succses_pass;    //有効移動成立
};

#endif
