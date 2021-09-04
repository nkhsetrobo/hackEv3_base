#include "CircleDecision.h"

CircleDecision::CircleDecision()    //コンストラクタ
:RouteDecision()
{
    
}

int CircleDecision::routeDecision()    //ルート決定する
{
    runInfo run_info = bingo_area->RunningBodyInformation();    //走行体情報を問い合わせる
    gameCoordiantes ri_coordinates = bingo_area->relativeCoordinates(run_info.coordinates,run_info.dir);
    
    switch()
    return num;
}