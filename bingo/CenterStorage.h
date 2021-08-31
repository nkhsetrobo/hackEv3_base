#ifndef _CENTER_CIRCLE_H_
#define _CENTER_CIRCLE_H_

class CircleStorage : public BlockStorage
{
public:
    CircleStorage(int n, gameCoordinates c_coordinates);    //コンストラクタ
private:
    static const double r;    //半径
}
