#include "BlockList.h"

static passList pass_list[320];

BlockList::BlockList()    //コンストラクタ
{
    initList();
}

double BlockList::getCost(gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)    //コストを取得する
{
    int i;
    int j;
    switch ((int)rb_coordinates.x)
    {
    case 1:
        i = 0;
        j = 96;
        break;
    case 2:
        i = 96;
        j = 192;
        break;
    case 3:
        i = 192;
        j = 288;
        break;
    }
    for (; i < j; i++)    //コストを持った配列を線型探索
    {
        if (pass_list[i].s_cood.x == rb_coordinates.x && pass_list[i].s_cood.y == rb_coordinates.y && pass_list[i].e_cood.x == goal_coordinates.x && pass_list[i].e_cood.y == goal_coordinates.y)
        {
            return pass_list[i].cost;    //取得したコストをリターンする
        }
    }
	return 999;
}

void BlockList::getParam(passList *&ret_pass_list, gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)
{
    int i;
    int j;
    switch ((int)rb_coordinates.x)
    {
    case 1:
        i = 0;
        j = 96;
        break;
    case 2:
        i = 96;
        j = 192;
        break;
    case 3:
        i = 192;
        j = 288;
        break;
    }
    //移動パラメータを取得する
    for (; i < j; i++)   //移動パラメータを持った構造体の配列を線型探索
    {
        if (pass_list[i].s_cood.x == rb_coordinates.x && pass_list[i].s_cood.y == rb_coordinates.y && pass_list[i].e_cood.x == goal_coordinates.x && pass_list[i].e_cood.y == goal_coordinates.y)
        {
            ret_pass_list = &pass_list[i];//移動パラメータのポインタを属性の移動パラメータの変数に代入
            printf("pass_listの配列の参照した添え字 i = %d\n",i);
            break;
        }
    }
}

