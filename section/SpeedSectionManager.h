#ifndef _SPEED_SECTION_MANAGER_H_
#define _SPEED_SECTION_MANAGER_H_
#include "SectionManager.h"

typedef struct _Param1
{

  int flag;
  Section::WALKER_NO walk;
  Section::JUDGE_NO judge;
  float speed;
  float target;
  float kp;
  float ki;
  float kd;
  float angleTarget;
  float anglekp;

  float absangle;
  float round;

  float forward;
  float turn;

  bool _EDGE; //true=left,false=right

  Judge::JUDGE_MODE jflag;

  float fangle;
  float flength;
  float bright1;
  float bright2;
  float color1;
  float color2;
  float count;
  bool vangle;

} wParam;

class SpeedSectionManager : public SectionManager
{
public:
  SpeedSectionManager();
  void init();

protected:
private:
  int n;

  //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, iの値, dの値, 0, 0 ,
  ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
  //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}

  //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
  // tracer->setParam(30,0,30,0.2,0.1)
  //Virtual->setParam(20,2,0.2,0,1,1)
  //Walker->setCommand(0,10)

#if defined(MAKE_RIGHT)
  const int _EDGE = LineTracer::LEFTEDGE;
#else
  const int _EDGE = LineTracer::RIGHTEDGE;
#endif

    //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
    ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか,
    //1の時現在地を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値,止まる秒数}
    
    
    //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
    // tracer->setParam(30,0,30,0.2,0.1)
    //Virtual->setParam(20,2,0.2,0,1,1)
    //Walker->setCommand(0,10)
    

   wParam sirakin[100] = 
                   //スタート！
                   {{0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 49, 0, 0, true, Judge::UPDATE, 90, -0.5, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 90, 0, 0, 0, true, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 17, 0, 0, true, Judge::UPDATE, 160, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 35, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 160, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},

                   {0, Section::TRACER, Section::LENGTH, 30, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 117, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -110, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 27, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -110, 0, 0, 0, true, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 16, 0, 0, true, Judge::UPDATE, 103, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 27, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 103, 0, 0, 0, true, Judge::UPDATE, 0, 45, -0.5, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0},

                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -23, 0, 0, true, Judge::UPDATE, -170, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -168, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},

