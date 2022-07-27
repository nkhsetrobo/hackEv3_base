#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"


typedef struct _Param1
{

  int flag;
  Section::WALKER_NO walk;
  Section::JUDGE_NO judge;
  double speed;
  double target;
  double kp;
  double ki;
  double kd;
  double angleTarget;
  double anglekp;


  double absangle;
  double round;
  double forward;
  double turn;
  bool _EDGE; //true=left,false=right

  Judge::JUDGE_MODE jflag;

  double fangle;
  double flength;
  double bright1;
  double bright2;
  double color1;
  double color2;
  double count;
  bool vangle;

} wParam;

class SpeedSectionManager : public SectionManager
{
public:
  SpeedSectionManager();
  void init();

protected:
private:


  double YELLOW = 55;
  double GREEN = 138;
  double RED = 0;
  double BLUE = 207;
  double bspd = 11.5;
  double bspd2 = bspd*0.6;
  double bkp = 36;

  int n;

  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, iの値, dの値, 0, 0 ,
  ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
  //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}

  //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
  // tracer->setParam(30,0,30,0.2,0.1)
  //Virtual->setParam(20,2,0.2,0,1,1)
  //Walker->setCommand(0,10)

#if defined(MAKE_RIGHT)
  const int _EDGE = LineTracer::RIGHTEDGE;
  const float sign=-1;
#else
  const int _EDGE = LineTracer::LEFTEDGE;
  const float sign=1;
#endif

wParam entry2022[100] = {
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 650, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 665, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 120, 0.35, 0 , 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 5, -15, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 3, 0,40, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 16, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 3, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0.35, 0 , 0},
                    {0, Section::VIRTUAL2, Section::SONER, 3, 0,60, 10.0, 3.0, 0, 0 /*setparam*/, -0.5, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 32, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};

float normal_spd=32;
wParam advance2022[500] = {
                    {0, Section::TRACER, Section::LENGTH, 30, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0,40, 30.0, 8.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 630, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,35, 30.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 645, 0, 0, 0, 0, 0},
                          // {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 100000, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 115, 0.35, 0 , 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::WALKER, Section::TURNANGLE, 6, 0,25, 5.0, 2.0, 0, 0 /*setparam*/, 0, 8, 10, -18, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 15, 0,30, 10.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATEALL, 0, 14, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, 0.35, 0 , 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0.35, 0 , 0},
                 //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    //ブロックキャッチ終了
                    //ダブルアップへ
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 11, 0, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 25, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 90, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0.2, 0, 0, 0.35, 0 , 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,30, 20.0, 2.0, 0, 0 /*setparam*/, 0, 30, 0, 0, _EDGE, Judge::UNUPDATE, 98, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 18, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 108, 0, 20, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0.6, 0, 0, 0.35, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,35, 5.0, 2.6, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},

                //   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 


                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,25, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 23, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄色
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 10.0, 5.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 5.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0,25 , 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄色
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -16, 0, 0, _EDGE, Judge::UPDATE, -80, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,30, 10.0, 5.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 50, _EDGE, Judge::UPDATE, -10, 0, 0, 0, 60, 0.35, 0 , 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -30, 0, _EDGE, Judge::UPDATE, 0, -3, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, -30, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, -30, 0, _EDGE, Judge::UNUPDATE, 0, -7, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 30, _EDGE, Judge::UPDATE, -48, 0, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UNUPDATE, 0, 2, 0, 0, 60, 0.35, 0 , 0}, 
                    {0, Section::VIRTUAL2, Section::BRIGHTNESS, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -50, 0, 20, 0, _EDGE, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0.35, 0 , 0},
//一つ目
                    {0, Section::TRACER, Section::LENGTH, 15, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, 0, RED, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 25, _EDGE, Judge::UPDATE, -43, 0, 0, 0, 0, 0.35, 0 , 0}, //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -43, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATEALL, 0, 0, 0, 0, 0, RED, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0 , 0},
    //一つ目運搬
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -8, 0, 0, _EDGE, Judge::UPDATE, -42, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 15, 0,32, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -10.5, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 25, 0,32, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, GREEN, 0.35, 0 , 0}, //緑
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,10}, 
  // 運搬完了
  //二つ目
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,-20, 0, _EDGE, Judge::UPDATE, 0, -3.0, 0, 0, 0, 0, 0 , 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 00, 0, 0, 0,0, 0,5}, 
                    {0, Section::VIRTUAL, Section::TURNANGLE, 12, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -8.5, 0, 0, _EDGE, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 15, 0,35, 10.0, 2.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0}, //黄
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::TURNANGLE, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 0, 20, _EDGE, Judge::UPDATE, -43, 0, 0, 0, 0,0, 0 , 0}, //旋回
                    {0, Section::VIRTUAL2, Section::LENGTH, 20, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, -43, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0 , 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, YELLOW, 0.35, 0 , 0},  //黄
    //二つ目運搬運搬
                      {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0 , 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 12, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -8.0, 0, 0, _EDGE, Judge::UPDATE, -44, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0,35, 10.0, 2.5, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, -10.5, 0, 0, _EDGE, Judge::UPDATE, -91, 0, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, RED, 0.35, 0 , 0}, //赤
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, normal_spd, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, normal_spd, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
                    {0, Section::WALKER, Section::LENGTH, 0, 0,35, 20.0, 3.0, 0, 0 /*setparam*/, 0, 0,normal_spd, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,30, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::COLOR, 0, 0,35, 20.0, 2.0, 0, 0 /*setparam*/, 0, 0, 15, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE, 0.35, 0 , 0}, //青
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

  void setWalker(Section *sc);
  void setJudge(Section *sc);

//  wParam *array[10] = {base, b};  // Lコース　S字スキップ
//  wParam *array[10] = {base_sc2_r, b};  // Rコース　ショートカットテスト
//  wParam *array[10] = {base_sc3_r, b};  // Rコース 全速ショートカット
//  wParam *array[10] = {base_sc2, b};  // Lコース　S字スキップ
//wParam *array[10] = {base_sc, b};  // Lコース　S字バンプ越え
//  wParam *array[10] = {outer, b};
  wParam *array[10] = {advance2022, b};
//  wParam *array[10] = {outer_adv3, b}; //コーナーオブジェクト乗り越え
  wParam *wp;
};
#endif
