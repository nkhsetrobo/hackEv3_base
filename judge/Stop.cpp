#include "Stop.h"
#include "util.h"

bool Stop::run()
{


    mCount=mCount-1;
    if(mCount!=0){
        return false;
    }
    else{
        return true;
    }


}

void  Stop::setCount(int count)
{
    mCount=count;
}