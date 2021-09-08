#ifndef _PASSING_CIRCLE_H_
#define _PASSING_CIRCLE_H_

class TravelableArea;

class PassingCircle : public TravelableArea
{
public:
    PassingCircle(gameCoordinates c_coordinates);    //コンストラクタ
protected:
    static const double r;    //半径
};

#endif