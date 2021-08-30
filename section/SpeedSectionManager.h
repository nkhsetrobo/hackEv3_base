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

 //こっから左
  
  
   wParam a2[100] = 
                  //スピードコース
                  //スタート！
                  {{0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 45, 0, 0, true, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 85, 0, 0, 0, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 61, 0, 0, true, Judge::UPDATE, 91, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 91, 0, 0, 0, true, Judge::UPDATE, 0, 120, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -26, 0, 0, true, Judge::UNUPDATE, 13, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 42, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 13, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -72, 0, 0, false, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 120, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 33, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -55, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    //旋回
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   //{0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -25, 0, 0, 0, 0, 0},
                   
                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左コース========================================
   wParam b[100] = 
                  //スピードコース
                  //スタート！
                  {{0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 47, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 90, 0, 0, 0, true, Judge::UPDATE, 0, 40, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 58, 0, 0, true, Judge::UPDATE, 84, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 84, 0, 0, 0, true, Judge::UPDATE, 0, 127, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -23, 0, 0, true, Judge::UNUPDATE, 8, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 42, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 8, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -75, 0, 0, false, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 120, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 33, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    //旋回
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   //{0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -25, 0, 0, 0, 0, 0},

                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

      

  
//右斜め前において戻る
   wParam c[100] =                 
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -22, 0, 0, true, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -16, 0, 0, true, Judge::UPDATE, 48, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, true, Judge::UPDATE, 0, -11, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左斜め前において戻る
   wParam d[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
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
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//右に90°曲がる
   wParam e[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -13, 0, 0, true, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
//左に90°曲がる
   wParam f[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 12, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 10, 0, 0, true, Judge::UPDATE, 50, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// サークル突破
   wParam g[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, true, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
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
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -33, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// グイーン右
   wParam i[100] =
                   

                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -10, 0, 0, true, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -10, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, true, Judge::UPDATE, 0, -30, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//180°旋回
   wParam j[100] =
                  //180°旋回
                  {{0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -3, 0, 0, true, Judge::UPDATE, -145, 0, 0, 0, 0, 0, 0},
                  //旋回後のライントレース
                  {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0.5, 0},
                  //ストップ
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                  {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};



//決め打ち
   wParam dangerous[100] =

                  //スピードコース
                  //スタート！
                  {{0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                  //最初のストレート
                   {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 161, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 48, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //第一コーナー後のストレート
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 90, 0, 0, 0, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.2, 1, 1 /*setparam*/, 0, 60, 0, 0, true, Judge::UPDATE, 85, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 85, 0, 0, 0, true, Judge::UPDATE, 0, 122, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -24, 0, 0, true, Judge::UNUPDATE, 8, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 42, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, 8, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -67, 0, 0, false, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 38, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 120, 0, 0, false, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 33, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, false, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, -68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 350, 0, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -56, 0, 0, true, Judge::UPDATE, -86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, -86, 0, 0, 0, true, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, true, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    //旋回
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, true, Judge::UPDATE, 0, -5, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 6, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   //{0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   //下がる
                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, true, Judge::UPDATE, 0, -25, 0, 0, 0, 0, 0},

                  //遊び
                   //黄色
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, 70, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 15, 0, true, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 287, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //青
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 15, 0, true, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, true, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 1, 0, 0, true, Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0},
                   //赤M
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 25, 0, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 3, 0, 20, 0, 0.3, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},

                   // サークル突破
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
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
                  

  

  


//右コース========================================
  wParam wp2[100] = 
                   //スピードコース
                  //スタート！
                  //直線
                  {{0, Section::TRACER, Section::LENGTH, 43, 0, 20, 0.1, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 43, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 162, 0, 0, 0, 0, 0},
                   //第一コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -45, 0, 0, false, Judge::UPDATE, -87, 0, 0, 0, 0, 0, 0},
                   //直線
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -87, 0, 0, 0, false, Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                   //第二コーナー
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 40, 0.1, 0.5, 1, 1 /*setparam*/, 0, -61, 0, 0, false, Judge::UPDATE, -91, 0, 0, 0, 0, 0, 0},
                   //ロングショートカット
                   {0, Section::VIRTUAL2, Section::LENGTH, 43, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, -91, 0, 0, 0, false, Judge::UPDATE, 0, 120, 0, 0, 0, 0, 0},
                   //ラストカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 26, 0, 0, false, Judge::UNUPDATE, -14, 0, 0, 0, 0, 0, 0},
                    //第三ショートカットストレート
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 42, 0, 20, 0.1, 0.3, 1, 1 /*setparam*/, -14, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //復帰
                   {0, Section::VIRTUAL, Section::LENGTH, 42, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 80, 0, 0, true, Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::LENGTH, 42, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, -120, 0, 0, true, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 42, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 110, 0, 0, 0, 0, 0},
                   //ゴール

                   //ブロックビンゴ前

                   //黄色サークル到達
                   {0, Section::TRACER, Section::COLOR, 30, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //黄色サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 40, 0, true, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                   //緑サークル判定
                   {0, Section::TRACER, Section::COLOR, 20, 0, 20, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 156, 0, 0},
                   //緑曲がった後
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 7, 0, 0, true, Judge::UPDATE, 68, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 5, 0, true, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //赤色サークル判定
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0.1, 0.9, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 350, 0, 0},
                   //赤サークル検知後のカーブ
                   {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 55, 0, 0, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   //ストレート.黒判定
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 15, 0, 10, 0, 0.3, 1, 1 /*setparam*/, 86, 0, 0, 0, false, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0},
                   //黒判定後のストレート少し.置く
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 8, 0, false, Judge::UPDATE, 0, 11, 0, 0, 0, 0, 0},
                    //旋回
                   //{0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                    //置いた後下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //下がりながら曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -6, 0, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   //ライントレースで体制を整える
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0},

                   //{0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -15, 0, false, Judge::UPDATE, 0, -25, 0, 0, 0, 0, 0},

                    //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};



//右斜め前において戻る
   wParam c1[100] =                 
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //右斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -22, 0, 0, false, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -16, 0, 0, false, Judge::UPDATE, 48, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, false, Judge::UPDATE, 0, -11, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::TRACER, Section::COLOR, 7, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左斜め前において戻る
   wParam d1[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //キャッチ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, 7, 0, false, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                   //左斜め前に置く
                   {0, Section::VIRTUAL, Section::LENGTH, 10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 20, 0, 0, false, Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //元の場所に戻る
                   {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 15, 0, 0, false, Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0},
                   //まっすぐ下がる
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -10, 0, 0, 0, 0, 0},
                   //ライン復帰
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -7, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
              
//右に90°曲がる
   wParam e1[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //右に90°曲がる
                   {0, Section::VIRTUAL, Section::BRIGHTNESS, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -12, 0, 0, false, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -10, 0, 0, false, Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 156, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

//左に90°曲がる
   wParam f1[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //左に90°曲がる
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 13, 0, 0, false, Judge::UPDATE, 68, 0, 0, 0, 0, 0, 0},
                   //ライン復帰をしたい
                   {0, Section::TRACER, Section::COLOR, 3, 0, 30, 0, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0.5, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
// サークル突破
   wParam g1[100] =
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   // サークル突破
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                   //ライントレース
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
            
// グイーン左
   wParam h1[100] =
                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 11, 0, 0, false, Judge::UPDATE, 180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, 9, 0, 0, false, Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 7, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -33, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
            
// グイーン右
   wParam i1[100] =
                   

                   //入れる処理
                   //黄色判定
                   {{0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //旋回！
                   {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -10, 0, 0, false, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},

                   //戻る処理
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -5, 0, false, Judge::UPDATE, 0, -3, 0, 0, 0, 0, 0},
                   //戻る！
                   {0, Section::VIRTUAL, Section::TURNANGLE, -3, 0, 30, 0.1, 0.3, 1, 1 /*setparam*/, 0, -7, 0, 0, false, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //角度調整
                   {0, Section::TRACER, Section::LENGTH, 3, 0, 30, 0.1, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 9, 0, 0, 0, 0, 0},
                   //バック！
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 30, 0.1, 0.5, 1, 1 /*setparam*/, 0, 0, -10, 0, false, Judge::UPDATE, 0, -36, 0, 0, 0, 0, 0},
                   //止まる
                   {0, Section::VIRTUAL2, Section::STOP, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 0, 0, 100},
                   //黄色判定
                   {0, Section::TRACER, Section::COLOR, 5, 0, 30, 0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 0, 0, 0, 60, 0, 0},
                   //ストップ
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATE, 0, 999, 0, 0, 0, 0, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

  void setWalker(Section *sc);
  void setJudge(Section *sc);

wParam *array[10]={b,wp2};
  wParam *wp;
};
#endif
