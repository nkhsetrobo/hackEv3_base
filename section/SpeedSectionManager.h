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

} wParam;

typedef struct _Param2
{

    int lflag;
    int tflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;
} jParam;

class SpeedSectionManager : public SectionManager
{
public:
    SpeedSectionManager();

protected:
private:
    int n;

    //{-1の時終了, Section::使いたいwalker, Section::使いたいjudge, 速度, 0, pの値, dの値, iの値, 0, 0 ,
    ///*setparam*/, 直線仮想ライントレースの角度, 円仮想ライントレースの半径, 単純走行のパワー, 単純走法の曲がり具合, 線のどちらを進むか}
    //setparamの例,Virtual2->setParam(10,5, 0.2, 0.2,1,1)
    // tracer->setParam(30,0,30,0.2,0.1)
    //Virtual->setParam(20,2,0.2,0,1,1)
    //Walker->setCommand(0,10)
    wParam wp[100] = {{0, Section::TRACER, Section::LENGTH, 20, 0, 30, 0.2, 0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, true},
                      {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true}};

    //{1の時現在地を更新可能, 1の時現在角度を更新可能, 終了角度, 終了距離,白黒割合 , 白黒計測フラグ, 色数値, 彩度数値}

    jParam jp[100] = {{1, 1, 0, 110, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0}};
    void setWalker(Section *sc);
    void setJudge(Section *sc);
};
#endif
