#include "RouteDecision.h"
#include "Scene.h"
#include "BingoSectionManager.h"
#include "stdlib.h"

RouteDecision::RouteDecision()
{
	//bingo_area = BingoSectionManager::bingo_area;
    //bingo_manager = Scene::mBsm;
    //block_list = new BlockList();
	wp = (passList*)malloc(sizeof(passList) * 100);    //paramを含む拡張版パラメータ
	bingo_area = BingoSectionManager::bingo_area;
	bingo_manager = Scene::mBsm;
	block_list = new BlockList();
}

void RouteDecision::passParam(mParam *&p)  //移動パラメータを問い合わせる
{
    block_list->getParam(pass_list, run_info.rb_coordinates, goal_coordinates);    //移動パラメータを問い合わせる
	printf("+++++++++++++++++++++++++++++++++++++++\n");
	for (int i = 0; i < 100; i++) {
    	printf("pass_list->param[i]->coordinates.x = %d p[i]->coordinates.y = %d\n", pass_list->param[i].x, pass_list->param[i].y);
	}
	printf("++++++++++++++++++++++++++++++++++++++++\n");
    p = pass_list->param;
	for (int i = 0; i < 100; i++) {
		printf("p[i]->coordinates.x = %d p[i]->coordinates.y = %d\n", p[i].coordinates.x, p[i].coordinates.y);
	}
	printf("+++++++++++++++++++++++++++++++++++++++\n");
    runInfo runinfo = bingo_area->runningInformation();
    direction old_direction = runinfo.rb_dir;
    bingo_area->updateRunInfo(pass_list->e_cood, pass_list->dir, old_direction);    //走行体情報を更新する
}

int RouteDecision::passColor(gameCoordinates pass_coordinates)    //通過座標の色を問い合わせる
{
    return bingo_area->circleColor(pass_coordinates);
    //交点サークルを問い合わせる
}

bool RouteDecision::minCompare(double now_min_cost, double cost)    //最小コスト比較
{
	printf("now_min_cost = %lf, cost = %lf\n", now_min_cost, cost);
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
