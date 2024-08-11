#ifndef _BLOCK_SECTION_MANAGER_H_
#define _BLOCK_SECTION_MANAGER_H_
#include "SectionManager.h"
//#include "BingoState.h"
//#include "BingoStateCarry.h"
//#include "BingoStateMove.h"
//#include "Area.h"
#include "HackEv3.h"

enum COMMAND{
    SLR, //0
    SLL,

    SL2RR, 
    SL2RL,
    SL2BR,
    SL2BL,
    SL2GR,
    SL2GL,
    SL2YR, //5
    SL2YL,

    L2BR,  
    L2BL,
    L2GR,
    L2GL,  //10
    L2RR,
    L2RL,  
    L2YR,
    L2YL,

    TL1,  //15
    TL2,
    TL3,   
    TR1,
    TR2, //19
    TR3,
    
    TL0,  
    TR0,

    GO,

    PUSH_RR,
    PUSH_GR,
    PUSH_BR,
    PUSH_YR,
    PUSH_RL,
    PUSH_GL,
    PUSH_BL,
    PUSH_YL,

    PUSH_RR2,
    PUSH_YR2,
    PUSH_RL2,
    PUSH_YL2,

    PUSH_RTR,
    PUSH_RTL,

    ROT_RR,
    ROT_RL,
    ROT_GR,
    ROT_GL,
    ROT_BR,
    ROT_BL,
    ROT_YR,
    ROT_YL,

    ROT180_GR,
    ROT180_GL,

    PUSH_LINE_L,
    PUSH_LINE_R,

    BACK_R,
    BACK_G,
    BACK_B,
    BACK_Y,

    EXIT1,
    EXIT2,
    EXIT2b,
    EXIT3,
    EXIT4,

    COLOR,

    CMDEND
};



namespace BSM {
class BlockSectionManager : public SectionManager {
    public:
        BlockSectionManager();

       // void setState(BingoState *bst);
        void init();
        void multiinit(COMMAND cmd[]);
      using SectionManager::init;
       bool run();        

      void initArea();
      void execAreaSearch();
      void initBonusMove();
      void execBonusMove();
      void initColor();
      void execColor();
      void initCarry();
      void execCarry();
      void initMove();
      void execMove();
      void exitMove();
    void initEnter();
    void execEnter();
        //static BingoState *msCarryState;
        //static BingoState *msMoveState;
        //static Area *msArea;
        enum BkCol {
            BKRED,
            BKGREEN,
            BKBLUE,
            BKYELLOW
        };
    protected:


    private:
      //  BingoState *mState;
      enum State {
        UNDEFINED,
        AREASEARCH,
        INITBONUSMOVE,
        BONUSMOVE,
        INITENTER,
        ENTER,

        INITMOVE,
        MOVE,
        EXITMOVE,
        INITCOLOR,
        COLOR,
        INITCARRY,
        CARRY,
        END
      };

      State mState;

