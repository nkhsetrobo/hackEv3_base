#include "CircleDecision.h"
#include "BingoSectionManager.h"

CircleDecision::CircleDecision()    //コンストラクタ
:RouteDecision()
{
	    
}

int CircleDecision::routeDecision()    //ルート決定する
{
	run_info = bingo_area->runningInformation();    //走行体情報を問い合わせる
    gameCoordinates re_cood = bingo_area->relativeCoordinates(run_info.rb_coordinates,run_info.rb_dir);    //相対座標に変換
	/*printf("+--------------変換前-----------+\n");
	printf("circle x = %lf, y = %lf\n", run_info.rb_coordinates.x, run_info.rb_coordinates.y);
	printf("+-------------------------------+\n");
	printf("+----------------------------+\n");
	printf("circle x = %lf, y = %lf\n", re_cood.x, re_cood.y);
	printf("+----------------------------+\n");*/
    num = bingo_manager->getBlockNum();

    color block_color = bingo_area->blockColor(num);
	switch (block_color) {
		case BLUE:
			printf("Blue\n");
			break;
		case RED:
			printf("Red\n");
			break;
		case GREEN:
			printf("Green\n");
			break;
		case YELLOW:
			printf("Yellow\n");
			break;
	}

    int circle_num[3]; 
    switch(block_color)
    {
        case BLUE:
            circle_num[1] = 4;
            circle_num[2] = 8;
            break;
        case RED:
            circle_num[1] = 3;
            circle_num[2] = 7;
            break;
        case GREEN:
            circle_num[1] = 2;
            circle_num[2] = 6;
            break;
        case YELLOW:
            circle_num[1] = 1;
            circle_num[2] = 5;
            break;
    }

	min_cost = 999;
	gameCoordinates goal;

    for (int i = 1; i < 3; i++)
	{
        if (!bingo_area->objSuccsesPass(STORAGE, circle_num[i]))/*有効移動が成立しているか*/
        {
	        goal = bingo_area->objCoordinates(STORAGE, circle_num[i]);    //ブロック座標を問い合わせる
			//printf("objCoordinates: x = %lf, y = %lf\n", goal.x, goal.y);
			goal = bingo_area->relativeCoordinates(goal, run_info.rb_dir);
	        double cost = block_list->getCost(re_cood, goal);    //コストを取得する
	        if (minCompare(min_cost, cost))    //更新処理
            {
				goal_coordinates = goal;
		        min_cost = cost;
		        num = i;
	        }
        }
	}
	printf("goal.x = %lf, goal.y = %lf\n", goal_coordinates.x, goal_coordinates.y);
    bingo_area->updateTransportStatus(STORAGE, circle_num[num]);
	//printf("goal_coordinates x = %lf, y = %lf\n", goal_coordinates.x, goal_coordinates.y);
	return num;
}

void CircleDecision::finishRun()
{
	bingo_manager->rdStateChange(BingoSectionManager::block_decision);
	printf("CircleDecision::通ったよ！\n");
}
