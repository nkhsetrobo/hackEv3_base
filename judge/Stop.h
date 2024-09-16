#ifndef _STOP_H_
#define _STOP_H_

#include "Judge.h"

class Stop : public Judge
{
    public :

        bool  run();
        void  setCount(int count);

    private : 
        int mCount;
        
};



#endif