    void changeBonusBlock(int area,BkCol col);
    int getBonusArea(BkCol col);
    bool run_section();

#if (defined(MAKE_RIGHT) && defined(PRIMARY)) || (!defined(MAKE_RIGHT) && !defined(PRIMARY)) 
  const int _EDGE = LineTracer::LEFTEDGE;
  //const float sign=-1;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
  //const float sign=1;
#endif


const static int _EDGE_L;
const static int _EDGE_R;
const static float sign;

const int AREA0=100;
const int AREA1=101;
const int AREA2=102;
const int BONUSBLOCK=103;
const int COLORBLOCK=104;



#if defined(MAKE_SIM)
double kp=22.0,ki=15.0,kd=3.6;
double rvkp=40,rvki=5.0,rvkd=3.5;
double normal_spd=50;
double turn_spd=30;
int armdir = 1;
double arm_angle=50;
double block_out_len=17;
#else
static float kp,ki,kd;
//float rvkp=60,rvki=20.0,rvkd=9.0;
//loat rvkp=15,rvki=0.5,rvkd=2.1;
static float rvkp,rvki,rvkd;  // lowpass 0.85
static float lvkp,lvki,lvkd; // lowpass 0.85
static float rkp0,rki0,rkd0;

static float rkpf,rkif,rkdf;   //spd 100用 2024再調整
static float rkpf2,rkif2,rkdf2;   //spd 100用 2024再調整
static float rkp2,rki2,rkd2;  // lowpass 0.85


static double normal_spd;
static double turn_spd;
static int armdir;
static double arm_agnle;
static double block_out_len;

static double turnoffs;
#endif
const double OUTER_TURN_ANGLE=38.0;


wParam test2024_L[80] = {
   {0, Section::TRACER, Section::LENGTH, 65, 0, rkpf,rkif,rkdf, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 95, 0, 0, 0, 0,0,false},
  //青サークル検知
  {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2 , 0,1 /*setparam*/, 0, mode2, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.10,0,false},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //青サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.10,0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, +2, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, BLEN, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
  //旋回
  {12, Section::VIRTUAL2, Section::LENGTH, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN_CENT, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  //{0, Section::WALKER, Section::TURNANGLE, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 30, 40, _EDGE, Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0 , 0},
  //{0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, +60, false,Judge::UNUPDATE, -88, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
  {12, Section::VIRTUAL, Section::TURNANGLE, 30, 0,  rkp2 ,rki2, rkd2, +20, 0 /*setparam*/, 0, -6, 0, 0, _EDGE_R, Judge::UPDATEALL, -88, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                  // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},


  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, BLEN-12, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, BLEN, 0, 0, 0, 0,0,false},
    //黄サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, BLEN, 0, 0, 0, 0,0,false},
    //黄サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, CSPD, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0,  YELLOW_H, 0.10,0 ,false,Section::JNONE},

// キャリーエリアへ
  {12, Section::VIRTUAL2, Section::LENGTH, 55, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0 ,false,Section::JNONE},

//青エッジに沿って
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 23, 0, 0, 0, 0,0,false},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, 35, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
  // {12, Section::VIRTUAL2, Section::LENGTH, 80, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  // {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
//目標へ向けて旋回
  {12, Section::VIRTUAL, Section::TURNANGLE, 50, 0,  rkp2 ,rki2, rkd2, +10, 0 /*setparam*/, 0, -20, 0, 0, _EDGE_R, Judge::UPDATE_RESET, -78.5, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

//  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, +60, false,Judge::UNUPDATE, -75, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//キャリー
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -78.5, mode3, 37, -100, !_EDGE_R, Judge::UPDATE, 0, 77.5, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, -50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -40, 0, 0, 0, 0, 0 ,false,Section::JNONE},
//戻り
  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, -60, false,Judge::UNUPDATE, +90, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, -60, false,Judge::UPDATE, +65, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 40, 0, 0, 0, 0,0,false},
  {0, Section::TRACER, Section::COLOR, 50, -0.4, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, BLUE_H, 0.10,0 ,false},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

////　ブロック色取得パラメータ
wParam c_search[10] = {
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 4.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 6 , 0,Section::JNONE},
      {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {COLORBLOCK, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 10.0, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {0, Section::ARM, Section::ARMANGLE, 0, 0, -90, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},

      //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
#if 0
wParam c_0_0[100] = {

      {0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -20, _EDGE, Judge::UPDATE, +45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 8.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 45-180, 0, 0, 0, _EDGE, Judge::UPDATE, 0, -8.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      // {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -20.0, 0, 0, true,Judge::UPDATE, -20, 0, 0, 0, 0, 0, 0, Section::JNONE},
      //{0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 3, +3, _EDGE, Judge::UPDATE, -5, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      //{0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 4, +4, _EDGE, Judge::UNUPDATE, -10, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, +20, _EDGE, Judge::UNUPDATE, -18, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, -18, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      //  {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      //   {0, Section::VIRTUAL, Section::TURNANGLE,  20, 0, rvkp,rvki,rvkd, -25, 0 /*setparam*/, 0, 14.0, 0, 0, true,Judge::UNUPDATE, +45+90+45, 0, 0, 0, 0, 0, 0, Section::JNONE},
      //    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 3, -3, _EDGE, Judge::UNUPDATE, +5, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      //    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 4, -4, _EDGE, Judge::UNUPDATE, +10, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, -20, _EDGE, Judge::UNUPDATE, +50+90+90, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      //  {0, Section::TRACER, Section::LENGTH, 20, 0, kp,ki,kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE,Judge::UPDATE,0, 7, 0, 0, 0, 0, 0, Section::JNONE},

      {0, Section::WALKER, Section::BRIGHTNESS, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0.3, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, 20, 0, kp,ki,kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE,Judge::UPDATE,0, 20, 0, 0, 0, 0, 0, Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam c_0_1[100] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATE, 0, 32.0, 0, 0,  RED_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 14.0, 0, 0, _EDGE, Judge::UPDATE, 45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 9.0, 0, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 32.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATEALL, 0, 2.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, 40, 0.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 40, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 5.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

wParam c_8_2[100] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATE, 0, 32.0, 0, 0,  GREEN_H, 0.1, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -16.0, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*2.0, 0,rvkp*2, rvki*2, rvkd, +30, 0 /*setparam*/, 0, -7.0, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp*2, rvki*2, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 32.0, 0, 0,  BLUE_H, 0.09, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 6.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -4.0, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, -normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, -4.0, 0, 0, _EDGE, Judge::UNUPDATE, -0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 40, 0, 0, 0, _EDGE, Judge::UPDATE, 0, -5.0, 0, 0,  0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};
#endif
//直入れ
wParam c_8_1[10] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 20.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UNUPDATE, 0, 10.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
// 直入れ
// Rコースで半時計回り
wParam c_11_3[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam c_13_0[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam c_4_1[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
// Rコースで時計回り
wParam c_7_1[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam c_1_0[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 26.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam c_8_3[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam c_14_2[20] = {
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 31.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd-5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE, Judge::UNUPDATE, 0, 25.5, 0, 0,  0, 0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};




// 東向きから左サイド、西向きから右サイド
//* 13-8-(4)-0-(1)-(2) Rコースで反時計周り
wParam c_13_1[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 9, 0, 0, _EDGE, Judge::UPDATEALL, 88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.12, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (-180+40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


     // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

//* 4-1-(2)-3-(7)-(11) Rコースで反時計周り
wParam c_4_2[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 26.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 9, 0, 0, _EDGE, Judge::UPDATEALL, 88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (-180+40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


     // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

//* 2-7-(11)-15-(14)-(15) Rコースで反時計周り
wParam c_2_3[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 26.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 9, 0, 0, _EDGE, Judge::UPDATEALL, 88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (-180+40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


     // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};



//7-2-(1)-0-(4)-(8) Rコースで時計回り
wParam c_7_0[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -9, 0, 0, _EDGE, Judge::UPDATEALL, -88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.12, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

//8-13-(14)-15-(11)-(7) Rコースで時計回り
wParam c_8_2[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -9, 0, 0, _EDGE, Judge::UPDATEALL, -88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.12, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 1-4-(8)-12-(13)-(14) Rコースで時計回り
wParam c_1_3[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -9, 0, 0, _EDGE, Judge::UPDATEALL, -88, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -40*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-40)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +0*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},


 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


//


// 後方
//* 13-8-(4)-(5)-(6)-(7)-(11)
wParam c_13_2[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.13, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 4-1-(2)-(6)-(10)-(14)-(13))
wParam c_4_3[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 2-7-(11)-(10)-(9)-(8)-(4)
wParam c_2_0[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 11-14-(13)-(9)-(5)-(1)-(2)
wParam c_11_1[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};



// 7-2-(1)-(5)-(9)-(13)-(14)
wParam c_7_3[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.13, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (-180+30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 1-4-(8)-(9)-(10)-(11)-(7)
wParam c_1_2[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*0.7*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
 //   {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 8, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
  //  {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +30*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +30*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (-180+30)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


// 右サイド
//* 13-8-(4)-(5)-10-(14)-(13)
wParam c_13_3[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +10*sign, 0 /*setparam*/, 0, 15.5, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

//    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

//* 4-1-(2)-(6)-9-(8)-(4)
wParam c_4_0[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +10*sign, 0 /*setparam*/, 0, 15.5, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

//    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 7-2-(1)-(5)-9-(10)-(11)
wParam c_2_1[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -10*sign, 0 /*setparam*/, 0, -15.5, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
// 7-2-(1)-(5)-9-(10)-(11)
wParam c_7_2[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -10*sign, 0 /*setparam*/, 0, -15.5, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 1-4-(8)-(9)-6-(2)-(1)
wParam c_1_1[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -10*sign, 0 /*setparam*/, 0, -13.5, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// 1-4-(8)-(9)-6-(2)-(1)
wParam c_8_0[100] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE, Judge::UPDATE, 0, 25.0, 0, 0,  0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -10*sign, 0 /*setparam*/, 0, -13.5, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +90*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.30, 0 , 0,Section::JNONE},
  //おいた
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
   // {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
   // {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +45*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -60*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+180-60)*sign, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

 //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
//wParam *c_13_0 = c_8_1;

//wParam *c_13_2 = c_8_1;
//wParam *c_13_3 = c_8_1;




//ブロックまで移動するパラメータ群
//　R 右45度
#if 0
wParam m_7_7[10] = {
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*10, lvkd*2.0, 0, 0 /*setparam*/, +44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.1, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
#endif
wParam m_7_7[10] = {
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*5.0, lvkd*2.0, 0, 0 /*setparam*/, +44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


wParam *m_1_1 =  m_7_7;
wParam *m_8_8 =  m_7_7;
wParam *m_14_14 =  m_7_7;


//　R 左45度
wParam m_13_13[10] = {
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +turn_spd*sign, _EDGE_R, Judge::UPDATEALL, -44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*5.0, lvkd*2.0, 0, 0 /*setparam*/, -44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam *m_2_2 =  m_13_13;
wParam *m_11_11 =  m_13_13;
wParam *m_4_4 =  m_13_13;


wParam m_7_1[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},

//45度
      {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*5.0, lvkd*2.0, 0, 0 /*setparam*/, +44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},


      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam m_1_8[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.20, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -25*sign, 0 /*setparam*/, 0, -6, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0,  _EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.20, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},

//45度
      {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*5.0, lvkd*2.0, 0, 0 /*setparam*/, +44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},


      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam m_4_2[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +25*sign, 0 /*setparam*/, 0, 5, 0, 0, _EDGE, Judge::UPDATEALL, -92*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +turn_spd*sign, _EDGE_R, Judge::UPDATEALL, -44*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*20.0, lvki*5.0, lvkd*2.0, 0, 0 /*setparam*/, -44*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam m_4_11[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam m_2_11[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam m_11_13[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam m_13_4[20] = {
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, 6, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

wParam enter[10] = {

  {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2 , 0,1 /*setparam*/, 0, mode2, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.10,0,false},
  // {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//Lコース
wParam enter2[10] = {

  {0, Section::VIRTUAL2, Section::COLOR, CSPD, 0,rkp2 ,rki2, rkd2 , 0,1 /*setparam*/, 0, mode2, 0, 30, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  BLUE_H, 0.10,0,false},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
   //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};


//色チェック
static wParam color_check[];

// @@@@@@@@@@@@@@@@@@@@@@@ パターン１ @@@@@@@@@@@@@@@@@@@@@@@@@@
// １つ目へ移動
wParam pat1_1[20] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -10*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
//１つ目移動
wParam pat1_1a[20] = {
//つかみ
  //  {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 4, 0, 0,0,0, 0 , 0,Section::JNONE},
//飛ばし
     //   {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +100*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -185*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -9, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.7, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +9*sign, 0, 0, _EDGE, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

   //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},


 {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//１つ目待避
wParam pat1_1b[20] = {
//つかみ
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0,0,0, 0 , 0,Section::JNONE},
//待避
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*1.2, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.7, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +9.5*sign, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,6, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -15, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +90*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 3, 0, 0,0,0, 0 , 0,Section::JNONE},
  //戻る
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*1.2, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.7, 0,rvkp, rvki, rvkd, -+0*sign, 0 /*setparam*/, 0, -8.0*sign, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},


 {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//２つ目へ移動
wParam pat1_2[20] = {
 //  {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +10*sign, 0, 0, _EDGE, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
  //通貨
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//２つ目移動
wParam pat1_2a[20] = {
  //つかみ
   // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 4, 0, 0,0,0, 0 , 0,Section::JNONE},
//飛ばし
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
        // {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -8, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,4, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -12*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

// ２つ目待避
wParam pat1_2b[30] = {
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -10*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
     {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL2, Section::COLOR, -normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -3, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +turn_spd*sign, _EDGE_R, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -88*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 3, 0, 0,0,0, 0 , 0,Section::JNONE},
  //戻る
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*1.2, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11.0*sign, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*1.2, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,16, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11.0*sign, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.7, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -10.0*sign, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};


// ３つ目へ移動
wParam pat1_3[20] = {
  // {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
  //通過
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.11, 0 , 0,Section::JNONE},
  //通過
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.11, 0 , 0,Section::JNONE},

   {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +9*sign, 0, 0, _EDGE, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.11, 0 , 0,Section::JNONE},



    //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

// ３つ目移動
wParam pat1_3a[20] = {

   // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 2, 0, 0,0,0, 0 , 0,Section::JNONE},
//飛ばし
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 9, 0, 0,0,0, 0 , 0,Section::JNONE},
        // {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +80*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
//        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, +85*sign, _EDGE_R, Judge::UPDATEALL, -360*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -180*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -8, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,4, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.11, 0 , 0,Section::JNONE},

 //     {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

// ３つ目ゴールへ
wParam exit1b[20] = {
//つかみ
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
   {0, Section::VIRTUAL, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +60*sign, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, 40 ,0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, 60, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0, 70, 0, 0, 0, 0 , 0,Section::JNONE},
 //  {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -11*sign, 0, 0, _EDGE, Judge::UPDATEALL, -88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

// ３つ目回収後ゴールへ
wParam exit1a[20] = {
// キャリーエリアへ
  {12, Section::VIRTUAL2, Section::LENGTH, 55, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0 ,false,Section::JNONE},

//青エッジに沿って
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2*1.5,rkif2*1.5,rkdf2*1.5, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0,0,false},
    {0, Section::VIRTUAL2, Section::LENGTH, -40, 0,rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, -180*sign, mode0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -15, 0, 0,0,0, 0 , 0,Section::JNONE},
  {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2*1.5,rkif2*1.5,rkdf2*1.5, +0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 20, 0, 0, 0, 0,0,false},
                      {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
    //赤サークル検知
  {12, Section::VIRTUAL2, Section::COLOR, 35, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,  RED_H, 0.10,0 ,false,Section::JNONE},
  // {12, Section::VIRTUAL2, Section::LENGTH, 80, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, CLEN, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  // {0, Section::TRACER, Section::LENGTH, 40, 0, rkpf2,rkif2,rkdf2, +0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
//目標へ向けて旋回
  {12, Section::VIRTUAL, Section::TURNANGLE, 50, 0,  rkp2 ,rki2, rkd2, -10, 0 /*setparam*/, 0, +20, 0, 0, _EDGE_R, Judge::UPDATE_RESET, +78.5, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

//  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, +60, false,Judge::UNUPDATE, -75, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//キャリー
  {12, Section::VIRTUAL2, Section::LENGTH, 45, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, +78.5, mode3, +34, +97, !_EDGE_R, Judge::UPDATE, 0, 76.5, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, -50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, -40, 0, 0, 0, 0, 0 ,false,Section::JNONE},
//戻り
  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, +60, false,Judge::UNUPDATE, -90, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
  {12, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 ,false,Section::JNONE},
  {12, Section::VIRTUAL2, Section::LENGTH, 50, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, mode2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0, 0 ,false,Section::JNONE},
  {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, +60, false,Judge::UPDATE, -65, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 40, 0, 0, 0, 0,0,false},
  {0, Section::TRACER, Section::COLOR, 50, -0.4, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, BLUE_H, 0.10,0 ,false},
  {0, Section::TRACER, Section::LENGTH, 50, 0, rkpf2,rkif2,rkdf2, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},


};

// @@@@@@@@@@@@@@@@@@@@@@@ パターン3 @@@@@@@@@@@@@@@@@@@@@@@@@@
// １つ目へ移動
wParam pat2_1[20] = {
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
     {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
     {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};




wParam *moveList[10] = {
 // pat1_1, pat1_1b, pat1_2, pat1_2a, pat1_3,pat1_3a,exit1b,nullptr //赤青青
  pat1_1, color_check, pat1_1a, pat1_2, color_check, pat1_2b, pat1_3,pat1_3a,exit1b,nullptr //青赤青
  //pat1_1, pat1_1a, pat1_2, pat1_2a, pat1_3,exit1,nullptr //青青赤
};

// wParam *movePhase1[10] = {pat1_1, color_check,nullptr};
// wParam *carryPhase1[10] = {pat1_1a,pat1_1b,nullptr};
// wParam *movePhase2[10] = {pat1_2, color_check,nullptr};
// wParam *carryPhase2[10] = {pat1_2a,pat1_2b,nullptr};
// wParam *movePhase3[10] = {pat1_3,nullptr};
// wParam *carryPhase3[10] = {pat1_3a,exit1b,nullptr};
// wParam *exitPhase[10] = {exit1a,nullptr};
wParam *movePhase1[10] = {pat2_1, color_check,nullptr};
wParam *carryPhase1[10] = {pat1_1a,pat1_1b,nullptr};
wParam *movePhase2[10] = {pat1_2, color_check,nullptr};
wParam *carryPhase2[10] = {pat1_2a,pat1_2b,nullptr};
wParam *movePhase3[10] = {pat1_3,nullptr};
wParam *carryPhase3[10] = {pat1_3a,exit1b,nullptr};
wParam *exitPhase[10] = {exit1a,nullptr};

static wParam shortline_r[];
static wParam shortline_l[];

static wParam shortline2red_r[];
static wParam shortline2red_l[];
static wParam shortline2blue_r[];
static wParam shortline2blue_l[];
static wParam shortline2green_r[];
static wParam shortline2green_l[];
static wParam shortline2yellow_r[];
static wParam shortline2yellow_l[];

static wParam line2blue_r[];
static wParam line2blue_l[];
static wParam line2green_r[];
static wParam line2green_l[];
static wParam line2red_r[];
static wParam line2red_l[];
static wParam line2yellow_r[];
static wParam line2yellow_l[];

static wParam turn_right1[];
static wParam turn_right2[];
static wParam turn_right3[];
static wParam turn_left1[];
static wParam turn_left2[];
static wParam turn_left3[];

static wParam turn_left0[];
static wParam turn_right0[];


static wParam go_straight[];

static wParam push_red_right[];
static wParam push_green_right[];
static wParam push_blue_right[];
static wParam push_yellow_right[];
static wParam push_red_left[];
static wParam push_green_left[];
static wParam push_blue_left[];
static wParam push_yellow_left[];

static wParam push_red_right2[];
static wParam push_red_left2[];
static wParam push_yellow_right2[];
static wParam push_yellow_left2[];

static wParam push_red_turn_right[];
static wParam push_red_turn_left[];

static wParam rot_red_right[];
static wParam rot_red_left[];
static wParam rot_green_right[];
static wParam rot_green_left[];
static wParam rot_blue_right[];
static wParam rot_blue_left[];
static wParam rot_yellow_right[];
static wParam rot_yellow_left[];

static wParam rot180_green_right[];
static wParam rot180_green_left[];

static wParam push_line_l[];
static wParam push_line_r[];

static wParam back_red[];
static wParam back_green[];
static wParam back_blue[];
static wParam back_yellow[];

static wParam exit1[];
static wParam exit2[];
static wParam exit2b[];
static wParam exit3[];
static wParam exit4[];

static wParam *pat[];

wParam *array[10] = {nullptr,nullptr};

// ブロック運搬経路リスト
wParam *carry_list[16][4] = {
    {}, // 0 未使用
    {c_1_0,c_1_1,c_1_2,c_1_3}, // 1
    {c_2_0,c_2_1,nullptr,nullptr}, // 2
    {}, // 3　未使用

    {c_4_0,c_4_1,c_4_2,c_4_3}, // 4
    {}, // 5　未使用
    {}, // 6　未使用
    {c_7_0 , c_7_1 , c_7_2, c_7_3}, // 7

    {c_8_0,nullptr,c_8_2,c_8_3}, // 8　
    {}, // 9　未使用
    {}, // 10　未使用
    {nullptr,c_11_1,nullptr,c_11_3}, // 11

    {}, // 12　未使用
    {c_13_0 , c_13_1 , c_13_2, c_13_3}, // 13
    {nullptr , nullptr , c_14_2, nullptr}, // 14
    {}, // 15　未使用

};

int arry_endpt[16][4] = {
    {}, // 0 未使用
    {8,1,7,14}, // 1
    {4,2,11,13}, // 2
    {}, // 3　未使用

    {4,2,11,13}, // 4
    {}, // 5　未使用
    {}, // 6　未使用
    {8,1,7,14}, // 7

    {8,1,7,14}, // 8　
    {}, // 9　未使用
    {}, // 10　未使用
    {4,2,11,13}, // 11

    {}, // 12　未使用
    {4,2,11,13}, // 13
    {8,1,7,14}, // 14
    {}, // 15　未使用  
};

// ブロック移動経路リスト
wParam *move_list[16][16] = {
    {}, // 0 未使用
    {nullptr,m_1_1,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, m_1_8,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr}, // 1
    {nullptr,nullptr,m_2_2,nullptr, nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,m_2_11, nullptr,nullptr,nullptr,nullptr}, // 2
    {}, // 3　未使用
    {nullptr,nullptr,m_4_2,nullptr, m_4_4,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,m_4_11, nullptr,nullptr,nullptr,nullptr}, // 4
    {}, // 5　未使用
    {}, // 6　未使用
    {nullptr,m_7_1,nullptr,nullptr, nullptr,nullptr,nullptr,m_7_7, nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr}, // 7
    {nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, m_8_8,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr}, // 8　
    {}, // 9　未使用
    {}, // 10　未使用
    {nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,m_11_11, nullptr,m_11_13,nullptr,nullptr}, // 11
    {}, // 12　未使用
    {nullptr,nullptr,nullptr,nullptr, m_13_4,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, nullptr,m_13_13,nullptr,nullptr, }, // 13
    {nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,nullptr,nullptr, nullptr,nullptr,m_14_14,nullptr,}, // 14
    {}, // 15　未使用

};

int block_list_in_area[9] = {1,0,1, 0,0,0, 1,0,1};
int node_to_block[16] = {-1,0,2,-1, 0,-1,-1,2, 6,-1,-1,8, -1,6,8,-1};

BkCol bonus_area[4] = {BKRED,BKGREEN,BKBLUE,BKYELLOW};
BkCol bonus_col = BKGREEN;
BkCol carry_block = BKGREEN;
int cur_no=0;
int next_pos;

int block_phase=0;
int block_fix=0;
int color=0;
int block_color[3] = {0,1,1};

int pattern = 1; //プライマリブロックパターン

};
}; //namespace

#endif
