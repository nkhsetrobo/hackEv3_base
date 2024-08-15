//namespace BSM = BlockSectionManager;

const  int BlockSectionManager::_EDGE_L = LineTracer::LEFTEDGE;
const  int BlockSectionManager::_EDGE_R = LineTracer::RIGHTEDGE;
const  float BlockSectionManager::sign=-1;

 float BlockSectionManager::kp=37,BlockSectionManager::ki=20+8,BlockSectionManager::kd=6.2;
 float BlockSectionManager::rvkp=70,BlockSectionManager::rvki=80,BlockSectionManager::rvkd=20.0;  // lowpass 0.85
 float BlockSectionManager::lvkp=20,BlockSectionManager::lvki=13.0+2,BlockSectionManager::lvkd=15.0; // lowpass 0.85
 float BlockSectionManager::rkp0=20,BlockSectionManager::rki0=12,BlockSectionManager::rkd0=3.4;

 float BlockSectionManager::rkp2=25,BlockSectionManager::rki2=30,BlockSectionManager::rkd2=7.0;  // lowpass 0.85


 double BlockSectionManager::normal_spd=46;
 double BlockSectionManager::turn_spd=55;
 int BlockSectionManager::armdir = -1;
 double BlockSectionManager::arm_agnle=60;
 double BlockSectionManager::block_out_len=16.5;

 double BlockSectionManager::turnoffs=0;

float BlockSectionManager::rkpf=10,BlockSectionManager::rkif=11.0,BlockSectionManager::rkdf=4.20;   //spd 100用 2024再調整
float BlockSectionManager::rkpf2=BlockSectionManager::rkpf*1.5,BlockSectionManager::rkif2=BlockSectionManager::rkif*1.5,BlockSectionManager::rkdf2=BlockSectionManager::rkdf;   //spd 100用 2024再調整



using BSM::BlockSectionManager;

// Rコース基準

// COMMAND cmd[] = {SL2BR,GO,L2RR,GO,L2RR,TL1,
//                 L2RR,GO,L2YR,GO,L2YR,TL1,
//                 L2YR,GO,L2GR,GO,L2GR,TL1,
//                 L2GR,GO,L2BR,TL1,
//                 L2BR,GO,L2RR,TL1,
//                 L2YR,TL1,
//                 L2GR,GO,L2GR,TL1,
//                 L2BR,GO,L2BR,GO,
//                 CMDEND};
COMMAND cmd[] = {SL2BR,GO,L2RR,GO,L2RR,TL1,
                L2RR,TL1,
                L2RR,GO,L2BR,GO,L2BR,TR2,
                L2GL,TR1,
                L2GL,GO,L2YL,GO,L2YL,TL1,
                L2YR,TL1,
                L2YR,GO,L2GR,GO,L2GR,TL1,
                L2GR,GO,L2BR,GO,L2BR,GO,
                CMDEND};

