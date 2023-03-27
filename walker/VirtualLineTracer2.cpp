#include "VirtualLineTracer2.h"
#include "math.h"
#define M_PI 3.14159265358979323846

extern float gStartAngle;

float VirtualLineTracer2::SX = 0;
float VirtualLineTracer2::SY = 0;
float VirtualLineTracer2::FX = 0;
float VirtualLineTracer2::FY = 0;

VirtualLineTracer2::VirtualLineTracer2(Odometry *odo,
                        SpeedControl *scon)
                         : SimpleWalker(odo,scon) {
    sx=0;
    sy=0;
    fx=0;
    fy=0;
    nx=0;
    ny=0;
    basedistance=0;
    mTarget=0;
    mTargetSpeed=0;
    mPFactor=0;
    mIFactor=0;
    mDFactor=0;
    mLimit = 100;

    initMode=0;

    mPid->resetParam();

    mPid->debug=false;
    mPid->debug_char = 'L';

    mLpf = new LowPassFilter();
    mLpf->setRate(0.8);

}

void VirtualLineTracer2::setParam(float speed,float kp, float ki, float kd,float angleTarget,float angleKp){


   // msg_log("testtt");
    mTargetSpeed = speed;
    
    mPFactor = kp;
    mIFactor = ki;
    mDFactor = kd;

  
    mTarget= 0;
    mPid->setTarget(mTarget);


   
    mCurve = angleTarget;
    mAngleKp = angleKp;

}

void    VirtualLineTracer2::setsPosition(float x,float y){
    sx = x+mXPosition->getvalue();
    sy = y+mYPosition->getvalue();

}
void    VirtualLineTracer2::setfPosition(float x,float y){
    fx = x+mXPosition->getvalue();
    fy = y+mYPosition->getvalue();

}

void  VirtualLineTracer2::setRelaTurnAngle(float angle,float dangle){
setsPosition(0,0);
setfPosition( 100*cos((angle/180)*M_PI+(dangle/180)*M_PI), 100*sin((angle/180)*M_PI+(angle/180)*M_PI));
}
void  VirtualLineTracer2::setAbsTurnAngle(float angle){

    angle2=angle;

}


void    VirtualLineTracer2::setnPosition(){
    nx = mXPosition->getvalue();
    ny = mYPosition->getvalue();

}

void VirtualLineTracer2::setInitMode(int mode) {

    initMode = mode;
}

float VirtualLineTracer2::calcdistance(){


    float nx2=nx;
    float ny2=ny;

    float noze=2.0;
    double angle = mTurnAngle->getValue();
   if(mTargetSpeed>=0){
         nx2=nx2+noze*cos((angle/180)* M_PI);
         ny2=ny2+noze*sin((angle/180)* M_PI);
    }
    else{
         nx2=nx2-noze*cos((angle/180)* M_PI);
         ny2=ny2-noze*sin((angle/180)* M_PI);

     }



        double a1=(FY-SY)*nx2;
        double b1=(FX-SX)*ny2; 

        double a=(FY-SY)*nx2;
        double b=(FX-SX)*ny2; 
        double c=FX*SY;
        double d=FY*SX;
        static char buf[256];
        static char buf2[256];
        double ans = (a-b)+(c-d);
        double len =  ans/1.0;

        if(!flag) 
        {
            //   sprintf(buf,"%f,%f, %f,%f, %f,%f, %f,  %f,%f,%f,%f",nx2,ny2,sx,sy,fx,fy,(a-b+c-d),a,b,c,d);
            // sprintf(buf,"%f,%f  %f %f",nx2,ny2,ans, len);
            // sprintf(buf2,"%f,%f, %f,%f    %f",a,b,c,d ,a-b+c-d );
            // msg_log(buf);
            // msg_log(buf2);
            flag = true;
        }
       // printf("VT2 %f,%f<-%f,%f, %f,%f, %f,%f,%f,%f\n",nx2,ny2,nx,ny,  sx,sy,fx,fy);

    if(len>2.0) len=2.0;
    if(len<-2.0) len=-2.0;
    return len ;

} 

float VirtualLineTracer2::calcTurn(){
        
    float dist = calcdistance();
    mLpf->addValue(dist);
    dist = mLpf->getFillteredValue();
        float val1_turn =  mPid->getOperation(dist);


        //setBias(-mForward*(1-mCurve)/(1+mCurve)*mAngleKp);
        float turn =  val1_turn+mBias;
        return turn;
}

void VirtualLineTracer2::setBias(float curve){
     mBias = curve;

}

void VirtualLineTracer2::run(){
    setnPosition();
    mTurn = calcTurn();
       
    setCommandV((int)mTargetSpeed, (int)mTurn);
    SimpleWalker::run();


}

void VirtualLineTracer2::init(){


    sx = mXPosition->getvalue();
    sy = mYPosition->getvalue();
    // 現在の方向に向かうモード
    angle2 += gStartAngle; // 基準位置からの角度に変換
    if(initMode==2) {
        angle2 = mTurnAngle->getValue();
        if(mTargetSpeed<0) angle2 += 180;
    }

    float noze=1.0;

    fx = noze*cos((angle2/180)*M_PI)+sx;
    fy = noze*sin((angle2/180)*M_PI)+sy;

    // Mode0 Mode2 でグローバル変数に格納 Mode1 でそのまま継続
    if( initMode==0 || initMode==2) {
        SX=sx;
        SY=sy;
        FX=fx;
        FY=fy;
    }

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();

    setnPosition();
    float dist = calcdistance();
    mLpf->reset(dist);

    printf("****VirtualLineTracer 2****::init %f,%f,%f,%f  %f,%f,%f\n",SX,SY,FX,FY ,mPFactor,mIFactor,mDFactor);
   
}

void VirtualLineTracer2::setvangle(bool a){
    aflag = a;
}

