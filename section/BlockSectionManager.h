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
      // bool run();        

        void initArea();
    
        //static BingoState *msCarryState;
        //static BingoState *msMoveState;
        //static Area *msArea;

    protected:


    private:
      //  BingoState *mState;

#if (defined(MAKE_RIGHT) && defined(PRIMARY)) || (!defined(MAKE_RIGHT) && !defined(PRIMARY)) 
  const int _EDGE = LineTracer::LEFTEDGE;
  const float sign=-1;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
  const float sign=1;
#endif

double kp=30.0,ki=20.0,kd=2.0;

wParam search_area[500] = {
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATEALL, 45, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::BRIGHTNESS, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, +30, _EDGE, Judge::UPDATEALL, -80, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 17, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 50, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
                    {0, Section::WALKER, Section::LENGTH, -30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -30, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 0, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 35, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, GREEN_H, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, -25, _EDGE, Judge::UPDATE, 30, 0, 0, 0, GREEN_H, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 35, 0, 0, 0, 0, 0 , 0,Section::JNONE},

                    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 50, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
                    {0, Section::WALKER, Section::LENGTH, -30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -30, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 0, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 35, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, BLUE_H, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, -25, _EDGE, Judge::UPDATE, 30, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 35, 0, 0, 0, 0, 0 , 0,Section::JNONE},


                    {0, Section::WALKER, Section::STOP, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0, 5 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 50, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0.35, 0 , 0,Section::COLORSTATUS},
                    {0, Section::WALKER, Section::LENGTH, -30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -30, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, 40, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::STOP, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 2 , 0,Section::JNONE},
                    {0, Section::ARM, Section::ARMANGLE, 0, 0, 4, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,kp, ki, kd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 35, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::COLOR, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, RED_H, 0.35, 0 , 0,Section::JNONE},


                    {0, Section::WALKER, Section::LENGTH, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 45, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, +105, 0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},

};

wParam *array[10] = {search_area};



};

#endif