//最初のブロックへ移動
COMMAND block1cmd[5][50]=
{
    //pat 1
    {   GO,L2BR,GO,L2RR,GO,SLR,
       //  TL1, SL2RR,GO, L2YR,GO,L2YR, 
        CMDEND },
    //pat 2
    {
        TR2,SL2BL,GO,SLL,
        CMDEND   
    },
    //pat 3
    {   GO,SLR,
        CMDEND },
    //pat 4
    {   GO,L2GL,GO,SLL,
        CMDEND
    },
    //pat5 
    {   GO,L2BR,SL2BR,GO,SLR,
        CMDEND
    }
};
COMMAND colorcmd[] = 
{
    COLOR,
    CMDEND
};
//排除用
COMMAND block1pushcmd[5][10]=
{   
    //pat 1
    {
        PUSH_RR,
        TL1,
        CMDEND},
    //pat 2
    {
        PUSH_RL,
        TL2,
        CMDEND}
    ,
    //pat 3
    {
        PUSH_RR2,
        TL1,
        CMDEND
    },
    //pat 4
    {   PUSH_GL,
        TR1,
        CMDEND
},
    //pat 5
    {  
        PUSH_GR,
        TR1,
        CMDEND
    },
};
//2024は回避に使います
COMMAND block1swapcmd[5][50]=
{
    // pat 1
    {
        GO,L2GR,GO,L2GR,TR2,PUSH_LINE_L,
        BACK_G,TR0,L2GL,GO,L2BL,TL3,
        CMDEND},
    //pat 2
    {
        TR2,L2BL,GO,L2GL,TR2,L2GL,TL2,L2GR,TR2,PUSH_LINE_L,
        BACK_G,TR0,L2GL,GO,L2BL,GO,L2BL,TR1,L2BL,TR1,
        CMDEND},
    //pat 3
    {
        GO,L2GR,GO,L2GR,TR2,PUSH_LINE_L,
        BACK_G,TR0,L2GL,GO,L2BL,TL2,
        CMDEND
    },
    //pat 4
    {
        GO,L2GR,GO,L2GR,TR2,PUSH_LINE_L,
        BACK_G,TR0, L2GL,GO,L2BL,TL2,

    CMDEND},
    //pat 5
    {
        TR1,L2GL,GO,L2GL,TR2,PUSH_LINE_L,
        BACK_G,TR0,L2GL,GO,L2BL,GO,L2BL,TL2,L2BR,TL1,L2BR,TL1,L2BR,TR1,
        CMDEND},
};
//2つめのブロックへ移動
COMMAND block2cmd[5][50]=
{
    // pat 1
    {SL2RR,TL1,SL2RR,GO,SLR,
    CMDEND},
    //pat 2
    {SL2YR,GO,L2YR,TL1,SL2GR,GO,SLR,
    CMDEND},
    //pat 3
    {SL2RR,GO,SLR,
    CMDEND},
    //pat 4
    {SL2GL,TR1,
    SL2GL,GO,SLL,
    CMDEND},
    //pat 5
    {   
        SL2YR,GO,L2YR,TR1,
        SL2RL,GO,SLL,
        CMDEND
    },

};
COMMAND block2pushcmd[5][5]=
{
    // pat 1
    {   //PUSH_YL,
        PUSH_BR,
        TL1,
        CMDEND
    },
    //pat 2
    {   
        PUSH_GR,
        TL1,
        CMDEND},
    //pat 3
    {   PUSH_YR2,
        TL1,
        CMDEND},
    //pat 4
    {
        PUSH_GL,
        TL2,
        CMDEND},
    //pat 5
    {   PUSH_RTR,
        SL2RR,TL1,
        CMDEND
    },
   
};
COMMAND block2swapcmd[5][50]=
{
    // pat 1
    {
        GO,L2YL,TL2,L2YR,GO,PUSH_LINE_R,
        BACK_Y,TL0,L2YR,GO,L2RR,TL1,L2RR,TL1,L2YR,TL1,
        CMDEND
    },
    //pat 2
    {
        TL1,L2YR,GO,L2YR,TL1,PUSH_LINE_R,
        BACK_Y,TL0,L2YR,TR2,L2GR,TL1,L2BR,TL1,L2RR,TL2,
        CMDEND   
    },
    //pat 3
    {    GO,L2YR,TL1,PUSH_LINE_R,
        BACK_Y,TL0,L2YR,TL2,
        CMDEND
    },
    //pat 4
    {   GO,L2YR,TL1,L2YR,GO,PUSH_LINE_R,
        BACK_Y,TL0,L2YR,GO,L2RR,TL3,L2RL,TL2,L2YR,TL1,
        CMDEND},
    //pat 5
    {
        TL2,L2GR,TL2,PUSH_LINE_R,
        BACK_G,TL0,L2GR,GO,
        CMDEND},

};

//３つ目のブロックへ
COMMAND block3cmd[5][50]=
{   
    //pat1
    {
        SL2BR,TR1,SL2BL,TR2,SL2BL,GO,SLL,
        CMDEND
    },
    //pat 2
    {
        SL2GR,GO,L2BR,GO,SLR,
        CMDEND
    },
    //pat 3
    {
        SL2GR,GO,SLR,
        CMDEND
    },
    //pat 4
    {   
        SL2RR,TR2,
        SL2RL,TL2,
        SL2RR,TL2,
        SL2RR,GO,SLR, 
        CMDEND
    },
    //pat 5
    {
        SL2RR,GO,
        L2BR,GO,
        SLR,
        CMDEND
    },

};

COMMAND block3pushcmd[5][50]=
{   
    //pat1
    {
        PUSH_GL,
        TR1,
        CMDEND
    },
    //pat 2
    {
        PUSH_BR,TL1,
        CMDEND
    },
    //pat 3
    {
        PUSH_GR,
        TL1,
        CMDEND
    },
    //pat 4
    {   
        PUSH_YR,
        TL1,
        CMDEND
    },
    //pat 5
    {
        PUSH_BR,
        TL1,
        CMDEND
    },

};

