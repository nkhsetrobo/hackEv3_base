#include "RouteDecision.h"

#include "Scene.h"
#include "BingoSectionManager.h"

RouteDecision::RouteDecision()
{
	bingo_area = BingoSectionManager::bingo_area;
    bingo_manager = Scene::mBsm;
    block_list = new BlockList();
}

void RouteDecision::passParam(mParam *p)  //移動パラメータを問い合わせる
{
    block_list->getParam(&pass_list, run_info.rb_coordinates, goal_coordinates);    //移動パラメータを問い合わせる

    p = pass_list.param;
    int i;
    for(i = 0; p[i + 1].front != -1; i++){}
    runInfo runinfo = bingo_area->runningInformation();
    direction old_direction = runinfo.rb_dir;
    bingo_area->updateRunInfo(p[i].p_coordinates, pass_list.dir, old_direction);    //走行体情報を更新する
}

int RouteDecision::passColor(gameCoordinates pass_coordinates)    //通過座標の色を問い合わせる
{
    return bingo_area->circleColor(pass_coordinates);
    //交点サークルを問い合わせる
}

bool RouteDecision::minCompare(double now_min_cost, double cost)    //最小コスト比較
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

void RouteDecision::initList()     //移動パターンリストの初期化
{
	block_list->initList();
}
