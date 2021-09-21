#include "Section.h"
 
extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
extern VirtualLineTracer *gVitual;
extern Odometry *gOdo;
extern SpeedControl *gSpeed;
extern TailWalker *gTailWalker;



Section::Section()
{
    first=true;
    first2=true;
    emergency=false;
    mEmergencyJudge=nullptr;
}

Section::~Section()
{
    // msg_log("destruct Section");
    delete mWalker;
    delete mJudge;
    if (mEmergencyJudge!=nullptr)
        delete mEmergencyJudge;
}


bool Section::run()
{
    error_code=0;
    if(first2){
        // msg_log("3");
        //printf("emg %d\n",emergency);
        mJudge->init();
        if(emergency)
            mEmergencyJudge->init();
        first2 = false;
    }
    //判定
    if(mJudge->run()){
        return true;
    }
    if(emergency && mEmergencyJudge->run()){
        error_code=1;
        printf("Emergency Stop!!!\n");
        return true;
    }

    //走法
    if(first){
        mWalker->init();
        first = false;
    }
    mWalker->run();
    
    return false;
}

Walker *Section::selectWalker(int  no)
{
    switch(no) {
        case WALKER:
            mWalker = (Walker*)(new SimpleWalker(gOdo,gSpeed));
            break;
        case TRACER:
            mWalker = (Walker*)(new LineTracer(gOdo,gSpeed));
           break;
        case VIRTUAL:
            mWalker = (Walker*)(new VirtualLineTracer(gOdo,gSpeed));
            break;
        case VIRTUAL2:
            mWalker = (Walker*)(new VirtualLineTracer2(gOdo,gSpeed));
            break;
        case TAIL:
            mWalker = (Walker*)(new TailWalker(gOdo,gSpeed));
            // ((TailWalker*)mWalker)->setFlag(1);
            break;
        case ARM:
            mWalker = (Walker*)(new ArmWalker(gOdo,gSpeed));
            // ((ArmWalker*)mWalker)->setFlag(1);
            break;
        default:
            printf("selectWalker error!! %d \n",no);
    }

    return mWalker;
}


Judge *Section::selectJudge(int no)
{
    emergency = false;
    mEmergencyJudge = nullptr;
    switch(no) {
        case LENGTH:
            mJudge = (Judge*)(new LengthJudge());
            break;
        case TURNANGLE:
            mJudge = (Judge*)(new TurnAngleJudge());
            break;
        case BRIGHTNESS:
            mJudge = (Judge*)(new BrightnessJudge());
            break;
        case COLOR:
            emergency=true;
            mJudge = (Judge*)(new ColorJudge());
            mEmergencyJudge =  (Judge*)(new LengthJudge());
            ((LengthJudge *)mEmergencyJudge)->setFinLength(20);
            ((LengthJudge *)mEmergencyJudge)->setupdate(Judge::UPDATE);
            break;
        case TAILANGLE:
            mJudge = (Judge*)(new TailAngleJudge());
            break;
        case ARMANGLE:
            mJudge = (Judge*)(new ArmAngleJudge());
            break;
        case STOP:
            mJudge = (Judge*)(new Stop());
            break;
        case SONER:
            mJudge = (Judge*)(new SonerJudge());
            break;
        default:
            printf("selectJudge error!! %d\n",no);
    }
    
    return mJudge;
}

void Section::init(){

    mWalker->init();
}

int Section::getError()
{
    return error_code;
}