COMMAND block3swapcmd[5][50]=
{   
    //pat1
    {
        PUSH_GL,
        TR1,
        CMDEND
    },
    //pat 2
    {
        L2YL,TL1,L2GR,GO,L2GR,TR1,L2GL,CMDEND
    },
    //pat 3
    {
        L2YL,TR1,L2RL,GO,L2RL,CMDEND
    },
    //pat 4
    {   
        L2YR,GO,L2GR,GO,L2GR,TR3,L2GR,
        CMDEND
    },
    //pat 5
    {
        L2BR,GO,L2BR,TL1,L2RR,GO,L2RR,
        CMDEND
    },

};


//４つ目のブロックへ
COMMAND block4cmd[5][50]=
{   
    //pat1
    {
        SL2GL,GO,SLL,
        CMDEND
    },
    //pat 2
    {
        SL2BR,TL1,
        SL2BR,GO,SLR,
        CMDEND
    },
    //pat 3
    {
        SL2GR,TL1,
        SL2GR,TL1,
        SL2GR,ROT180_GL,
        GO,SLL,
        CMDEND
    },
    //pat 4
    {   
        SL2YL,GO,L2GL,GO,L2GL,TL1,
        SL2BR,GO,SLR,
        CMDEND
    },
    //pat 5
    {
        SL2BL,TL1,
        SL2BL,GO,
        SLL,
        CMDEND
    },

};

COMMAND block4pushcmd[5][50]=
{   
    //pat1
    {
        PUSH_YL,
        TL1,
        CMDEND
    },
    //pat 2
    {
        PUSH_GR,
        TR1,
        CMDEND
    },
    //pat 3
    {
        PUSH_BL,
        TL2,
        CMDEND
    },
    //pat 4
    {   
        PUSH_BR,
        TL1,
        CMDEND
    },
    //pat 5
    {
        PUSH_RR,
        TL1,
        CMDEND
    },

};

COMMAND block4swapcmd[5][50]=
{   
    //pat1
    {
        PUSH_GL,
        TR1,
        CMDEND
    },
    //pat 2
    {
        L2YL,TL1,L2GR,GO,L2GR,TR1,L2GL,CMDEND
    },
    //pat 3
    {
        L2YL,TR1,L2RL,GO,L2RL,CMDEND
    },
    //pat 4
    {   
        L2YR,GO,L2GR,GO,L2GR,TR3,L2GR,
        CMDEND
    },
    //pat 5
    {
        L2BR,GO,L2BR,TL1,L2RR,GO,L2RR,
        CMDEND
    },

};


// ３つ目はゴールへそのまま
COMMAND exitacmd[5][50] = 
{
    //pat1
    {
        EXIT4,
        CMDEND
    },
    //pat2
    {
        EXIT4,
        CMDEND},
    //pat3
    {
        TR1,L2RL,GO,L2BL,GO,L2BL,TR1,L2BL,GO,L2GL,GO,L2GL,EXIT4,
        CMDEND},
    //pat4
    {EXIT4,
    CMDEND},
    //pat5
    {
        TL1,L2RR,TL1,L2RR,TR2,L2YR,GO,L2YR, EXIT2b,
    CMDEND},

    
};
// ３つ目は出す、回収してゴールへ
COMMAND exitbcmd[5][50] = 
{
    //pat1
    {
        //PUSH_GL,
        ROT_GL,
        TR1,L2GL,GO,L2YL,EXIT2,
        CMDEND},
    //pat2
    {
        //PUSH_GL,
        ROT_GL,
        TR1,L2GL,GO,L2YL,EXIT2,
        CMDEND},
    //pat3
    {
        //PUSH_RL,
        ROT_RL,
        TR1,L2RL,GO,L2BL,GO,L2BL,TR1,L2BL,GO,L2GL,GO,L2GL,TR1,L2GL,GO,L2YL,
        EXIT2,
        CMDEND},
    //pat4
    {
        //PUSH_GL,
        ROT_GR,
        TR1,L2GL,GO,L2YL,
        EXIT2,
        CMDEND
    },
    //pat5
    {
        //PUSH_RR,
        ROT_RR,
        TL1,L2RR,GO,L2YR,GO,L2YR,TL1,L2YR,GO,L2GR,GO,L2GR,TR0, EXIT4,
    CMDEND},

    
};

//４つめから脱出
COMMAND exit1cmd[5][50] = 
{
    //pat1
    {
        SL2YR,TR1,SL2YL,TL1,
        CMDEND
    },
    //pat2
    {
        SL2YL,GO,L2YL,TL2,
        SL2YR,GO,
        CMDEND},
    //pat3
    {
        SL2RR,GO,L2RR,TL1,
        SL2YR,GO,L2YR,GO,
        CMDEND},
    //pat4
    {   SL2BL,GO,L2RL,TL1,
        SL2RR,GO,L2YR,GO,L2YR,TR2,
        SL2YL,TL1,
        CMDEND},
    //pat5
    {
        SL2RR,GO,L2YR,TR1,
        SL2YL,TL1,
        SL2YR,GO,
        CMDEND
    },

    
};




