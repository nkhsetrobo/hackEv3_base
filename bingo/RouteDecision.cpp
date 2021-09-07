#include "RouteDecision.h"

RouteDecision::RouteDecition()
{
    bingo_area = new BingoArea();
    bingo_manager = new BingoSectionManager();
    block_list = new BlockList();
}

void RouteDecition::passParam(param *p)  //移動パラメータを問い合わせる
{
    block_list->getParam(&wp, run_info.rb_coordinates, goal_coordinates);    //移動パラメータを問い合わせる

    p = *wp.mparam;
    int i;
    for(i = 0, p[i + 1].front != -1, i++)
    {
        
    }
    bingo_area->updateRunInfo(p[i].coordinates, wp.e_dir, bingo_area->runningInformation().dir);    //走行体情報を更新する
    
}

int RouteDecision::pass_Color(gameCoordinates pass_coordinates)    //通過座標の色を問い合わせる
{
    return bingo_area->circleColor(pass_coordinates);
    //交点サークルを問い合わせる
}

bool RouteDecision::minCompare(int now_min_cost, int cost)    //最小コスト比較
{
    if (now_min_cost > cost)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int RouteDecision::routeDecision()    //ルートを決定する(仮想関数)
{
    //サブクラスのほうでそれぞれ実装
}