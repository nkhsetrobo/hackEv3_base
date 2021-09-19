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

wParam base[100] = {
                    {0, Section::TRACER, Section::LENGTH, 35, 0,22, 24.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 145, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0,30, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 295, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 350, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 45, 0,35, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 475, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 530, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 30, 0,35, 28.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 560, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 13, 0,40, 45.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 610, 0, 0, 0, 0, 0},

                    {0, Section::TRACER, Section::LENGTH, 50, 0,25, 26.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 670, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 48, 0,35, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 720, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,42, 50.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 800, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,30, 30.0, 2.2, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1000, 0, 0, 0, 0, 0},

                   // {0, Section::TRACER, Section::LENGTH, 0, 00, 0.0, 0, 0, 0 ,0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1050, 0, 0, 0, 0, 0},

                  //  // 最終コーナーへ
                    {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 30.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 60, 0, 0, 0, 0, 0},



                      // スラロームテスト
                      {0, Section::TRACER, Section::LENGTH, 7, -0.0, 20, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 25, 0, 0, 138, 0.35, 0 , 0 },  
                      {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 1, 1 /*setparam*/, 0, 0, 3, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -3, 0, _EDGE,Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0},
                      {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +20, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -36, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                          // スラロームpatern 1
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                           {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                            {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                          //スラロームpatern2
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15.5, 0, 0, _EDGE,Judge::UNUPDATE, -115, 0, 0, 0, 0, 0, 0},
                          //  {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16.5, 0, 0, _EDGE,Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0},

                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -65, 0, 0, 0, 0, 0, 0},
                          //   //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                          //   {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                          //   {0, Section::TRACER, Section::LENGTH, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                          //   {0, Section::TRACER, Section::SONER, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 38, 0, 0, 0, 0, 0},
                      // ブロック回収
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UPDATE, -83, 0, 0, 0, 0, 0, 0},
                           // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 10, 2.0, 1, 1/*setparam*/, -83, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, !_EDGE,Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UNUPDATE, -100, 0, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
//                            {0, Section::VIRTUAL2, Section::TURNANGLE, 5, 0, 30, 10, 0, 1, 1/*setparam*/, 22, 0, 0, 0, !_EDGE,Judge::UNUPDATE, -100, 00, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 0, 0, 0, 5, 0.35, 0 , 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, 0, -20, 0, 0, !_EDGE,Judge::UPDATE, -180, 00, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, -180, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   80, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 10, 0, 1.0, 1, 1/*setparam*/, 0, -8, 0, 0, !_EDGE,Judge::UPDATE, -90, 00, 0, 0, 0, 0, 0},

                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                           // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0},


                      //ガレージ停止
                          {0, Section::WALKER, Section::SONER,0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了



                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};


wParam base_sc[100] = {
                    {0, Section::TRACER, Section::LENGTH, 35, 0,22, 24.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 145, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0,30, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 295, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 370, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                    // sc
                    {0, Section::TRACER, Section::LENGTH, 45, 0,35, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
 //                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, -35, 00, 0, _EDGE, Judge::UPDATE, -70, 0, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 20, _EDGE, Judge::UPDATE, 0, 39, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 15, -15, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 3, 0.2 , 0, 0, 0, 0},
                    //  {0, Section::TRACER, Section::LENGTH, 15, 0,35, 1.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, 36, 00, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                   //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 8, 0.2 , 0, 0, 0, 0},
                   // {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, -35, 00, 0, _EDGE, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                     {0, Section::TRACER, Section::LENGTH, 20, 0,40, 40.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,42, 50.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 350, 0, 0, 0, 0, 0},
                                //   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  

                   // {0, Section::TRACER, Section::LENGTH, 0, 00, 0.0, 0, 0, 0 ,0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1050, 0, 0, 0, 0, 0},

                  //  // 最終コーナーへ
                    {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 30.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 60, 0, 0, 0, 0, 0},



                      // スラロームテスト
                      {0, Section::TRACER, Section::LENGTH, 7, -0.0, 20, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 25, 0, 0, 138, 0.35, 0 , 0 },  
                      {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 1, 1 /*setparam*/, 0, 0, 3, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -3, 0, _EDGE,Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0},
                      {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +20, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -36, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                          // スラロームpatern 1
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                          //  {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                          //   {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                          //スラロームpatern2
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15.5, 0, 0, _EDGE,Judge::UNUPDATE, -115, 0, 0, 0, 0, 0, 0},
                           {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16.5, 0, 0, _EDGE,Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0},

                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -65, 0, 0, 0, 0, 0, 0},
                            //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::SONER, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 38, 0, 0, 0, 0, 0},
                      // ブロック回収
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UPDATE, -83, 0, 0, 0, 0, 0, 0},
                           // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 10, 2.0, 1, 1/*setparam*/, -83, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, !_EDGE,Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UNUPDATE, -100, 0, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
//                            {0, Section::VIRTUAL2, Section::TURNANGLE, 5, 0, 30, 10, 0, 1, 1/*setparam*/, 22, 0, 0, 0, !_EDGE,Judge::UNUPDATE, -100, 00, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 0, 0, 0, 5, 0.35, 0 , 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, 0, -20, 0, 0, !_EDGE,Judge::UPDATE, -180, 00, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, -180, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   80, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 10, 0, 1.0, 1, 1/*setparam*/, 0, -8, 0, 0, !_EDGE,Judge::UPDATE, -90, 00, 0, 0, 0, 0, 0},

                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                           // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0},


                      //ガレージ停止
                          {0, Section::WALKER, Section::SONER,0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了



                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};



wParam base_sc2[100] = {
                    {0, Section::TRACER, Section::LENGTH, 35, 0,22, 24.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 145, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0,30, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 295, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 370, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -60, 0, 0, 0, 0, 0, 0},
                    // sc2
                    {0, Section::TRACER, Section::LENGTH, 45, 0,35, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 52, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 30.0, 3.5,0.7, 1.00 /*setparam*/, 0, -35, 00, 0, _EDGE, Judge::UPDATE, -88, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, -88, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 30.0, 3.5,0.45, 1.00 /*setparam*/, 0, 18, 00, 0, _EDGE, Judge::UNUPDATE, 80, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, 80, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 25, 0,35, 30.0, 3.5,0.55, 1.00 /*setparam*/, 0, -24, 00, 0, _EDGE, Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 300, 0, 0, 0, 0, 0},
                            //       {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                  //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 15, -15, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 3, 0.2 , 0, 0, 0, 0},
                  //   //  {0, Section::TRACER, Section::LENGTH, 15, 0,35, 1.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, 36, 00, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                  //  //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 8, 0.2 , 0, 0, 0, 0},
                  //  // {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, -35, 00, 0, _EDGE, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                  //    {0, Section::TRACER, Section::LENGTH, 20, 0,40, 5.0, 3.8, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 40, 0,42, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 350, 0, 0, 0, 0, 0},
                  //               //   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  

                  //  // {0, Section::TRACER, Section::LENGTH, 0, 00, 0.0, 0, 0, 0 ,0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1050, 0, 0, 0, 0, 0},

                  // //  // 最終コーナーへ
                  //   {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 30.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 60, 0, 0, 0, 0, 0},



                      // スラロームテスト
                      {0, Section::TRACER, Section::LENGTH, 7, -0.0, 20, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 25, 0, 0, 138, 0.35, 0 , 0 },  
                      {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 1, 1 /*setparam*/, 0, 0, 3, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -3, 0, _EDGE,Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0},
                      {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +20, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -36, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                          // スラロームpatern 1
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                          //  {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                          //   {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                          //スラロームpatern2
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15.5, 0, 0, _EDGE,Judge::UNUPDATE, -115, 0, 0, 0, 0, 0, 0},
                           {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16.5, 0, 0, _EDGE,Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0},

                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -65, 0, 0, 0, 0, 0, 0},
                            //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::SONER, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 38, 0, 0, 0, 0, 0},
                      // ブロック回収
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UPDATE, -83, 0, 0, 0, 0, 0, 0},
                           // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 10, 2.0, 1, 1/*setparam*/, -83, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, !_EDGE,Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UNUPDATE, -100, 0, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
//                            {0, Section::VIRTUAL2, Section::TURNANGLE, 5, 0, 30, 10, 0, 1, 1/*setparam*/, 22, 0, 0, 0, !_EDGE,Judge::UNUPDATE, -100, 00, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 0, 0, 0, 5, 0.35, 0 , 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, 0, -20, 0, 0, !_EDGE,Judge::UPDATE, -180, 00, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, -180, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   80, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 10, 0, 1.0, 1, 1/*setparam*/, 0, -8, 0, 0, !_EDGE,Judge::UPDATE, -90, 00, 0, 0, 0, 0, 0},

                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                           // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0},


                      //ガレージ停止
                          {0, Section::WALKER, Section::SONER,0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了



                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};

wParam base_sc2_r[100] = {
                    {0, Section::TRACER, Section::LENGTH, 35, 0,22, 24.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 55, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 145, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0,30, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 295, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 370, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 38, 0,35, 45.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 60, 0, 0, 0, 0, 0, 0},
                    // sc2
                    {0, Section::TRACER, Section::LENGTH, 45, 0,35, 50.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 53, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 30.0, 3.5,1/0.7, 1.00 /*setparam*/, 0, 35, 00, 0, _EDGE, Judge::UPDATE, 88, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, 88, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 30.0, 3.5,1/0.45, 1.00 /*setparam*/, 0, -18, 00, 0, _EDGE, Judge::UNUPDATE, 20, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,35, 30.0, 3.5,1/0.45, 1.00 /*setparam*/, 0, 19, 00, 0, _EDGE, Judge::UNUPDATE, 80, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, 80, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,35, 30.0, 3.5,1/0.45, 1.00 /*setparam*/, 0, -20, 00, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0,35, 30.0, 3.5,1/0.45, 1.00 /*setparam*/, 0, 25, 00, 0, _EDGE, Judge::UNUPDATE, 70, 0, 0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::BRIGHTNESS, 40, 0,35, 30.0, 3.5,1/0.45, 1.00 /*setparam*/, 00, 0, 35, 0, _EDGE, Judge::UNUPDATE, 0, 0, -0.5, 0, 0, 0, 0},


                    {0, Section::TRACER, Section::LENGTH, 40, 0,20, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                            //       {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                  //   {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 15, -15, _EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 3, 0.2 , 0, 0, 0, 0},
                  //   //  {0, Section::TRACER, Section::LENGTH, 15, 0,35, 1.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, 36, 00, 0, _EDGE, Judge::UPDATE, 90, 0, 0, 0, 0, 0, 0},
                  //  //{0, Section::WALKER, Section::LENGTH, 0, 0,0, 0.0, 0, 0, 0 /*setparam*/, 00, 0, 20, 0, _EDGE, Judge::UPDATE, 0, 8, 0.2 , 0, 0, 0, 0},
                  //  // {0, Section::VIRTUAL, Section::TURNANGLE, 18, 0,39, 50.0, 3.5, 0, 0 /*setparam*/, 0, -35, 00, 0, _EDGE, Judge::UPDATE, -180, 0, 0, 0, 0, 0, 0},
                  //    {0, Section::TRACER, Section::LENGTH, 20, 0,40, 5.0, 3.8, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 40, 0,42, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 350, 0, 0, 0, 0, 0},
                  //               //   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  

                  //  // {0, Section::TRACER, Section::LENGTH, 0, 00, 0.0, 0, 0, 0 ,0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 0, 1050, 0, 0, 0, 0, 0},

                  // //  // 最終コーナーへ
                  //   {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 20, 0, 30, 30.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 60, 0, 0, 0, 0, 0},



                      // スラロームテスト
                      {0, Section::TRACER, Section::LENGTH, 7, -0.0, 20, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 25, 0, 0, 138, 0.35, 0 , 0 },  
                      {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 1, 1 /*setparam*/, 0, 0, 3, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -3, 0, _EDGE,Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0},
                      {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +20, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -36, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                          // スラロームpatern 1
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                          //  {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                          //   {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                          //スラロームpatern2
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15.5, 0, 0, _EDGE,Judge::UNUPDATE, -115, 0, 0, 0, 0, 0, 0},
                           {0, Section::VIRTUAL2, Section::LENGTH, 3, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16.5, 0, 0, _EDGE,Judge::UNUPDATE, -45, 0, 0, 0, 0, 0, 0},

                            {0, Section::VIRTUAL, Section::TURNANGLE, 3, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -65, 0, 0, 0, 0, 0, 0},
                            //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::SONER, 7, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 38, 0, 0, 0, 0, 0},
                      // ブロック回収
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UPDATE, -83, 0, 0, 0, 0, 0, 0},
                           // {0, Section::VIRTUAL2, Section::LENGTH, 30, 0, 30, 10, 2.0, 1, 1/*setparam*/, -83, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 20, 0, !_EDGE,Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 5, !_EDGE,Judge::UNUPDATE, -100, 0, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
//                            {0, Section::VIRTUAL2, Section::TURNANGLE, 5, 0, 30, 10, 0, 1, 1/*setparam*/, 22, 0, 0, 0, !_EDGE,Judge::UNUPDATE, -100, 00, 0, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 35, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 0, 0, 0, 5, 0.35, 0 , 0},
                            {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0 , 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, 0, -20, 0, 0, !_EDGE,Judge::UPDATE, -180, 00, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL2, Section::LENGTH, 15, 0, 30, 10, 2.0, 1, 1/*setparam*/, -180, 00, 0, 0, !_EDGE,Judge::UPDATE,   0,   80, 0, 0, 0, 0, 0},
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 0, -0.1, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 10, 0, 1.0, 1, 1/*setparam*/, 0, -8, 0, 0, !_EDGE,Judge::UPDATE, -90, 00, 0, 0, 0, 0, 0},

                            {0, Section::TRACER, Section::LENGTH, 5, 0.2, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 0, 35, 0, 0, 0, 0, 0},
                           // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0},


                      //ガレージ停止
                          {0, Section::WALKER, Section::SONER,0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了



                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};

wParam base_sc3_r[100] = {
                    {0, Section::WALKER, Section::LENGTH, 30, 0,10, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,40, 10.0, 3.5, 0, 0 /*setparam*/, 0, 0, 45, 0, _EDGE, Judge::UNUPDATE, 0, 135, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 95*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 27*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, 55*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,40, 10.0, 3.5, 0, 0 /*setparam*/,  90*sign, 0,0 , 0, _EDGE, Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 20, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, 22*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 260*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,40, 10.0, 3.5, 0, 0 /*setparam*/,  260*sign, 0,0 , 0, _EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, -45*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 180*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,40, 10.0, 3.5, 0, 0 /*setparam*/,  180*sign, 0,0 , 0, _EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, -42*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 95*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,40, 10.0, 3.5, 0, 0 /*setparam*/,  90*sign, 0,0 , 0, _EDGE, Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, 25*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 155*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, -20*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 95*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, 20*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 170*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, -35*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 97*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, 97*sign, 0, 35, 0, _EDGE, Judge::UPDATE, 0,20, -0, 0, 0, 0, 0},
                    {0, Section::WALKER, Section::BRIGHTNESS, 40, 0,35, 30.0, 3.5,1.0, 1.00 /*setparam*/, 97*sign, 0, 50, 0, _EDGE, Judge::UNUPDATE, 0, 0, -0.8, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 50, 0,30, 30.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 150, 0, 0, 0, 0, 0},
                                     {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  


                    {-1, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
};

wParam outer[100] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 600, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},

                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 15, 10.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 43, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 5.0, 2.0, 0, 0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,60, 12.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 76, 0, 0, 0, 0, 0}, //下り
                                      
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, !_EDGE, Judge::UPDATE, 00, -10, 0, 0, 0,0 , 0 , 0 },  //緑色

                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0},  //黄色

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};

