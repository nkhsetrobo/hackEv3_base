#include "BingoArea.h"

static TravelableArea *object_management_array[INTERSECTION_CIRCLE_COUNT + STORAGE_COUNT];
static Block *block_management_array[BLOCK_COUNT];
static int intersection_circle[INTERSECTION_CIRCLE_COUNT];
static int storage[STORAGE_COUNT];

BingoArea::BingoArea()    //コンストラクタ
{
    run_body = new RunningBody();
}

void BingoArea::initCircleBlock()    //交点サークル初期化
{
    gameCoordinates coordinates;
    //（交点サークルナンバー, 色, 座標）
    coordinates.x = 0.0;
    coordinates.y = 0.0;
    object_management_array[0] = new IntersectionCircle(0, RED, coordinates);    //赤
    coordinates.x = 1.0;
    object_management_array[1] = new IntersectionCircle(1, RED, coordinates);    //赤
    coordinates.x = 2.0;
    object_management_array[2] = new IntersectionCircle(2, BLUE, coordinates);    //青
    coordinates.x = 3.0;
    object_management_array[3] = new IntersectionCircle(3, BLUE, coordinates);    //青
    coordinates.y = 1.0;
    coordinates.x = 0.0;
    object_management_array[4] = new IntersectionCircle(4, RED, coordinates);    //赤
    coordinates.x = 1.0;
    object_management_array[5] = new IntersectionCircle(5, RED, coordinates);    //赤
    coordinates.x = 2.0;
    object_management_array[6] = new IntersectionCircle(6, BLUE, coordinates);    //青
    coordinates.x = 3.0;
    object_management_array[7] = new IntersectionCircle(7, BLUE, coordinates);    //青
    coordinates.y = 2.0;
    coordinates.x = 0.0;
    object_management_array[8] = new IntersectionCircle(8, YELLOW, coordinates);    //黄
    coordinates.x = 1.0;
    object_management_array[9] = new IntersectionCircle(9, YELLOW, coordinates);    //黄
    coordinates.x = 2.0;
    object_management_array[10] = new IntersectionCircle(10, GREEN, coordinates);    //緑
    coordinates.x = 3.0;
    object_management_array[11] = new IntersectionCircle(11, GREEN, coordinates);    //緑
    coordinates.y = 3.0;
    coordinates.x = 0.0;
    object_management_array[12] = new IntersectionCircle(12, YELLOW, coordinates);    //黄
    coordinates.x = 1.0;
    object_management_array[13] = new IntersectionCircle(13, YELLOW, coordinates);    //黄
    coordinates.x = 2.0;
    object_management_array[14] = new IntersectionCircle(14, GREEN, coordinates);    //緑
    coordinates.x = 3.0;
    object_management_array[15] = new IntersectionCircle(15, GREEN, coordinates);    //緑

    for(int i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        intersection_circle[i] = i;
    }
    int block_num;
    char block_c;
    int  block_num_arr[84];
    block_num_arr['A'] = 1;
    block_num_arr['B'] = 1;
    block_num_arr['C'] = 2;
    block_num_arr['D'] = 2;
    block_num_arr['E'] = 3;
    block_num_arr['F'] = 3;
    block_num_arr['G'] = 4;
    block_num_arr['H'] = 4;
    block_num_arr['J'] = 5;
    block_num_arr['K'] = 5;
    block_num_arr['L'] = 6;
    block_num_arr['M'] = 6;
    block_num_arr['P'] = 7;
    block_num_arr['Q'] = 7;
    block_num_arr['R'] = 8;
    block_num_arr['S'] = 8;

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE1);
    
    int i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, BLUE, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, BLUE, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_BLUE2);
    
    i = block_num_arr[block_c];
    if(i == 1 || i ==  2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, BLUE, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, BLUE, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED1);
    
    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, RED, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, RED, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_RED2);
    
    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, RED, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, RED, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN1);
    
    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, GREEN, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, GREEN, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_GREEN2);
    
    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, GREEN, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, GREEN, object_management_array[2 * i - 2]);
    }

	block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW1);
    
    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, YELLOW, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, YELLOW, object_management_array[2 * i - 2]);
    }

    block_c = ETRoboc_getCourceInfo(ETROBOC_COURSE_INFO_BLOCK_POS_YELLOW2);

    i = block_num_arr[block_c];
    if(i == 1 || i == 2 || i == 5 || i == 6)
    {
        block_management_array[i] = new ColorBlock(i, YELLOW, object_management_array[2 * i - 1]);
    }else{
        block_management_array[i] = new ColorBlock(i, YELLOW, object_management_array[2 * i - 2]);
    }
}

