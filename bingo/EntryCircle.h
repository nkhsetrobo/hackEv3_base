#ifndef _ENTRY_CIRCLE_H_
#define _ENTRY_CIRCLE_H_

#include "PassingCircle.h"

class EntryCircle : public PassingCircle
{
public:
    EntryCircle();    //コンストラクタ
private:
    int entry_circle_num;    //進入サークルナンバー
    int c_color;    //色
};

#endif