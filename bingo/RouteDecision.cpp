#include "RouteDecision.h"

RouteDecision::RouteDecition()
{
    bingo_area = new BingoArea();
    bingo_manager = new BingoSectionManager();
    block_list = new BlockList();
}

void RouteDecition::passParam(passList *wp)  //移動パラメータを問い合わせる
{
    block_list->getParam(&wp, run_info.rb_coordinates, goal_coordinates);    //移動パラメータを問い合わせる
    //移動パターンリストクラスのパラメータとコストの配列320通りを全探索
    bingo_area->updateRunInfo(wp.e_cood, wp.e_dir, bingo_area->runningInformation().dir)
}

int RouteDecision::pass_Color(gameCoordinates pass_coordinates)    //通過座標の色を問い合わせる
{
    return bingo_area->circleColor(pass_coordinates);
    //交点サークルを問い合わせる
}

bool RouteDecision::minCompare(int now_minCost, int cost)    //最小コスト比較
{
    if (now_minCost > cost)
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