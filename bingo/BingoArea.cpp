#include "BingoArea.h"

BingoArea::BingoArea()    //コンストラクタ
{
    travelable_area = new TravelableArea();
    routeDecision = new RouteDecision();
    run_body = new RunningBody();
    init_block();   //ブロックの初期化
    travelable_area = new TravelableArea();
    init_circle();    //交点サークル初期化
}

void BingoArea::init_block()    //ブロックの初期化
{
    for (int i = 0; i < 9; i++)
    {
        block[i] = new Block(i);
    }
}

void BingoArea::init_circle()    //交点サークル初期化
{
    intersection_circle[0] = new IntersectionCircle(0, 1);    //赤
    intersection_circle[1] = new IntersectionCircle(1, 1);    //赤
    intersection_circle[2] = new IntersectionCircle(2, 0);    //青
    intersection_circle[3] = new IntersectionCircle(3, 0);    //青
    intersection_circle[4] = new IntersectionCircle(4, 1);    //赤
    intersection_circle[5] = new IntersectionCircle(5, 1);    //赤
    intersection_circle[6] = new IntersectionCircle(6, 0);    //青
    intersection_circle[7] = new IntersectionCircle(7, 0);    //青
    intersection_circle[8] = new IntersectionCircle(8, 3);    //黄色
    intersection_circle[9] = new IntersectionCircle(9, 3);    //黄色
    intersection_circle[10] = new IntersectionCircle(10, 2);    //緑
    intersection_circle[11] = new IntersectionCircle(11, 2);    //緑
    intersection_circle[12] = new IntersectionCircle(12, 3);    //黄色
    intersection_circle[13] = new IntersectionCircle(13, 3);    //黄色
    intersection_circle[14] = new IntersectionCircle(14, 2);    //緑
    intersection_circle[15] = new IntersectionCircle(15, 2);    //緑
}

gameCoordinates BlockCoordinates(int block_num)    //ブロック座標を問い合わせる
{
    return block[block_num]->BlockCoordinates();    //取得したブロック座標をリターン
}

runInfo RunningInformation()    //走行体情報を問い合わせる
{
    return run_body->get_runInfo();    //走行体情報を問い合わせる
}

gameCoordinates CircleCoordinates(int circle_num)    //ブロックサークル座標を問い合わせる
{
    Coordinates circle_coordinates = block_storage//中身は後で実装
}

int CircleColor(Coordinates pass_coordinates)    //交点サークルの色を問い合わせる
{
    return intersection_circle[/*何番？*/]->getColor();    //色を取得する
    //座標とオブジェクトと結びつける
}

int BlockColor(int block_num)    //ブロックの色を問い合わせる
{
    //中身はあとで実装
}

bool B_SuccsesPass(int block_num)    //ブロックが有効移動成立しているか問い合わせる
{
    return block[block_num]->EffectiveMovementJudgment(block_num);
}

bool C_SuccsesPass(int block_num)   //ブロックサークルが有効移動成立しているか問い合わせる
{
    //return block_circle[block_num]->EffectiveMovementJudgment(block_num);
}

gameCoordinates relative_coordinates(gameCoordinates coordinates, Direction direction)    //相対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction){
        case north:     //走行体向きが北の場合（ｘ、ｙ）→（ｙ、3-ｘ）
             x = coordinates.y;
             y = 3 - coordinates.x;
             break;
        case south:     //走行体向きが南の場合（ｘ、ｙ）→（3-ｙ、ｘ）
            x = 3 - coordinates.y;
            y = coordinates.x;
            break;
        case west:      //走行体向きが西の場合（ｘ、ｙ）→（3-ｙ、3-ｘ）
            x = 3 - coordinates.y;
            y = 3 - coordinates.x;
            break;
    }
    coordinates.x = x;
    coordinates.y = y,
    return coordinates;
}

gameCoordiantes absolute_coordinates(gameCoordinates coordinates, Direction direction)    //絶対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction){
        case north:     //走行体向きが北の場合（ｘ、ｙ）→（3-ｙ、ｘ）
             x = 3 - coordinates.y;
             y = coordinates.x;
             break;
        case south:     //走行体向きが南の場合（ｘ、ｙ）→（ｙ、3-ｘ）
            x = coordinates.y;
            y = 3 - coordinates.x;
            break;
        case west:      //走行体向きが西の場合（ｘ、ｙ）→（3-ｙ、3-ｘ）
            x = 3 - coordinates.y;
            y = 3 - coordinates.x;
            break;
    }
    coordinates.x = x;
    coordinates.y = y,
    return coordinates;
}