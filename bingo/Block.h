#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "TravelableArea.h"

typedef struct gameCoordinates    //ゲーム内座標
{
    double x;
    double y;
} gameCoordinates;

class Block
{
public:
    Block(int n);    //コンストラクタ
    bool getSuccsesPass();    //有効移動成立のゲッタ
    void EffectiveMovementJudgment();    //ブロック有効移動判定

private:
    int block_num;   //ブロックナンバー
    bool succses_pass = false;    //有効移動が成立すればtrue
    static const double r;    //半径
    static const double h;    //高さ

    TravelableArea *travelable_area;
};

#endif