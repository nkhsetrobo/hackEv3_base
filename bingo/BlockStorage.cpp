#include "BlockStorage.h"

BlockStorage::BlockStorage(int n, gameCoordinates c_coordinates)
:TravelableArea(c_coordinates)		//コンストラクタ
{
	BS_number = n;
}
