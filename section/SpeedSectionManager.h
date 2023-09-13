#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "HackEv3.h"

class SpeedSectionManager : public SectionManager
{
public:
  SpeedSectionManager();
  void init();
  using SectionManager::init;

protected:
private:


  double YELLOW = 55;
  double GREEN = 145;
  double RED = 0;
  double BLUE = 200;
  double bspd = 11.5;
  double bspd2 = bspd*0.6;
  double bkp = 36;

 
  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, iの値, dの値, 0, 0 ,
  ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
  //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}

  //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
  // tracer->setParam(30,0,30,0.2,0.1)
  //Virtual->setParam(20,2,0.2,0,1,1)
  //Walker->setCommand(0,10)

#if defined(PRIMARY)
  const int _PRIMARY = 1;
#endif


#if (defined(MAKE_RIGHT) && defined(PRIMARY)) || (!defined(MAKE_RIGHT) && !defined(PRIMARY)) 
  const int _EDGE = LineTracer::LEFTEDGE;
 //const float sign=1;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
 // const float sign=-1;
#endif

#if defined(PRIMARY)
  const int _EDGE_L = LineTracer::LEFTEDGE;
  const int _EDGE_R = LineTracer::RIGHTEDGE;
  const float sign=+1;
  const float sign_r=-1;
#else
  const int _EDGE_L = LineTracer::LEFTEDGE;
  const int _EDGE_R = LineTracer::RIGHTEDGE;
  const float sign=-1;
#endif

wParam entry2022[100] = {
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE,   Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 75, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,    Judge::UNUPDATE, 0, 670, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,    Judge::UNUPDATE, 0, 680, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 120, 0.35, 0 , 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 5, -15, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 3, 0,40, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 16, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 3, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0.2, 0 , 0},
                    {0, Section::VIRTUAL2, Section::SONER, 3, 0,60, 10.0, 3.0, 0, 0 /*setparam*/, -0.5, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 32, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};

#if defined(MAKE_RASPIKE)
float normal_spd=45;
float rkp=22,rki=40,rkd=3.8;
float ckp=25,cki=25,ckd=4.5;
//float rkp2=10,rki2=0.2,rkd2=1.2;
float rkp2=30,rki2=10,rkd2=34.0;  // lowpass 0.85
float rkp3=100,rki3=20,rkd3=90.0;

//float rvkp=45,rvki=0.0,rvkd=5.3;
float tkp=5,tki=0,tkd=0.00;
//float rvkp=20,rvki=30.0,rvkd=8.0; // lowpass 0.8
float rvkp=25,rvki=30.0,rvkd=7.0; // lowpass 0.85
float lvkp=15,lvki=10.0,lvkd=9.0; // lowpass 0.85
#elif defined(MAKE_SIM)
float normal_spd=60;
float rkp=35,rki=10,rkd=2.0;
float rkp2=10,rki2=0.2,rkd2=1.2;
float rvkp=15,rvki=0.5,rvkd=2.1;
#else
float normal_spd=45;
float rkp=16*4,rki=12,rkd=1.1;
float rkp2=50,rki2=10,rkd2=45.0;
float rkp3=100,rki3=20,rkd3=90.0;
float rvkp=15,rvki=0.5,rvkd=2.1;
#endif

wParam fin_R[20] = {
                  //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0,Section::COLORSTATUS},

  //finish
                    {0, Section::TRACER, Section::TURNANGLE,  40, -0.3,rkp*1.5,rki*1.5,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::RIGHTEDGE, Judge::UPDATE, -30, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  35, -0.3,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::RIGHTEDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};

wParam fin_Pri_R[20] = {

                    {0, Section::TRACER, Section::TURNANGLE,  40, -0.3,rkp*1.5,rki*1.5,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::LEFTEDGE, Judge::UPDATE, -30, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  35, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::LEFTEDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};


wParam fin_L[20] = {
                  //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0,Section::COLORSTATUS},

  //finish
                    {0, Section::TRACER, Section::TURNANGLE,  40, -0.3,rkp*1.5,rki*1.5,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::LEFTEDGE, Judge::UPDATE, +30, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  35, -0.3,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::LEFTEDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};

wParam fin_Pri_L[20] = {

                    {0, Section::TRACER, Section::TURNANGLE,  40, -0.3,rkp*1.5,rki*1.5,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::RIGHTEDGE, Judge::UPDATE, +30, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  35, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, LineTracer::RIGHTEDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};


wParam primary2022R[200] = {
                    //    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, lvkp,lvki,lvkd, 0, 0 /*setparam*/, 2, 0, 0, 0, true,Judge::UPDATE, 0,2000, 0, 0, 0, 0, 0, Section::JNONE},
                   //     {0, Section::VIRTUAL, Section::LENGTH, 37, 0, rkp2,rki2,rkd2, -12, 0 /*setparam*/, 0, +18.0, 0, 0, true,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, Section::JNONE},
                    //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0,Section::COLORSTATUS},

                    //    {0, Section::TURN, Section::TURNANGLE, 0, -0, 0,0,0, 0, 0 /*setparam*/, 0, 0, 0, -35, false,Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    // {0, Section::VIRTUAL, Section::LENGTH, 37, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, 1, -31, -31, 0, _EDGE, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0 , 0,Section::JNONE},

                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, -10, _EDGE, Judge::UPDATEALL, 360*5, 00, 0, 0, 0, 0, 0 , 0},
                       //  {0, Section::WALKER, Section::TURNANGLE, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, +80, _EDGE, Judge::UPDATEALL, -360*5, 00, 0, 0, 0, 0, 0 , 0},
                  //  {0, Section::TURN, Section::LENGTH, 0, 0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 10, -55, _EDGE, Judge::UPDATE, 0,1000, 0.0, 0, 0, 0, 0 , 0},
                  //  {0, Section::TRACER, Section::LENGTH, 58, 0,rkp,rki,rkd, 0, 0       /*setparam*/, 0, 0, 00, 0, _EDGE,   Judge::UPDATE, 0, 200, 0, 0, 0, 0, 0,false,Section::JNONE},

               //     {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0,0, 0, 0, _EDGE, Judge::UPDATE, 0,30, 0.0, 0, 0, 0, 0 , 0},
               //    {12, Section::VIRTUAL, Section::LENGTH, 30, 0, rkp2,rki2,rkd2, +13, 0 /*setparam*/, 0, -31, 0, 0, _EDGE, Judge::UNUPDATE, -10, 120, 0, 0, 0, 0, 0 , 0},
//                          {0, Section::WALKER, Section::TURNANGLE, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, -40, _EDGE, Judge::UPDATEALL, 360*5, 00, 0, 0, 0, 0, 0 , 0},
                       //   {0, Section::WALKER, Section::TURNANGLE, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 100, _EDGE, Judge::UPDATE, -2, 0, 0, 0, 0, 0, 0 , 0},
//                           {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 25, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0 , 0},
//                        {0, Section::WALKER, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 25, false,Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0},
//                       {0, Section::VIRTUAL, Section::TURNANGLE, 25, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, 18.5, 0, 0, true,Judge::UNUPDATE, +45, 0, 0, 0, 0, 0, 0},
//                        {0, Section::VIRTUAL, Section::TURNANGLE, 25, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, -17.5, 0, 0, true,Judge::UNUPDATE, -30, 0, 0, 0, 0, 0, 0},
//                          {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 25, 0, _EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0 , 0},
                        //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                   // {0, Section::VIRTUAL2, Section::LENGTH, 65, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, 5, 0, 0, _EDGE, Judge::UPDATE, 0,300, -0, 0, 0, 0, 0 , 0},
                   // {12, Section::VIRTUAL, Section::TURNANGLE, 60, 0, rkp, rki, 15.0, 0, 0 /*setparam*/, 0, -95, 0, 0, _EDGE, Judge::UNUPDATE, 310, 0, 0, 0, 0, 0, 0 , 0},

//                         {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0,Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH, 58, 0,rkp,rki,rkd, 0, 0       /*setparam*/, 0, 0, 00, 0, _EDGE_R,   Judge::UPDATEALL, 0, 22, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE, 48, 0,rkp,rki,rkd, -15, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 85, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 58, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 29, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE, 48, 0,rkp,rki,rkd, -15, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 170, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE, 55, 0,rkp,rki,rkd, +12, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 15, 0, 0, 0, 0, 0, 0,false, Section::JNONE},
                         //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                    {12, Section::VIRTUAL, Section::TURNANGLE, 55, 0,  rkp2 ,rki2, rkd2, +10, 0 /*setparam*/, 0, -32, 0, 0, _EDGE_R, Judge::UNUPDATE, -3, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp,rki,rkd, -10, 0 /*setparam*/, 0, 0, 60, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0 , false, Section::JNONE},
                   // {0, Section::TRACER, Section::TURNANGLE, 55, 0,rkp,rki,rkd, -10, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 355, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp,rki,rkd, -10, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0,267 , 0, 0, 0, 0, 0, false,Section::JNONE},
                    {12, Section::VIRTUAL, Section::LENGTH, 55, 0,  rkp2 ,rki2, rkd2, 8, 0 /*setparam*/, 0, -40, 0, 0, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , false, Section::JNONE},
                     //    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {12, Section::WALKER, Section::BRIGHTNESS, 0, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 0, 40, 10, _EDGE_R, Judge::UNUPDATE, 0, 0,  0.5, 0, 0, 0, 0 , false, Section::JNONE},

                        //{0, Section::VIRTUAL2, Section::LENGTH, 55, 0, rvkp ,rvki, rvkd, 0, 0 /*setparam*/, 305, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0,50, 0.0, 0, 0, 0, 0 , 0},
                          //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    //{0, Section::VIRTUAL2, Section::LENGTH, 55, 0,rvkp ,rvki, rvkd, 0, 0 /*setparam*/, 300, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0,80, 0.0, 0, 0, 0, 0 , 0},
                    //{0, Section::VIRTUAL2, Section::BRIGHTNESS, 55, 0,rvkp ,rvki, rvkd, 0, 0 /*setparam*/, 300, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0.0, 0 , 0},
//                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 65, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 310, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, -0.1, 1, 0, 0.0, 0 , 0},
                    //{12, Section::VIRTUAL, Section::TURNANGLE, 55, 0, rkp2 ,rki2, rkd2, -15, 0 /*setparam*/, 0, -17, 0, 0, _EDGE_R, Judge::UNUPDATE, 280, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH,  48, 0,rkp,rki*1.5,rkd*2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  50, 0,rkp,rki*1.5,rkd*1.5, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0 , false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  50, 0,rkp*1.5,rki*1.5,rkd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 10, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                          //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::TURNANGLE,  55, 0,rkp,rki,rkd, -18, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 86, 0, 0, 0, 0, 0, 0 ,false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  55, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  55, 0,rkp,rki,rkd, -18, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 175, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                         // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  65, 0,rkp,rki,rkd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 175, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  60, 0,rkp,rki,rkd, 18, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  55, 0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 150, 0, 0, 0, 0, 0 ,false, Section::JNONE},
  //finish
                    {0, Section::TRACER, Section::TURNANGLE,  40, -0.3,rkp*1.5,rki*1.5,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, -30, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  35, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};


wParam primary2022L[200] = {

                    {0, Section::TRACER, Section::LENGTH, 58, 0,rkp,rki,rkd, 0, 0       /*setparam*/, 0, 0, 00, 0, _EDGE_L,   Judge::UPDATEALL, 0, 22, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE, 48, 0,rkp,rki,rkd, -15*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 85*sign, 0, 0, 0, 0, 0, 0, false,Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH, 58, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 29, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 48, 0,rkp,rki,rkd, -12*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 168*sign, 37, 0, 0, 0, 0, 0,false,Section::JNONE},
                   // {0, Section::TRACER, Section::LENGTH, 50, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE, 50, 0,rkp,rki,rkd, +12*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 15*sign, 0, 0, 0, 0, 0, 0,false, Section::JNONE},
                         //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                    {12, Section::VIRTUAL, Section::TURNANGLE, 55, 0,  rkp2 ,rki2, rkd2, +8, 0 /*setparam*/, 0, -32*sign, 0, 0, _EDGE_L, Judge::UNUPDATE, -3*sign, 0, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp,rki,rkd, -15*sign, 0 /*setparam*/, 0, 0, 60*sign, 0, _EDGE_L, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0 , false, Section::JNONE},
                   // {0, Section::TRACER, Section::TURNANGLE, 55, 0,rkp,rki,rkd, -10, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 355, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp,rki,rkd, -15*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0,262 , 0, 0, 0, 0, 0, false,Section::JNONE},
                    {12, Section::VIRTUAL, Section::LENGTH, 55, 0,  rkp2 ,rki2, rkd2, 5, 0 /*setparam*/, 0, -40*sign, 0, 0, _EDGE_L, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , false, Section::JNONE},
                         //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {12, Section::WALKER, Section::BRIGHTNESS, 0, 0,  rkp2 ,rki2, rkd2, 0, 0 /*setparam*/, 0, 0, 40, 10*sign, _EDGE_L, Judge::UNUPDATE, 0, 0,  0.5, 0, 0, 0, 0 , false, Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH,  48, 0,rkp*1.5,rki*1.5,rkd*2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  48, 0,rkp*1.5,rki*1.5,rkd*2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 110, 0, 0, 0, 0, 0 , false,Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  50, 0,rkp*1.5,rki*1.5,rkd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 10*sign, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                          //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::TURNANGLE,  55, 0,rkp,rki,rkd, -20*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 86*sign, 0, 0, 0, 0, 0, 0 ,false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  55, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  55, 0,rkp,rki,rkd, -20*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 175*sign, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                         // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  65, 0,rkp,rki,rkd*1.2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 175, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::TURNANGLE,  60, 0,rkp,rki,rkd, 18*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, -85*sign, 0, 0, 0, 0, 0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  55, 0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 155, 0, 0, 0, 0, 0 ,false, Section::JNONE},
                       //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
  //finish
                    {0, Section::TRACER, Section::TURNANGLE,  35, -0.2,rkp,rki,rkd, +5*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, -30*sign, 0, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  30, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},


                       //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, false, Section::JNONE},

};

#if defined(MAKE_SIM)
wParam advance2022_b[50] = {

                    {0, Section::TRACER, Section::LENGTH, 100, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0,Section::JNONE},
                    {1, Section::TRACER, Section::TURNANGLE, 60, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    {2, Section::TRACER, Section::LENGTH, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 190, 0, 0, 0, 0, 0,Section::JNONE},
                    {3, Section::TRACER, Section::TURNANGLE, 55, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    {4, Section::TRACER, Section::LENGTH, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0,Section::JNONE},
                    {5, Section::TRACER, Section::TURNANGLE, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 70, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    {6, Section::TRACER, Section::LENGTH, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0,Section::JNONE},

                   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
#endif

#if defined(MAKE_RASPIKE)
wParam advance2022_L[50] = {
                   // {6, Section::WALKER, Section::COLOR, 40, -0.2,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, 0, 1.0, 1,false,Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH, 100, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE_L, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE_L, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {1, Section::TRACER, Section::TURNANGLE, 60, 0,rkp, rki, rkd, +15, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, -75, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {2, Section::TRACER, Section::LENGTH, 65, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 175, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {3, Section::TRACER, Section::TURNANGLE, 65, 0,rkp, rki, rkd, -20, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {4, Section::TRACER, Section::LENGTH, 65, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {5, Section::TRACER, Section::TURNANGLE, 65, 0,rkp, rki, rkd, -13, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 70, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {6, Section::TRACER, Section::COLOR, 35, -0.4,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0,false,Section::JNONE},
                    {6, Section::WALKER, Section::STOP, 40, -0.2,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, 0, 0.0, 1,false,Section::JNONE},

                   // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
wParam advance2022_R[50] = {

                    {0, Section::TRACER, Section::LENGTH, 100, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE_R, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0, false,Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH, 60, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE_R, Judge::UPDATE, 0, 95, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {1, Section::TRACER, Section::TURNANGLE, 60, 0,rkp, rki, rkd, +15*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, -75*sign, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {2, Section::TRACER, Section::LENGTH, 65, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 173, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {3, Section::TRACER, Section::TURNANGLE, 65, 0,rkp, rki, rkd, -20*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 85*sign, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {4, Section::TRACER, Section::LENGTH, 65, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {5, Section::TRACER, Section::TURNANGLE, 65, 0,rkp, rki, rkd, -13*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 70*sign, 0, 0, 0, 0, 0, 0,false,Section::JNONE},
                    {6, Section::TRACER, Section::COLOR, 35, -0.4,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15 ,0,false,Section::JNONE},
                    {6, Section::WALKER, Section::STOP, 40, -0.2,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, 0, 0.0, 1,false,Section::JNONE},

                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
#endif

#if 0
wParam advance2022[500] = {

                    {0, Section::TRACER, Section::LENGTH, 100, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0,Section::JNONE},
                    {1, Section::TRACER, Section::TURNANGLE, 60, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    {2, Section::TRACER, Section::LENGTH, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 190, 0, 0, 0, 0, 0,Section::JNONE},
                    {3, Section::TRACER, Section::TURNANGLE, 55, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    {4, Section::TRACER, Section::LENGTH, 72, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 290, 0, 0, 0, 0, 0,Section::JNONE},
                       //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                    {5, Section::TRACER, Section::LENGTH, 30, 0,32, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 305, 0, 0, 0, 0, 0,Section::JNONE},
                          // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {6, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, GREEN, 0.45, 0 , 0,Section::JNONE},
                    {7, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0,Section::JNONE},
                   {8, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5,Section::JNONE}, 
                    {9, Section::WALKER, Section::TURNANGLE, 6, 0,25, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 3, -30, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                    {10, Section::TRACER, Section::LENGTH, 35, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 13, 0, 0, 0, 0, 0,Section::JNONE},
                    {11, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, RED, 0.4, 0 , 0,Section::JNONE},
                    //{9, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0,Section::JNONE},
                 //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    //ブロックキャッチ終了
                    //ダブルアップへ

                 {12, Section::VIRTUAL, Section::TURNANGLE, 55, 0, rkp, rki, rkd, 0.09, 1 /*setparam*/, 0, 16, 0, 0, _EDGE, Judge::UPDATE, 91, 0, 0, 0, 0, 0, 0 , 0},
                    {13, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 90, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0.2, 0, 0, 0.45, 0 , 0},
                    {14, Section::VIRTUAL, Section::TURNANGLE, 50, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 0, 30, 0, 0, _EDGE, Judge::UNUPDATE, 100, 0, 0, 0, 0, 0, 0 , 0},
                    {15, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,15,rki2,rkd2, 0, 0 /*setparam*/, 100, 0, 20, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0.6, 0, 0, 0.45, 0 , 0},
                    {16, Section::TRACER, Section::LENGTH, 45, 0,rkp,rki*0.5, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {17, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                    {18, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},

                //   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 


                    {19, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 23, 0, 0, 0, 0, 0},
                    {20, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄色
                    {21, Section::WALKER, Section::LENGTH, 0, 0,0, 10.0, 5.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {22, Section::TRACER, Section::LENGTH, normal_spd, 0,30, 10.0, 5.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0,25 , 0, 0, 0, 0, 0},
                    {23, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄色
                    {24, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 0, -14, 0, 0, _EDGE, Judge::UPDATE, -80, 0, 0, 0, 0, 0, 0 , 0},
                    {25, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {26, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 60, _EDGE, Judge::UPDATE, -10, 0, 0, 0, 60, 0.35, 0 , 0}, 
                    {27, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 50, 0, _EDGE, Judge::UPDATE, 0, 6, 0, 0, 60, 0.35, 0 , 0}, 
                   {28, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {29, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -50, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 60, 0.35, 0 , 0}, 
                    {30, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -50, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -50, 0, _EDGE, Judge::UNUPDATE, 0, -9, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 50, _EDGE, Judge::UPDATE, -48, 0, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE, Judge::UNUPDATE, 0, 2, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0,rkp2,rki2,rkd2, 0, 0 /*setparam*/, -50, 0, 20, 0, _EDGE, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0.35, 0 , 0},
//一つ目
                    {0, Section::TRACER, Section::LENGTH, 40, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, 0, RED, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 50, _EDGE, Judge::UPDATE, -44, 0, 0, 0, 0, 0.35, 0 , 0}, //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, -45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,0,0,0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, RED, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0,0,0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
    //一つ目運搬
                    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, -11, 0, 0, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, -10.5, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0}, //緑
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
  // 運搬完了
  //二つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-40, 0, _EDGE, Judge::UNUPDATE, 0, -3.0, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, -8.5, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 50, _EDGE, Judge::UPDATE, -45, 0, 0, 0, 0,0, 0 , 0}, //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, -45, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
    //二つ目運搬運搬
                      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0 , 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, -8.0, 0, 0, _EDGE, Judge::UPDATE, -44, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, -10.5, 0, 0, _EDGE, Judge::UPDATE, -91, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, RED, 0.35, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,rkp, rki, rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
                     {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
// 運搬完了
 //３つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-20, 0, _EDGE, Judge::UPDATE, 0, -3.0, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, 13, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -9.5, 0, 0, _EDGE, Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 13, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.30, 0 , 0}, //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 25, _EDGE, Judge::UPDATE, -43, 0, 0, 0, 0,0, 0 , 0}, //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 23, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -43, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.30, 0 , 0},  //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0 , 0},
    //３つ目運搬運搬
                    {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -7, 0, 0, _EDGE, Judge::UPDATE, -43, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,35, 20.0, 2.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 3.5, 0, 0, 0, 0, 0},
                    //スロー左投げ
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -40, _EDGE, Judge::UPDATE, 30, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,20}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 25, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,2}, 

// 運搬完了
 //４つ目
                    {0, Section::TRACER, Section::LENGTH, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0,6, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -9, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,35, 10.0, 2.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, RED, 0.35, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 25, _EDGE, Judge::UPDATE, -130, 0, 0, 0, 0,0, 0 , 0},  //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -130, 0, 25, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄

                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, +9.5, 0, 0, _EDGE, Judge::UPDATE, +44, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,35, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0},  //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 28, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0},  //緑
                     {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 

// 運搬完了
 //５つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-20, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, 12, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 8, 0, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 4.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -20, _EDGE, Judge::UPDATE, 44, 0, 0, 0, 0,0, 0 , 0}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 25, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0},  //青
                  //スロー　右投げ　
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,10, 0, _EDGE, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0 , 0},
                  // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UPDATE, +5, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,25}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 35, _EDGE, Judge::UNUPDATE, -15, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,20}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
              // 運搬完了
 //６つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,10, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -25, _EDGE, Judge::UNUPDATE, 85, 0, 0, 0, 0,0, 0 , 0},  //旋回
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 25, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, RED, 0.35, 0 , 0},  //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0},
                 //６つ目運搬    
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -10, 0, 0, _EDGE, Judge::UPDATE, -44, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, RED, 0.35, 0 , 0},  //赤
                     {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
              // 運搬完了
 //７つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-20, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, 12, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, +9, 0, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,20, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 10, 0, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 15, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,10, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -25, _EDGE, Judge::UPDATE, 44, 0, 0, 0, 0,0, 0 , 0},  //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 44, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0},  //緑
    //７つ目運搬
                    {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 10, 0, 0, _EDGE, Judge::UPDATE, 44, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0},  //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,0, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0},  //青
                     {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
// 運搬完了
 //８つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-20, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, 12, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0,-9, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 4.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0,-8, 0, 0, !_EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 4.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                   
                    {0, Section::WALKER, Section::COLOR, 0, 0,0, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0},  //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,30, 0, _EDGE, Judge::UPDATE, 0, 6, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, +25, _EDGE, Judge::UPDATE, -44, 0, 0, 0, 0,0, 0 , 0},  //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -44, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0},  //緑
    //８つ目運搬
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,30, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0 , 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -10, 0, 0, _EDGE, Judge::UPDATE, -43, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,20, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,0, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
                     {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 

                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
#endif

wParam base2022[100] = {
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 30.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 216, 0, 0, 0, 0, 0},
                   // {0, Section::TRACER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0,5, 1.0, 0.0, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UNUPDATE, 0, 219, 0, 0, 0, 0, 0},
                    //{0, Section::TRACER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 530, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UNUPDATE, 0, 545, 0, 0, 0, 0, 0},
                    //{0, Section::TRACER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 660, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 700, 0, 0, 0, 0, 0},
                   // {0, Section::TRACER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0,35, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1100, 0, 0, 0, 0, 0},
                   


                    {0, Section::TRACER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};


  wParam b[100] = {   
  
                      {0, Section::TRACER, Section::LENGTH, 25, 0, 10, 0, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 10, 0, 0.1, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 65, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.8, 0.1, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 100, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 20, 0.8, 0.1, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.8, 0.1, 1/1.3,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0.8, 0.1, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 45, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.8, 0.2, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.9, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 55, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1.1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                       {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 63, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 70, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 40, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 30, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0, 0.8, 1/0.85,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 50, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 35, 0, 30, 0, 0.8, 1/0.7,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 60, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 25, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 110, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 40, 0, 20, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0, 0.8, 1/1.5,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0, 0.8, 1/1.6,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0,0,false},
                      
                      {0, Section::TRACER, Section::LENGTH, 42, 0, 30, 0, 0.8, 1,1 /*setparam*/, 0, 0, 0, 30, true, Judge::UPDATE, 0,85, 0, 0, 0, 0,0,false},
                      
    
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0,0,false}};

#if 1
wParam test[80] = {
    //   {0, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::JNONE},
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, 60, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    //    // {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp, lvki, lvkd, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, block_out_len, 0, 0, 0, 0.40, 1 , 0,Section::COLORSTATUS},
    // {100, Section::WALKER, Section::STOP, 0, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 10 , 0,Section::COLORSTATUS},
    // {0, Section::ARM, Section::ARMANGLE, 0, 0, -90, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    // {0, Section::ARM, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 50, 0, 0, 0, 0, 0, 2 , 0,Section::JNONE},
    //                 {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                   // {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 10, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 80, false,Judge::UPDATE, -90, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},
                   // {0, Section::VIRTUAL2, Section::LENGTH,  0, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, -90, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 1000, 0, 0, 0, 0.0, 0 , false, Section::JNONE},

                   //   {12, Section::VIRTUAL, Section::LENGTH, 60, 0, rkp2,rki2,rkd2, -0*sign, 0 /*setparam*/, 0, +40*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0, 0 ,false,Section::JNONE},

              //  {0, Section::WALKER, Section::STOP, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0,1000,false},
                {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 78, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 285, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign_r,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 315, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 500, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign_r,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 530, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 557, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::COLOR, 75, -0.4, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,  BLUE_H, 0.10,0,false},
                   // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {12, Section::VIRTUAL, Section::LENGTH, 74, 0,  rkp2 ,rki2, rkd2, +10*sign_r, 0 /*setparam*/, 0, -54*sign_r, 0, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd*1.2, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0,0,false},

                    //マーカー→小円
                    {0, Section::TRACER, Section::COLOR,  65, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 55, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0, 0, 0,0,false},
                   // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},


                    {12, Section::VIRTUAL, Section::LENGTH, 60, 0,  rkp2 ,rki2, rkd2, +10*sign_r, 0 /*setparam*/, 0, -45*sign_r, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 24, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                      {0, Section::TRACER, Section::LENGTH, 60, 0, rkp,rki,rkd, -20*sign_r,1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 50, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 65, 0, rkp,rki,rkd, -20*sign_r,1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 172, 0, 0, 0, 0,0,false},
                    //小円→大円
                    {0, Section::TRACER, Section::COLOR,  65, -0.4,rkp,rki,rkd, -20*sign_r, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.13, 0 , false, Section::JNONE},
                  // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                      {0, Section::TRACER, Section::LENGTH, 55, -0.4, rkp*1.1,rki,rkd*1.2, 0*sign_r,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 20, 0, 0, 0, 0,0,false},
//                    {12, Section::VIRTUAL, Section::LENGTH, 70, 0,  rkp2 ,rki2, rkd2, +10*sign_r, 0 /*setparam*/, 0, -48, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 35, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 53, 0, rkp,rki,rkd*1.2, +5*sign_r,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0,0,false},
//                   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, +10*sign_r,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 158, 0, 0, 0, 0,0,false},
//                  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    //大円→　出口 ショートカット
                    {12, Section::VIRTUAL, Section::LENGTH, 70, 0,  rkp2 ,rki2, rkd2, -7*sign_r, 0 /*setparam*/, 0, +40*sign_r, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 22, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    {0, Section::VIRTUAL2, Section::LENGTH,  70, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 0*sign_r, 0, 0, !_EDGE_R, Judge::UPDATEALL, 0, 36, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
                    {12, Section::VIRTUAL, Section::BRIGHTNESS, 65, 0,  rkp2 ,rki2, rkd2, +7*sign_r, 0 /*setparam*/, 0, -43*sign_r, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 ,false,Section::JNONE},
                     {0, Section::TRACER, Section::LENGTH, 38, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0, 0, 0,0,false},
                     {0, Section::TRACER, Section::LENGTH, 45, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 8, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 70, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 52, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::COLOR,  40, 0,rkp2,rki2,rkd2/2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, RED_H, 0.15, 0 , false, Section::JNONE},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};

wParam test_L[80] = {
                   //   {12, Section::VIRTUAL, Section::LENGTH, 60, 0, rkp2,rki2,rkd2, -0*sign, 0 /*setparam*/, 0, +40*sign, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0, 0 ,false,Section::JNONE},

              //  {0, Section::WALKER, Section::STOP, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 5, 0, 0, 0, 0,1000,false},
                {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 78, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 285, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 315, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 500, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 530, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 557, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::COLOR, 75, -0.4, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 0, 0, 0,  BLUE_H, 0.10,0,false},
                   // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {12, Section::VIRTUAL, Section::LENGTH, 74, 0,  rkp2 ,rki2, rkd2, +10*sign, 0 /*setparam*/, 0, -56*sign, 0, 0, _EDGE_L, Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd*1.2, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0,0,false},

                    //マーカー→小円
                    {0, Section::TRACER, Section::COLOR,  65, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 55, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 8, 0, 0, 0, 0,0,false},
                   // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},


                    {12, Section::VIRTUAL, Section::LENGTH, 60, 0,  rkp2 ,rki2, rkd2, +10*sign, 0 /*setparam*/, 0, -45*sign, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 24, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                      {0, Section::TRACER, Section::LENGTH, 60, 0, rkp,rki,rkd, -20*sign,1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 50, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 65, 0, rkp,rki,rkd, -20*sign,1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 172, 0, 0, 0, 0,0,false},
                    //小円→大円
                    {0, Section::TRACER, Section::COLOR,  65, -0.4,rkp,rki,rkd, -20*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.13, 0 , false, Section::JNONE},
                  // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

                      {0, Section::TRACER, Section::LENGTH, 55, -0.4, rkp*1.1,rki,rkd*1.1, 0*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 20, 0, 0, 0, 0,0,false},
//                    {12, Section::VIRTUAL, Section::LENGTH, 70, 0,  rkp2 ,rki2, rkd2, +10*sign, 0 /*setparam*/, 0, -48, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 35, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                      {0, Section::TRACER, Section::LENGTH, 55, 0, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_L, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0,0,false},
//                   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                      {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_L, Judge::UNUPDATE, 0, 160, 0, 0, 0, 0,0,false},
//                  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    //大円→　出口 ショートカット
                    {12, Section::VIRTUAL, Section::LENGTH, 70, 0,  rkp2 ,rki2, rkd2, -7*sign, 0 /*setparam*/, 0, +40*sign, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 22, 0, 0, 0, 0, 0 ,false,Section::JNONE},
                    {0, Section::VIRTUAL2, Section::LENGTH,  70, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 0*sign, 0, 0, !_EDGE_L, Judge::UPDATEALL, 0, 30, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
                    {12, Section::VIRTUAL, Section::BRIGHTNESS, 65, 0,  rkp2 ,rki2, rkd2, +7*sign, 0 /*setparam*/, 0, -43*sign, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 0, -0.5, 0, 0, 0, 0 ,false,Section::JNONE},
                     {0, Section::TRACER, Section::LENGTH, 38, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 12, 0, 0, 0, 0,0,false},
                     {0, Section::TRACER, Section::LENGTH, 45, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UPDATE, 0, 8, 0, 0, 0, 0,0,false},
                      {0, Section::TRACER, Section::LENGTH, 70, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_L, Judge::UNUPDATE, 0, 58, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::COLOR,  40, 0,rkp2,rki2,rkd2/2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_L, Judge::UPDATE, 0, 0, 0, 0, RED_H, 0.15, 0 , false, Section::JNONE},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};

// wParam test_L[80] = {
//               //  {0, Section::WALKER, Section::STOP, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,1000,false},
//                 {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 78, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 285, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 315, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 500, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, +25*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 530, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 555, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::COLOR, 75, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 0, 0, 0,  BLUE_H, 0.15,0,false},
//                     {12, Section::VIRTUAL, Section::LENGTH, 74, 0,  rkp2 ,rki2, rkd2, +10*sign, 0 /*setparam*/, 0, -55*sign, 0, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0 ,false,Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 74, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0,0,false},

//                     //マーカー→小円
//                     {0, Section::TRACER, Section::COLOR,  65, -0.4,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 60, 0, rkp,rki,rkd, 0,0 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                                       {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
//                     {12, Section::VIRTUAL, Section::LENGTH, 65, 0,  rkp2 ,rki2, rkd2, +0, 0 /*setparam*/, 0, -55*sign, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 30*sign, 0, 0, 0, 0, 0 ,false,Section::JNONE},
    
                      
//                       {0, Section::TRACER, Section::LENGTH, 65, 0, rkp,rki,rkd, -20*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UNUPDATE, 0, 175, 0, 0, 0, 0,0,false},
//                     //小円→大円
//                     {0, Section::TRACER, Section::COLOR,  70, -0.4,rkp,rki,rkd, -20*sign, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 70, 0, rkp,rki,rkd, -20*sign,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 28, 0, 0, 0, 0,0,false},
//                     {12, Section::VIRTUAL, Section::LENGTH, 70, 0,  rkp2 ,rki2, rkd2, +10*sign, 0 /*setparam*/, 0, -48*sign, 0, 0, _EDGE_R, Judge::UNUPDATE, 0, 35, 0, 0, 0, 0, 0 ,false,Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 70, 0, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 260, 0, 0, 0, 0,0,false},
//                     //大円→　出口
//                     {0, Section::TRACER, Section::COLOR,  75, -0.4,rkp,rki,rkd, +10*sign, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 60, +0.1, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UPDATE, 0, 20, 0, 0, 0, 0,0,false},
//                      //{0, Section::TRACER, Section::LENGTH, 60, -0.5, rkp,rki,rkd, +10,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 40, 0, 0, 0, 0,0,false},                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},


//                       {0, Section::TRACER, Section::LENGTH, 60, 0, rkp,rki,rkd, +10*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0,0,false},
//                     {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 60, 0, _EDGE, Judge::UNUPDATE, 0, 160, 0, 0, 0, 0, 0 , 0},
//                     {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

//                       {0, Section::TRACER, Section::LENGTH, 50, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 205, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 50, 0, rkp,rki,rkd, +25*sign,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 235, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::LENGTH, 50, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, !_EDGE_R, Judge::UNUPDATE, 0, 415, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  45, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2*sign, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, RED_H, 0.15, 0 , false, Section::JNONE},

// // 難所２
//                         {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 10, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 85, false,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//                     {0, Section::VIRTUAL2, Section::LENGTH,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, -90, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 36, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
//                         {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, -85, false,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//                     {0, Section::VIRTUAL2, Section::BRIGHTNESS,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 3, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
//                     {0, Section::VIRTUAL2, Section::LENGTH,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 4, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
//                         {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 10, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 85, false,Judge::UNUPDATE, -180, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 55, 0, ckp,cki,ckd,  0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 3, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, YELLOW_H, 0.15, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, -43, 0 /*setparam*/, 0, 10, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    //{0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -30, 0 /*setparam*/, 0, 0, 54, -43, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},


//                       {0, Section::TRACER, Section::LENGTH, 50, 0, ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, YELLOW_H, 0.15, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, -43, 0 /*setparam*/, 0, 10, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    //{0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -40, 0 /*setparam*/, 0, 0, 54, -43, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//                       {0, Section::TRACER, Section::LENGTH, 50, 0, ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, YELLOW_H, 0.15, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, -43, 0 /*setparam*/, 0, 10, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    //{0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -40, 0 /*setparam*/,0, 00 54, -45, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//                       {0, Section::TRACER, Section::LENGTH, 50, 0, ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0, YELLOW_H, 0.15, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, +50, 0 /*setparam*/, 0, -10, 0, 0, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                   // {0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, +40, 0 /*setparam*/, 0, -0, 54,43, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//                       {0, Section::TRACER, Section::LENGTH, 50, 0, ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, RED_H, 0.15, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, +50, 0 /*setparam*/, 0, -10, 0, 0, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    //{0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, +40, 0 /*setparam*/, 0, -0, 54,43, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},

//                       {0, Section::TRACER, Section::LENGTH, 50, 0, ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, RED_H, 0.15, 0 , false, Section::JNONE},

//                     {0, Section::VIRTUAL2, Section::LENGTH,  60, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 12, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
//                       {0, Section::TRACER, Section::LENGTH, 60, 0,ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATE, 0, 15, 0, 0, 0, 0,0,false},
//                     {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},

//                    //{0, Section::VIRTUAL, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -40, 0 /*setparam*/, 0, 11, 0, 0, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                   // {0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -40, 0 /*setparam*/, 0, 0, 52, -43, _EDGE, Judge::UPDATEALL, 89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                   // {0, Section::WALKER, Section::TURNANGLE, 45, 0,rkp2, rki2,rkd2, -40, 0 /*setparam*/, 0, 0, 52, 43, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, -50, 0 /*setparam*/, 0, +10, 0, 0, _EDGE, Judge::UPDATEALL, +89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE, 54, 0,rkp2, rki2,rkd2, +50, 0 /*setparam*/, 0, -10, 0, 0, _EDGE, Judge::UPDATEALL, -89, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                     {0, Section::VIRTUAL2, Section::BRIGHTNESS,  60, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 3, 0, 0, 0, 0.0, 0 , false, Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE,65, 0,rkp2, rki2,rkd2, +40, 0 /*setparam*/, 0, -30, 0, 0, _EDGE, Judge::UPDATEALL, -45, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                    {0, Section::VIRTUAL, Section::TURNANGLE,65, 0,rkp2, rki2,rkd2, -38, 0 /*setparam*/, 0, +30, 0, 0, _EDGE, Judge::UPDATEALL, +70, 0, 0, 0, 0, 0, 0 , 0,Section::JNONE},
//                     {0, Section::VIRTUAL2, Section::BRIGHTNESS,  60, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, +110, 0, 0, 0, !_EDGE_R, Judge::UNUPDATE, 0, 3, 0, 0, 0, 0.0, 0 , false, Section::JNONE},

//                       {0, Section::TRACER, Section::LENGTH, 55, 0,ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 30, 0, 0, 0, 0,0,false},
//                       {0, Section::TRACER, Section::COLOR, 55, 0,ckp,cki,ckd, 0,1 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 0, 0, 0,  BLUE_H, 0.15,0,false},

//                     {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},



//                    //{7, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 5, -50, _EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0,Section::JNONE},
//                   //  {0, Section::TURN, Section::LENGTH, 100, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, -5, 30, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0,Section::JNONE},
//                   //  {7, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0,Section::JNONE},
//                      {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UPDATE, -90, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, -90, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UNUPDATE, -180, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, -180, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UNUPDATE, -270, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, -270, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, _EDGE, Judge::UNUPDATE, -360, 0.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},
//                      {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,rvkp, rvki, rvkd, 0, 0 /*setparam*/, -360, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10.0, 0, 0, 0, 0.35, 0 , 0,Section::JNONE},

//                     {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},

//                    // {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATEALL, 0, 10000, 0, 0, 0, 0.35, 0 , 0},
//                    {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

// };

wParam test2019[80] = {
                {0, Section::TRACER, Section::LENGTH, 75, 0, rkp,rki,rkd, 0, 1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 5, 0, 0, 0, 0,0,false},
                {0, Section::TRACER, Section::LENGTH, 73, 0, rkp,rki,rkd, 0,1 /*setparam*/, 0, 0, 0, 30, _EDGE_R, Judge::UPDATE, 0, 1200, 0, 0, 0, 0,0,false},
                    {0, Section::VIRTUAL2, Section::COLOR,  55, 0,rkp2,rki2,rkd2, +0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, YELLOW_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 10, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 85, false,Judge::UNUPDATE, -170, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                   
                {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
#endif
//  wParam *array[10] = {base, b};  // Lコース　S字スキップ
//  wParam *array[10] = {base_sc2_r, b};  // Rコース　ショートカットテスト
//  wParam *array[10] = {base_sc3_r, b};  // Rコース 全速ショートカット
//  wParam *array[10] = {base_sc2, b};  // Lコース　S字スキップ
//wParam *array[10] = {base_sc, b};  // Lコース　S字バンプ越え
//  wParam *array[10] = {outer, b};
// right = 0 , left=1
#if defined(PRIMARY)
  wParam *array[10] = {test, test_L};
  //wParam *array[10] = {fin_Pri_R, fin_Pri_L};
#else
  wParam *array[10] = {advance2022_R, advance2022_L};
  //wParam *array[10] = {fin_R, fin_L};
#endif

int mIdx;

};

#endif
