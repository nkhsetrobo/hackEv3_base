#include "Section.h"
 
extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
extern Odometry *gOdo;
extern SpeedControl *gSpeed;

Section::Section()
{
}

Section::~Section()
{
    msg_log("destruct Section");
    delete mWalker;
}


bool Section::run()
{
    //判定
    
    if(mJudge->run()){
        return true;
    }

    //走法
    mWalker->run();
    
    return false;
}

Walker *Section::selectWalker(int no)
{
    switch(no) {
        case WALKER:
            mWalker = (Walker*)(new SimpleWalker(gOdo,gSpeed));
            break;
        case TRACER:
            mWalker = (Walker*)(new LineTracer(gOdo,gSpeed));
           break;
        default:
            msg_log("selectWalker error!!");
    }

    return mWalker;
}


Judge *Section::selectJudge(int no)
{
   // mJudge =(Judge*)(new LengthJudge());
   // return mJudge;

      //mJudge =(Judge*)(new TurnAngleJudge());
      //return mJudge;

       //mJudge =(Judge*)(new BrightnessJudge());
       //return mJudge;


        mJudge =(Judge*)(new ColorJudge());
        return mJudge;

}