wParam outer_adv[200] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 600, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},

                  //  {0, Section::WALKER, Section::LENGTH, 00, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},

                    // entry 入り口 / advanced センター置き
                  // {0, Section::TRACER, Section::LENGTH, 35, 0, kp, 4.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 25, 0, 15, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 35, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -9.5*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


                  // advanced センター置き
                  {0, Section::TRACER, Section::LENGTH, 5, 0,25, 5.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 00, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL2, Section::LENGTH, 20, 0,35, 10.0, 1.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL2, Section::LENGTH, 5, 0,30, 10.0, 1.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UNUPDATE, 0, 66, 0, 0, 0, 0, 0}, //下り  advanced
                  //センター置き終了
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -3, 0, 0, 0,0 , 0 , 0 },  


                  // advanced ビンゴテスト
                  {0, Section::WALKER, Section::TURNANGLE,0, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 10*sign, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -15, 0, 0,  0,0 , 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, 8, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 8, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0},
                   // 設置（左）1 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, 30, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,10}, 
                    //設置完了
                  // 設置後旋回して次の交点
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*0.7, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,10}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,15}, 
                    //設置完了
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 8.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*0.7, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 3
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,10}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 2*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,10}, 
                   // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 25, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 30, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                   // 設置（左） 4
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,15}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                   // 設置（左） 5
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 24, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                   // 設置（左） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後設置
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 10, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2 ,0, 10, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 5.5*sign, 0, 0, false, Judge::UNUPDATE, (90+80)*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, -bspd2, 0, 10, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 4.5*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                    // 前方交点まで
                  {0, Section::TRACER, Section::LENGTH, bspd2, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 



                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},
};

