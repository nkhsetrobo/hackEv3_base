#ifndef _STOP_H_
#define _STOP_H_

#include "Judge.h"

class Stop : public Judge
{
    public :

        bool  run();
        void  setParam(int count,int update);
        void init();

    private : 
        int mCount;
        int mUpdate;
        
};



#endif