wParam *BlockSectionManager::pat[] = {
    shortline_r,
    shortline_l,

    shortline2red_r,
    shortline2red_l,
    shortline2blue_r,
    shortline2blue_l,
    shortline2green_r,
    shortline2green_l,
    shortline2yellow_r,
    shortline2yellow_l,

    line2blue_r,
    line2blue_l,
    line2green_r,
    line2green_l,
    line2red_r,
    line2red_l,
    line2yellow_r,
    line2yellow_l,

    turn_left1,
    turn_left2,
    turn_left3,
    turn_right1,
    turn_right2,
    turn_right3,

    turn_left0,
    turn_right0,

    go_straight,

    push_red_right,
    push_green_right,
    push_blue_right,
    push_yellow_right,
    push_red_left,
    push_green_left,
    push_blue_left,
    push_yellow_left,

    push_red_right2,
    push_red_left2,
    push_yellow_right2,
    push_yellow_left2,

    push_red_turn_right,
    push_red_turn_left,

    rot_red_right,
    rot_red_left,
    rot_green_right,
    rot_green_left,
    rot_blue_right,
    rot_blue_left,
    rot_yellow_right,
    rot_yellow_left,

    rot180_green_right,
    rot180_green_left,

    push_line_l,
    push_line_r,

    back_red,
    back_green,
    back_blue,
    back_yellow,

    exit1,
    exit2,
    exit2b,
    exit3,
    exit4,

    color_check,
    camera_check,

};

wParam BlockSectionManager::shortline_l[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-4, 0, 0, 0, 0,0,false},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::shortline_r[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, BLEN-4, 0, 0, 0, 0,0,false},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


wParam BlockSectionManager::shortline2red_l[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::shortline2red_r[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::shortline2blue_l[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-11, 0, 0, 0, 0,0,false},
   // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0.5, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.20,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::shortline2blue_r[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, BLEN-11, 0, 0, 0, 0,0,false},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0.5, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.20,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::shortline2green_l[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  GREEN_H, 0.10,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::shortline2green_r[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  GREEN_H, 0.10,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::shortline2yellow_l[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::shortline2yellow_r[] = {
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, BLEN-10, 0, 0, 0, 0,0,false},
    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},

   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


double line_length=15;