wParam outer_adv2[200] = {
                    {0, Section::TRACER, Section::LENGTH, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 600, 0, 0, 0, 0, 0},

                    {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 50, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},

                  //  {0, Section::WALKER, Section::LENGTH, 00, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},

                    // entry 入り口 / advanced センター置き
                  // {0, Section::TRACER, Section::LENGTH, 35, 0, kp, 4.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0},
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 40, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
              //     {0, Section::VIRTUAL2, Section::COLOR, 30, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 30, 0, !_EDGE, Judge::UPDATEALL, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 40, 0, !_EDGE, Judge::UPDATEALL, 00, 8, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 40, 0,  45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 45, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 15, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 5, 0, !_EDGE, Judge::UPDATE, 00, 5, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0,1.0, 1.0 /*setparam*/, 0, -5.0*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


                  // advanced センター置き
                  {0, Section::TRACER, Section::LENGTH, 10, 0,25, 3, 0.6, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 14, 0, 0, 0, 0, 0}, //下り  advanced
                //  {0, Section::WALKER, Section::LENGTH, 00, 0,35, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 15, 0, false, Judge::UNUPDATE, 0, 52.5, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL2, Section::LENGTH, 20, 0,35, 8.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UPDATEALL, 0, 52.5-14, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 10.0, 0.5, 1.0, 1.0 /*setparam*/, 0, -18*sign, 0, 0, false, Judge::UPDATE, -88*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,35, 20.0, 5.0, 1, 1 /*setparam*/, -88*sign, 0, 0, 0, false, Judge::UPDATE, 0, 45, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL2, Section::LENGTH, 10, 0,35, 10.0, 5.0, 1, 1 /*setparam*/, -88*sign, 0, 0, 0, false, Judge::UNUPDATE, 0, 61, 0, 0, 0, 0, 0}, //下り  advanced
                  //センター置き終了
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -8, 0, _EDGE, Judge::UNUPDATE, 00, 52, 0, 0, 0,0 , 0 , 0 },  


                  // advanced ビンゴテスト 初期値クリア
                  {0, Section::WALKER, Section::TURNANGLE,0, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 20*sign, false, Judge::UPDATE, -87*sign, 0, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -12, 0, _EDGE, Judge::UPDATE, 00, -8, 0, 0,  0,0 , 0, 0}, 
                  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -0, 0, _EDGE, Judge::UPDATE, 00, -8, 0, 0,  0,0 , 20, 0}, 
                  {0, Section::TRACER, Section::LENGTH, 22.0, 0,38, 10.0, 5.1, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 12, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0},
                    {-1},

                  // 1つ目　黄色
                  //旋回（左）後交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 2, 0, 0,0, 0, 0}, 
