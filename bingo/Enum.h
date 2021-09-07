#ifndef _Enum_h_
#define _Enum_h_

enum direction    //方向
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

enum color    //色
{
    BLUE,
    RED,
    GREEN,
    YELLOW
};

enum object    //コース内要素
{
    BLOCK,
    STORAGE
};

enum WALKER_NO
{
    WNONE,
    WALKER,    //単純走法
    TRACER,    //ライントレース
    VIRTUAL,    //曲線仮想ライントレース
    VIRTUAL2    //直線仮想ライントレース
};

enum JUDGE_NO {
    JNONE,
    LENGTH,
    TURNANGLE,
    BRIGHTNESS,
    COLOR,
    STOP
};

#endif