void BingoArea::initStorage()    //ブロックサークル初期化
{
    //(ブロック置き場ナンバー, 座標x,y)
    gameCoordinates coordinates;
    int i = 0;
    coordinates.x = 1.5;
    coordinates.y = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CenterStorage(i, coordinates);    //センターブロック置き場
    //(ブロック置き場ナンバー, 色, 座標x,y)
    i++;
    coordinates.x = 0.5;
    coordinates.y = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, YELLOW, coordinates);    //黄
    i++;
    coordinates.x = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, GREEN, coordinates);    //緑
    i++;
    coordinates.x = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, RED, coordinates);    //赤
    i++;
    coordinates.y = 1.5;
    coordinates.x = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, BLUE, coordinates);    //青
    i++;
    coordinates.x = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, YELLOW, coordinates);    //黄
    i++;
    coordinates.y = 2.5;
    coordinates.x = 0.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, GREEN, coordinates);    //緑
    i++;
    coordinates.x = 1.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, RED, coordinates);    //赤
    i++;
    coordinates.x = 2.5;
    object_management_array[INTERSECTION_CIRCLE_COUNT + i] = new CircleStorage(i, BLUE, coordinates);    //青

    int j = INTERSECTION_CIRCLE_COUNT;
    for(i = 0; i < STORAGE_COUNT; i++)
    {
        storage[i] = j;
        j++;
    }
}

gameCoordinates BingoArea::objCoordinates(object object_type, int object_num)    //コース内要素座標を問い合わせる
{
    switch(object_type)
    {
        case BLOCK:
            return ((ColorBlock*)block_management_array[object_num])->getCoordinates();
        case STORAGE:
            return object_management_array[storage[object_num]]->getCoordinates();
    }
}

runInfo BingoArea::runningInformation()    //走行体情報を問い合わせる
{
    return run_body->getRunInfo();    //走行体情報を問い合わせる
}

color BingoArea::circleColor(gameCoordinates pass_coordinates)    //交点サークルの色を問い合わせる
{
    int i;
    gameCoordinates g_coordinates;
    for(i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
    {
        g_coordinates = object_management_array[i]->getCoordinates();
        if(coordinatesConparison(pass_coordinates, g_coordinates) == true)    //一致したら
        {
            break;
        }
    }
    return ((IntersectionCircle *)object_management_array[i])->getColor();    //色を取得する
}

bool BingoArea::coordinatesConparison(gameCoordinates pass_coordinates, gameCoordinates g_coordinates)
{
    if(pass_coordinates.x == g_coordinates.x && pass_coordinates.y == g_coordinates.y)
    {
        return true;
    }
    return false;
}

color BingoArea::blockColor(int block_num)    //ブロックの色を問い合わせる
{
    return ((ColorBlock *)block_management_array[block_num])->getColor();
}

bool BingoArea::objSuccsesPass(object object_type, int object_num)   //有効移動成立しているか問い合わせる
{
    switch(object_type)
    {
        case BLOCK:
            return (block_management_array[object_num])->getSuccsesPass();
        case STORAGE:
            return ((CircleStorage *)object_management_array[INTERSECTION_CIRCLE_COUNT + object_num - 1])->getSuccsesPass();
    }
}

gameCoordinates BingoArea::relativeCoordinates(gameCoordinates coordinates, direction direction)    //相対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction)
    {
        case NORTH:     //走行体向きが北の場合
            x = 3 - coordinates.y;
            y = x;
            break;
        case SOUTH:     //走行体向きが南の場合
			x = y;
            y = 3 - coordinates.x;
            break;
        case WEST:      //走行体向きが西の場合
            x = 3 - coordinates.x;
            y = 3 - coordinates.y;
            break;
    }
    coordinates.x = x;
    coordinates.y = y;
    return coordinates;
}