                   {0, Section::TRACER, Section::LENGTH, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 500, 0, 0, 0, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam ee[100] =
                   //黄色判定
                   {//{0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 60, 0, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UPDATE, -68, 10, -0.5, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam kennsyou_right[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, -56, 0, true, Judge::UNUPDATE, -90, 100, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL2, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, -90, 100, 0, 0, 0, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam QQQ[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -90, 0, 0, 0, true, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},

                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam hazero[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::LENGTH, 36.5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 520, 0, 0, 60, 0.5, 0},
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 80, 0, 0, 60, 0.5, 0},
                   {0, Section::TRACER, Section::LENGTH, 36.5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 520, 0, 0, 60, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam dynamic_eh[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 25, 0, true, Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //右に90°曲がる
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -13, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 10, 0, 0, true, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 7, 0, 0, true, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam dynamic_ee[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //右に90°曲がる
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   
   wParam dynamic_eie[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -11, 0, 0, true, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -4, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -37, 0, 0, 0, 0, 0},
                   //青色サークル判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

   wParam dynamic_ef[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 45, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

   wParam dynamic_f[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 45, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
                  
   wParam dynamic_eg[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   
   wParam anzen_egg[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

   
   wParam anzen_eg[100]  = 
                   //赤色サークル判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7, 0, 0, 220, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
   wParam bbb[100] = //スピードコース
                  //スタート！
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   //{0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 46, 0, 0, true, Judge::UPDATE, 88, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 88, 0, 0, 0, true, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 47, 0, 0, true, Judge::UPDATE, 81, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 84, 0, 0, 0, true, Judge::UPDATE, 0, 138, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 10.5, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 10.5, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -55, 0, 0, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 100, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -5, 0, 0, true, Judge::UPDATE, -18, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -33, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //すすむ
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                  
                   
                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左コース========================================================================================================================================
//==================================================================================================================================================



wParam opp[100] = 
                  //スピードコース
                  //スタート！
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 165, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 46, 0, 0, true, Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 87, 0, 0, 0, true, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 47, 0, 0, true, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 85, 0, 0, 0, true, Judge::UPDATE, 0, 136, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 12.5, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 12.5, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -55, 0, 0, false, Judge::UPDATE, 0, 37, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 100, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -4, 0, 0, true, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   //{0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 33, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 50},
                    //置いた後下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   //{0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -3.3, 0, 0, true, Judge::UPDATE, -75, 0, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7.5, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -20, 0, true, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //すすむ
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                    //ストップ
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

wParam bb[100] = 
                  //スピードコース
                  //スタート！
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 165, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 46, 0, 0, true, Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 87, 0, 0, 0, true, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 47, 0, 0, true, Judge::UPDATE, 84, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 85, 0, 0, 0, true, Judge::UPDATE, 0, 136, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 11.5, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 11.5, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -55, 0, 0, false, Judge::UPDATE, 0, 37, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 100, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -5, 0, 0, true, Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -33, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //すすむ
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                    //ストップ
                    //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

   wParam b[100] = 
                  //スピードコース
                  //スタート！
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   //{0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 46, 0, 0, true, Judge::UPDATE, 88, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 88, 0, 0, 0, true, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 52, 0, 0, true, Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 86, 0, 0, 0, true, Judge::UPDATE, 0, 130, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 12, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 12, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -52, 0, 0, false, Judge::UPDATE, 0, 40, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 100, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -5, 0, 0, true, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   //下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //すすむ
                   {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

      

  
//右斜め前において戻る・
   wParam c[100] =                 
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -23, 0, 0, true, Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -19, 0, 0, true, Judge::UPDATE, 55, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -11, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左斜め前において戻る・
   wParam d[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 7, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 24, 0, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},

                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, -48, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -13, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//右に90°曲がる
   wParam e[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//左に90°曲がる・
   wParam f[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 45, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// サークル突破・
   wParam g[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// グイーン左
   wParam h[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 10, 0, 0, true, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 7, 0, 0, true, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// グイーン右
   wParam i[100] =
                   //入れる処理
                   //赤判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -11, 0, 0, true, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -4, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -37, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//180°旋回・
   wParam j[100] =
                  //少し進む
                  {{0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 350, 0.5, 0},
                  //180°旋回
                  {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -3, 0, 0, true, Judge::UPDATE, -145, 0, 0, 0, 0, 0, 0},
                  //旋回後のライントレース
                  {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                  //ストップ
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                  {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};


//決め打ち
   wParam dangerous[100] =

                  //スピードコース
                  //スタート！
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 165, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 46, 0, 0, true, Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 87, 0, 0, 0, true, Judge::UPDATE, 0, 42, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 47, 0, 0, true, Judge::UPDATE, 84, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 85, 0, 0, 0, true, Judge::UPDATE, 0, 136, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 11.5, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 11.5, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -55, 0, 0, false, Judge::UPDATE, 0, 37, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 100, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -2, 0, 0, true, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //一旦止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},

                  //遊び
                   //黄色
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, 70, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 15, 0, true, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 280, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 50},
                   //青
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 15, 0, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 1, 0, 0, true, Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0},
                   //赤M
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 25, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 3, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   // サークル突破
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, true, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   
                   //左斜め前において戻る

                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0},

                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 15, 0, 0, true, Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 210, 0.5, 0},
                   //左に90°曲がる
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 10, 0, 0, true, Judge::UPDATE, 50, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 210, 0.5, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -22, 0, 0, true, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -16, 0, 0, true, Judge::UPDATE, 45, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 210, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, true, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, true, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -11, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //グイーン左
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 10, 0, 0, true, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 7, 0, 0, true, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -30, 0, true, Judge::UPDATE, 0, -33, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},

                  //ストップ
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                  {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

   wParam zzz[100]=
                   {{0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //右に90°曲がる
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -13, 0, 0, true, Judge::UNUPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 350, 0, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UNUPDATE, 0, 57, 0, 0, 0, 0, 0},
                   //青色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
                     
                  

  

  


//右コース=======================================================================================================================================
//===============================================================================================================================================
//完成版
  wParam wp2[100] = 
                   //スピードコース
                  //スタート！
                  //直線
                  {//{0, Section::TRACER, Section::LENGTH, 45, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 168, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 45, 0, true, Judge::UPDATE, 0, 166, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -1.5, 0, 0, 0, false, Judge::UPDATE, 0, 171, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -43, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //直線
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -87, 0, 0, 0, false, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 40, 0.1, 0.5, 1, 1 /*setparam*/, 0, -56, 0, 0, false, Judge::UPDATE, -85, 0, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 40, 0.1, 0.5, 1, 1 /*setparam*/, 0, -48, 0, 0, false, Judge::UPDATE, -30, 0, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 40, 0.1, 0.5, 1, 1 /*setparam*/, 0, -50, 0, 0, false, Judge::UPDATE, -5, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 50, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -85, 0, 0, 0, false, Judge::UPDATE, 0, 126, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 30, 0, 0, false, Judge::UNUPDATE, -15, 0, 0, 0, 0, 0, 0},
                    //第三ショートカットストレート
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, -15, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 54, 0, 0, true, Judge::UPDATE, 0, 40, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 45, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -100, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, true, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 5, 0, 0, true, Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0},
                   //{0, Section::TRACER, Section::LENGTH, 45, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 110, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, true, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::LENGTH, 30, 0, 20, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 20, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 7, 0, 0, true, Judge::UPDATE, 68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 55, 0, 0, false, Judge::UPDATE, 86.8, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 86.8, 0, 0, 0, false, Judge::UPDATE, 0, 0, -0.9, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                    //旋回
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},

                   //決め打ち
                   //1個目
                   //左斜め前に置く
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 17, 0, 0, false, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -4, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 10, 0, 0, false, Judge::UPDATE, -48, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -15, 0, false, Judge::UPDATE, 0, -12, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   

                   //2個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 11, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 17, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 10, 0, true, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -180, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -180, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -21, 0, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -8, 0, 0, false, Judge::UPDATE, 52, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -15, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   //{0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},

                   //3個目
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //左斜め前に置く
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 18, 0, 0, false, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -7, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 11, 0, 0, false, Judge::UPDATE, -42, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -13, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   //4個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //左グイーン
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 13, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -5, 0, 0, false, Judge::UPDATE, 87, 0, -0.5, 0, 0, 0, 0},
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 7, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //角度調整
                   //{0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   //バック！
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -35, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //黄色判定
                   //{0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   //5個目
                   //180°旋回
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 3, 0, 0, false, Judge::UPDATE, 148, 0, 0, 0, 0, 0, 0},
                    //緑判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 52, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -21, 0, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -11, 0, 0, false, Judge::UPDATE, 52, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -18, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //6個目
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右グイーン
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -13, 0, 0, false, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -7, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -12, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 7, 0, 0, false, Judge::UPDATE, -85, 0, -0.5, 0, 0, 0, 0},
                   //角度調整
                   //青色判定
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 7, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 8, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //バック！
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   //{0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //7個目
                   //180°旋回
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 3, 0, 0, false, Judge::UPDATE, 148, 0, 0, 0, 0, 0, 0},
                    //青色判定
                   //{0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 52, 0, 0, 0, 0, 0},
                   //赤色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左グイーン
                   // キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 13, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 6, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},

                   //8個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 10, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左斜め前に置く
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 23, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 18, 0, 0, false, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0},

                   
                   
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

wParam rrr[100] = {//右に90°曲がる
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -120, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};              


                   
wParam wp3[100] = 
                   {
                    //決め打ち
                   //1個目
                   //左斜め前に置く
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 17, 0, 0, false, Judge::UPDATE, 0, 13, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -4, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 10, 0, 0, false, Judge::UPDATE, -52, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -12, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   

                   //2個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 11, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -180, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //{0, Section::VIRTUAL, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -180, 0, 0, false, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -21, 0, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -8, 0, 0, false, Judge::UPDATE, 52, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -15, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   //{0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},

                   //3個目
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //左斜め前に置く
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 18, 0, 0, false, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -7, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, -42, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -12, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   //4個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //左グイーン
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 13, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -5, 0, 0, false, Judge::UPDATE, 87, 0, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //角度調整
                   //{0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   //バック！
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -35, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //黄色判定
                   //{0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},

                   //5個目
                   //180°旋回
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 3, 0, 0, false, Judge::UPDATE, 148, 0, 0, 0, 0, 0, 0},
                    //緑判定
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -21, 0, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -9, 0, 0, false, Judge::UPDATE, 52, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -18, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //6個目
                   //右カーブ
                   //曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -11, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //右グイーン
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -13, 0, 0, false, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 8, 0, 0, false, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   //青色判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   //バック！
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   //{0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},

                   //7個目
                   //180°旋回
                   //{0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 3, 0, 0, false, Judge::UPDATE, 148, 0, 0, 0, 0, 0, 0},
                    //青色判定
                   //{0, Section::TRACER, Section::COLOR, 15, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 220, 0.5, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
                   //赤色判定
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左グイーン
                   // キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 6, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},

                   //8個目
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左カーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   //{0, Section::TRACER, Section::LENGTH, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                   //左斜め前に置く
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 20, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 18, 0, 0, false, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -7, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   //{0, Section::VIRTUAL, Section::TURNANGLE, -20, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, -42, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -12, 0, 0, 0, 0, 0},
                   //止まる
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                   //ライン復帰
                   //{0, Section::TRACER, Section::COLOR, 18, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},

                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};


 wParam aaa[100] ={
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -11, 0, 0, false, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, -11, 0, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

            
// グイーン左編集済み
   wParam h1[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 6, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 9, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, false, Judge::UPDATE, 0, -35, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//中グイーン左編集済み
  wParam hh[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 6, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 25, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},
                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -7, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 9, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, false, Judge::UPDATE, 0, -35, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 30},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

                  
            
// グイーン右未編集
   wParam i1[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -10, 0, 0, false, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, false, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 12, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//中右グイーン
  wParam ii[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -26, 0, 0, false, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -2, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, false, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -20, 0, false, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //緑色判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//180°旋回
   wParam j1[100] =
                  //少し進む
                  {{0, Section::TRACER, Section::LENGTH, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                  //180°旋回
                  {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 3, 0, 0, false, Judge::UPDATE, 148, 0, 0, 0, 0, 0, 0},
                  //旋回後のライントレース
                  {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                  //ストップ
                  //{0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                  {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
  void setWalker(Section *sc);
  void setJudge(Section *sc);

wParam *array[10]={opp,wp2};
  wParam *wp;
};

#endif
