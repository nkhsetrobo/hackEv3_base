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
        INITCOLOR,
        COLOR,
        INITCARRY,
        CARRY,
        INITMOVE,
        MOVE
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



#if defined(MAKE_SIM)
double kp=20.0,ki=12.0,kd=3.4;
double rvkp=40,rvki=5.0,rvkd=3.5;
double normal_spd=50;
double turn_spd=30;
int armdir = 1;
double arm_angle=50;
double block_out_len=17;
#else
float kp=18,ki=20,kd=3.8;
//float rvkp=60,rvki=20.0,rvkd=9.0;
//loat rvkp=15,rvki=0.5,rvkd=2.1;
float rvkp=45,rvki=50,rvkd=10.0;  // lowpass 0.85
float lvkp=17,lvki=12.0,lvkd=9.0; // lowpass 0.85
float rkp0=20,rki0=12,rkd0=3.4;

double normal_spd=48;
double turn_spd=50;
int armdir = -1;
double arm_agnle=60;
double block_out_len=13.5;

double turnoffs=0;
#endif

wParam search_area_v2[100] = {

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
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -3 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 26, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.3, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UPDATE, -20, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 25, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UPDATE, -20, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -4, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
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
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0.35, 5 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 55*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 2, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +95*sign, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, YELLOW_H, 0.2, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -21*sign, 0, 0, _EDGE_R, Judge::UPDATE, -25*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,32, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {AREA0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180*sign, 0, -normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, -1 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    //グレー
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -35*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 2, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
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
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -35*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 2, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 25, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -20*sign, 0, 0, _EDGE_R, Judge::UPDATE, -25*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,32, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {AREA2, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 180*sign, 0, -normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, -2, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    //グレー
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -(35+turnoffs)*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},

    //{0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    //{0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -105*sign, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
 
//ボーナスを取りに行く場合
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +40*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +45*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 30, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,0, 1, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 5, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, !_EDGE_R, Judge::UPDATE, +60*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd*0.75, 0,rvkp, rvki, rvkd, -15*sign, 0 /*setparam*/, 0, +9.5*sign, 0, 0, _EDGE_R, Judge::UPDATE, +87*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {BONUSBLOCK, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -55, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},



    //   {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
   
   
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

wParam carry_bonus_2[30] = {
// 運搬 2
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +8*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +85*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +85*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 24, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
   //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, +15*sign, 0 /*setparam*/, 0, -4*sign, 0, 0, _EDGE_R, Judge::UPDATE, -110*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, -100*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.8, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATEALL, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +20*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, (+20-180)*sign, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, -3, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

 
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UNUPDATE, +55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +55*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0,20 , 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,BLUE_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

        {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};
wParam carry_bonus_3[30] = {

// 運搬 3
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, -5*sign, 0 /*setparam*/, 0, +8*sign, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +78*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, +78*sign, 0, normal_spd, 0, _EDGE_R, Judge::UPDATE, 0, 24, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, -(turn_spd+5)*sign, _EDGE_R, Judge::UPDATE, +80*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp*1.5, ki, kd*1.6, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,GREEN_H, 0.13, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20*sign, 0 /*setparam*/, 0, -21*sign, 0, 0, _EDGE_R, Judge::UPDATE, -15*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL,0,21, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, -19*sign, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UPDATE, -20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -20*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  (-20+180)*sign, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd*sign, _EDGE_R, Judge::UNUPDATE, -55*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/,  -55*sign, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki ,rvkd,0, 0 /*setparam*/, 0, 0, 0, -turn_spd*sign, _EDGE_R, Judge::UPDATE, +20*sign, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd*0.75, 0,kp, ki, kd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATEALL,0,15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, 0, 0,YELLOW_H, 0.15, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 1, 0, 0, _EDGE_R, Judge::UPDATE, 0, 4, 0, 0,0, 0.0, 0 , 0,Section::JNONE},

       {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, GREEN_H, 0.25, 0 , 0,Section::JNONE},
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

wParam c_search[10] = {
      {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
                      {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
                      {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
                      {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
                      {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},

//         {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
};

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
wParam *array[10] = {search_area_v2,search_area_R};


BkCol bonus_area[4] = {BKRED,BKGREEN,BKBLUE,BKYELLOW};
BkCol bonus_col = BKRED;

};

#endif
