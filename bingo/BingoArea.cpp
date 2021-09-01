#include "BingoArea.h"

const int BingoArea::COLORKIND_COUNT = 4;
const int BingoArea::BLOCK_COUNT = 9;
const int BingoArea::C_COLOR_COUNT = 4;
const int BingoArea::B_COLOR_COUNT = 2;

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
    int i = 0;
    /*
    *ブロックナンバーについて
    *黒が0、青が1,2、赤が3,4、緑が5,6、黄色が7,8　
    */
    b_block = new BlackBlock(i);
    for (i = 1; i < BLOCK_COUNT; i++)
    {
        if(i % B_COLOR_COUNT == 1)
        {
            switch(c)
                case NULL:
                    c = blue;
                    break;
                case blue:
                    c = red;
                    break;
                case red:
                    c = green;
                    break;
                case green:
                    c = yellow;
                    break;
        }
        c_block[i] = new ColorBlock(i,c);
    }
}

void BingoArea::init_circle()    //交点サークル初期化
{
    game_coordinates coordinates;
    //（交点サークルナンバー, 色, 座標）
    coordinates.x = 0.0;
    coordinates.y = 0.0;
    intersection_circle[0] = new IntersectionCircle(0, red, coordinates);    //赤
    coordinates.y = 1.0;
    intersection_circle[1] = new IntersectionCircle(1, red, coordinates);    //赤
    coordinates.y = 2.0;
    intersection_circle[2] = new IntersectionCircle(2, blue, coordinates);    //青
    coordinates.y = 3.0;
    intersection_circle[3] = new IntersectionCircle(3, blue, coordinates);    //青
    coordinates.x = 1.0;
    coordinates.y = 0.0;
    intersection_circle[4] = new IntersectionCircle(4, red, coordinates);    //赤
    coordinates.y = 1.0;
    intersection_circle[5] = new IntersectionCircle(5, red, coordinates);    //赤
    coordinates.y = 2.0;
    intersection_circle[6] = new IntersectionCircle(6, blue, coordinates);    //青
    coordinates.y = 3.0;
    intersection_circle[7] = new IntersectionCircle(7, blue, coordinates);    //青
    coordinates.x = 2.0;
    coordinates.y = 0.0;
    intersection_circle[8] = new IntersectionCircle(8, yellow, coordinates);    //黄
    coordinates.y = 1.0;
    intersection_circle[9] = new IntersectionCircle(9, yellow, coordinates);    //黄
    coordinates.y = 2.0;
    intersection_circle[10] = new IntersectionCircle(10, green, coordinates);    //緑
    coordinates.y = 3.0;
    intersection_circle[11] = new IntersectionCircle(11, green, coordinates);    //緑
    coordinates.x = 3.0;
    coordinates.y = 0.0;
    intersection_circle[12] = new IntersectionCircle(12, yellow, coordinates);    //黄
    coordinates.y = 1.0;
    intersection_circle[13] = new IntersectionCircle(13, yellow, coordinates);    //黄
    coordinates.y = 2.0;
    intersection_circle[14] = new IntersectionCircle(14, green, coordinates);    //緑
    coordinates.y = 3.0;
    intersection_circle[15] = new IntersectionCircle(15, green, coordinates);    //緑
    
}

void BingoArea::init_storage()    //ブロックサークル初期化
{
    //(ブロック置き場ナンバー, 座標x,y)
    game_coordinates coordinates;
    coordinates.x = 1.5;
    coordinates.y = 1.5;
    center_storage = new CenterStorage(0, coordinates);    //センターブロック置き場
    //(ブロック置き場ナンバー, 色, 座標x,y)
    coordinates.x = 0.5;
    coordinates.y = 0.5;
    circle_storage[0] = new CircleStorage(1, yellow, coordinates);    //黄  
    coordinates.y = 1.5;
    circle_storage[1] = new CircleStorage(2, green, coordinates);    //緑
    coordinates.y = 2.5;
    circle_storage[2] = new CircleStorage(3, red, 0.5, 2.5);    //赤
    coordinates.x = 1.5;
    coordinates.y = 0.5;
    circle_storage[3] = new CircleStorage(4, blue, 1.5, 0.5);    //青
    coordinates.y = 2.5;
    circle_storage[4] = new CircleStorage(5, yellow, 1.5, 2.5);    //黄
     coordinates.x = 2.5;
    coordinates.y = 0.5;
    circle_storage[5] = new CircleStorage(6, green, 2.5, 0.5);    //緑
    coordinates.y = 1.5;
    circle_storage[6] = new CircleStorage(7, red, 2.5, 1.5);    //赤
    coordinates.y = 2.5;
    circle_storage[7] = new CircleStorage(8, blue, 2.5, 2.5);    //青
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