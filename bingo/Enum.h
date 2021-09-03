#ifndef _Enum_h_
#define _Enum_h_

enum direction    //方向
{
    north,
    east,
    south,
    west
};

enum color    //色
{
    blue,
    red,
    green,
    yellow
};

enum object    //コース内要素
{
    block,
    storage
};

enum WALKER_NO 
{
    WNONE,
    WALKER,
    TRACER,
    VIRTUAL,
    VIRTUAL2
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