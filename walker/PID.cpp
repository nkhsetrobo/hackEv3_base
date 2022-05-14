#include "PID.h"
#include "util.h"

PID::PID() 
{
    limit = 100;
    diff[0]=diff[1]=0.0;
    integral=0;
    DELTAT=0.01;

    resetFlg=true;
<<<<<<< Updated upstream
    
}
PID::PID(float delta) {
    PID();
    DELTAT=delta;
=======

    sec = 100;
    cnt=0;

    for(int i=0;i<sec;i++) 
        last_integral[i]=0.0f;

  //  printf("created %f %d\n",DELTAT,sec);

>>>>>>> Stashed changes
}
PID::~PID() 
{
}

void PID::setLimit(float limit) 
{
    this->limit = limit;
}
void PID::setTarget(float t)
{
    this->target = t;
}

float PID::getOperation(float value)
{

   static char buf[256];

    diff[0]=diff[1];
    diff[1] = target-value;
    float prev_i=integral;
   
    delta = (diff[1]-diff[0])/DELTAT;
    integral+=(diff[0]+diff[1])/2.0*DELTAT;   

    if(resetFlg) {
        delta=0.0f;
        integral=0.0f;
        resetFlg=false;
    }

    // 積分値のオーバーを防ぐ
    if (integral>11.0) 
        integral=11.0;
    if (integral<-11.0) 
        integral=-11.0;

 
    float val = diff[1]*Kp + delta*Kd + integral*Ki;

    if (debug) {
        sprintf(buf,"pid:(%3.1f-%3.1f), diff:%4.2f d:%4.2f i:%4.2f  op:%5.3f",target,value,diff[1],delta,integral,val);
        msg_log(buf);
    }

    if(val>limit) 
        val=limit;
    if(val<-limit)
        val=-limit;
    
    return val;
}

void PID::setKp(float kp)
{
    Kp = kp;
}

void PID::setKi(float ki)
{
    Ki = ki;
}

void PID::setKd(float kd)
{
    Kd = kd;
}

float PID::getDiff() 
{
    return diff[1];
}

float PID::getIntegral()
{
    return integral;
}

void PID::resetParam()
{
    if(debug)
        msg_f("reset PID",1);
    diff[0]=diff[1]=0.0f;
    integral=0;

}

float PID::getTarget()
{
    return target;
}

void PID::setDeltaT(float delta)
{
    DELTAT = delta;
}