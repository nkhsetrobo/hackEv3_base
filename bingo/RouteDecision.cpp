#include "RouteDecision.h"
#include "Scene.h"
#include "BingoSectionManager.h"
#include "stdlib.h"

RouteDecision::RouteDecision()
{
	//bingo_area = BingoSectionManager::bingo_area;
    //bingo_manager = Scene::mBsm;
    //block_list = new BlockList();
	//wp = (passList *)malloc(sizeof(passList) * 100);    //paramを含む拡張版パラメータ
	bingo_area = BingoSectionManager::bingo_area;
	bingo_manager = Scene::mBsm;
	block_list = new BlockList();
}

void RouteDecision::passParam(mParam *&pnt)  //移動パラメータを問い合わせる
{
	run_info = bingo_area->runningInformation();
	gameCoordinates re_cood = bingo_area->relativeCoordinates(run_info.rb_coordinates, run_info.rb_dir);    //相対座標に変換
	//printf("re_cood.x = %lf, re_cood.y = %lf\n", re_cood.x, re_cood.y);
    block_list->getParam(p_list, re_cood, goal_coordinates);    //移動パラメータを問い合わせる
    //runInfo runinfo = bingo_area->runningInformation();
    direction old_direction = run_info.rb_dir;
	//printf("p_list->e_cood.x = %lf, y = %lf\n", p_list->e_cood.x, p_list->e_cood.y);
	pnt = p_list->param;
	int i;
	for (i = 0; pnt[i].front != -1; i++)
	{
		if (pnt[i].mjudge == Section::COLOR)
		{
			 pnt[i].mcolor = bingo_area->c_getColor(pnt[i].p_coordinates);
		}
	}
	if(i != 0){
	    bingo_area->updateRunInfo(pnt[i - 1].p_coordinates, p_list->dir, old_direction);
	}
}

int RouteDecision::passColor(gameCoordinates pass_coordinates)    //通過座標の色を問い合わせる
{
    return bingo_area->circleColor(pass_coordinates);
    //交点サークルを問い合わせる
}

bool RouteDecision::minCompare(double now_min_cost, double cost)    //最小コスト比較
{
	printf("RouteDecision:: now_min_cost = %lf, cost = %lf\n", now_min_cost, cost);
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

void RouteDecision::finishRun()    //状態遷移
{
	//サブクラスのほうでそれぞれ実行
}
