#ifndef _RUNNING_BODY_H_
#define _RUNNING_BODY_H_

#include "Block.h"
#include "Enum.h"

typedef struct runInfo    //走行体情報
{
    gameCoordinates rb_coordinates;    //走行体座標
    Direction direction;    //方向
} runInfo;

class RunningBody
{
public:
	runInfo getRunInfo();	//走行体情報を取得する
    void setInfo(gameCoordiantes new_coodiantes, Direction new_direction);    //走行体情報を更新する
private:
	runInfo ri;   //走行体情報
	Block *block;
};

#endif
