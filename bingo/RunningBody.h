#ifndef _RUNNING_BODY_H_
#define _RUNNING_BODY_H_

#include "Block.h"

enum Direction    //方向
{
	north,
	east,
	south,
	west
};

typedef struct runInfo    //走行体情報
{
    gameCoordinates rb_coordinates;    //走行体座標
    Direction direction;    //方向
} runInfo;

class RunningBody
{
public:
	runInfo get_runInfo();	//走行体情報を取得する

private:
	runInfo ri;   //走行体情報
	Block *block;
};

#endif