//                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 10.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 1
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, -10*sign, _EDGE, Judge::UPDATE, 90*sign, 0, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  //小旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
   
                  // 2つ目　緑色
                   // 設置（左） 1
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,40}, 

                  // 3つ目　黄色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 3, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 24, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,50}, 

                  // 4つ目　赤色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 3, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 

                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.5*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp*0.9, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -14.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,40}, 

                  //5個目 赤
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,50}, 


                  // 5つ目　青色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 4, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd2, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 2, 0, 0,0, 0, 0}, 
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.4, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -15.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 

                // 6個目
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                // 7個目
                  //小旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後その場設置
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 10, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2*0.5 ,0, 10, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 5.5*sign, 0, 0, false, Judge::UNUPDATE, (90+80)*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, -bspd2*0.5, 0, 10, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 2.0*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                 
                //終了処理
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},


};

wParam outer_adv3[200] = {
                    {0, Section::TRACER, Section::LENGTH, 25, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 42, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 131, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 95*sign, 00, 0, !_EDGE, Judge::UPDATE, 27*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, 30, 15.0, 4.0, 0, 0 /*setparam*/, 0, 70*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 82*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 45, 0, 45, 15.0, 4.0, 0, 0  /*setparam*/, 82*sign , 0, 0, 0, !_EDGE, Judge::UPDATE, 00, 20, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                    {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 50*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 174*sign, 0, 0, 0, 0, 0, 0},
                   // {0, Section::TRACER, Section::TURNANGLE, 40, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -45*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0,35, 20.0, 1.5, 1, 1 /*setparam*/, 174*sign, 0, 0, 0, false, Judge::UPDATE, 0, 0, -0.7, 0, 0, 0, 0}, //下り  advanced
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, 42, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 60*sign, 00, 0, !_EDGE, Judge::UNUPDATE, 170*sign, 0, 0, 0, 0, 0, 0},
                    {0, Section::TRACER, Section::LENGTH, 45, 0, 45, 15.0, 4.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 250, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 00, 10000, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 00, 10000, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                    {0, Section::TRACER, Section::LENGTH, 45, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 80, 0, 0, 0, 0, 0},

                  //  {0, Section::WALKER, Section::LENGTH, 00, 0, 45, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 10000, 0, 0, 0, 0, 0},

                    // entry 入り口 / advanced センター置き
                  // {0, Section::TRACER, Section::LENGTH, 35, 0, kp, 4.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 100, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                   {0, Section::TRACER, Section::LENGTH, 20, 0, 15, 2.0, 1.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 45, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},


                  // advanced センター置き
                  {0, Section::TRACER, Section::LENGTH, 5, 0,25, 3.0, 1.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 00, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 10, 0, false, Judge::UNUPDATE, 0, 57, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -13*sign, 0, 0, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL2, Section::LENGTH, 23, 0,35, 20.0, 1.5, 1, 1 /*setparam*/, -89*sign, 0, 0, 0, false, Judge::UPDATE, 0, 45, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::VIRTUAL2, Section::LENGTH, 5, 0,30, 10.0, 1.0, 1, 1 /*setparam*/, -89*sign, 0, 0, 0, false, Judge::UNUPDATE, 0, 66, 0, 0, 0, 0, 0}, //下り  advanced
                  //センター置き終了
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -3, 0, _EDGE, Judge::UNUPDATE, 00, 60, 0, 0, 0,0 , 0 , 0 },  


                  // advanced ビンゴテスト 初期値クリア
                  {0, Section::WALKER, Section::TURNANGLE,0, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 10*sign, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0}, //下り  advanced
                  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -15, 0, 0,  0,0 , 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd2, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0},
                  // 1つ目　黄色
                  //旋回（左）後交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 2, 0, 0,0, 0, 0}, 
