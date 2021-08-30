#include "BlockList.h"

BlockList::BlockList()    //コンストラクタ
{
    routedecision = new RouteDecision();
}

double BlockList::getCost(gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)    //コストを取得する
{
    for (int i = 0; i < 320; i++)    //コストを持った配列を線型探索
    {
        if (pass_list[i].s_cood == rb_coordinates && pass_list[i].e_cood == goal_coordinates)
        {
            return pass_list[i].cost;    //取得したコストをリターンする
            break;
        }
    }
}

void BlockList::getParam(/*パラメータ型*/ *wp, gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)
{
    //移動パラメータを取得する
    for (int i = 0; i < 320; i++)   //移動パラメータを持った構造体の配列を線型探索
    {
        if (pass_list[i].s_cood == rb_coordinates && pass_list[i].e_cood == goal_coordinates)
        {
            wp = //移動パラメータのポインタを属性の移動パラメータの配列に代入
        }
    }
}