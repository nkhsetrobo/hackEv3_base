#include "BingoArea.h"

const int BingoArea::circle_count = 16;
const int BingoArea::block_count = 9;
const int BingoArea::c_color_count = 4;
const int BingoArea::b_color_count = 2;

BingoArea::BingoArea()    //コンストラクタ
{
    travelable_area = new TravelableArea();
    run_body = new RunningBody();
    init_block();   //ブロックの初期化
    init_circle();    //交点サークル初期化
    init_storage();   //ブロックサークル初期化
}

void BingoArea::init_block()    //ブロックの初期化
{
    Color c;
    /*
    *ブロックナンバーについて
    *黒が0、青が1,2、赤が3,4、緑が5,6、黄色が7,8　
    */
    b_block = new BlackBlock(c);
    for (int i = 1; i < block_count; i++)
    {
        if(i % color_count == 0)
        {
            c++;
        }
        c_block[i] = new ColorBlock(i,c);
    }
}

void BingoArea::init_circle()    //交点サークル初期化
{
    //（交点サークルナンバー, 色, 座標）
    for(int i = 0; i < )
}

void BingoArea::init_storage()    //ブロックサークル初期化
{
    center_storage = new CenterStorage(0, 1.5, 1.5);    //(ブロック置き場ナンバー, 座標x,y)
    circle_storage[0] = new CircleStorage(1, 3, 0.5, 0.5);   //(ブロック置き場ナンバー, 色, 座標x,y)
    circle_storage[1] = new CircleStorage(2, 2, 0.5, 1.5);
    circle_storage[2] = new CircleStorage(3, 1, 0.5, 2.5);
    circle_storage[3] = new CircleStorage(4, 0, 1.5, 0.5);
    
    circle_storage[4] = new CircleStorage(5, 3, 1.5, 2.5);
    circle_storage[5] = new CircleStorage(6, 2, 2.5, 0.5);
    circle_storage[6] = new CircleStorage(7, 1, 2.5, 1.5);
    circle_storage[7] = new CircleStorage(8, 0, 2.5, 2.5);
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