#include "BlockList.h"

static passList pass_list[320];

BlockList::BlockList()    //コンストラクタ
{

}

double BlockList::getCost(gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)    //コストを取得する
{
    for (int i = 0; i < 320; i++)    //コストを持った配列を線型探索
    {
        if (pass_list[i].s_cood.x == rb_coordinates.x && pass_list[i].s_cood.y == rb_coordinates.y && pass_list[i].e_cood.x == goal_coordinates.x && pass_list[i].e_cood.y == goal_coordinates.y)
        {
            return pass_list[i].cost;    //取得したコストをリターンする
        }
    }
}

void BlockList::getParam(passList *ret_pass_list, gameCoordinates rb_coordinates, gameCoordinates goal_coordinates)
{
    //移動パラメータを取得する
    for (int i = 0; i < 320; i++)   //移動パラメータを持った構造体の配列を線型探索
    {
        if (pass_list[i].s_cood.x == rb_coordinates.x && pass_list[i].s_cood.y == rb_coordinates.y && pass_list[i].e_cood.x == goal_coordinates.x && pass_list[i].e_cood.y == goal_coordinates.y)
        {
            ret_pass_list = &pass_list[i];//移動パラメータのポインタを属性の移動パラメータの変数に代入
            break;
        }
    }
}

void BlockList::initList()
{
    pass_list[0] =
    {
        {0.0,0.0},{0.0,1.0},3.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[1] =
    {
        {0.0,0.0},{0.0,2.0},6.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[2] =
    {
        {0.0,0.0},{0.0,3.0},9.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }

    };
    pass_list[3] =
    {
        {0.0,0.0},{1.0,0.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[4] =
    {
        {0.0,0.0},{1.0,1.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[5] =
    {
        {0.0,0.0},{1.0,2.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[6] =
    {
        {0.0,0.0},{1.0,3.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[7] =
    {
        {0.0,0.0},{2.0,0.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[8] =
    {
        {0.0,0.0},{2.0,1.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[9] =
    {
        {0.0,0.0},{2.0,2.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[10] =
    {
        {0.0,0.0},{2.0,3.0},17.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }

    };
    pass_list[11] =
    {
        {0.0,0.0},{3.0,0.0},11.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }

    };
    pass_list[12] =
    {
        {0.0,0.0},{3.0,1.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[13] =
    {
        {0.0,0.0},{3.0,2.0},19.5,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }

    };
    pass_list[14] =
    {
        {0.0,0.0},{3.0,3.0},20.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };
    pass_list[15] =
    {
        {0.0,1.0},{0.0,0.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[16] =
    {
        {0.0,1.0},{0.0,2.0},3.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[17] =
    {
        {0.0,1.0},{0.0,3.0},6.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    pass_list[18] =
    {
        {0.0,1.0},{0.5,0.5},12.0,EAST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[19] =
    {
        {0.0,1.0},{0.5,1.5},12.5,EAST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[20] =
    {
        {0.0,1.0},{0.5,2.5},15.5,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[21] =
    {
        {0.0,1.0},{1.0,0.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[22] =
    {
        {0.0,1.0},{1.0,1.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }

    };
    pass_list[23] =
    {
        {0.0,1.0},{1.0,2.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[24] =
    {
        {0.0,1.0},{1.0,3.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[25] =
    {
        {0.0,1.0},{1.5,0.5},9.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[26] =
    {
        {0.0,1.0},{1.5,2.5},12.5,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[27] =
    {
        {0.0,1.0},{2.0,0.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[28] =
    {
        {0.0,1.0},{2.0,1.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[29] =
    {
        {0.0,1.0},{2.0,2.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[30] =
    {
        {0.0,1.0},{2.0,3.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    pass_list[31] =
    {
        {0.0,1.0},{2.5,0.5},12.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[32] =
    {
        {0.0,1.0},{2.5,1.5},12.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{02,1},BLUE,0.5}
        }
    };
    pass_list[33] =
    {
        {0.0,1.0},{2.5,2.5},15.5,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[34] =
    {
        {0.0,1.0},{3.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };
    pass_list[35] =
    {
        {0.0,1.0},{3.0,1.0},11.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[36] =
    {
        {0.0,1.0},{3.0,2.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    pass_list[37] =
    {
        {0.0,1.0},{3.0,3.0},17.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }

    };
    pass_list[38] =
    {
        {0.0,2.0},{0.0,0.0},15.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[39] =
    {
        {0.0,2.0},{0.0,1.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    pass_list[40] =
    {
        {0.0,2.0},{0.0,3.0},3.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[41] =
    {
        {0.0,2.0},{0.5,0.5},14.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[42] =
    {
        {0.0,2.0},{0.5,1.5},12.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[43] =
    {
        {0.0,2.0},{0.5,2.5},12.5,EAST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[44] =
    {
        {0.0,2.0},{1.0,0.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[45] =
    {
        {0.0,2.0},{1.0,1.0},10.0,EAST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[46] =
    {
        {0.0,2.0},{1.0,2.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[47] =
    {
        {0.0,2.0},{1.0,3.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[48] =
    {
        {0.0,2.0},{1.5,0.5},14.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[49] =
    {
        {0.0,2.0},{1.5,2.5},9.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[50] =
    {
        {0.0,2.0},{2.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[51] =
    {
        {0.0,2.0},{2.0,1.0},13.0,WEST,
            {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
            }
    };
    pass_list[52] =
    {
        {0.0,2.0},{2.0,2.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[53] =
    {
        {0.0,2.0},{2.0,3.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    pass_list[54] =
    {
        {0.0,2.0},{2.5,0.5},17.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[55] =
    {
        {0.0,2.0},{2.5,1.5},12.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[56] =
    {
        {0.0,2.0},{2.5,2.5},12.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[57] =
    {
        {0.0,2.0},{3.0,0.0},19.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };
    pass_list[58] =
    {
        {0.0,2.0},{3.0,1.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[59] =
    {
        {0.0,2.0},{3.0,2.0},11.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    pass_list[60] =
    {
        {0.0,2.0},{3.0,3.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };
    pass_list[61] =
    {
        {0.0,3.0},{0.0,0.0},18.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[62] =
    {
        {0.0,3.0},{0.0,1.0},15.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[63] =
    {
        {0.0,3.0},{0.0,2.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[64] =
    {
        {0.0,3.0},{0.5,0.5},17.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[65] =
    {
        {0.0,3.0},{0.5,1.5},14.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[66] =
    {
        {0.0,3.0},{0.5,2.5},17.0,NORTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[67] =
    {
        {0.0,3.0},{1.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[68] =
    {
        {0.0,3.0},{1.0,1.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[69] =
    {
        {0.0,3.0},{1.0,2.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[70] =
    {
        {0.0,3.0},{1.0,3.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[71] =
    {
        {0.0,3.0},{1.5,0.5},17.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[72] =
    {

        {0.0,3.0},{1.5,2.5},17.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }

    };
    pass_list[73] =
    {
        {0.0,3.0},{2.0,0.0},19.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[74] =
    {
        {0.0,3.0},{2.0,1.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[75] =
    {
        {0.0,3.0},{2.0,2.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[76] =
    {
        {0.0,3.0},{2.0,3.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    pass_list[77] =
    {
        {0.0,3.0},{2.5,0.5},20.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[78] =
    {
        {0.0,3.0},{2.5,1.5},17.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[79] =
    {
        {0.0,3.0},{2.5,2.5},20.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[80] =
    {
        {0.0,3.0},{3.0,0.0},22.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };
    pass_list[81] =
    {
        {0.0,3.0},{3.0,1.0},19.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[82] =
    {
        {0.0,3.0},{3.0,2.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    pass_list[83] =
    {
        {0.0,3.0},{3.0,3.0},11.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };
    pass_list[84] =
    {
        {1.0,1.0},{0.0,0.0},11.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[85] =
    {
        {1.0,1.0},{0.0,1.0},5.5,NORTH,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[86] =
    {
        {1.0,1.0},{0.0,2.0},8.5,NORTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[87] =
    {
        {1.0,1.0},{0.0,3.0},11.5,NORTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    pass_list[88] =
    {
        {1.0,1.0},{0.5,0.5},7.5,NORTH,
        {//右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[89] =
    {
        {1.0,1.0},{0.5,1.5},4.5,EAST,
        {//左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[90] =
    {
        {1.0,1.0},{0.5,2.5},7.5,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[91] =
    {
        {1.0,1.0},{1.0,0.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[92] =
    {
        {1.0,1.0},{1.0,2.0},3.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[93] =
    {
        {1.0,1.0},{1.0,3.0},6.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[94] =
    {
        {1.0,1.0},{1.5,0.5},7.0,SOUTH,
        {//左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[95] =
    {
        {1.0,1.0},{1.5,2.5},7.0,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[96] =
    {
        {1.0,1.0},{2.0,0.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[97] =
    {
        {1.0,1.0},{2.0,1.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[98] =
    {
        {1.0,1.0},{2.0,2.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[99] =
    {
        {1.0,1.0},{2.0,3.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    pass_list[100] =
    {
        {1.0,1.0},{2.5,0.5},9.0,SOUTH,
            {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[101] =
    {
        {1.0,1.0},{2.5,1.5},9.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[102] =
    {
        {1.0,1.0},{2.5,2.5},12.5,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[103] =
    {
        {1.0,1.0},{3.0,0.0},13.0,EAST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };
    pass_list[104] =
    {
        {1.0,1.0},{3.0,1.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[105] =
    {
        {1.0,1.0},{3.0,2.0},11.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    pass_list[106] =
    {
        {1.0,1.0},{3.0,3.0},14.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };
    pass_list[107] =
    {
        {1.0,2.0},{0.0,0.0},14.0,EAST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[108] =
    {
        {1.0,2.0},{0.0,1.0},11.0,EAST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[109] =
    {
        {1.0,2.0},{0.0,2.0},5.5,NORTH,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[110] =
    {
        {1.0,2.0},{0.0,3.0},8.5,NORTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    pass_list[111] =
    {
        {1.0,2.0},{0.5,0.5},19.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[112] =
    {
        {1.0,2.0},{0.5,1.5},7.5,NORTH,
        {//右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[113] =
    {
        {1.0,2.0},{0.5,2.5},4.5,EAST,
        {//左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[114] =
    {
        {1.0,2.0},{1.0,0.0},15.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[115] =
    {
        {1.0,2.0},{1.0,1.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[116] =
    {
        {1.0,2.0},{1.0,3.0},8.5,EAST,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    pass_list[117] =
    {
        {1.0,2.0},{1.5,0.5},14.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[118] =
    {
        {1.0,2.0},{1.5,2.5},4.5,EAST,
        {//左入れ
        //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[119] =
    {
        {1.0,2.0},{2.0,0.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[120] =
    {
        {1.0,2.0},{2.0,1.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[121] =
    {
        {1.0,2.0},{2.0,2.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[122] =
    {
        {1.0,2.0},{2.0,3.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    pass_list[123] =
    {
        {1.0,2.0},{2.5,0.5},14.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[124] =
    {
        {1.0,2.0},{2.5,1.5},9.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[125] =
    {
        {1.0,2.0},{2.5,2.5},9.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    pass_list[126] =
    {
        {1.0,2.0},{3.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };
    pass_list[127] =
    {
        {1.0,2.0},{3.0,1.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };
    pass_list[128] =
    {
        {1.0,2.0},{3.0,2.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    pass_list[129] =
    {
        {1.0,2.0},{3.0,3.0},8.0,SOUTH,
        {/*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };
    pass_list[130] =
    {
        {1.0,3.0},{0.0,0.0},17.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };
    pass_list[131] =
    {
        {1.0,3.0},{0.0,1.0},14.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };
    pass_list[132] =
    {
        {1.0,3.0},{0.0,2.0},11.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };
    pass_list[133] =
    {
        {1.0,3.0},{0.0,3.0},5.5,NORTH,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    pass_list[134] =
    {
        {1.0,3.0},{0.5,0.5},19.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[135] =
    {
        {1.0,3.0},{0.5,1.5},16.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[136] =
    {
        {1.0,3.0},{0.5,2.5},19.0,NORTH,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[137] =
    {
        {1.0,3.0},{1.0,0.0},18.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };
    pass_list[138] =
    {
        {1.0,3.0},{1.0,1.0},15.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[139] =
    {
        {1.0,3.0},{1.0,2.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[140] =
    {
        {1.0,3.0},{1.5,0.5},19.5,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };
    pass_list[141] =
    {
        {1.0,3.0},{1.5,2.5},19.5,SOUTH,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    pass_list[142] =
    {
        {1.0,3.0},{2.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };
    pass_list[143] =
    {
        {1.0,3.0},{2.0,1.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };
    pass_list[144] =
    {
        {1.0,3.0},{2.0,2.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[145] =
    {
        {1.0,3.0},{0.0,1.0},14.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[146] =
    {
        {1.0,3.0},{0.0,2.0},11.0,WEST,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[147] =
    {
        {1.0,3.0},{0.0,3.0},5.5,NORTH,
        {//左に90度
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    },
    //4
    pass_list[148] =
    {
        {1.0,3.0},{0.5,0.5},19.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[149] =
    {
        {1.0,3.0},{0.5,1.5},16.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[150] =
    {
        {1.0,3.0},{0.5,2.5},19.0,NORTH,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //左Uターン
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3
    pass_list[151] =
    {
        {1.0,3.0},{1.0,0.0},18.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[152] =
    {
        {1.0,3.0},{1.0,1.0},15.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[153] =
    {
        {1.0,3.0},{1.0,2.0},12.0,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //4

    pass_list[154] =
    {
        {1.0,3.0},{1.5,0.5},19.5,WEST,
        {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[155] =
        {
            {1.0,3.0},{1.5,2.5},19.5,SOUTH,
            {/*180度旋回*/
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3

    pass_list[156] =
    {
        {1.0,3.0},{2.0,0.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[157] =
    {
        {1.0,3.0},{2.0,1.0},13.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[158] =
    {
        {1.0,3.0},{2.0,2.0},10.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[159] =
    {
        {1.0,3.0},{2.0,3.0},5.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //4

    pass_list[160] =
    {
        {1.0,3.0},{2.5,0.5},17.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[161] =
    {
        {1.0,3.0},{2.5,1.5},14.5,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //左入れ
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[162] =
    {
        {1.0,3.0},{2.5,2.5},17.5,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //右Uターン
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3
    pass_list[163] =
    {
        {1.0,3.0},{3.0,0.0},19.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[164] =
    {
        {1.0,3.0},{3.0,1.0},16.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[165] =
    {
        {1.0,3.0},{3.0,2.0},5.0,WEST,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[166] =
    {
        {1.0,3.0},{3.0,3.0},8.0,SOUTH,
        {//右に90度
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            /*walker*/			//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[167] =
    {
        {2.0,1.0},{0.0,0.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[168] =
    {
        {2.0,1.0},{0.0,1.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[169] =
    {
        {2.0,1.0},{0.0,2.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[170] =
    {
        {2.0,1.0},{0.0,3.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4

    pass_list[171] =
    {
        {2.0,1.0},{0.5,0.5},10.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[172] =
    {
        {2.0,1.0},{0.5,1.5},9.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[173] =
    {
        {2.0,1.0},{0.5,2.5},12.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,7,0,{0,0},0,0,0,0,Section::LENGTH,3,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},5,0,0,-23,Section::LENGTH,22,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-5,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,-19,Section::TURNANGLE,55,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-5,0,{0,0},0,0,0,0,Section::LENGTH,-11,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3

    pass_list[174] =
    {
        {2.0,1.0},{1.0,0.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[175] =
    {
        {2.0,1.0},{1.0,1.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[176] =
    {
        {2.0,1.0},{1.0,2.0},8.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[177] =
    {
            {2.0,1.0},{1.0,3.0},11.5,NORTH,
            {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4

    pass_list[178] =
    {
        {2.0,1.0},{1.5,0.5},7.5,NORTH,
        {//キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[179] =
    {
        {2.0,1.0},{1.5,2.5},7.5,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3
    pass_list[180] =
    {
        {2.0,1.0},{2.0,0.0},12.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[181] =
    {
        {2.0,1.0},{2.0,2.0},3.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[182] =
    {
        {2.0,1.0},{2.0,3.0},6.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //4
    pass_list[183] =
    {
        {2.0,1.0},{2.5,0.5},7.0,SOUTH,
        {//Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[184] =
    {
        {2.0,1.0},{2.5,1.5},4.0,EAST,
        {//キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[185] =
    {
        {2.0,1.0},{2.5,2.5},7.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3

    pass_list[186] =
    {
        {2.0,1.0},{3.0,0.0},10.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[187] =
    {
        {2.0,1.0},{3.0,1.0},10.0,SOUTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[188] =
    {
        {2.0,1.0},{3.0,2.0},8.0,SOUTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[189] =
    {
        {2.0,1.0},{3.0,3.0},11.0,SOUTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[190] =
    {
        {2.0,2.0},{0.0,0.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[191] =
    {
        {2.0,2.0},{0.0,1.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[192] =
    {
        {2.0,2.0},{0.0,2.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[193] =
    {
        {2.0,2.0},{0.0,3.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4
    pass_list[194] =
    {
        {2.0,2.0},{0.5,0.5},15.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[195] =
    {
        {2.0,2.0},{0.5,1.5},10.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[196] =
    {
        {2.0,2.0},{0.5,1.5},9.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3

    pass_list[197] =
    {
        {2.0,2.0},{1.0,0.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[198] =
    {
        {2.0,2.0},{1.0,1.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[199] =
    {
        {2.0,2.0},{1.0,2.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[200] =
    {
        {2.0,2.0},{1.0,3.0},8.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4

    pass_list[201] =
    {
        {2.0,2.0},{1.5,0.5},16.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[202] =
    {
        {2.0,2.0},{1.5,2.5},4.5,EAST,
        {//キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3

    pass_list[203] =
    {
        {2.0,2.0},{2.0,0.0},15.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[204] =
    {
        {2.0,2.0},{2.0,1.0},12.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[205] =
    {
        {2.0,2.0},{2.0,3.0},3.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //4

    pass_list[206] =
    {
        {2.0,2.0},{2.5,0.5},16.5,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[207] =
    {
        {2.0,2.0},{2.5,1.5},7.0,SOUTH,
        {//Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,1},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }

    };

    pass_list[208] =
    {
        {2.0,2.0},{2.5,2.5},4.0,EAST,
        {//キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3

    pass_list[219] =
    {
        {2.0,2.0},{3.0,0.0},13.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[210] =
    {
        {2.0,2.0},{3.0,1.0},10.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[211] =
    {
        {2.0,2.0},{3.0,2.0},5.0,SOUTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[212] =
    {
        {2.0,2.0},{3.0,3.0},3.0,SOUTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[213] =
    {
        {2.0,3.0},{0.0,0.0},20.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[214] =
    {
        {2.0,3.0},{0.0,1.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[215] =
    {
        {2.0,3.0},{0.0,2.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[216] =
    {
        {2.0,3.0},{0.0,3.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4

    pass_list[217] =
    {
        {2.0,3.0},{0.5,0.5},18.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[218] =
    {
        {2.0,3.0},{0.5,1.5},15.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[219] =
    {
        {2.0,3.0},{0.5,2.5},18.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,1},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
                                    //3
    pass_list[220] =
    {
        {2.0,3.0},{1.0,0.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[221] =
    {
        {2.0,3.0},{1.0,1.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[222] =
    {
        {2.0,3.0},{1.0,2.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[223] =
    {
        {2.0,3.0},{1.0,2.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4

    pass_list[224] =
    {
        {2.0,3.0},{1.5,0.5},18.5,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[225] =
    {
        {2.0,3.0},{1.5,2.5},7.5,NORTH,
        {//キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //3

    pass_list[226] =
    {
        {2.0,3.0},{2.0,0.0},18.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[227] =
    {
        {2.0,3.0},{2.0,1.0},15.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[228] =
    {
        {2.0,3.0},{2.0,2.0},12.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //4
    pass_list[229] =
    {
        {2.0,3.0},{2.5,0.5},23.5,SOUTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[230] =
    {
        {2.0,3.0},{2.5,1.5},20.5,SOUTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[231] =
    {
        {2.0,3.0},{2.5,2.5},7.0,SOUTH,
        {//Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,1},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //3
    pass_list[232] =
    {
        {2.0,3.0},{3.0,0.0},16.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[233] =
    {
        {2.0,3.0},{3.0,1.0},13.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[234] =
    {
        {2.0,3.0},{3.0,2.0},10.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[235] =
    {
        {2.0,3.0},{3.0,3.0},5.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[236] =
    {
        {3.0,0.0},{0.0,0.0},11.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[237] =
    {
        {3.0,0.0},{0.0,1.0},14.0,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[238] =
    {
        {3.0,0.0},{0.0,2.0},17.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[239] =
    {
        {3.0,0.0},{0.0,3.0},20.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };

    pass_list[240] =
    {
        {3.0,0.0},{1.0,0.0},20.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[241] =
    {
        {3.0,0.0},{1.0,1.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[242] =
    {
        {3.0,0.0},{1.0,2.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[243] =
    {
        {3.0,0.0},{1.0,3.0},17.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };

    pass_list[244] =
    {
        {3.0,0.0},{2.0,0.0},20.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[245] =
    {
        {3.0,0.0},{2.0,1.0},8.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[246] =
    {
        {3.0,0.0},{2.0,2.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[247] =
    {
        {3.0,0.0},{2.0,3.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };

    pass_list[248] =
    {
        {3.0,0.0},{3.0,1.0},3.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[249] =
    {
        {3.0,0.0},{3.0,2.0},6.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[250] =
    {
        {3.0,0.0},{3.0,3.0},9.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[251] =
    {
        {3.0,1.0},{0.0,0.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[252] =
    {
        {3.0,1.0},{0.0,1.0},11.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[253] =
    {
        {3.0,1.0},{0.0,2.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[254] =
    {
        {3.0,1.0},{0.0,3.0},17.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4
    pass_list[255] =
    {
        {3.0,1.0},{0.5,0.5},13.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[256] =
    {
        {3.0,1.0},{0.5,1.5},12.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[257] =
    {
        {3.0,1.0},{0.5,2.5},15.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3
    pass_list[258] =
    {
        {3.0,1.0},{1.0,0.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}}
    };

    pass_list[259] =
    {
        {3.0,1.0},{1.0,1.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[260] =
    {
        {3.0,1.0},{1.0,2.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[261] =
    {
        {3.0,1.0},{1.0,3.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4
    pass_list[262] =
    {
        {3.0,1.0},{1.5,0.5},10.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[263] =
    {
        {3.0,1.0},{1.5,2.5},12.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3
    pass_list[264] =
    {
        {3.0,1.0},{2.0,0.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[265] =
    {
        {3.0,1.0},{2.0,1.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[266] =
    {
        {3.0,1.0},{2.0,2.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[267] =
    {
        {3.0,1.0},{2.0,3.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //4
    pass_list[268] =
    {
        {3.0,1.0},{2.5,0.5},13.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,1},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[269] =
    {
        {3.0,1.0},{2.5,1.5},12.5,EAST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,1},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[270] =
    {
        {3.0,1.0},{2.5,2.5},7.5,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
    //3
    pass_list[271] =
    {
        {3.0,1.0},{3.0,0.0},12.0,WEST,
            {{Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[272] = 
    {
        {3.0,1.0},{3.0,2.0},3.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };

    pass_list[273] =
    {
        {3.0,1.0},{3.0,2.0},6.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[274] =
    {
        {3.0,2.0},{0.0,0.0},20.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[275] =
    {
        {3.0,2.0},{0.0,1.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[276] =
    {
        {3.0,2.0},{0.0,2.0},11.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[277] =
    {
        {3.0,2.0},{0.0,3.0},14.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4
    pass_list[278] =
    {
        {3.0,2.0},{0.5,0.5},18.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[279] =
    {
        {3.0,2.0},{0.5,1.5},13.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[280] =
    {
        {3.0,2.0},{0.5,2.5},12.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3
    pass_list[281] =
    {
        {3.0,2.0},{1.0,0.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}
        }
    };

    pass_list[282] =
    {
        {3.0,2.0},{1.0,1.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[283] =
    {
        {3.0,2.0},{1.0,2.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[284] =
    {
        {3.0,2.0},{1.0,3.0},11.5,NORTH,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4
    pass_list[285] =
    {
        {3.0,2.0},{1.5,0.5},15.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[286] =
    {
        {3.0,2.0},{1.5,2.5},9.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3

    pass_list[287] =
    {
        {3.0,2.0},{2.0,0.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[288] =
    {
        {3.0,2.0},{2.0,1.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[289] =
    {
        {3.0,2.0},{2.0,2.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[290] =
    {
        {3.0,2.0},{2.0,3.0},10.5,EAST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},13.0,0,0,-12,Section::TURNANGLE,-75,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},14.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
    //4
    pass_list[291] =
    {
        {3.0,2.0},{2.5,0.5},15.5,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[292] =
    {
        {3.0,2.0},{2.5,1.5},13.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[293] =
    {
        {3.0,2.0},{2.5,2.5},12.5,EAST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3
    pass_list[294] =
    {
        {3.0,2.0},{3.0,0.0},15.0,WEST,
            {{Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[295] =
    {
        {3.0,2.0},{3.0,1.0},12.0,WEST,
            {{Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[296] =
    {
        {3.0,2.0},{3.0,3.0},3.0,EAST,
        {//サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,3},BLUE,0.5}
        }
    };

    pass_list[297] =
    {
        {3.0,3.0},{0.0,0.0},23.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,0},BLUE,0.5}
        }
    };

    pass_list[298] =
    {
        {3.0,3.0},{0.0,1.0},20.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,1},BLUE,0.5}
        }
    };

    pass_list[299] = 
    {
        {3.0,3.0},{0.0,2.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{0,2},BLUE,0.5}
        }
    };

    pass_list[300] = 
    {
        {3.0,3.0},{0.0,3.0},11.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{0,3},BLUE,0.5}
        }
    };
    //4
    pass_list[301] = 
    {
        {3.0,3.0},{0.5,0.5},21.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[302] =
    {
        {3.0,3.0},{0.5,1.5},18.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}}
    };

    pass_list[303] =
    {
        {3.0,3.0},{0.5,2.5},21.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };
    //3
    pass_list[304] =
    {
        {3.0,3.0},{1.0,0.0},20.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,0},BLUE,0.5}}
    };

    pass_list[305] =
    {
        {3.0,3.0},{1.0,1.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,1},BLUE,0.5}
        }
    };

    pass_list[306] =
    {
        {3.0,3.0},{1.0,2.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{1,2},BLUE,0.5}
        }
    };

    pass_list[307] =
    {
        {3.0,3.0},{1.0,3.0},8.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{1,3},BLUE,0.5}
        }
    };
    //4
    pass_list[308] = 
    {
        {3.0,3.0},{1.5,0.5},18.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //右斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},18,0,0,-21,Section::LENGTH,18,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,-15,Section::TURNANGLE,53,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-21,0,{0,0},0,0,0,0,Section::LENGTH,-12,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},9.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[309] = 
    {
        {3.0,3.0},{1.5,2.5},18.0,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,-12,Section::TURNANGLE,-195,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-10,0,0,-8,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-30,0,{0,0},0,0,0,0,Section::LENGTH,-37,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},8.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };
    //3
    pass_list[310] = 
    {
        {3.0,3.0},{2.0,0.0},17.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,0},BLUE,0.5}
        }
    };

    pass_list[311] = 
    {
        {3.0,3.0},{2.0,1.0},14.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[312] = 
    {
        {3.0,3.0},{2.0,2.0},11.0,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[313] = 
    {
        {3.0,3.0},{2.0,3.0},5.5,NORTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5}
        }
    };
                                //4
    pass_list[314] = 
    {
        {3.0,3.0},{2.5,0.5},18.5,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,1},BLUE,0.5}
        }
    };

    pass_list[315] = 
    {
        {3.0,3.0},{2.5,1.5},15.5,WEST,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,15,0,{0,0},0,0,0,0,Section::LENGTH,4,{0,0},BLUE,0},
            //左斜め前に置く
            {Section::VIRTUAL,0,0,{0,0},20,0,0,21,Section::LENGTH,16,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,1,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //元の場所に戻る
            {Section::VIRTUAL,0,0,{0,0},-20,0,0,15,Section::TURNANGLE,-50,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-20,0,{0,0},0,0,0,0,Section::LENGTH,-8,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},18.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[316] =
    {
        {3.0,3.0},{2.5,2.5},18.5,SOUTH,
        {//旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,3},BLUE,0.5},
            //旋回
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,11,Section::TURNANGLE,60,{0,0},BLUE,0},
            {Section::VIRTUAL,0,0,{0,0},10.0,0,0,10,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},7.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5},
            //キャッチ
            {Section::WALKER,5,0,{0,0},0,0,0,0,Section::LENGTH,2,{0,0},BLUE,0},
            //Uターン
            {Section::VIRTUAL,0,0,{0,0},8,0,0,12,Section::TURNANGLE,200,{0,0},BLUE,0},
            //まっすぐ下がる
            {Section::WALKER,-10,0,{0,0},0,0,0,0,Section::LENGTH,-3,{0,0},BLUE,0},
            //戻る！
            {Section::VIRTUAL,0,0,{0,0},-5,0,0,6,Section::BRIGHTNESS,-0.5,{0,0},BLUE,0},
            //角度調整
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::LENGTH,7,{0,0},BLUE,0.5},
            //まっすぐ下がる
            {Section::WALKER,-23,0,{0,0},0,0,0,0,Section::LENGTH,-42,{0,0},BLUE,0},
            //ストップ
            {Section::WALKER,0,0,{0,0},0,0,0,0,Section::LENGTH,-1,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},5.0,0,0,0,Section::COLOR,0,{2,2},BLUE,0.5}
        }
    };

    pass_list[317] =
    {
        {3.0,3.0},{3.0,0.0},18.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,0},BLUE,0.5}
        }
    };

    pass_list[318] =
    {
        {3.0,3.0},{3.0,1.0},15.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5},
            //サークル突破
            {Section::WALKER,30,0,{0,0},0,0,0,0,Section::LENGTH,17,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},20.0,0,0,0,Section::COLOR,0,{3,1},BLUE,0.5}
        }
    };

    pass_list[319] =
    {
        {3.0,3.0},{3.0,2.0},12.0,WEST,
        {
            {Section::VIRTUAL,0,0,{0,0},15,0,0,-3,Section::TURNANGLE,-145,{0,0},BLUE,0},
            /*linetrace色判定*/
            {Section::TRACER,0,0,{0,0},10.0,0,0,0,Section::COLOR,0,{3,2},BLUE,0.5}
        }
    };
}
