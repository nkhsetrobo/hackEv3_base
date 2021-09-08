#include "BlockStorage.h"

BlockStorage::BlockStorage(int n, gameCoordinates c_coordinates)
:TravelableArea(c_coordinates)		//コンストラクタ
{
	bs_number = n;
	succses_pass = false;
}

bool BlockStorage::getSuccsesPass()
{
	return succses_pass;
}
