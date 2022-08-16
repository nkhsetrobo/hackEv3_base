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
      void initColor();
      void execColor();
      void initCarry();
      void execCarry();

        //static BingoState *msCarryState;
        //static BingoState *msMoveState;
        //static Area *msArea;

    protected:


    private:
      //  BingoState *mState;
      enum State {
        UNDEFINED,
        AREASEARCH,
        INITCOLOR,
        COLOR,
        INITCARRY,
        CARRY,
        INITMOVE,
        MOVE
      };

      State mState;

#if (defined(MAKE_RIGHT) && defined(PRIMARY)) || (!defined(MAKE_RIGHT) && !defined(PRIMARY)) 
  const int _EDGE = LineTracer::LEFTEDGE;
  const float sign=-1;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
  const float sign=1;
#endif

#if defined(MAKE_SIM)
double kp=18.0,ki=5.0,kd=3.0;
double rvkp=20,rvki=5.0,rvkd=3.0;
double normal_spd=50;
double turn_spd=30;
int armdir = 1;
double arm_angle=50;
double block_out_len=17;
#else
float kp=50,ki=5,kd=4.0;
float rvkp=100,rvki=20.0,rvkd=10.0;
double normal_spd=50;
double turn_spd=60;
int armdir = -1;
double arm_agnle=60;
double block_out_len=21;
#endif

wParam search_area_v2[100] = {
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATEALL, 30, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 60, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATEALL, 0, 6, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, _EDGE, Judge::UPDATEALL, +115, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 10, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, YELLOW_H, 0.09, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -18, 0, 0, _EDGE, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6 ,0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
        // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 10, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 28, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.2, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -19, 0, 0, _EDGE, Judge::UPDATE, -26, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    //キャッチ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.1, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -18, 0, 0, _EDGE, Judge::UPDATE, -28, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL,0,30, 0, 0, 0, 0, 0 , 0,Section::JNONE},

    //角へ
    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, 40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
    {0, Section::VIRTUAL2, Section::LENGTH, -normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 180, 0, -normal_spd, 0, _EDGE, Judge::UPDATE, 0, -6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::ARMANGLE, 0, 0, -40, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 18, 0, 0, 0, 0, 0 , 0,Section::JNONE},
    {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.1, 0 , 0,Section::JNONE},

    {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {0, Section::TURN, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +turn_spd, _EDGE, Judge::UPDATE, -110, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
 

       {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

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
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -14.0, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, +20, 0 /*setparam*/, 0, -9.0, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
      {0, Section::TRACER, Section::LENGTH, normal_spd, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 15, 0, 0, 0, 0, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::COLOR, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 32.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -1, 0, 0, _EDGE, Judge::UPDATEALL, 0, 2.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::TURN, Section::TURNANGLE, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, 40, 0.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},
      {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 40, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 5.0, 0, 0,  BLUE_H, 0.4, 0 , 0,Section::JNONE},

      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};
wParam *array[10] = {search_area_v2};



};

#endif
