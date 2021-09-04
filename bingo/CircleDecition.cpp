#include "CircleDecision.h"

CircleDecision::CircleDecision()    //コンストラクタ
:RouteDecision()
{
    
}

int CircleDecision::routeDecision()    //ルート決定する
{
    runInfo run_info = bingo_area->RunningBodyInformation();    //走行体情報を問い合わせる
    gameCoordiantes ri_coordinates = bingo_area->relativeCoordinates(run_info.coordinates,run_info.dir);    //相対座標に変換
    block_num = BingoSectionManager bsm->getBlockNum();

    color block_color = bsm->blockColor(block_num);

    int circle_num[2]; 
    switch(block_color)
    {
        case BLUE:
            circle_num[0] = 4;
            circle_num[1] = 8;
            break;
        case RED:
            circle_num[0] = 3;
            circle_num[1] = 7;
            break;
        case GREEN:
            circle_num[0] = 2;
            circle_num[1] = 6;
            break;
        case YELLOW:
            circle_num[0] = 1;
            circle_num[1] = 5;
            break;            
    }
    bsm->rdStateChange(block_decision);
    return num;
}