#include "RunningBody.h"

RunningBody::RunningBody()    //コンストラクタ
{
    block = new Block();    //運搬ブロックのインスタンス生成
    ri.coordinates.x = 1.0;    //走行体のx座標の初期化
    ri.coordinates.y = 1.0;    //走行体のy座標の初期化
    ri.dir = south;    //走行体の方角の初期化
}

runInfo RunningBody::getRunInfo()    //走行体情報を取得する
{
    return ri;    //取得した走行体情報をリターンする
}

void setInfo(gameCoordiantes new_coodiantes, Direction new_direction)
{
    ri.rb_coordinates.x = new_coodiantes.x;
    ri.rb_coordinates.y = new_coodiantes.y;
    direction = new_direction;
}