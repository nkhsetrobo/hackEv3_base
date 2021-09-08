#ifndef _BLOCK_H_
#define _BLOCK_H_

class TravelableArea;

class Block
{
public:
    Block(int n);    //コンストラクタ
    bool getSuccsesPass();    //有効移動成立のゲッタ
    void effectiveMovementJudgment();    //ブロック有効移動判定

protected:
    int block_num;   //ブロックナンバー
    bool succses_pass = false;    //有効移動が成立すればtrue
    static const double r;    //半径
    static const double h;    //高さ;
};

#endif