//                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 10.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 1
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, -10*sign, _EDGE, Judge::UPDATE, 90*sign, 0, 0, 0,0, 0, 0}, 
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  //小旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 25, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
   
                  // 2つ目　緑色
                   // 設置（左） 1
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,40}, 

                  // 3つ目　黄色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 3, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 24, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,50}, 

                  // 4つ目　赤色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 3, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 

                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.5*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp*0.9, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -14.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,40}, 

                  //5個目 赤
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,50}, 


                  // 5つ目　青色
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 4, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd2, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 2, 0, 0,0, 0, 0}, 
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.4, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.4, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.4, 0, 0}, 
                   // 設置（右） 
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -15.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 

                // 6個目
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 28, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                   // 設置（左） 2
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                  {0, Section::VIRTUAL, Section::TURNANGLE, -8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,20}, 
                // 7個目
                  //小旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 23, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                    // 前方交点まで
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 6, 0, 0,0, 0, 0}, 
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0}, 
                   {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後交点まで
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //旋回（左）後その場設置
                   {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 10, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2*0.5 ,0, 10, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 5.5*sign, 0, 0, false, Judge::UNUPDATE, (90+80)*sign, 0, 0, 0, 0, 0, 0},
                  {0, Section::VIRTUAL, Section::TURNANGLE, -bspd2*0.5, 0, 10, 1.0, 1.0, 0.1, 1.0 /*setparam*/, 0, 2.0*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                 
                //終了処理
                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},


};

