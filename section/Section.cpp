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
    mStatusJudge=nullptr;

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

    status=0;
    if (mStatusJudge!=nullptr)
        status = mStatusJudge->status();
        

   /* if(emergency && mEmergencyJudge->run()){
        error_code=1;
        printf("Emergency Stop!!!\n");
        return true;
    }*/

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
            printf("no selectWalker  %d \n",no);
    }

    return mWalker;
}

Judge *Section::selectJudge(int no)
{
    mJudge = selectJudgePtr(no);
    return  mJudge;
}

Judge *Section::selectStatusJudge(int no)
{
    mStatusJudge = selectJudgePtr(no);
    return  mStatusJudge;
}

Judge *Section::selectJudgePtr(int no)
{
    emergency = false;
    mEmergencyJudge = nullptr;
    Judge *jptr=nullptr;
    switch(no) {
        case LENGTH:
            jptr = (Judge*)(new LengthJudge());
            break;
        case TURNANGLE:
            jptr = (Judge*)(new TurnAngleJudge());
            break;
        case BRIGHTNESS:
            jptr = (Judge*)(new BrightnessJudge());
            break;
        case COLOR:
            emergency=true;
            jptr = (Judge*)(new ColorJudge());
            mEmergencyJudge =  (Judge*)(new LengthJudge());
            ((LengthJudge *)mEmergencyJudge)->setFinLength(20);
            ((LengthJudge *)mEmergencyJudge)->setupdate(Judge::UPDATE);
            break;
        case TAILANGLE:
            jptr = (Judge*)(new TailAngleJudge());
            break;
        case ARMANGLE:
            jptr = (Judge*)(new ArmAngleJudge());
            break;
        case STOP:
            jptr = (Judge*)(new Stop());
            break;
        case SONER:
            jptr = (Judge*)(new SonerJudge());
            break;
        case SONERSTATUS:
            jptr = (Judge*)(new SonerStatusJudge());
                printf("mStatusJudge %d\n",jptr);

            break;

        default:
            printf("no selectJudge  %d\n",no);
    }
    
    return jptr;
}

void Section::init(){

    mWalker->init();
}

int Section::getError()
{
    return error_code;
}

float Section::getStatus()
{
    return status;
}

void Section::setID(int i)
{
    id =i;
}

int Section::getID()
{
    return id;
}

Judge* Section::getJudge()
{
    return mJudge;
}