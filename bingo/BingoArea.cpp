#include "BingoArea.h"

BingoArea::BingoArea()    //コンストラクタ
{
    travelable_area = new TravelableArea();
    routeDecision = new RouteDecision();
    run_body = new RunningBody();
    init_block();   //ブロックの初期化
    travelable_area = new TravelableArea();
    init_circle();    //交点サークル初期化
    init_storage();   //ブロックサークル初期化
}

void BingoArea::init_block()    //ブロックの初期化
{
    int c = 0;  //enumcolor
    /*
    *ブロックナンバーについて
    *黒が1、青が1,2、赤が3,4、緑が5,6、黄色が7,8　
    */
    b_block = new BlackBlock(c);
    for (int i = 1; i < 9; i++)
    {
        if(i%3 == 0)
        {
            c++;
        }
        c_block[i] = new ColorBlock(i,c);
    }
}

void BingoArea::init_circle()    //交点サークル初期化
{
    iintersection_circle[0] = new IntersectionCircle(0, 1, 0.0, 0.0);    //交点サークルナンバー, 赤, 座標x,y
    intersection_circle[1] = new IntersectionCircle(1, 1, 0.0, 1.0);    //赤
    intersection_circle[2] = new IntersectionCircle(2, 0, 0.0, 2.0);    //青
    intersection_circle[3] = new IntersectionCircle(3, 0, 0.0, 3.0);    //青
    intersection_circle[4] = new IntersectionCircle(4, 1, 1.0, 0.0);    //赤
    intersection_circle[5] = new IntersectionCircle(5, 1, 1.0, 1.0);    //赤
    intersection_circle[6] = new IntersectionCircle(6, 0, 1.0, 2.0);    //青
    intersection_circle[7] = new IntersectionCircle(7, 0, 1.0, 3.0);    //青
    intersection_circle[8] = new IntersectionCircle(8, 3, 2.0, 0.0);    //黄色
    intersection_circle[9] = new IntersectionCircle(9, 3, 2.0, 1.0);    //黄色
    intersection_circle[10] = new IntersectionCircle(10, 2, 2.0, 2.0);    //緑
    intersection_circle[11] = new IntersectionCircle(11, 2, 2.0, 3.0);    //緑
    intersection_circle[12] = new IntersectionCircle(12, 3, 3.0, 0.0);    //黄色
    intersection_circle[13] = new IntersectionCircle(13, 3, 3.0, 1.0);    //黄色
    intersection_circle[14] = new IntersectionCircle(14, 2, 3.0, 2.0);    //緑
    intersection_circle[15] = new IntersectionCircle(15, 2, 3.0, 3.0);    //緑
}

void BingoArea::init_storage()    //ブロックサークル初期化
{
    circle_storage[0] = new CircleStorage(1, 3, 0.5, 0.5);   //(ブロック置き場ナンバー, 色, 座標x,y)
    circle_storage[1] = new CircleStorage(2, 2, 0.5, 1.5);
    circle_storage[2] = new CircleStorage(3, 1, 0.5, 2.5);
    circle_storage[3] = new CircleStorage(4, 0, 1.5, 0.5);
    center_storage = new CenterStorage(5, 1.5, 1.5);    //(ブロック置き場ナンバー, 座標x,y)
    circle_storage[4] = new CircleStorage(6, 3, 1.5, 2.5);
    circle_storage[5] = new CircleStorage(7, 2, 2.5, 0.5);
    circle_storage[6] = new CircleStorage(8, 1, 2.5, 1.5);
    circle_storage[7] = new CircleStorage(9, 0, 2.5, 2.5);
}

gameCoordinates BlockCoordinates(int block_num)    //ブロック座標を問い合わせる
{
    return c_block[block_num]->BlockCoordinates();    //取得したブロック座標をリターン
}

runInfo RunningInformation()    //走行体情報を問い合わせる
{
    return run_body->get_runInfo();    //走行体情報を問い合わせる
}

gameCoordinates CircleCoordinates(int circle_num)    //ブロックサークル座標を問い合わせる
{
    circle_storage = new CircleStorage();
    return circle_storage->getCoordinates(circle_num);
}

int CircleColor(Coordinates pass_coordinates)    //交点サークルの色を問い合わせる
{
    int i;
    gameCoordiantes g_coordinates;
    for(i = 0; i < 16; i++)
    {
        g_coordinates = intersection_circle[i]->getCoordinates();
        if(pass_coordinates.x == g_coordinates.x && pass_coordinates.y == g_coordinates.y)
        {
            break;
        }
    }
    return intersection_circle[i]->getColor();    //色を取得する
    //座標とオブジェクトと結びつける,
}

int BlockColor(int block_num)    //ブロックの色を問い合わせる
{
    return c_block[block_num]->getColor();
}

bool B_SuccsesPass(int block_num)    //ブロックが有効移動成立しているか問い合わせる
{
    bool flag;
    if(block_num != 0)
    {
        flag = c_block[block_num]->getE_move();
    }else{
        flag = b_block->getE_move();
    }
    return flag;
}

bool C_SuccsesPass(int　circle_num)   //ブロックサークルが有効移動成立しているか問い合わせる
{
    return circle_storage[circle_num]->getE_move();
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