#ifndef _RUNNING_BODY_H_
#define _RUNNING_BODY_H_

#include "Block.h"
#include "Enum.h"
#include "Struct.h"

class RunningBody
{
public:
	runInfo getRunInfo();	//走行体情報を取得する
    void setInfo(gameCoordinates new_coodiantes, direction new_direction);    //走行体情報を更新する
private:
	runInfo ri;   //走行体情報
	Block *block;
};

#endif
