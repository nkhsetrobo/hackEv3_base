#ifndef __BINGO_STATE_MOVE_DATA__
#define __BINGO_STATE_MOVE_DATA__

#define bkp 38
#define bki 10.0
#define bkd 5.1
#define bspd 26.0
#define bspd2 16.5


#define _EDGE true
#define sign 1.0

#define end_r_angle -2.0
#define end_l_angle 2.0

// 1 1区画前進
BINGO_SEC BingoStateMove::c1_2[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};


// 2  2区画前進
BINGO_SEC BingoStateMove::c1_3[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2.0, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};
// R1R1 右旋回　1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c1_4[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
        
    {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};        

// 1R2L2 1区画　右旋回　2区画 左旋回　2区画
BINGO_SEC BingoStateMove::c1_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  2 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  6 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1R3  1区画　右旋回　3区画
BINGO_SEC BingoStateMove::c1_14[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  2 ,0.3, 0 , 0}, Judge::UPDATE},

    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 6,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN

    {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 10,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //  {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //     Section::LENGTH,{ 0, 62, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2R3 2区画　右旋回　3区画
BINGO_SEC BingoStateMove::c1_15[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 20, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)12.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN

        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},//左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1 １区画
BINGO_SEC BingoStateMove::c2_3[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  3 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WEND,{},Section::JEND,{}}                      
};

