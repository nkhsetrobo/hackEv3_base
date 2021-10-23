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
	gameCoordinates goal;
    run_info = bingo_area->runningInformation();    //走行体情報を問い合わせる
	gameCoordinates re_cood = bingo_area->relativeCoordinates(run_info.rb_coordinates, run_info.rb_dir);    //座標変換
	/*printf("+------変換前---------+\n");
	printf("x = %lf, y = %lf\n", run_info.rb_coordinates.x, run_info.rb_coordinates.y);
	printf("+---------------------+\n");
	printf("+---------------------+\n");
	printf("x = %lf, y = %lf\n", re_cood.x, re_cood.y);
	printf("+---------------------+\n");*/
	for (int i = 1; i < BLOCK_COUNT; i++)
	{
        if (!bingo_area->objSuccsesPass(BLOCK, i))/*有効移動が成立しているか*/
        {
	        goal = bingo_area->objCoordinates(BLOCK, i);    //ブロック座標を問い合わせる
			//printf("変換前 i = %d, x = %lf, y = %lf\n", i, goal.x, goal.y);
			goal = bingo_area->relativeCoordinates(goal, run_info.rb_dir);
			//printf("変換後 i = %d, x = %lf, y = %lf\n", i, goal.x, goal.y);
	        cost = block_list->getCost(re_cood, goal);    //コストを取得する
			/*if (cost < 0) {
				printf("========================\n");
				printf("i = %d\n", i);
				printf("========================\n");
			}*/
	        if (minCompare(min_cost, cost))    //更新処理
            {
				goal_coordinates = goal;
		        min_cost = cost;
		        num = i;
	        }
        }
	}
	printf("goal.x = %lf, goal.y = %lf\n", goal_coordinates.x, goal_coordinates.y);
	if (num == 0) return 0;
	bingo_area->updateTransportStatus(BLOCK, num);
    return num;    //取得したブロックナンバーをリターンする
}

void BlockDetermination::finishRun()
{
	bingo_manager->rdStateChange(BingoSectionManager::circle_decision);
}
