#include "BlockDetermination.h"

BlockDetermination::BlockDetermination()
:RouteDecision()
{
}

int BlockDetermination::routeDecision()    //ルートを決定する
{
	num = 0;
	double cost;
    runInfo run_info = bingo_area->RunningInformation();    //走行体情報を問い合わせる
	for (int i = 0; i < BLOCK_COUNT; i++)
	{
        if (!bingo_area->B_SuccsesPass(i)/*有効移動が成立しているか*/);
        {
	        goal_coordinates = bingo_area->BlockCoordinates(i);    //ブロック座標を問い合わせる
	        cost = block_list->getCost(run_info.rb_coordinates, goal_coordinates);    //コストを取得する
	        if (minCompare(min_cost, cost))    //更新処理
            {
		        min_cost = cost;
		        num = i;
	        }
        }
	}
    return num;    //取得したブロックナンバーをリターンする
}
