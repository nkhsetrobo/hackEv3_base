#include "BlockDetermination.h"
#include "BingoSectionManager.h"

BlockDetermination::BlockDetermination()
:RouteDecision()
{
}

int BlockDetermination::routeDecision()    //ルートを決定する
{
	num = 0;
	min_cost = 999;
	double cost;
    run_info = RouteDecision::bingo_area->runningInformation();    //走行体情報を問い合わせる
	for (int i = 1; i < BLOCK_COUNT; i++)
	{
        if (!bingo_area->objSuccsesPass(BLOCK, i))/*有効移動が成立しているか*/
        {
	        goal_coordinates = bingo_area->objCoordinates(BLOCK, i);    //ブロック座標を問い合わせる
	        cost = block_list->getCost(run_info.rb_coordinates, goal_coordinates);    //コストを取得する
	        if (minCompare(min_cost, cost))    //更新処理
            {
		        min_cost = cost;
		        num = i;
	        }
        }
	}
	bingo_area->updateTransportStatus(BLOCK, num);
	bingo_manager->rdStateChange(BingoSectionManager::circle_decision);
    return num;    //取得したブロックナンバーをリターンする
}
