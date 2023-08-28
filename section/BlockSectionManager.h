#ifndef _BLOCK_SECTION_MANAGER_H_
#define _BLOCK_SECTION_MANAGER_H_
#include "SectionManager.h"
//#include "BingoState.h"
//#include "BingoStateCarry.h"
//#include "BingoStateMove.h"
//#include "Area.h"
#include "HackEv3.h"

class BlockSectionManager : public SectionManager {
    public:
        BlockSectionManager();

       // void setState(BingoState *bst);
        void init();
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


const int _EDGE_L = LineTracer::LEFTEDGE;
const int _EDGE_R = LineTracer::RIGHTEDGE;
const float sign=-1;

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
float kp=19,ki=20+2,kd=4.5;
//float rvkp=60,rvki=20.0,rvkd=9.0;
//loat rvkp=15,rvki=0.5,rvkd=2.1;
float rvkp=45,rvki=50,rvkd=12.0;  // lowpass 0.85
float lvkp=17,lvki=13.0+2,lvkd=9.2; // lowpass 0.85
float rkp0=20,rki0=12,rkd0=3.4;

float rkp2=30,rki2=10,rkd2=34.0;  // lowpass 0.85


double normal_spd=46-2;
double turn_spd=50+9;
int armdir = -1;
double arm_agnle=60;
double block_out_len=16.5;

double turnoffs=0;
#endif
const double OUTER_TURN_ANGLE=38.0;

//未使用
wParam search_area_L[100] = {

    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATEALL, 55, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0.35, 5 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 55, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATEALL, 0, 6, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATEALL, +115, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, YELLOW_H, 0.2, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -21, 0, 0, _EDGE, Judge::UPDATE, -15, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,29, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -3 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 27, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.3, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UPDATE, -20, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 27, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UPDATE, -20, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -4, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},

//内側へ入る場合
   // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
   // {0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -105, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
 
//ボーナスを取りに行く場合
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},


      // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};


