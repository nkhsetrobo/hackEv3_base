#ifndef _BINGO_SECTION_MANAGER_H_
#define _BINGO_SECTION_MANAGER_H_

#include "SectionManager.h"
#include "RouteDecision.h"
#include "etroboc_ext.h"
#include "Struct.h"

enum State
    {
       INIT,
       RUN
    };

class BingoSectionManager : public SectionManager
{
public:
    BingoSectionManager();    //コンストラクタ
    bool run();    //走行する
    bool exe_run();
    void exe_number();
    void rdStateChange(RouteDecision *routeDecision);    //ルート決定状態遷移
    void mStateChange(State m_state);    //初期化、実行の状態遷移
    void init();    //初期化
    //void s_addSection();    //区間の追加
    void running();    //実行する
    void chengeToSenpai();    //先輩から受け継がれた形に変換する
    static RouteDecision *circle_decision;
    static RouteDecision *block_decision;
private:
   
    wParam3 wp[100];
    mParam p[100];
    State mState;    //状態の変数
    int n;
    RouteDecision *rdState;

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
    int ho=0;
    
    void setWalker(Section *sc);
    void setJudge(Section *sc);
};

#endif