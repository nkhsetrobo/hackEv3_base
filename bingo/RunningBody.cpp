#include "RunningBody.h"

RunningBody::RunningBody()    //コンストラクタ
{
    ri.rb_coordinates.x = 1.0;    //走行体のx座標の初期化
    ri.rb_coordinates.y = 1.0;    //走行体のy座標の初期化
    ri.rb_dir = SOUTH;    //走行体の方角の初期化
}

runInfo RunningBody::getRunInfo()    //走行体情報を取得する
{
    return ri;    //取得した走行体情報をリターンする
}

void RunningBody::setInfo(gameCoordinates new_coodinates, direction new_direction)
{
    ri.rb_coordinates.x = new_coodinates.x;
    ri.rb_coordinates.y = new_coodinates.y;
    ri.rb_dir = new_direction;
}
