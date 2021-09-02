#include "BingoArea.h"

const int BingoArea::INTERSECTION_CIRCLE_COUNT = 16;
const int BingoArea::BLOCK_COUNT = 9;
const int BingoArea::STORAGE_COUNT = 9;

BingoArea::BingoArea()    //コンストラクタ
{
    travelable_area = new TravelableArea();
    run_body = new RunningBody();
    initCircleBlock();    //交点サークル初期化
    initStorage();   //ブロックサークル初期化
}

void BingoArea::init_CircleBlock()    //交点サークル初期化
{
    game_coordinates coordinates;
    //（交点サークルナンバー, 色, 座標）
    coordinates.x = 0.0;
    coordinates.y = 0.0;
    object_management_array[0] = new IntersectionCircle(0, red, coordinates);    //赤
    coordinates.y = 1.0;
    object_management_array[1] = new IntersectionCircle(1, red, coordinates);    //赤
    coordinates.y = 2.0;
    object_management_array[2] = new IntersectionCircle(2, blue, coordinates);    //青
    coordinates.y = 3.0;
    object_management_array[3] = new IntersectionCircle(3, blue, coordinates);    //青
    coordinates.x = 1.0;
    coordinates.y = 0.0;
    object_management_array[4] = new IntersectionCircle(4, red, coordinates);    //赤
    coordinates.y = 1.0;
    object_management_array[5] = new IntersectionCircle(5, red, coordinates);    //赤
    coordinates.y = 2.0;
    object_management_array[6] = new IntersectionCircle(6, blue, coordinates);    //青
    coordinates.y = 3.0;
    object_management_array[7] = new IntersectionCircle(7, blue, coordinates);    //青
    coordinates.x = 2.0;
    coordinates.y = 0.0;
    object_management_array[8] = new IntersectionCircle(8, yellow, coordinates);    //黄
    coordinates.y = 1.0;
    object_management_array[9] = new IntersectionCircle(9, yellow, coordinates);    //黄
    coordinates.y = 2.0;
    object_management_array[10] = new IntersectionCircle(10, green, coordinates);    //緑
    coordinates.y = 3.0;
    object_management_array[11] = new IntersectionCircle(11, green, coordinates);    //緑
    coordinates.x = 3.0;
    coordinates.y = 0.0;
    object_management_array[12] = new IntersectionCircle(12, yellow, coordinates);    //黄
    coordinates.y = 1.0;
    object_management_array[13] = new IntersectionCircle(13, yellow, coordinates);    //黄
    coordinates.y = 2.0;
    object_management_array[14] = new IntersectionCircle(14, green, coordinates);    //緑
    coordinates.y = 3.0;
    object_management_array[15] = new IntersectionCircle(15, green, coordinates);    //緑

    for(int i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        intersection_circle[i] = i;
    }
    
    for(int i = INTERSECTION_CIRCLE_COUNT; i < INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT; i++)
    {
        if(i == INTERSECTION_CIRCLE_COUNT)
        {
            object_management_array[i] = new BlackBlock(i - INTERSECTION_CIRCLE_COUNT);
        }else
        {
            if(i - INTERSECTION_CIRCLE_COUNT = 1 || 2 || 5 || 6)
            {
                object_management_array[i] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, blue, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 1]);
            }
            else{
                object_management_array[i] = new ColorBlock(i - INTERSECTION_CIRCLE_COUNT, blue, object_management_array[2 * (i - INTERSECTION_CIRCLE_COUNT) - 2]);
            }
        }
        
    }
    int j = INTERSECTION_CIRCLE_COUNT
    
    for(int i = 0; i < BLOCK_COUNT; i++)
    {
        block[i] = j;
        j++;
    }
}

void BingoArea::initStorage()    //ブロックサークル初期化
{
    //(ブロック置き場ナンバー, 座標x,y)
    game_coordinates coordinates;
    int i = 0;
    coordinates.x = 1.5;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CenterStorage(i, coordinates);    //センターブロック置き場
    //(ブロック置き場ナンバー, 色, 座標x,y)
    i++;
    coordinates.x = 0.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, yellow, coordinates);    //黄  
    i++;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, green, coordinates);    //緑
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, red, coordinates);    //赤
    i++;
    coordinates.x = 1.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, blue, coordinates);    //青
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, yellow, coordinates);    //黄
    i++;
    coordinates.x = 2.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, green, coordinates);    //緑
    i++;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, red, coordinates);    //赤
    i++;
    coordinates.y = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT + i] = new CircleStorage(i, blue, coordinates);    //青

    int j = INTERSECTION_CIRCLE_COUNT + BLOCK_COUNT;
    for(i = 0; i < STORAGE_COUNT; i++)
    {
        storage[i] = j;
        j++;
    }
}

BingoArea::gameCoordinates BingoArea::objCoordinates(object object_type, int object_num)    //コース内要素座標を問い合わせる
{
    switch(object_type)
    {
        case block:
            return object_management_array[block[object_num]]->getCoordinates();
        case storage:
            return object_management_array[storage[object_num]]->getCoordinates();    
    }
}

BingoArea::runInfo BingoArea::runningInformation()    //走行体情報を問い合わせる
{
    return run_body->get_runInfo();    //走行体情報を問い合わせる
}

int BingoArea::circleColor(Coordinates pass_coordinates)    //交点サークルの色を問い合わせる
{
    int i;
    gameCoordiantes g_coordinates;
    for(i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        g_coordinates = object_management_array[i]->getCoordinates();
        if(coordinatesConparison(pass_coordinates, g_coordinates) == true)    //一致したら
        {
            break;
        }
    }
    return static_cast<IntersectionCircle>object_management_array[i]->getColor();    //色を取得する
}

BingoArea::Color BingoArea::blockColor(int block_num)    //ブロックの色を問い合わせる
{
    return static_cast<ColorBlock>object_management_array[block[block_num]]->getColor();
}

bool BingoArea::objSuccsesPass(object object_type, int　object_num)   //有効移動成立しているか問い合わせる
{
    switch(object_type)
    {
        case block:
            return static_cast<Block>object_management_array[block[object_num]]->getSuccsesPass();
        case storage:
            return static_cast<Block>object_management_array[storage[object_num]]->getSuccsesPass();
    }
}

BingoArea::gameCoordinates BingoArea::relativeCoordinates(gameCoordinates coordinates, Direction direction)    //相対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction)
    {
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

BingoArea::gameCoordiantes BingoArea::absoluteCoordinates(gameCoordinates coordinates, Direction direction)    //絶対座標に変換する
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