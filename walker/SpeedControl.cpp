#include "SpeedControl.h"

SpeedControl::SpeedControl(Odometry *odo,Velocity *v):
    mOdo(odo),
    mVelo(v),
    mForward(0),
    mCurrentSpeed(0.0),
    mMode_flag(true),
    mBreake_flag(false)
{
    mPid = new PID(0.0166666*4);
    mPid->debug = false;
    mPid->debug_char = 'S';

}

void SpeedControl::setTargetSpeed(double speed)
{
    static double prev_speed=0;
    double bai =1.0;
    //float bai =0.3;
    //float bai =speed/60.0;

    float spd = fmax(fabs(mTargetSpeed),fabs(speed));
    /*if(spd<70) bai=1.3;
    if(spd<50) bai=0.8;
    if(spd<36) bai=0.7;*/

   // bai*=1.0;
   // if(fabs(mTargetSpeed)<31) bai=0.25;

    if(mTargetSpeed!=speed) {
        mPid->resetParam();
        if(mTargetSpeed*speed<0) { 
            bai =0.6;
        }
        if(fabs(mTargetSpeed)>fabs(speed)) {
            bai =1.2;    
        }
    }

    mTargetSpeed = speed;

    mPid->setTarget(speed);

    mPid->setKp(0.4*bai);
    mPid->setKi(0.01);
        //mPid->setKd(0.03*bai);
    mPid->setKd(0.08*bai);
    mPid->setLimit(8*bai+1);    // 9*bai+1
    //mPid->setLimit(1);    

}

int SpeedControl::getPwm()
{
    // 直接制御なら
   // mMode_flag=false;
    if(!mMode_flag) {
	    //ev3_speaker_play_tone(NOTE_F4,50);
        mForward = mTargetSpeed;
        return mTargetSpeed;
    }
    //停止モード
    if(mBreake_flag) {
        mForward=0;
        return 0;
    }
  if(mCnt++==4) { // 80ms毎に速度制御
    mCurrentSpeed = mVelo->getValue();
    double op = mPid->getOperation(mCurrentSpeed);
  //  syslog(LOG_NOTICE,"spd %d fwd %d op%d",(int)mCurrentSpeed,(int)mForward,(int)op);
   int pwd = (int)((op>0)?(op+0.5):(op-0.5));
    mForward += pwd; 
    int maxFwd = fabs(mTargetSpeed)>0?fabs(mTargetSpeed)*2.5:85;
    if (maxFwd>85) maxFwd=85;

    if(mForward>maxFwd) {
        // syslog(LOG_NOTICE,"over speed");
        mForward=maxFwd;
    }

    if(mForward<-maxFwd) {
        // syslog(LOG_NOTICE,"over speed");
       mForward=-maxFwd;
    }
   
    mCnt=0;  
  //  static char buf[256];
 //   sprintf(buf,"op%3.1f fwd%2.1d v:%2.1f",op,mForward,mOdo->getVelocity());
//    msg_f(buf,12);
    }
    return mForward;
}

void SpeedControl::resetParam()
{
    mForward = 0;
    mCnt=0;
    mPid->resetParam();
}

void SpeedControl::setMode(bool mode)
{
    mMode_flag=mode;
}
void SpeedControl::setBreak(bool brk)
{
    mBreake_flag=brk;
}

double SpeedControl::getCurrentFwd()
{
    return mForward;
}

double SpeedControl::getCurrentSpeed()
{
    return mCurrentSpeed;
}