wParam BlockSectionManager::line2blue_r[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //青サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.20,0 ,false,Section::JNONE},

    //    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2blue_l[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //青サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.20,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2red_r[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2red_l[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2green_r[] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,line_length, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2green_l[] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,line_length, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2yellow_r[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATEALL, 0, BLEN, 0, 0, 0, 0,0,false},
    //黄サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::line2yellow_l[] = {
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, BLEN, 0, 0, 0, 0,0,false},
    //黄サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::turn_right1[] = {
   {12, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN_CENT, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {12, Section::VIRTUAL, Section::TURNANGLE, 30, 0,  rkp2 ,rki2, rkd2, +25, 0 /*setparam*/, 0, -6.5, 0, 0, _EDGE_R, Judge::UPDATEALL, -88, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::turn_right2[] = {
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.9, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +8.5*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

  //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::turn_right3[] = {
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -25*sign, 0 /*setparam*/, 0, +6.5*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

////    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::turn_left1[] = {
   {12, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN_CENT, 0, 0, 0, 0, 0 ,false,Section::JNONE},
            //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
  {12, Section::VIRTUAL, Section::TURNANGLE, 30, 0,  rkp2 ,rki2, rkd2, -25, 0 /*setparam*/, 0, +6.5, 0, 0, _EDGE_R, Judge::UPDATEALL, +88, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
        //    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::turn_left2[] = {
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.9, 0,rvkp, rvki, rvkd, +25*sign, 0 /*setparam*/, 0, -8.5*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::turn_left3[] = {
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +24*sign, 0 /*setparam*/, 0, -6.5*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::turn_left0[4] = {
        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +turn_spd*sign, _EDGE_R, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -88*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, -88*sign, 0, 0, 10,YELLOW_H, 0.15, 50 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -88*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE,0, 3, 0, 10,YELLOW_H, 0.15, 50 , 0,Section::JNONE},
   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam BlockSectionManager::turn_right0[4] = {
        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +88*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 10,YELLOW_H, 0.15, 50 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,+88*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE,0, 3, 0, 10,YELLOW_H, 0.15, 50 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


wParam BlockSectionManager::go_straight[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};



//色チェック
wParam BlockSectionManager::color_check[20] = {

    // {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::JNONE},
    // {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/,0, mode2, 0, 0, _EDGE_R, Judge::UPDATE,0, -3, 0, 0,0,0,0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 60, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 40, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
       // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {100, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100 , 0,Section::COLORSTATUS},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -90, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -40, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//カメラ利用の色チェック
wParam BlockSectionManager::camera_check[20] = {

    {100, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100 , 0,Section::COLORSTATUS},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};
// 押したあとに元のサークルへ前進
wParam BlockSectionManager::push_red_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::push_green_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},

    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_blue_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0,0, BLUE_H, 0.20, 0 , 0,Section::JNONE},

 //    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


wParam BlockSectionManager::rot_red_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +50*sign, _EDGE_R, Judge::UNUPDATE, -210*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +60*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -6, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, 40, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,9, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::rot_red_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -80*sign, _EDGE_R, Judge::UPDATEALL, +110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -50*sign, _EDGE_R, Judge::UNUPDATE, +210*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -60*sign, _EDGE_R, Judge::UNUPDATE, +360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -6, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, 40, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,9, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::push_yellow_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},

   //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_red_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

   //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_green_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_blue_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.20, 0 , 0,Section::JNONE},

    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::push_yellow_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},

    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


wParam BlockSectionManager::rot_green_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

// 180度旋回してからサークルへ移動
wParam BlockSectionManager::rot180_green_left[] = {
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +60*sign, _EDGE_R, Judge::UPDATEALL, -180*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,BLEN, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::rot180_green_right[] = {
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -60*sign, _EDGE_R, Judge::UPDATEALL, +180*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,BLEN, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};



// 前方の1つ先のサークルまで押す
wParam BlockSectionManager::push_red_right2[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
    {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},

    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_red_left2[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
    {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},

    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_yellow_right2[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
    {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},

    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_yellow_left2[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
    {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},

    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -CLEN, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


// 押した後に１８０度旋回してからサークルまで
wParam BlockSectionManager::push_red_turn_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -15, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -60*sign, _EDGE_R, Judge::UPDATEALL, +180*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};
wParam BlockSectionManager::push_red_turn_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -15, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +60*sign, _EDGE_R, Judge::UPDATEALL, -180*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, CSPD, 0,rkpf2, rkif2, rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},

  //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};



wParam BlockSectionManager::rot_green_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::rot_blue_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +55*sign, _EDGE_R, Judge::UNUPDATE, -200*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +65*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, 40, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::rot_blue_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -80*sign, _EDGE_R, Judge::UPDATEALL, +110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -55*sign, _EDGE_R, Judge::UNUPDATE, +200*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -65*sign, _EDGE_R, Judge::UNUPDATE, +360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, 40, 0,rkpf2,rkif2,rkdf2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::rot_yellow_left[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -80*sign, _EDGE_R, Judge::UPDATEALL, +360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};

wParam BlockSectionManager::rot_yellow_right[] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -80*sign, _EDGE_R, Judge::UPDATEALL, +360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, -3, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.30, 0 , 0,Section::JNONE},


   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},   
};


wParam BlockSectionManager::push_line_l[20] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp*1.2, ki*1.2, kd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::push_line_r[20] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp*1.2, ki*1.2, kd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


wParam BlockSectionManager::back_red[20] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd*1.3, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -15, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam BlockSectionManager::back_green[20] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd*1.3, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd*0.7, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -15, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, +normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, +1, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::back_blue[20] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd*1.3, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -15, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::back_yellow[20] = {
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd*1.3, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -15, 0, 0,YELLOW_H, 0.20, 0 , 0,Section::JNONE},

    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::exit1[20] = {
        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::exit2[20] = {
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 5, 0, 0,0,0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -8*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  0*sign, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 40, 0, 0,0,0, 0 , 0,Section::JNONE},
      //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd*1.2, 0, _EDGE_R, Judge::UPDATEALL, 0, 37, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
       
     
        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +8*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 25, 0, 0,0,0, 0 , 0,Section::JNONE},
        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
//2番出口から直進脱出
wParam BlockSectionManager::exit2b[20] = {
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 58, 0, 0,0,0, 0 , 0,Section::JNONE},
       // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +8*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 25, 0, 0,0,0, 0 , 0,Section::JNONE},
        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam BlockSectionManager::exit3[20] = {
        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam BlockSectionManager::exit4[20] = {
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +60*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::TRACER, Section::LENGTH, 40 ,0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::TRACER, Section::LENGTH, 60, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0, 70, 0, 0, 0, 0 , 0,Section::JNONE},
        //  {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

