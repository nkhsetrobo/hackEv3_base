#include "Block.h"

const double Block::r = 30;    //半径
const double Block::h = 30;    //半径

Block::Block(int n)    //コンストラクタ
{
    block_num = n;    //引数で受け取った番号をブロックナンバーに格納する
    succses_pass = false;    //有効移動成立のメンバ変数に初期値を格納する
}

bool Block::getSuccsesPass()
{
    return succses_pass;    //有効移動成立を表す変数をリターン
}

void Block::effectiveMovementJudgement()    //ブロックの有効移動判定
{
    succses_pass = true;    //有効移動成立
}
