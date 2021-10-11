#ifndef _BLOCK_LIST_H_
#define _BLOCK_LIST_H_

#include "Enum.h"
#include "Struct.h"

class RouteDecision;

class BlockList
{
public:
    BlockList();
    double getCost(gameCoordinates rb_coordinates, gameCoordinates goal_coordinates);    //コストを取得する
    void getParam(passList *ret_pass_list, gameCoordinates rb_coordinates, gameCoordinates goal_coordinates);    //移動パラメータを取得する
    void initList();    //ブロックリスト初期化
    //static passList pass_list[320];
private:
    double cost;    //移動コスト
    passList *ret_pass_list;    //受け渡しのためのポインタ
    mParam p[100];    //移動パラメータの配列(サイズはまだ知らない)

	//{{開始座標},{終了座標},コスト,方向,{{移動パラメータ},{0,0}・・・}};


    //passList *all_table[24] = {*table00,*table01,*table02,*table03,*table11,*table12,*table13,*table21,*table22,*table23,*table30,*table31,*table32,*table33};
    //passList *pl;
};

#endif
