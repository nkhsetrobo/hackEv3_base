#include "CircleDecision.h"

CircleDecision::CircleDecision()    //コンストラクタ
:RouteDecision()
{
	    
}

int CircleDecision::routeDecision()    //ルート決定する
{
    runInfo run_info = bingo_area->runningInformation();    //走行体情報を問い合わせる
    gameCoordinates ri_coordinates = bingo_area->relativeCoordinates(run_info.rb_coordinates,run_info.rb_dir);    //相対座標に変換
    num = bsm->getBlockNum();

    color block_color = bingo_area->blockColor(num);

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

    for (int i = 0; i < 2; i++)
	{
        if (!bingo_area->objSuccsesPass(STORAGE, circle_num[i]))/*有効移動が成立しているか*/
        {
	        goal_coordinates = bingo_area->objCoordinates(STORAGE, circle_num[i]);    //ブロック座標を問い合わせる
	        double cost = block_list->getCost(run_info.rb_coordinates, goal_coordinates);    //コストを取得する
	        if (minCompare(min_cost, cost))    //更新処理
            {
		        min_cost = cost;
		        num = i;
	        }
        }
	}

    bsm->rdStateChange(BingoSectionManager::block_decision);
    bingo_area->updateTransportStatus(STORAGE, num);
    return num;
}
