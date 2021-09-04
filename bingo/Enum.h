#ifndef _Enum_h_
#define _Enum_h_

enum direction    //方向
{
    NORTH,
    EAST,
    SAUTH,
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