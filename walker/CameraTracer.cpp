
#include "CameraTracer.h"
#include <math.h>

#include "util.h"

extern PipeComm *gPcomm2;

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param balancingWalker 倒立走行
 */
CameraTracer::CameraTracer( Odometry *odo,
                        SpeedControl *scon
                    ) 
    : SimpleWalker(odo,scon)
{
    mPid2=new PID(0.1);
    mPid2->debug = true;
    mPid2->debug_char='c';

    mPcomm  = gPcomm2;

}


CameraTracer::~CameraTracer()
{
    stp_cyc(SEND_RCV_TASK2);
}
 
void CameraTracer::run()
{
    char get[256];
    mPcomm->getResponse(get);
    double center=atoi(get);
    if(center<40) center=40;
    if(center>60) center=60;
    mTurn = calcTurn(center);
    if(center==0)
        mTurn=0;

   /* static char buf[256];
    sprintf(buf,"LT %2.3f, %d,%d",brightness,mTargetSpeed,mTurn);
    msg_log(buf);*/
    printf("CT %s, %f,%d\n",get,center,mTurn);

    setCommandV((int)mTargetSpeed, (int)mTurn);

    SimpleWalker::run();

}


   
float CameraTracer::calcTurn(float val1) {

    mPid2->setKp(mPFactor); 
    mPid2->setKi(mIFactor);
    mPid2->setKd(mDFactor);

    float val1_turn =  mPid2->getOperation(val1);

    float turn =  val1_turn;
   
    return turn;
}


void CameraTracer::setParam(float speed,float target,float kp, float ki, float kd) 
{

    printf("Cameratracer setParam %2.1f,%3.1f,  %3.1f,%3.1f,%3.1f\n",speed,target, kp,ki,kd);
  
    mTargetSpeed = speed;
    mTarget= target;
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

  
    mPid2->setTarget(mTarget);
    mPid2->setKp(mPFactor); 
    mPid2->setKi(mIFactor);
    mPid2->setKd(mDFactor);
   
    mPid2->resetParam();

}




void CameraTracer::init(){

    printf("cameraTracer execParam %d,  %3.1f,%3.1f,%3.1f\n",mTargetSpeed, mPFactor,mIFactor,mDFactor);
    mPid2->setKp(mPFactor); 
    mPid2->setKi(mIFactor);
    mPid2->setKd(mDFactor);
    mPid2->resetParam();
    
    sta_cyc(SEND_RCV_CYC2);

}