gameCoordinates BingoArea::absoluteCoordinates(gameCoordinates coordinates, direction direction)    //絶対座標に変換する
{
    double x = coordinates.x;
    double y = coordinates.y;
    switch(direction){
        case NORTH:     //走行体向きが北の場合
			x = y;
			y = 3 - coordinates.x;
            break;
        case SOUTH:     //走行体向きが南の場合（ｘ、ｙ）→（ｙ、3-ｘ）
			x = 3 - coordinates.y;
			y = coordinates.x;
            break;
        case WEST:      //走行体向きが西の場合（ｘ、ｙ）→（3-ｙ、3-ｘ）
            //x = 3 - coordinates.y;
            //y = 3 - coordinates.x;
            x = 3 - coordinates.x;
            y = 3 - coordinates.y;
            break;
    }
    coordinates.x = x;
    coordinates.y = y;
    return coordinates;
}

void BingoArea::updateRunInfo(gameCoordinates new_coordinates, direction new_direction, direction old_direction)
{
	new_coordinates = absoluteCoordinates(new_coordinates, old_direction);
    direction absolute_direction = convertDirection(old_direction, new_direction);
	switch (absolute_direction) {
		case NORTH:
			 printf("NORTH\n");
			 break;
		case SOUTH:
			 printf("SOUTH\n");
			 break;
		case EAST:
			 printf("EAST\n");
			 break;
		case WEST:
			 printf("WEST\n");
			 break;
	}
    run_body->setInfo(new_coordinates, absolute_direction);
}

direction BingoArea::convertDirection(direction run_direction, direction relative_direction)
{
    direction new_direction;
    switch(run_direction)
    {
        case NORTH:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = WEST;
                    break;
                case EAST:
                    new_direction = NORTH;
                    break;
                case SOUTH:
                    new_direction = EAST;
                    break;
                case WEST:
                    new_direction = SOUTH;
                    break;
            }
            break;
        case EAST:
            new_direction = relative_direction;
            break;
        case SOUTH:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = EAST;
                    break;
                case EAST:
					printf("eeeeeeeeeeeeeeeeeeeeee\n");
                    new_direction = SOUTH;
                    break;
                case SOUTH:
                    new_direction = WEST;
                    break;
                case WEST:
                    new_direction = NORTH;
                    break;
            }
            break;
        case WEST:
            switch(relative_direction)
            {
                case NORTH:
                    new_direction = SOUTH;
                    break;
                case EAST:
                    new_direction = WEST;
                    break;
                case SOUTH:
                    new_direction = NORTH;
                    break;
                case WEST:
                    new_direction = EAST;
                    break;
            }
            break;
    }
    return new_direction;
}

void BingoArea::initBingo()
{
	initCircleBlock();
	initStorage();
}

void BingoArea::updateTransportStatus(object obj, int obj_num)
{
    switch (obj)
    {
    case BLOCK:
        block_management_array[obj_num]->effectiveMovementJudgement();
        break;
    case STORAGE:
        ((CircleStorage*)object_management_array[INTERSECTION_CIRCLE_COUNT + obj_num - 1])->effectiveMovementJudgement();
		printf("obj_num = %d\n", obj_num);
        break;
    }
}

color BingoArea::c_getColor(gameCoordinates coordinates)
{
	runInfo run_info = runningInformation();
	printf("BingoArea:: coordinates.x = %lf, coordinates.y = %lf, dir = %d\n", coordinates.x, coordinates.y, run_info.rb_dir);
	coordinates = absoluteCoordinates(coordinates, run_info.rb_dir);
	for (int i = 0; i < INTERSECTION_CIRCLE_COUNT; i++)
	{
		printf("BingoArea:: i = %d\n", i);
		gameCoordinates t_coordinates = ((IntersectionCircle *)object_management_array[i])->getCoordinates();
		printf("BingoArea:: t_coordinates.x = %lf, y = %lf\n", t_coordinates.x, t_coordinates.y);
		if (coordinates.x == t_coordinates.x && coordinates.y == t_coordinates.y)
		{
			return ((IntersectionCircle *)object_management_array[i])->getColor();
		}
	}
}
