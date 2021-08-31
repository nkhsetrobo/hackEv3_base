#ifndef _BINGO_AREA_H_
#define _BINGO_AREA_H_

#include "RouteDecision.h"
#include "RunningBody.h"
#include "Block.h"
#include "TravelableArea.h"

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

typedef struct runInfo    //走行体情報
{
    Direction direction;    //方向
    gameCoordinates game_coordinates;    //ゲーム内座標
} runInfo;

class BingoArea
{
public:
    BingoArea();    //コンストラクタ
    void init_block();    //ブロックの初期化
    void init_circle();    //交点サークルの
    void init_storage();    //ブロックサークルの初期化
    gameCoordinates BlockCoordinates(int block_num);    //ブロック座標の問い合わせを依頼する
    runInfo RunningInformation();    //走行体情報を問い合わせる
    gameCoordinates CircleCoordinates(int circle_num);    //ブロックサークル座標を問い合わせる
    int CircleColor(gameCoordinates pass_coordinates);    //交点サークルの色を問い合わせる
    int BlockColor(int block_num);    //ブロックの色を問い合わせる
    bool B_SuccsesPass(int block_num);    //ブロックが有効移動成立しているか問い合わせる
    bool C_SuccsesPass(int circle_num);    //ブロックサークルが有効移動成立しているか問い合わせる
    gameCoordinates relative_coordinates(gameCoordinates coordinates, Direction rb_direction);    //相対座標系に変換する
    gameCoordinates absolute_coordinates(gameCoordinates coordinates, Direction rb_direction);    //絶対座標系に変換する

private:
    enum Direction    //方向
    {
        north,    //北
        east,    //東
        south,    //南
        west    //西
    };
    enum ColorBlock
    {
        blue,   //青
        red,    //赤
        green,  //緑
        yellow  //黄色
    };
    RouteDecision* routeDecision;
    RunningBody* run_body;
    Block* b_block;
    Block* c_block[8];
    TravelableArea* travelable_area;
    TravelableArea* circle_storage[8];
    TravelableArea* intersection_circle[16];
    TravelableArea* center_storage;
};

#endif