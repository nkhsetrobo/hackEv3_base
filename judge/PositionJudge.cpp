#include "PositionJudge.h"

PositionJudge::PositionJudge()
{

}

bool PositionJudge::run(){
    double cx = mXPosition->getvalue();
    double cy = mYPosition->getvalue(); 

    if(calcDist(cx,cy,mTargetX,mTargetY)<mDisance)
        return true;

    return false;
}

double PositionJudge::calcDist(double x1,double y1,double x2,double y2)
{
    double dist = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    printf("calcDist (%f,%f)-(%f,%f) = %f\n",x1,y1,x2,y2,dist);
    return dist;
}


void PositionJudge::init(){

    
}

void PositionJudge::setParam(double x, double y, double dist)
{
    mTargetX=x;
    mTargetY=y;
    mDisance=dist;
}