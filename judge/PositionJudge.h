#ifndef _POSITIONJUDGE_H_
#define _POSITIONJUDGE_H_

#include "Judge.h"
class PositionJudge : public Judge{
    public:
        PositionJudge();
        bool run();
        void init();
        void setParam(double x, double y, double dist);

    private:
        double calcDist(double x1,double y1,double x2,double y2);
        double mTargetX;
        double mTargetY;
        double mDisance;
    
};



#endif