double kp=60.0;
double vkp=38.0,vki=40.0,vkd=3.5;
double vkp2=30.0,vki2=10.0,vkd2=5.0;
//double vkp=0.0,vki=0.0,vkd=0.0;


wParam sc_l[150] = {
                    {0, Section::TRACER, Section::LENGTH, 39, 0, 20, 10.0, 0.1, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 1200, 0, 0, 0, 0, 0},

                  //  {0, Section::TRACER, Section::TURNANGLE, 39, 0, kp, 35.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 5*sign, 0, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::TURNANGLE, 33, 0, kp, 90.0, 6.8, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UNUPDATE, 85*sign, 0, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 20.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 45, 0, 0, 0, 0, 0},
                  //   {0, Section::WALKER, Section::LENGTH, 39, 0,  vkp, vki, vkd,  0, 0 /*setparam*/, 90*sign , 0 , 39, 0, _EDGE, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0, 0},
                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0, vkp, vki, vkd,  0.5, 1.0/*setparam*/, 0, 20*sign, 0, 0, false, Judge::UPDATE, 156*sign, 0, 0, 0, 0, 0, 0},  // 左
                  //   {0, Section::VIRTUAL2, Section::LENGTH, 32, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 166*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 34, 0, 0, 0, 0, 0},

                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.6, 1.0 /*setparam*/, 0, -29*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0}, //右
                  //   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/,  90*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},

                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.6, 1.0 /*setparam*/, 0, -24*sign, 0, 0, false, Judge::UNUPDATE, -15*sign, 0, 0, 0, 0, 0, 0}, //右
                  //   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, -20*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 4, 0, 0, 0, 0, 0},

                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 31, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, 18.0*sign, 0, 0, false, Judge::UNUPDATE, 82*sign, 0, 0, 0, 0, 0, 0}, //左
                  //   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 84*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 24, 0, 0, 0, 0, 0},

                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 31, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, 22*sign, 0, 0, false, Judge::UNUPDATE, 160*sign, 0, 0, 0, 0, 0, 0}, //左
                  //   {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, vkp2, vki2, vkd2, 0, 0 /*setparam*/, 167*sign, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                  //   {0, Section::VIRTUAL, Section::TURNANGLE, 32, 0,vkp, vki, vkd, 0.55, 1.0 /*setparam*/, 0, -23.5*sign, 0, 0, false, Judge::UNUPDATE, -1.0*sign, 0, 0, 0, 0, 0, 0}, //右
                  //   {0, Section::TRACER, Section::LENGTH, 39, 0, 7, 0.0, 9.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 50, 0, 0, 0, 0, 0},
                  
                  //  // 最終コーナーへ
                  //   {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 40, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                  //   {0, Section::TRACER, Section::LENGTH, 30, 0, kp, 15.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},

                    // 外側コース
                   // {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 35.0, 2.95, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 550, 0, 0, 0, 0, 0},
                    // 最終コーナーへ
                    // {0, Section::TRACER, Section::LENGTH, 39, 0, kp, 40, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 100, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::TURNANGLE, 30, 0, 30, 15.0, 3.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, -30*sign, 0, 0, 0, 0, 0, 0},
                    // {0, Section::TRACER, Section::LENGTH, 30, 0, kp, 15.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 0, 70, 0, 0, 0, 0, 0},


                      // スラロームテスト
                      {0, Section::TRACER, Section::LENGTH, 5, -0.0, 18, 8.0, 0.5, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 12, 0, 0, 138, 0.35, 0 , 0 },  
                      {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 4, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                      {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 13, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.1, 0.1, 0.01, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 12, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 16, 0, 0, 0, 0, 0}, //昇段
                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 1, 0, _EDGE,Judge::UNUPDATE, 0, 16.5, 0, 0, 0, 0, 0},
                      {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                      {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, _EDGE,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},

                      {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE,Judge::UNUPDATE, 0, 16-2, 0, 0, 0, 0, 0},
                      {0, Section::TRACER, Section::LENGTH, 3, -0.3, 20, 8, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, _EDGE,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -15, 0, 0, _EDGE,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +19, 0, 0, _EDGE,Judge::UNUPDATE, +38.5, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -18, 0, 0, _EDGE,Judge::UNUPDATE, -35, 0, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL2, Section::LENGTH, 5, 0, 25, 10, 0, 1, 1/*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 1, 0, 0, 0, 0, 0},
                      {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, +16, 0, 0, _EDGE,Judge::UNUPDATE, +20, 0, 0, 0, 0, 0, 0},

                          // スラロームpatern 1
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -50, 0, 0, 0, 0, 0, 0},
                          //  {0, Section::VIRTUAL2, Section::BRIGHTNESS, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -50, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 0, -0.5, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0},   
                          //   {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -92, 0, 0, 0, 0, 0, 0},
                          //   {0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                          //   {0, Section::TRACER, Section::LENGTH, 7, 0, 25, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 19, 0, 0, 0, 0, 0},

                          //スラロームpatern2
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -16, 0, 0, _EDGE,Judge::UNUPDATE, -110, 0, 0, 0, 0, 0, 0},
                           {0, Section::VIRTUAL2, Section::LENGTH, 5, 0, 25, 10, 0, 1, 1/*setparam*/, -110, 0, 00, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, 16, 0, 0, _EDGE,Judge::UNUPDATE, -40, 0, 0, 0, 0, 0, 0},
                            {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 25, 10, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, _EDGE,Judge::UNUPDATE, -60, 0, 0, 0, 0, 0, 0},
                            //{0, Section::WALKER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0},   //降段
                            {0, Section::WALKER, Section::BRIGHTNESS, 0, -0.7, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 5, 0, _EDGE,Judge::UPDATE, 0, 0, -0.10, 0, 0, 0, 0},
                            {0, Section::TRACER, Section::LENGTH, 7, 0, 30, 0, 1.5, 1, 1 /*setparam*/, 0, 0, 5, 0, !_EDGE,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                      //ガレージ停止
                          {0, Section::WALKER, Section::SONER, 7, 0, 10, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 10, 0, !_EDGE,Judge::UPDATE, 0, 5, 0, 0, 0, 0, 0},
                                    {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 00, 0, _EDGE, Judge::UPDATE, 00, 10000, 0, 0, 138, 0.35, 0 , 0 },  
                      // スラローム終了

                    // entry 入り口 / advanced センター置き
                  //  {0, Section::TRACER, Section::LENGTH, 35, 0, kp, 4.0, 2.5, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UNUPDATE, 0, 95, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 55, 0.35, 0 , 0 },  //黄色
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 20, 0, !_EDGE, Judge::UPDATE, 00, 12, 0, 0, 0, 0.0, 0 , 0 },  //黄色
                  //  {0, Section::TRACER, Section::LENGTH, 25, 0, 15, 5.0, 2.0, 0, 0 /*setparam*/, 0, 0, 00, 0, !_EDGE, Judge::UPDATE, 00, 35, 0, 0,0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, !_EDGE, Judge::UPDATE, 00, 0, 0, 0, 138, 0.35, 0 , 0 },  //緑色
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -9.8*sign, 0, 0, false, Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0},

                  // entry ブロック置き
                  //  //{0, Section::VIRTUAL2, Section::LENGTH, 10, 0,40, 10.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 78, 0, 0, 0, 0, 0}, //下り  entry
                  //  // etry 超音波センサーテスト
                  //  {0, Section::VIRTUAL2, Section::SONER, 5, 0,40, 10.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 31, 0, 0, 0, 0, 0}, //下り  entry

                  // advanced センター置き
                  // {0, Section::TRACER, Section::LENGTH, 10, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, //下り  advanced
                  // {0, Section::WALKER, Section::LENGTH, 00, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 15, 0, false, Judge::UNUPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -11.5*sign, 0, 0, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::VIRTUAL2, Section::LENGTH, 25, 0,30, 15.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0}, //下り  advanced
                  // {0, Section::VIRTUAL2, Section::LENGTH, 5, 0,30, 15.0, 5.0, 1, 1 /*setparam*/, -90*sign, 0, 0, 0, false, Judge::UNUPDATE, 0, 66, 0, 0, 0, 0, 0}, //下り  advanced
                  // //センター置き終了
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -4, 0, 0, 0,0 , 0 , 0 },  


                  // // advanced ビンゴテスト
                  // {0, Section::WALKER, Section::TURNANGLE,0, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 10*sign, false, Judge::UPDATE, -89*sign, 0, 0, 0, 0, 0, 0}, //下り  advanced
                  // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -5, 0, _EDGE, Judge::UPDATE, 00, -10, 0, 0,  0,0 , 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, 8, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 5, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 10, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0},
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   //設置完了
                  // // 設置後旋回して次の交点
                  // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*0.7, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   //設置完了
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*0.7, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  // //旋回（左）後交点まで
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                  // //旋回（左）後交点まで
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  // //旋回（左）後交点まで
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  RED,0.3, 0, 0}, 
                  //  // 設置（左） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UPDATE, 50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 18, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  // //旋回（左）後設置
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, 20, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::VIRTUAL, Section::TURNANGLE, 10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.5*sign, 0, 0, false, Judge::UNUPDATE, (90+80)*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 10.5*sign, 0, 0, false, Judge::UNUPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  //   // 前方交点まで
                  // {0, Section::TRACER, Section::LENGTH, 10, 0,30, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 15, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  YELLOW,0.3, 0, 0}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  // //旋回（左）後交点まで
                  //  {0, Section::VIRTUAL, Section::TURNANGLE, bspd2, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false, Judge::UPDATE, 90*sign, 0, 0, 0, 0, 0, 0},
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 12, 0, 0, 0, 0, 0}, 
                  // {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  GREEN,0.3, 0, 0}, 
                  //   // 前方交点まで
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::TRACER, Section::LENGTH, bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UNUPDATE, 0, 20, 0, 0, 0, 0, 0}, 
                  //  {0, Section::WALKER, Section::COLOR, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,  BLUE,0.3, 0, 0}, 
                  //  // 設置（右） 
                  //  {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE, Judge::UPDATE, 00, 5, 0, 0,0, 0, 0}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UPDATE, -50*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 
                  // {0, Section::VIRTUAL, Section::TURNANGLE, -10, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false, Judge::UNUPDATE, 0*sign, 0, 0, 0, 0, 0, 0},
                  //  {0, Section::WALKER, Section::STOP, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 0, 0, 0,0, 0,5}, 



                   {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 00, 100000, 0, 0,0, 0, 0}, 

                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0},

};
  
  wParam a[50] = {{0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 54, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0.1, 0.1, 1, 1 /*setparam*/, 0, 61, 0, 30, false, Judge::UPDATE, 86, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0, 0, 1, 1 /*setparam*/, 88, 0, 30, 0, false, Judge::UNUPDATE, 0, 186, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 30, 0.1, 0.1, 1, 1 /*setparam*/, 0, 30, 0, 30, false, Judge::UNUPDATE, 170, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, 178, 0, 30, 0, false, Judge::UNUPDATE, 0, 245, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 0, 0, 0, 1, 1 /*setparam*/, -2, 0, 30, 0, false, Judge::UNUPDATE, 0, 240, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -45, 0, 10, 0.01, 0.2, 1, 1 /*setparam*/, -2, 0, 30, 0, false, Judge::UNUPDATE, 0, 150, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, -40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 40, 0, 0, false, Judge::UNUPDATE, 90, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, -40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, -88, 0, 30, 0, false, Judge::UNUPDATE, 0, 80, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 1, 0.1, 0.1, 1, 1 /*setparam*/, 89, 0, 30, 0, false, Judge::UNUPDATE, 0, 90, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 32, 0, 0, false, Judge::UNUPDATE, 176, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 176, 0, 30, 0, false, Judge::UNUPDATE, 0, 298, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -30, 0, 0, false, Judge::UNUPDATE, 94, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::LENGTH, 40, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 90, 0, 30, 0, false, Judge::UNUPDATE, 0, 471, 0, 0, 0, 0, 0},
                   {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 30, false, Judge::UNUPDATE, 60, 0, 0, 0, 0, 0, 0},
                   {0, Section::VIRTUAL2, Section::BRIGHTNESS, 20, 0, 10, 0.02, 0.01, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, -0.3, 0, 0, 0, 0},
                   {0, Section::TRACER, Section::LENGTH, 10, 0, 30, 0.2, 0.2, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UPDATE, 0, 7, 0, 0, 207, 0.35, 0},
                   {0, Section::TRACER, Section::COLOR, 10, 0, 30, 0.2, 0.2, 1, 1 /*setparam*/, 0, 0, 30, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 207, 0.35, 0},
                   {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 1, 1 /*setparam*/, 0, 0, 0, 0, false, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

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
  wParam *array[10] = {outer_adv2, b};
//  wParam *array[10] = {outer_adv3, b}; //コーナーオブジェクト乗り越え
  wParam *wp;
};
#endif
