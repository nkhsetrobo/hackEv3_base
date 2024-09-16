#include "TravelableArea.h"

TravelableArea::TravelableArea(gameCoordinates c_coordinates)
{
    coordinates = c_coordinates;
}

gameCoordinates TravelableArea::getCoordinates()    //座標を取得する
{
    return coordinates;
}