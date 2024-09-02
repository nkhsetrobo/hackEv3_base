#include "Section.h"
#include "HackEv3.h"

extern SimpleWalker *gWalker;
extern LineTracer *gTracer;
extern VirtualLineTracer *gVitual;
extern Odometry *gOdo;
extern SpeedControl *gSpeed;



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
    status=0;
    if (mStatusJudge!=nullptr) {
        if(first2) {
            mStatusJudge->init();
        }
        status = mStatusJudge->status();
    }
    
    if(mJudge!=nullptr) {
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
    } else {
        return true;
    }


        
#if defined(DEBUG_NOMOVE)
    return true;
#endif
   /* if(emergency && mEmergencyJudge->run()){
        error_code=1;
        printf("Emergency Stop!!!\n");
        return true;
    }*/

    if( mWalker!=nullptr) {
        //走法
        if(first){
            mWalker->init();
            first = false;
        }
        mWalker->run();
    }
    
    return false;
}

Walker *Section::selectWalker(int  no)
{
    printf("select Walker %d\n",no);
    switch(no) {
        case WALKER:
            mWalker = (Walker*)(new SimpleWalker(gOdo,gSpeed));
            break;
        case TRACER:
            mWalker = (Walker*)(new LineTracer(gOdo,gSpeed));
           break;
        case TURN:
            mWalker = (Walker*)(new TurnWalker(gOdo,gSpeed));
           break;
        case VIRTUAL:
            mWalker = (Walker*)(new VirtualLineTracer(gOdo,gSpeed));
            break;
        case VIRTUAL2:
            mWalker = (Walker*)(new VirtualLineTracer2(gOdo,gSpeed));
            break;
        case ARM:
            mWalker = (Walker*)(new ArmWalker(gOdo,gSpeed));
            // ((ArmWalker*)mWalker)->setFlag(1);
            break;
        case CAMTRACER:
            mWalker = new CameraTracer(gOdo,gSpeed);
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
            break;
        case COLORSTATUS:
            jptr =new ColorStatusJudge();            
            break;
        case COLORSTATUS_R:
            jptr =new ColorStatus_RJudge();            
            break;
        case CAMERACOLOR:
            jptr =new CameraColorJudge();            
            break;
        case CAMERACOLORSTATUS:
            jptr =new CameraColorStatusJudge();            
            break;
        case CAMERACARRYSTATUS:
            jptr =new CameraCarryStatusJudge();            
            break;
        case POSITION:
            jptr =new PositionJudge();            
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