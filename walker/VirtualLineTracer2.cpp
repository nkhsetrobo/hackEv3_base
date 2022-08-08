#include "VirtualLineTracer2.h"
#include "math.h"
#define M_PI 3.14159265358979323846

extern float gStartAngle;

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

    mPid->resetParam();

    mPid->debug=true;
    mPid->debug_char = 'L';

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

float VirtualLineTracer2::calcdistance(){


    float nx2=nx;
    float ny2=ny;

    float noze=2.0;

   if(mTargetSpeed>0){
         nx2=nx2+noze*cos((mTurnAngle->getValue()/180)* M_PI);
         ny2=ny2+noze*sin((mTurnAngle->getValue()/180)* M_PI);
    }
    else{
         nx2=nx2-noze*cos((mTurnAngle->getValue()/180)* M_PI);
         ny2=ny2-noze*sin((mTurnAngle->getValue()/180)* M_PI);

     }



     double a1=(fy-sy)*nx2;
     double b1=(fx-sx)*ny2; 
      
    float a=(fy-sy)*nx2;
    float b=(fx-sx)*ny2; 
    float c=fx*sy;
    float d=fy*sx;
      static char buf[256];
      static char buf2[256];
          float ans = (a-b)+(c-d);
        float len =  ans/100;
        if(!flag) 
        {
            //   sprintf(buf,"%f,%f, %f,%f, %f,%f, %f,  %f,%f,%f,%f",nx2,ny2,sx,sy,fx,fy,(a-b+c-d),a,b,c,d);
            // sprintf(buf,"%f,%f  %f %f",nx2,ny2,ans, len);
            // sprintf(buf2,"%f,%f, %f,%f    %f",a,b,c,d ,a-b+c-d );
            // msg_log(buf);
            // msg_log(buf2);
            flag = true;
        }
    if(len>2.0) len=2.0;
    if(len<-2.0) len=-2.0;
    return len ;

} 

float VirtualLineTracer2::calcTurn(){
        

        float val1_turn =  mPid->getOperation(calcdistance());


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
    angle2 += gStartAngle; // 基準位置からの角度に変換

    float noze=100.0;

    fx = noze*cos((angle2/180)*M_PI)+sx;
    fy = noze*sin((angle2/180)*M_PI)+sy;

    mPid->setKp(mPFactor); 
    mPid->setKi(mIFactor);
    mPid->setKd(mDFactor);
    mPid->resetParam();

    printf("VirtualLineTracer2::init %f,%f,%f,%f  %f,%f,%f\n",sx,sy,fx,fy ,mPFactor,mIFactor,mDFactor);
   
}

void VirtualLineTracer2::setvangle(bool a){
    aflag = a;
}