// R1R2 右旋回 1区画　右旋回　2区画
BINGO_SEC BingoStateMove::c2_4[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  6 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  5 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1R1 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c2_7[] = {

    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  3 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
        Section::TURNANGLE,{-96*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R2L1 右旋回　2区画 左旋回　1区画
BINGO_SEC BingoStateMove::c2_11[] = {
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN


    {Section::WEND,{},Section::JEND,{}}                      
};

// R3R1  右旋回　3区画 右旋回　1区画 
BINGO_SEC BingoStateMove::c2_13[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2*0.8, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 6,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 10,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

                    
                    
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
        {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// R3  右旋回　3区画
BINGO_SEC BingoStateMove::c2_14[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)8.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2*0.8, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 6,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 10,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1区画 右旋回　3区画
BINGO_SEC BingoStateMove::c2_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 12, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 右旋回 1区画 右旋回　3区画　右旋回 1区画
BINGO_SEC BingoStateMove::c3_0[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -12*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 25, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0,(float)_EDGE},
        Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 60, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 75, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
        Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// R1 右旋回　1区画
BINGO_SEC BingoStateMove::c3_7[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
        Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};   

// R3  右旋回　3区画
BINGO_SEC BingoStateMove::c3_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
        Section::TURNANGLE,{-96*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 7,0, 0, 0},Judge::UNUPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 5, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 28, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 40, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 55, 0, 0, 0, 0, 0},Judge::UNUPDATE},
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 62, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L1 左旋回　1区画　左旋回　1区画  
BINGO_SEC BingoStateMove::c5_0[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0,1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd,1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1 左旋回　1区画
BINGO_SEC BingoStateMove::c5_1[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1.5, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1L1 1区画　左旋回　1区画
BINGO_SEC BingoStateMove::c5_2[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  6 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// 2L1 2区画　左旋回　1区画
BINGO_SEC BingoStateMove::c5_3[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0, 0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 19, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2  2区画前進
BINGO_SEC BingoStateMove::c5_7[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2.0, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};

// R1R1 右旋回 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c5_8[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},   //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  9 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  8 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2R1 2区画　右旋回　1区画
BINGO_SEC BingoStateMove::c5_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2.0, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R2R1 右旋回 2区画　右旋回　1区画
BINGO_SEC BingoStateMove::c5_12[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  9 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  13 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL2,{bspd2, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{00, 3, 0, 0,  0,0, 0, 0},Judge::UPDATEALL}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R2R1 右旋回 2区画
BINGO_SEC BingoStateMove::c5_13[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  9 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  13 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1R2 1区画　右旋回　2区画
BINGO_SEC BingoStateMove::c5_14[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  6 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  10 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};


// 2R3 2区画　右旋回　2区画
BINGO_SEC BingoStateMove::c5_15[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)12.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 5, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN

        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

        
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L2 左旋回　1区画　左旋回　2区画
BINGO_SEC BingoStateMove::c6_0[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 左旋回　1区画　左旋回　1区画
BINGO_SEC BingoStateMove::c6_1[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1 左旋回　1区画
BINGO_SEC BingoStateMove::c6_2[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1.5, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1L1 1区画　左旋回　1区画
BINGO_SEC BingoStateMove::c6_3[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  7 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// 1 1区画前進
BINGO_SEC BingoStateMove::c6_7[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};

// R1R2 右旋回 1区画　右旋回　2区画
BINGO_SEC BingoStateMove::c6_8[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  6 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  9 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  8 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1R1 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c6_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  7 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0 , 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 右旋回　2区画　右旋回　2区画
BINGO_SEC BingoStateMove::c6_12[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -11.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -13.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd*2, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  12 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R2R1 右旋回 2区画　右旋回　1区画
BINGO_SEC BingoStateMove::c6_13[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  10 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  14 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL2,{bspd2, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{00, 3, 0, 0,  0,0, 0, 0},Judge::UPDATEALL}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R2 右旋回 2区画
BINGO_SEC BingoStateMove::c6_14[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  10 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  14 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WEND,{},Section::JEND,{}}                      
};
// 1R2 1区画　右旋回　2区画
BINGO_SEC BingoStateMove::c6_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  7 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2L2 2区画　左旋回　2区画
BINGO_SEC BingoStateMove::c9_3[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2  2区画前進
BINGO_SEC BingoStateMove::c9_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 20, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};
// R1 右旋回　1区画
BINGO_SEC BingoStateMove::c9_13[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2*0.8, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};   

// 1R1 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c9_14[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2区画　右旋回　1区画
BINGO_SEC BingoStateMove::c9_15[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 左旋回　2区画　左旋回　1区画
BINGO_SEC BingoStateMove::c12_1[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 13.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd*2, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 左旋回　2区画　左旋回　1区画
BINGO_SEC BingoStateMove::c9_0[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{00, 1, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setpVIRTUALaram*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 13.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// L2 左旋回　2区画
BINGO_SEC BingoStateMove::c9_1[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 5, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// 1L2 1区画　左旋回　2区画
BINGO_SEC BingoStateMove::c9_2[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  10 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L1 左旋回　1区画　左旋回　1区画  
BINGO_SEC BingoStateMove::c9_4[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, 13.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2L1 2区画　左旋回　1区画
BINGO_SEC BingoStateMove::c9_7[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0, 0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R1R1 右旋回 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c9_12[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},   //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  13 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  12 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L2L2 左旋回 2区画　左旋回　2区画
BINGO_SEC BingoStateMove::c10_0[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 左旋回　2区画　左旋回　1区画
BINGO_SEC BingoStateMove::c10_1[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{00, 1, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setpVIRTUALaram*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 13.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};



// L2 左旋回　2区画
BINGO_SEC BingoStateMove::c10_2[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1L2 1区画　左旋回　2区画
BINGO_SEC BingoStateMove::c10_3[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,11.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L2 左旋回　1区画　左旋回　2区画
BINGO_SEC BingoStateMove::c10_4[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L1 左旋回　1区画　左旋回　1区画   （初手）
BINGO_SEC BingoStateMove::c10_5[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 2.0, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1  左旋回　1区画  （２手目）
BINGO_SEC BingoStateMove::c10_6[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1区画　左旋回　1区画
BINGO_SEC BingoStateMove::c10_7[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1区画前進
BINGO_SEC BingoStateMove::c10_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};

// R1R2 右旋回 1区画　右旋回　2区画
BINGO_SEC BingoStateMove::c10_12[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  14 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  13 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  12 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// R1R1 右旋回　1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c10_13[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
        
    {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0, 13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// R1 右旋回　1区画
BINGO_SEC BingoStateMove::c10_14[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// 1区画　右旋回　1区画
BINGO_SEC BingoStateMove::c10_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L3L1  左旋回　3区画  左旋回　1区画 
BINGO_SEC BingoStateMove::c13_0[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// L3  左旋回　3区画
BINGO_SEC BingoStateMove::c13_1[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// 1L3 1区画　左旋回　3区画
BINGO_SEC BingoStateMove::c13_2[] = {

    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  14 ,0.3, 0 , 0}, Judge::UPDATE},

    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 99999, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN


    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN

        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 2L3 2区画　左旋回　3区画
BINGO_SEC BingoStateMove::c13_3[] = {
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

    // 1L2R1 1区画　左旋回　2区画　右旋回　1区画
BINGO_SEC BingoStateMove::c13_7[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  14 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,-(float)9.0*sign, 0, 0, false},
        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L1 左旋回　1区画　左旋回　1区画  
BINGO_SEC BingoStateMove::c13_8[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, 13.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  8 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1区画前進
BINGO_SEC BingoStateMove::c13_14[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  14  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};


// 2  2区画前進
BINGO_SEC BingoStateMove::c13_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 20, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2.0, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 20, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};

// L3L2  左旋回　3区画  左旋回　2区画 
BINGO_SEC BingoStateMove::c14_0[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  0,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// L3L1  左旋回　3区画  左旋回　1区画 
BINGO_SEC BingoStateMove::c14_1[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WEND,{},Section::JEND,{}}                      
};

// L3  左旋回　3区画
BINGO_SEC BingoStateMove::c14_2[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};


// 1区画　左旋回　3区画
BINGO_SEC BingoStateMove::c14_3[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  15 ,0.3, 0 , 0}, Judge::UPDATE},

    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 100000, 0, 0,0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
        {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN

    // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, (float)_EDGE},
    //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

        {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L2L2 左旋回 2区画　左旋回　2区画
BINGO_SEC BingoStateMove::c14_4[] = {
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
        Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{00, 10, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// L1L2 左旋回　1区画　左旋回　2区画
BINGO_SEC BingoStateMove::c14_8[] = {
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
        Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  8 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};

// 1L1 1区画　左旋回　1区画
BINGO_SEC BingoStateMove::c14_11[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
    // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
        Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}                      
};
// 1 1区画前進
BINGO_SEC BingoStateMove::c14_15[] = {
    {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
        Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
        Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
        Section::COLOR,{00, 0, 0, 0,  15  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    {Section::WEND,{},Section::JEND,{}}            
};


#endif