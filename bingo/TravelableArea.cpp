#include "TravelableArea.h"

TravelableArea::TravelableArea(gameCoordinates c_coordinates)
{
    coordinates = c_coordinates;
}

TravelableArea::gameCoordinates TravelableArea::getCoordinates()    //座標を取得する
{
    return coordiantes;
}