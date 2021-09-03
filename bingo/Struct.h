#ifndef _STRUCT_H_
#define _STRUCT_H_

#include "Enum.h"

typedef struct _gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

typedef struct _Coordinates    //座標
{
    int x;
    int y;
} Coordinates;

typedef struct _runInfo    //走行体情報
{
    direction rb_dir;    //方向
    gameCoordinates rb_coordinates;    //走行体座標
} runInfo;

typedef struct _getCostCoordinates    //コスト取得座標
{
    gameCoordinates g_coordinates;    //目的地の座標
    int cost;    //コスト
} getCostCoordinates;

typedef struct _Param2
{
    WALKER_NO mwalker;    //走法
    int front;    //前進量
    int turn;     //旋回量
    Coordinates coordinates;    //目標地点
    float speed;    //目標速度
    float x;    //中心x座標
    float y;    //中心y座標
    float radius;    //旋回半径
    JUDGE_NO mjudge;    //判定
    float atai;    //値
    gameCoordinates p_coordinates;    //通過座標
    int mcolor;    //色
    float sat;    //彩度
} wParam3;

typedef struct _pidParam    //制御パラメータ
{
    float p,
    float i,
    float d
} pidParam;

#endif