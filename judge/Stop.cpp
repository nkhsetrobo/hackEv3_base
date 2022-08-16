#include "Stop.h"
#include "util.h"


extern float gStart;
extern float gStartAngle;

bool Stop::run()
{

   // printf("stop %d\n",mCount);
    if(mCount--!=0){
        return false;
    }
    else{
        return true;
    }


}

void  Stop::setParam(int count,int update)
{
    mCount=count;
    mUpdate = update;

}

void Stop::init()
{
    if (mUpdate == Judge::UPDATEALL) {
        printf("STOP update all\n");
        gStartAngle = mTurnAngle->getValue();
        gStart = mLength->getValue(); // 更新
    }
    
}