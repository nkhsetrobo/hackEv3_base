#include "SpeedControl.h"

SpeedControl::SpeedControl(Odometry *odo,Velocity *v):
    mOdo(odo),
    mVelo(v),
    mForward(0),
    mCurrentSpeed(0.0),
    mMode_flag(true),
    mBreake_flag(false)
{
    mPid = new PID(0.001*4);
    mPid->debug = false;
    mPid->debug_char = 'S';

    mClock= new Clock();
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
        mPow=0;
        mCnt=4;
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

  //  mPid->setKp(0.4*0.01);
  //  mPid->setKi(0.15);
    //mPid->setKp(2.0);
    mPid->setKp(0.5);
    mPid->setKi(0);
        //mPid->setKd(0.03*bai);
    mPid->setKd(0);
    mPid->setLimit(8*bai+1);    // 9*bai+1
    //mPid->setLimit(1);    

}

int SpeedControl::accel(int target)
{
    static float spd=0;
    if (target==0 || spd*target<0 ) {
        spd=0;
        return (int)spd;
    }
    if(target>spd) {
        spd+=0.1;
    } else {
        spd-=0.1;
    }
    if(target>0 && spd>target) {
        spd=target;
    } 
     if(target<0 && spd<target) {
        spd=target;
    } 
 
    return (int)spd;
}
int SpeedControl::getPwm()
{
   

    // 直接制御なら false
    mMode_flag=false;
    if(!mMode_flag) {
	    //ev3_speaker_play_tone(NOTE_F4,50);
       // mForward = accel(mTargetSpeed);
        mForward = mTargetSpeed;
        return mForward;
    }
    //停止モード
    if(mBreake_flag) {
        mForward=0;
        return 0;
    }
  if(mCnt++==8) { // 80ms毎に速度制御
    mCurrentSpeed = mVelo->getValue();
   // printf("speed %f\n",mCurrentSpeed);
    double op = mPid->getOperation(mCurrentSpeed);
  //  syslog(LOG_NOTICE,"spd %d fwd %d op%d",(int)mCurrentSpeed,(int)mForward,(int)op);
    mPow  += (op>=0)?mAcc:-mAcc;
    int maxDiff = 12;
    mPow = (mPow>maxDiff)?maxDiff:((mPow<-maxDiff)?-maxDiff:mPow);
   // if(mPow==10) printf("op %f , pow %f\n",op,mPow);
   int pwd = (int)((op>0)?(op+0.5):(op-0.5));
    //mForward += pwd; 
    mForward += mPow;

    int maxFwd = fabs(mTargetSpeed)>0?fabs(mTargetSpeed)*2.5:85;
    if (maxFwd>75) maxFwd=75;

    if(mForward>maxFwd) {
       // printf("over speed +\n");
        mPow=0;
        mForward=maxFwd;
    }

    if(mForward<-maxFwd) {
//printf("over speed - \n");
        mPow=0;
       mForward=-maxFwd;
    }
   
    mCnt=0;  
    //static char buf[256];
    //sprintf(buf,"op%3.1f fwd%2.1d v:%2.1f",op,mForward,mOdo->getVelocity());
    //msg_f(buf,12);
    }
    msg_num('s',mClock->now(),mCurrentSpeed,mForward,0,0);
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