wParam search_area_R[200] = {

    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, 50*sign, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, +50*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 2, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +95*sign, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, +95*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
//    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, YELLOW_H, 0.2, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -21*sign, 0, 0, _EDGE_R, Judge::UPDATE, -23*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,32, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {AREA0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180*sign, 0, -normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, -1 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    //グレー
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -OUTER_TURN_ANGLE*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    //    {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, -OUTER_TURN_ANGLE*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
  {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -OUTER_TURN_ANGLE*sign, 2, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 26, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.3, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -20*sign, 0, 0, _EDGE_R, Judge::UPDATE, -25*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,32, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {AREA1, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180*sign, 0, -normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, -2, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    //グレー
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -OUTER_TURN_ANGLE*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      //  {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, -OUTER_TURN_ANGLE*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -OUTER_TURN_ANGLE*sign, 2, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 25, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -20*sign, 0, 0, _EDGE_R, Judge::UPDATE, -23*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,32, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {AREA2, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180*sign, 0, -normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, -2, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    //グレー
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -(OUTER_TURN_ANGLE+turnoffs)*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
     //   {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, -(OUTER_TURN_ANGLE+turnoffs)*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -(OUTER_TURN_ANGLE+turnoffs)*sign, 2, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 29, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.10, 0 , 0,Section::JNONE},

    //{0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    //{0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -105*sign, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
 
//ボーナスを取りに行く場合
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +42*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::STOP, 0, 0,lvkp*10.0, lvki*5.0, lvkd*1.5, 0, 0 /*setparam*/, +42*sign, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 100 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 30, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,0, 1, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 6.5, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, !_EDGE_R, Judge::UPDATE, +60*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 2, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.75, 0,rvkp, rvki, rvkd, -10*sign, 0 /*setparam*/, 0, +8.5*sign, 0, 0, _EDGE_R, Judge::UPDATE, +89*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.70, 0,kp*1.2, ki*1.2, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 2, 0, 0, 0, 0, 2 , 0,Section::JNONE},
     {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
   {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 40, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 40, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {BONUSBLOCK, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::COLORSTATUS},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -90, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -48, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd+5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},



    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
   
   
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

wParam carry_bonus_0[50] = {

// 運搬 0
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +10*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +60*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::STOP, normal_spd+5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +65*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 16, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, -(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.9, 0,kp*1.5, ki, kd*1.6, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::WALKER, Section::COLOR, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, GREEN_H, 0.09, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.7, 0,rvkp, rvki, rvkd, +30*sign, 0 /*setparam*/, 0, -5*sign, 0, 0, _EDGE_R, Judge::UPDATE, -60*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.10, 0 , 0,Section::JNONE},
    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -20*sign, 0, 0, _EDGE_R, Judge::UPDATE, -18*sign, 0, 0, 0.0, 0, 0, 0 , 0,Section::JNONE},

  //斜めのトレース
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -10*sign, 0, 0, _EDGE_R, Judge::UPDATE, -60*sign, 5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -20*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  (-20+180)*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -1.0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -55*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18.5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7.0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

wParam carry_bonus_1[30] = {
// 運搬 1
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki*2.0, rvkd, -15*sign, 0 /*setparam*/, 0, +10*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +85*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd+5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +85*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
   //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, +15*sign, 0 /*setparam*/, 0, -4*sign, 0, 0, _EDGE_R, Judge::UPDATE, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, -93*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, -93*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 35, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, +20*sign, 0, 0, _EDGE, Judge::UPDATE, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,22, 0, 0, 0, 0, 0 , 0,Section::JNONE},



    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +20*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+20-180)*sign, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

 
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +55*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0,18 , 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7.0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

        //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};


wParam carry_bonus_2[30] = {
// 運搬 2
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki*2.0, rvkd, -15*sign, 0 /*setparam*/, 0, +10*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +85*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd+5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +85*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
   //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, +15*sign, 0 /*setparam*/, 0, -4*sign, 0, 0, _EDGE_R, Judge::UPDATE, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.9, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +20*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+20-180)*sign, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

 
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +55*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0,18 , 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7.0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

      //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam carry_bonus_3[30] = {

// 運搬 3
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +10*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +65*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::STOP, normal_spd+5, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +65*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 16, 0, 0, 0, 0.35, 50 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, -(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.9, 0,kp*1.5, ki, kd*1.6, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::WALKER, Section::COLOR, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,GREEN_H, 0.10, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, GREEN_H, 0.09, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -19*sign, 0, 0, _EDGE_R, Judge::UPDATE, -18*sign, 5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -20*sign, 0, 0, _EDGE_R, Judge::UPDATE, -18*sign, 0, 0, 0.0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,21, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -20*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  (-20+180)*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, -1.0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -55*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 18.5, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.25, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 7.0, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};


wParam search_area[100] = {

    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATEALL, 60, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 60, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATEALL, 0, 7, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATEALL, -70, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    // キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.09, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 18, normal_spd, -47, _EDGE, Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6 , 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},


    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -arm_agnle*armdir, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 18, normal_spd, -47, _EDGE, Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6 , 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},


    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -arm_agnle*armdir, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -20, 0 /*setparam*/, 0, 18, normal_spd, -47, _EDGE, Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 30, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.4, 0 , 0,Section::JNONE},


    {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATE, +110, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    //{0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, +105 , 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0.5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
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

        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, +turn_spd*sign, _EDGE_R, Judge::UPDATEALL, -70*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rkp2, rki2, rkd2, 0, 0 /*setparam*/, -70*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 55, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,rkp2, rki2, rkd2, 0, 0 /*setparam*/, -70*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, -0.5, 0,0, 0.0, 0 , 0,Section::JNONE},
        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rkp2, rki2, rkd2, 0, 0 /*setparam*/, -70*sign, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 3, 0, 0,0, 0.0, 0 , 0,Section::JNONE},
        {0, Section::TURN, Section::TURNANGLE, 0, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 10, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -0*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      //{0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

//色チェック
wParam color_check[20] = {

    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
       // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {100, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::COLORSTATUS},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

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
     {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +11*sign, 0, 0, _EDGE, Judge::UPDATEALL, +88*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,GREEN_H, 0.13, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,RED_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd*0.8, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},

//つかみ
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -8*sign, 0, 0, _EDGE, Judge::UPDATEALL, -90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 40, 0, 0,0,0, 0 , 0,Section::JNONE},
     {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.8, 0,rvkp, rvki, rvkd, -20*sign, 0 /*setparam*/, 0, +8*sign, 0, 0, _EDGE, Judge::UPDATEALL, +90*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd*1.2, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 25, 0, 0,0,0, 0 , 0,Section::JNONE},
      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},


      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},


};




wParam *moveList[10] = {
 // pat1_1, pat1_1b, pat1_2, pat1_2a, pat1_3,pat1_3a,exit1b,nullptr //赤青青
  pat1_1, color_check, pat1_1a, pat1_2, color_check, pat1_2b, pat1_3,pat1_3a,exit1b,nullptr //青赤青
  //pat1_1, pat1_1a, pat1_2, pat1_2a, pat1_3,exit1,nullptr //青青赤
};

wParam *movePhase1[10] = {pat1_1, color_check,nullptr};
wParam *carryPhase1[10] = {pat1_1a,pat1_1b,nullptr};
wParam *movePhase2[10] = {pat1_2, color_check,nullptr};
wParam *carryPhase2[10] = {pat1_2a,pat1_2b,nullptr};
wParam *movePhase3[10] = {pat1_3,nullptr};
wParam *carryPhase3[10] = {pat1_3a,exit1b,nullptr};
wParam *exitPhase[10] = {exit1a,nullptr};


wParam *array[10] = {search_area_L,search_area_R};

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

};

#endif
