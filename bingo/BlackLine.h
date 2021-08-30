#ifndef _BLACK_LINE_H_
#define _BLACK_LINE_H_

#include "TravelableArea.h"

class BalckLine : public TravelableArea
{
public:
    BlackLine();    //コンストラクタ
private:
    static const double length;    //長さ(定数)
};

#endif