void BlockList::initList()
{
	/*printf("+---------引数-----------------------------------------------------------------+\n");
	printf("rb_coordinates.x = %lf, rb_coordinates.y = %lf, goal_coordinates.x = %lf, goal_coordinates.y = %lf\n", rb_coordinates.x, rb_coordinates.y, goal_coordinates.x, goal_coordinates.y);*/
	pass_list[0] =
	{
		{1.0, 0.0},{0.0,0.0},12.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
	};
    pass_list[1] =
    {
        {1.0, 0.0},{0.0,1.0},10.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[2] =
    {
        {1.0,0.0},{0.0,2.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[3] =
    {
        {1.0,0.0},{0.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[4] =
    {
        {1.0,0.0},{0.5,0.5},7.0,SOUTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[5] =
    {
        {1.0,0.0},{0.5,1.5},9.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
            {Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 232, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,0}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[6] =
    {
        {1.0,0.0},{0.5,2.5},12.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,true},
            //le2	右ななめ(左から右)
            {Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 232, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[7] =
    {
        {1.0,0.0},{1.0,0.0},0.0,EAST,
        {
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
    };
    pass_list[8] =
    {
        {1.0,0.0},{1.0,1.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[9] =
    {
        {1.0,0.0},{1.0,2.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false},

        }
    };
    pass_list[10] =
    {
        {1.0,0.0},{1.0,3.0},11.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[11] =
    {
        {1.0,0.0},{1.5,0.5},4.0,EAST,
        {
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, 25, 0, 0, -20, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -25, 0, 0, -15.3, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -18, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,0}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[12] =
    {
        {1.0,0.0},{1.5,2.5},12.5,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, 25, 0, 0, 18, Section::LENGTH, 17, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -4, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -25, 0, 0, 17.5, Section::TURNANGLE, -54.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -15, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[13] =
    {
        {1.0,0.0},{2.0,0.0},3.0,EAST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, true},
            //ld2	色未検知、左カーブ(左から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 13, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 20, 0, 0, 28, Section::TURNANGLE, 33, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 28, Section::BRIGHTNESS, -0.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 7, Section::LENGTH, 6, {0,0}, BLUE, 0, 30, 0.7, 3, true},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[14] =
    {
        {1.0,0.0},{2.0,1.0},2.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[15] =
    {
        {1.0,0.0},{2.0,2.0},2.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[16] =
    {
        {1.0,0.0},{2.0,3.0},14.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[17] =
    {
        {1.0,0.0},{2.5,0.5},7.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, 25, 0, 0, -20, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -25, 0, 0, -15.3, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -18, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,0}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[18] =
    {
        {1.0,0.0},{2.5,1.5},11.5,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 30, 0.7, 5},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[19] =
    {
        {1.0,0.0},{2.5,2.5},14.5,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[20] =
    {
        {1.0,0.0},{3.0,0.0},6.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[21] =
    {
        {1.0,0.0},{3.0,1.0},11.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[22] =
    {
        {1.0,0.0},{3.0,2.0},14.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[23] =
    {
        {1.0,0.0},{3.0,3.0},17.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{1.0,0.0}--------------------------------------------------------------------------------------------------------
    pass_list[24] =
    {
        {1.0,1.0},{0.0,0.0},11.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[25] =
    {
        {1.0,1.0},{0.0,1.0},12.0,NORTH,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[26] =
    {
        {1.0,1.0},{0.0,2.0},10.0,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[27] =
    {
        {1.0,1.0},{0.0,3.0},13.0,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[28] =
    {
        {1.0,1.0},{0.5,0.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[29] =
    {
        {1.0,1.0},{0.5,1.5},7.0,SOUTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[30] =
    {
        {1.0,1.0},{0.5,2.5},9.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[31] =
    {
        {1.0,1.0},{1.0,0.0},5.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[32] =
    {
        {1.0,1.0},{1.0,1.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[33] =
    {
        {1.0,1.0},{1.0,2.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[34] =
    {
        {1.0,1.0},{1.0,3.0},8.0,SOUTH,
        {
            //la1   色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, -3, Section::TURNANGLE, -100, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[35] =
    {
        {1.0,1.0},{1.5,0.5},4.5,EAST,
        {
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[36] =
    {
        {1.0,1.0},{1.5,2.5},9.5,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[37] =
    {
        {1.0,1.0},{2.0,0.0},8.5,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[38] =
    {
        {1.0,1.0},{2.0,1.0},2.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[39] =
    {
        {1.0,1.0},{2.0,2.0},2.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[40] =
    {
        {1.0,1.0},{2.0,3.0},11.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[41] =
    {
        {1.0,1.0},{2.5,0.5},7.5,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[42] =
    {
        {1.0,1.0},{2.5,1.5},7.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[43] =
    {
        {1.0,1.0},{2.5,2.5},12.5,SOUTH,
        {
            //lc2	色未検知、右カーブ(右から左)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -25, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -25, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -4.2, Section::LENGTH, 6, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[44] =
    {
        {1.0,1.0},{3.0,0.0},11.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[45] =
    {
        {1.0,1.0},{3.0,1.0},6.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[46] =
    {
        {1.0,1.0},{3.0,2.0},11.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[47] =
    {
        {1.0,1.0},{3.0,3.0},14.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{1.1,0.0}----------------------------------------------------------------------------------------------------------------------------------
    pass_list[48] =
    {
        {1.0,2.0},{0.0,0.0},14.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[49] =
    {
        {1.0,2.0},{0.0,1.0},11.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[50] =
    {
        {1.0,2.0},{0.0,2.0},12.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[51] =
    {
        {1.0,2.0},{0.0,3.0},10.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[52] =
    {
        {1.0,2.0},{0.5,0.5},10.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[53] =
    {
        {1.0,2.0},{0.5,1.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[54] =
    {
        {1.0,2.0},{0.5,2.5},7.0,NORTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[55] =
    {
        {1.0,2.0},{1.0,0.0},8.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[56] =
    {
        {1.0,2.0},{1.0,1.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[57] =
    {
        {1.0,2.0},{1.0,2.0},0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[58] =
    {
        {1.0,2.0},{1.0,3.0},5.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[59] =
    {
        {1.0,2.0},{1.5,0.5},9.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[60] =
    {
        {1.0,2.0},{1.5,2.5},4.0,EAST,
        {
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[61] =
    {
        {1.0,2.0},{2.0,0.0},11.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[62] =
    {
        {1.0,2.0},{2.0,1.0},2.0,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[63] =
    {
        {1.0,2.0},{2.0,2.0},1.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[64] =
    {
        {1.0,2.0},{2.0,3.0},8.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[65] =
    {
        {1.0,2.0},{2.5,0.5},12.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[66] =
    {
        {1.0,2.0},{2.5,1.5},7.5,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[67] =
    {
        {1.0,2.0},{2.5,2.5},7.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[68] =
    {
        {1.0,2.0},{3.0,0.0},14.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[69] =
    {
        {1.0,2.0},{3.0,1.0},11.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[70] =
    {
        {1.0,2.0},{3.0,2.0},6.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[71] =
    {
        {1.0,2.0},{3.0,3.0},11.0,SOUTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{1.0,2.0}------------------------------------------------------------------------------------------------------------------
    pass_list[72] =
    {
        {1.0,3.0},{0.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[73] =
    {
        {1.0,3.0},{0.0,1.0},14.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[74] =
    {
        {1.0,3.0},{0.0,2.0},11.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[75] =
    {
        {1.0,3.0},{0.0,3.0},12.0,NORTH,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[76] =
    {
        {1.0,3.0},{0.5,0.5},13.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[77] =
    {
        {1.0,3.0},{0.5,1.5},10.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[78] =
    {
        {1.0,3.0},{0.5,2.5},7.5,NORTH,
        {
            //lh2	左uターン(左から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,10,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[79] =
    {
        {1.0,3.0},{1.0,0.0},11.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[80] =
    {
        {1.0,3.0},{1.0,1.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[81] =
    {
        {1.0,3.0},{1.0,2.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[82] =
    {
        {1.0,3.0},{1.0,3.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[83] =
    {
        {1.0,3.0},{1.5,0.5},12.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0,0}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[84] =
    {
        {1.0,3.0},{1.5,2.5},4.5,EAST,
        {
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,3}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[85] =
    {
        {1.0,3.0},{2.0,0.0},14.5,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[86] =
    {
        {1.0,3.0},{2.0,1.0},2.0,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[87] =
    {
        {1.0,3.0},{2.0,2.0},2.0,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[88] =
    {
        {1.0,3.0},{2.0,3.0},3.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[89] =
    {
        {1.0,3.0},{2.5,0.5},15.5,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[90] =
    {
        {1.0,3.0},{2.5,1.5},11,EAST,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 30, 0.7, 5},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[91] =
    {
        {1.0,3.0},{2.5,2.5},7.5,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,3}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[92] =
    {
        {1.0,3.0},{3.0,0.0},17.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},

            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[93] =
    {
        {1.0,3.0},{3.0,1.0},14.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},

            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[94] =
    {
        {1.0,3.0},{3.0,2.0},11.5,NORTH,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},

            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[95] =
    {
        {1.0,3.0},{3.0,3.0},6.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{1.0,3.0}-----------------------------------------------------------------------------------------------------------
    pass_list[96] =
    {
        {2.0,0.0},{0.0,0.0},15.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[97] =
    {
        {2.0,0.0},{0.0,1.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[98] =
    {
        {2.0,0.0},{0.0,2.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[99] =
    {
        {2.0,0.0},{0.0,3.0},19.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[100] =
    {
        {2.0,0.0},{0.5,0.5},14.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[101] =
    {
        {2.0,0.0},{0.5,1.5},14.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[102] =
    {
        {2.0,0.0},{0.5,2.5},17.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lc4	色未検知、右カーブ(左から左)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -25, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -25, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -4.2, Section::LENGTH, 6, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[103] =
    {
        {2.0,0.0},{1.0,0.0},12.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[104] =
    {
        {2.0,0.0},{1.0,1.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[105] =
    {
        {2.0,0.0},{1.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[106] =
    {
        {2.0,0.0},{1.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, false},
//終わり
{Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[107] =
    {
        {2.0,0.0},{1.5,0.5},12.0,SOUTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[108] =
    {
        {2.0,0.0},{1.5,2.5},12.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[109] =
    {
        {2.0,0.0},{2.0,0.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[110] =
    {
        {2.0,0.0},{2.0,1.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[111] =
    {
        {2.0,0.0},{2.0,2.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[112] =
    {
        {2.0,0.0},{2.0,3.0},11.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[113] =
    {
        {2.0,0.0},{2.5,0.5},4.0,EAST,
        {
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,0}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[114] =
    {
        {2.0,0.0},{2.5,1.5},9.5,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[115] =
    {
        {2.0,0.0},{2.5,2.5},12.5,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[116] =
    {
        {2.0,0.0},{3.0,0.0},3.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[117] =
    {
        {2.0,0.0},{3.0,1.0},8.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[118] =
    {
        {2.0,0.0},{3.0,2.0},11.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[119] =
    {
        {2.0,0.0},{3.0,3.0},14.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{2.0,0.0}-------------------------------------------------------------------------------------------------------
    pass_list[120] =
    {
        {2.0,1.0},{0.0,0.0},14.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[121] =
    {
        {2.0,1.0},{0.0,1.0},15.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0, 0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[122] =
    {
        {2.0,1.0},{0.0,2.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[123] =
    {
        {2.0,1.0},{0.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[124] =
    {
        {2.0,1.0},{0.5,0.5},19.5,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, true},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[125] =
    {
        {2.0,1.0},{0.5,1.5},14.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[126] =
    {
        {2.0,1.0},{0.5,2.5},14.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[127] =
    {
        {2.0,1.0},{1.0,0.0},11.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[128] =
    {
        {2.0,1.0},{1.0,1.0},2.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[129] =
    {
        {2.0,1.0},{1.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[130] =
    {
        {2.0,1.0},{1.0,3.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[131] =
    {
        {2.0,1.0},{1.5,0.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[132] =
    {
        {2.0,1.0},{1.5,2.5},9.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[133] =
    {
        {2.0,1.0},{2.0,0.0},5.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[134] =
    {
        {2.0,1.0},{2.0,1.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[135] =
    {
        {2.0,1.0},{2.0,2.0},2.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[136] =
    {
        {2.0,1.0},{2.0,3.0},8.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[137] =
    {
        {2.0,1.0},{2.5,0.5},4.5,EAST,
        {
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[138] =
    {
        {2.0,1.0},{2.5,1.5},4.5,EAST,
        {
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[139] =
    {
        {2.0,1.0},{2.5,2.5},9.5,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[140] =
    {
        {2.0,1.0},{3.0,0.0},8.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[141] =
    {
        {2.0,1.0},{3.0,1.0},3.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[142] =
    {
        {2.0,1.0},{3.0,2.0},8.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[143] =
    {
        {2.0,1.0},{3.0,3.0},11.0,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{2.0,1.0}-------------------------------------------------------------------------------------------------
    pass_list[144] =
    {
        {2.0,2.0},{0.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[145] =
    {
        {2.0,2.0},{0.0,1.0},14.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[146] =
    {
        {2.0,2.0},{0.0,2.0},15.0,NORTH,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[147] =
    {
        {2.0,2.0},{0.0,3.0},13.0,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 0}, BLUE, 0, 39, 25, 5, true},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[148] =
    {
        {2.0,2.0},{0.5,0.5},15.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[149] =
    {
        {2.0,2.0},{0.5,1.5},15.5,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[150] =
    {
        {2.0,2.0},{0.5,2.5},20.5,SOUTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }

    };
    pass_list[151] =
    {
        {2.0,2.0},{1.0,0.0},14.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[152] =
    {
        {2.0,2.0},{1.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[153] =
    {
        {2.0,2.0},{1.0,2.0},2.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[154] =
    {
        {2.0,2.0},{1.0,3.0},10.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[155] =
    {
        {2.0,2.0},{1.5,0.5},10.0,NORTH,
        {
			//lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
			//lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
			{Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
			//終わり
			{Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
    };
    pass_list[156] =
    {
        {2.0,2.0},{1.5,2.5},12.0,SOUTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[157] =
    {
        {2.0,2.0},{2.0,0.0},8.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[158] =
    {
        {2.0,2.0},{2.0,1.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[159] =
    {
        {2.0,2.0},{2.0,2.0},0.0,EAST,
        {
            //stop
            //{Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,false},
            //終わり
			{Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
    };
    pass_list[160] =
    {
        {2.0,2.0},{2.0,3.0},5.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[161] =
    {
        {2.0,2.0},{2.5,0.5},9.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[162] =
    {
        {2.0,2.0},{2.5,1.5},4.5,EAST,
        {
			//lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
			{Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
			//終わり
			{Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
            
        }
    };
    pass_list[163] =
    {
        {2.0,2.0},{2.5,2.5},4.0,EAST,
        {
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[164] =
    {
        {2.0,2.0},{3.0,0.0},11.5,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[165] =
    {
        {2.0,2.0},{3.0,1.0},8.5,NORTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[166] =
    {
        {2.0,2.0},{3.0,2.0},3.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[167] =
    {
        {2.0,2.0},{3.0,3.0},8.0,SOUTH,
        {
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 30, 0.7, 5},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{2.0,2.0}------------------------------------------------------------------------------------------------------------------------------------------
    pass_list[168] =
    {
        {2.0,3.0},{0.0,0.0},20.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[169] =
    {
        {2.0,3.0},{0.0,1.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0, 1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[170] =
    {
        {2.0,3.0},{0.0,2.0},14.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[171] =
    {
        {2.0,3.0},{0.0,3.0},15.0,NORTH,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[172] =
    {
        {2.0,3.0},{0.5,0.5},18.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[173] =
    {
        {2.0,3.0},{0.5,1.5},15.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[174] =
    {
        {2.0,3.0},{0.5,2.5},15.5,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[175] =
    {
        {2.0,3.0},{1.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[176] =
    {
        {2.0,3.0},{1.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[177] =
    {
        {2.0,3.0},{1.0,2.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[178] =
    {
        {2.0,3.0},{1.0,3.0},12.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[179] =
    {
        {2.0,3.0},{1.5,0.5},13.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[180] =
    {
        {2.0,3.0},{1.5,2.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[181] =
    {
        {2.0,3.0},{2.0,0.0},11.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[182] =
    {
        {2.0,3.0},{2.0,1.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[183] =
    {
        {2.0,3.0},{2.0,2.0},2.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[184] =
    {
        {2.0,3.0},{2.0,3.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[185] =
    {
        {2.0,3.0},{2.5,0.5},12.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[186] =
    {
        {2.0,3.0},{2.5,1.5},9.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[187] =
    {
        {2.0,3.0},{2.5,2.5},4.5,EAST,
        {
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,3}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[188] =
    {
        {2.0,3.0},{3.0,0.0},14.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[189] =
    {
        {2.0,3.0},{3.0,1.0},11.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[190] =
    {
        {2.0,3.0},{3.0,2.0},10.5,NORTH,
        {
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[191] =
    {
        {2.0,3.0},{3.0,3.0},3.0,EAST,
        {
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{2.0,3.0}------------------------------------------------------------------------------------------------------------------
    pass_list[192] =
    {
        {3.0,0.0},{0.0,0.0},18.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[193] =
    {
        {3.0,0.0},{0.0,1.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[194] =
    {
        {3.0,0.0},{0.0,2.0},19.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[195] =
    {
        {3.0,0.0},{0.0,3.0},22.0,WEST,
        {
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 28, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 20, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[196] =
    {
        {3.0,0.0},{0.5,0.5},17.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[197] =
    {
        {3.0,0.0},{0.5,1.5},17.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[198] =
    {
        {3.0,0.0},{0.5,2.5},21.5,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[199] =
    {
        {3.0,0.0},{1.0,0.0},15.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false}, 
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[200] =
    {
        {3.0,0.0},{1.0,1.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[201] =
    {
        {3.0,0.0},{1.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[202] =
    {
        {3.0,0.0},{1.0,3.0},19.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[203] =
    {
        {3.0,0.0},{1.5,0.5},14.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[204] =
    {
        {3.0,0.0},{1.5,2.5},20,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
	};
    pass_list[205] =
    {
        {3.0,0.0},{2.0,0.0},12.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false}, 
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[206] =
    {
        {3.0,0.0},{2.0,1.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[207] =
    {
        {3.0,0.0},{2.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[208] =
    {
        {3.0,0.0},{2.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[209] =
    {
        {3.0,0.0},{2.5,0.5},7.0,SOUTH,
        {
            //	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-4,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-8,0,0,-6,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[210] =
    {
        {3.0,0.0},{2.5,1.5},9.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[211] =
    {
        {3.0,0.0},{2.5,2.5},20,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, true},
            //色検知、右カーブ(左から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0},25, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[212] =
    {
        {3.0,0.0},{3.0,0.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[213] =
    {
        {3.0,0.0},{3.0,1.0},5.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[214] =
    {
        {3.0,0.0},{3.0,2.0},8.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[215] =
    {
        {3.0,0.0},{3.0,3.0},11.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{3.0,0.0}----------------------------------------------------------------------------------------------------------------------------
    pass_list[216] =
    {
        {3.0,1.0},{0.0,0.0},17.0,WEST,
        {
            //lb1   色検知、左カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, 9.0, Section::TURNANGLE, 70, {0, 0}, BLUE, 0, 20, 0.7, 3, false},
			{Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 12, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[217] =
    {
        {3.0,1.0},{0.0,1.0},18.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[218] =
    {
        {3.0,1.0},{0.0,2.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[219] =
    {
        {3.0,1.0},{0.0,3.0},19.0,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[220] =
    {
        {3.0,1.0},{0.5,0.5},21.5,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 30, 0.7, 5},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[221] =
    {
        {3.0,1.0},{0.5,1.5},17.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[222] =
    {
        {3.0,1.0},{0.5,2.5},17.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //li2	サークル突破(左)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[223] =
    {
        {3.0,1.0},{1.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[224] =
    {
        {3.0,1.0},{1.0,1.0},2.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[225] =
    {
        {3.0,1.0},{1.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[226] =
    {
        {3.0,1.0},{1.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[227] =
    {
        {3.0,1.0},{1.5,0.5},19.5,NORTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[228] =
    {
        {3.0,1.0},{1.5,2.5},14.5,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la4	色検知、右カーブ(左から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[229] =
    {
        {3.0,1.0},{2.0,0.0},11.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 3}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {0, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[230] =
    {
        {3.0,1.0},{2.0,1.0},2.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[231] =
    {
        {3.0,1.0},{2.0,2.0},2.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[232] =
    {
        {3.0,1.0},{2.0,3.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //lc3	色未検知、右カーブ(左から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 13, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 20, 0, 0, -26, Section::TURNANGLE, -30, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -26, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 13, 0, 0, -0.5, Section::TURNANGLE, -40, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 10, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
    };
    pass_list[233] =
    {
        {3.0,1.0},{2.5,0.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[234] =
    {
        {3.0,1.0},{2.5,1.5},7.0,SOUTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,2},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[235] =
    {
        {3.0,1.0},{2.5,2.5},9.0,SOUTH,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}
        }
    };
    pass_list[236] =
    {
        {3.0,1.0},{3.0,0.0},5.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[237] =
    {
        {3.0,1.0},{3.0,1.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[238] =
    {
        {3.0,1.0},{3.0,2.0},5.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[239] =
    {
        {3.0,1.0},{3.0,3.0},8.0,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{3.0,1.0}------------------------------------------------------------------------------------
    pass_list[240] =
    {
        {3.0,2.0},{0.0,0.0},20.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[241] =
    {
        {3.0,2.0},{0.0,1.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[242] =
    {
        {3.0,2.0},{0.0,2.0},18.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[243] =
    {
        {3.0,2.0},{0.0,3.0},16.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[244] =
    {
        {3.0,2.0},{0.5,0.5},18.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[245] =
    {
        {3.0,2.0},{0.5,1.5},18.5,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[246] =
    {
        {3.0,2.0},{0.5,2.5},22.5,SOUTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[247] =
    {
        {3.0,2.0},{1.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[248] =
    {
        {3.0,2.0},{1.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[249] =
    {
        {3.0,2.0},{1.0,2.0},2.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,2},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[250] =
    {
        {3.0,2.0},{1.0,3.0},13.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[251] =
    {
        {3.0,2.0},{1.5,0.5},15.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[252] =
    {
        {3.0,2.0},{1.5,2.5},20.5,SOUTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[253] =
    {
        {3.0,2.0},{2.0,0.0},14.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[254] =
    {
        {3.0,2.0},{2.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[255] =
    {
        {3.0,2.0},{2.0,2.0},2.0,WEST,
        {
            //j    180度旋回(右) {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[256] =
    {
        {3.0,2.0},{2.0,3.0},10.0,WEST,
        {
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 3}, BLUE, 0, 39, 25, 5, true},
            //la3	色検知、右カーブ(左から右)
            //{Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 7, 0, 0, -9, Section::TURNANGLE, -90, {0, 0}, BLUE, 0, 28, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 25, 20, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[257] =
    {
        {3.0,2.0},{2.5,0.5},10.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[258] =
    {
        {3.0,2.0},{2.5,1.5},7.5,NORTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[259] =
    {
        {3.0,2.0},{2.5,2.5},7.0,SOUTH,
        {
            //lg1	右uターン(右から右)
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},7,0,0,-8,Section::TURNANGLE,-180,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,50,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-7,0,0,-4,Section::TURNANGLE,70,{0,0},BLUE,0,15,8,5,false},
            {Section::WALKER,-15,0,{0,0},0,0,0,0,Section::LENGTH,-6,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 8, {0,0}, BLUE, 0, 35, 25, 10.5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,3},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[260] =
    {
        {3.0,2.0},{3.0,0.0},8.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[261] =
    {
        {3.0,2.0},{3.0,1.0},5.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[262] =
    {
        {3.0,2.0},{3.0,2.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[263] =
    {
        {3.0,2.0},{3.0,3.0},5.5,SOUTH,
        {
            //la1	色検知、右カーブ(右から右)
            {Section::VIRTUAL, 0, 0, {0,0}, 10, 0, 0, -8, Section::TURNANGLE, -87, {0,0}, BLUE, 0, 39, 25, 5, false},
            //{Section::VIRTUAL, 0, 0, {0,0}, 5, 0, 0, 3, Section::TURNANGLE, 5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3,3}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    //{3.0,2.0}------------------------------------------------------------------------------------------------------------
    pass_list[264] =
    {
        {3.0,3.0},{0.0,0.0},23.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[265] =
    {
        {3.0,3.0},{0.0,1.0},20.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[266] =
    {
        {3.0,3.0},{0.0,2.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[267] =
    {
        {3.0,3.0},{0.0,3.0},18.0,NORTH,
        {
            //j    180度旋回(右) 
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 35, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 25, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{0,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}
        }
    };
    pass_list[268] =
    {
        {3.0,3.0},{0.5,0.5},22.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lc1	色未検知、右カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 17.6, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -29, Section::LENGTH, -10, {0, 0}, BLUE, 0, 20, 10, 3, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 15, 0, 0, -30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 25, 20, 5, false},
            //{Section::VIRTUAL, 0, 0, {0, 0}, 10, 0, 0, -20, Section::TURNANGLE, -10, {0, 0}, BLUE, 0, 25, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 1}, BLUE, 0, 30, 0.7, 5},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[269] =
    {
        {3.0,3.0},{0.5,1.5},18.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1, 2},BLUE,0,30,0.7,5,false},
            //le1	右ななめ(右から右)
            {Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, -18, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            {Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -14.5, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 228.7, Section::LENGTH, -8.5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[270] =
    {
        {3.0,3.0},{0.5,2.5},18.5,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1, 2},BLUE,0,30,0.7,5,false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {1, 2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[271] =
    {
        {3.0,3.0},{1.0,0.0},20.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[272] =
    {
        {3.0,3.0},{1.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[273] =
    {
        {3.0,3.0},{1.0,2.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,2},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[274] =
    {
        {3.0,3.0},{1.0,3.0},15.0,WEST,
        {
            //j    180度旋回(右)
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::TRACER, 0, 0, {0,0}, 24, 0, 0, 0, Section::LENGTH, 12, {0,0}, BLUE, 0, 39, 25, 5, false },
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{1,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[275] =
    {
        {3.0,3.0},{1.5,0.5},19.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //lf2	左ななめ(左から右)
			{Section::WALKER, 25, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true}, 
            {Section::VIRTUAL, 0, 0, {0,0}, 14, 0, 0, 18, Section::TURNANGLE, 48.7, {0,0}, BLUE, 0, 30, 20, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 14.5, Section::TURNANGLE, -48.7, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 131.3, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[276] =
    {
        {3.0,3.0},{1.5,2.5},15.5,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[277] =
    {
        {3.0,3.0},{2.0,0.0},17.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右)
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 0}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[278] =
    {
        {3.0,3.0},{2.0,1.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //ld1	色未検知、左カーブ(右から右)
            {Section::WALKER, 25, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 21, {0, 0}, BLUE, 0, 0, 0, 0, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::TURNANGLE, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 30, Section::BRIGHTNESS, -0.5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 10, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 5, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[279] =
    {
        {3.0,3.0},{2.0,2.0},2.0,WEST,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[280] =
    {
        {3.0,3.0},{2.0,3.0},12.0,WEST,
        {
            //j    180度旋回(右) 
            {Section::VIRTUAL,0,0,{0,0},1,0,0,3,Section::TURNANGLE,165,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{2,3},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[281] =
    {
        {3.0,3.0},{2.5,0.5},20.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 3, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 10, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 3, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::VIRTUAL, 0, 0, {0, 0}, 5, 0, 0, 8, Section::TURNANGLE, 80, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 24, 0, 0, 0, Section::LENGTH, 20, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 2}, BLUE, 0, 39, 25, 5, false},
            //la2	色検知、右カーブ(右から左)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, -10, Section::TURNANGLE, -83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 18, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, true},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2, 1}, BLUE, 0, 39, 25, 5, true},
            //le2	右ななめ(左から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, -19.5, Section::TURNANGLE, -49.5, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL, 0, 0, {0,0}, -16, 0, 0, -13, Section::TURNANGLE, 49.5, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::VIRTUAL2, 0, 0, {0,0}, -15, 0, 0, 229.5, Section::LENGTH, -9.5, {0,0}, BLUE, 0, 39, 25, 7, true},
            {Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0,0}, 20, 0, 0, 0, Section::LENGTH, 15, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {2,1}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[282] =
    {
        {3.0,3.0},{2.5,1.5},10.0,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //lf1	左ななめ(右から右)
			{Section::WALKER, 20, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, 5, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, 15, 0, 0, 19, Section::TURNANGLE, 52, {0,0}, BLUE, 0, 30, 25, 3, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
			{Section::WALKER, -15, 0, {0,0}, 0, 0, 0, 0, Section::LENGTH, -5.8, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0,0}, -15, 0, 0, 11, Section::TURNANGLE, -52, {0,0}, BLUE, 0, 30, 25, 3, false},
			{Section::VIRTUAL2, 0, 0, {0,0}, -10, 0, 0, 128, Section::LENGTH, -11, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::WALKER, 0, 0, {0,0}, 0, 0, 0, 0, Section::STOP, 50, {0,0}, BLUE, 0, 0, 0, 0, true},
            //{Section::TRACER, 0, 0, {0, 0}, 7, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[283] =
    {
        {3.0,3.0},{2.5,2.5},7.5,SOUTH,
        {
            //lh1	左uターン(右から右)
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::VIRTUAL,0,0,{0,0},12,0,0,11.5,Section::TURNANGLE,180,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3.5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,4,Section::TURNANGLE,-60,{0,0},BLUE,0,30,0.7,5,false},
            {Section::VIRTUAL2,0,0,{0,0},0,0,0,0,Section::STOP,30,{0,0},BLUE,0,0,0,0,true},
            {Section::TRACER,0,0,{0,0},5,0,0,0,Section::LENGTH,5,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3, 3},BLUE,0,30,0.7,5,false},
            //終了
            {Section::VIRTUAL,-1,0,{0,0},0,0,0,0,Section::TURNANGLE,0,{0,0},BLUE,0,0,0,0,true}

        }
    };
    pass_list[284] =
    {
        {3.0,3.0},{3.0,0.0},11.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右) 
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},25,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,39,0.7,5,false},
            {Section::VIRTUAL, 0, 0, {0,0}, 28, 0, 0, 0, Section::TURNANGLE, 0, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::VIRTUAL2, 0, 0, {0,0}, 28, 0, 0, 0, Section::LENGTH, 25, {0,0}, BLUE, 0, 39, 25, 5, true},
            {Section::TRACER, 0, 0, {0, 0}, 20, 0, 0, 0, Section::LENGTH, 10, {0,0}, BLUE, 0, 39, 0.7, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,0},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[285] =
    {
        {3.0,3.0},{3.0,1.0},8.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //li1	サークル突破(右) 
            {Section::WALKER,25,0,{0,0},0,0,0,0,Section::LENGTH,10,{0,0},BLUE,0,0,0,0,false},
            {Section::TRACER,0,0,{0,0},24,0,0,0,Section::LENGTH,15,{0,0},BLUE,0,30,0.7,5,false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR,0,{3,1},BLUE,0,30,0.7,5,false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[286] =
    {
        {3.0,3.0},{3.0,2.0},5.5,NORTH,
        {
            //lb1	色検知、左カーブ(右から右)
            {Section::WALKER, 12, 0, {0,0}, 10, 0, 0, 0, Section::LENGTH, 2, {0,0}, BLUE, 0, 39, 25, 5, true},
			{Section::VIRTUAL, 0, 0, {0, 0}, 12, 0, 0, 11, Section::TURNANGLE, 83, {0, 0}, BLUE, 0, 24, 20, 3, false},
            {Section::TRACER, 0, 0, {0, 0}, 12, 0, 0, 0, Section::LENGTH, 8, {0, 0}, BLUE, 0, 39, 25, 5, false},
			{Section::TRACER, 0, 0, {0, 0}, 15, 0, 0, 0, Section::LENGTH, 7, {0, 0}, BLUE, 0, 39, 25, 5, false},
            {Section::WALKER, 22, 0, {0, 0}, 0, 0, 0, 0, Section::COLOR, 0, {3, 2}, BLUE, 0, 39, 25, 5, false},
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
    pass_list[287] =
    {
        {3.0,3.0},{3.0,3.0},0.0,EAST,
        {
            //終わり
            {Section::VIRTUAL, -1, 0, {0, 0}, 0, 0, 0, 0, Section::LENGTH, 0, {0, 0}, BLUE, 0, 0, 0, 0, false}

        }
    };
}

