#include "CircleDecision.h"

CircleDecision::CircleDecision()    //コンストラクタ
:RouteDecision()
{
    
}

int CircleDecision::routeDecision()    //ルート決定する
{
    run_info = bingo_area->RunningBodyInformation();    //走行体情報を問い合わせる
    for (int i = 0; i < 9; i++)    //ブロックサークルを線型探索
    {
        if (!bingo_area->C_SuccsesPass(i) && bingo_area->BlockColor(i) == bingo_area->intersection_circle[i]->gerColor())    //有効移動未成立のブロックと同色のブロックサークル全て/*ビンゴエリア経由必要*/
        {
            goal_coordinates = bigo_area->CircleCoordinates(i);
            cost = blocklist->getCost(run_info.rb_coordinates, goal_coordinates);
            if (minCompare(min_cost, cost))    //最小コスト更新処理
            {
                min_cost = cost;
                num = i;
            }
        }
    }
    return num;
}