#define _USE_MATH_DEFINES

#include "Odometry.h"
#include "math.h"
#include "HackEv3.h"
#include "util.h"

#define M_PI 3.14159265358979323846


Odometry::Odometry(Motor *left, Motor *right,
					Length *len,
					TurnAngle *angle,
					Velocity *velo,
					XPosition *xposition,
					YPosition *yposition,
					Motor *tail,
					TailAngle *tailangle,
					Motor *arm,
					ArmAngle *armangle):
	mLeftMotor(left),
	mRightMotor(right),
	mTurnAngle(angle),
	mLength(len),
	mVelocity(velo),
	mXPosition(xposition),
	mYPosition(yposition),
	mTailMotor(tail),
	mTailAngle(tailangle),
	mArmMotor(arm),
	mArmAngle(armangle)
{
	mLeftMotor->reset();
	mRightMotor->reset();
	mTailMotor->reset();
	mArmMotor->reset();

	x=y=th=0.0;
	sumlen=0;
	prev_rs1=current_rs1=0;
	prev_rs2=current_rs2=0;
}



void Odometry::reset() 
{
	resetLength();
	resetAngle();

}
void Odometry::resetLength()
{
	sumlen=0.0;	
}
void Odometry::resetAngle()
{
	th=0.0;
	x=y=0;
	deg = 0.0;
}

void Odometry::update()
{
	current_rs1 = mLeftMotor->getCount();
	current_rs2 = mRightMotor->getCount();
	current_rs3 = mTailMotor->getCount();
	current_rs4 = mArmMotor->getCount();
	mTailAngle->update(current_rs3);
	mArmAngle->update(current_rs4);

	calc();
	mVelocity->update(current_rs1,current_rs2);

	prev_rs1=current_rs1;
	prev_rs2=current_rs2;
}

void Odometry::calc()
{

	static int count=0;
	static double last_angle=0;
	static int carib_cnt=0;
	static double tread_err=0;

	float rs1 = current_rs1;
	float rs2 = current_rs2;

	//syslog(LOG_NOTICE,"rs1,rs2 = %d,%d <- %d,%d",(int)rs1,(int)rs2, prev_rs1,prev_rs2);

	float drs1=rs1-prev_rs1;
	float drs2=rs2-prev_rs2;

	float len_l = drs1*M_PI*D_LEFT/360.0;
	float len_r = drs2*M_PI*D_RIGHT/360.0;
	float dth=(len_r-len_l)/(TREAD+tread_err);



#if defined(MAKE_RASPIKE)
//	double current_angle = mTurnAngle->getValue();
//	dth = (current_angle - last_angle)*M_PI/180;
//	last_angle =  current_angle;
	if(fabs(len_l)>0.2) 
		no_run_count_l=0;
	else
		no_run_count_l++;
	if(fabs(len_r)>0.2) 
		no_run_count_r=0;
	else
		no_run_count_r++;
#endif
	
	x+= (len_r+len_l)/2.0*cos(th+dth/2.0); //進行方向 X軸 0度方向
	y+= (len_r+len_l)/2.0*sin(th+dth/2.0); //横	

	th+=dth; // 左旋回＋、右旋回-
	sumlen += (len_r+len_l)/2.0;

/*
	if(++carib_cnt>100) {
		double diff = th - current_angle*M_PI/180;
		tread_err -= diff*1.0;
		//th = current_angle*M_PI/180;
		printf("tread error %f\n",tread_err);
		carib_cnt=0;
	}*/

	//printf("odometry %f, gyro %f\n",th*180/M_PI, current_angle);

	mLength->update(sumlen);
	mTurnAngle->update(th);
	mXPosition->update(x);
	mYPosition->update(y);
    static char buf[256];
	static int out_cnt=0;
	/*if(out_cnt++%100==0) {
		//sprintf(buf," %f,%f,%f\n",x,y,((th*180)/M_PI));
		//msg_log(buf);
		out_cnt=0;
	}*/

}

void Odometry::setPwm(int left,int right)
{
	/*static char buf[256];
    sprintf(buf,"Left %d, Right %d",left,right);
    msg_log(buf);*/
	int left_err=0;
	int right_err=0;

	int force_pwm=65;
	int force_cnt=250;
	if (left!=0 && no_run_count_l>force_cnt) {
		left = left>0?force_pwm:-force_pwm;
		left_err=1;
		printf("pulse L\n");
	}
	if (right!=0 && no_run_count_r>force_cnt) {
		right = right>0?force_pwm:-force_pwm;
		right_err=1;
		printf("pulse R\n");
	}
   // printf("Left %d, Right %d",left,right);

#if !defined(MAKE_SIM)
	int volt = ev3_battery_voltage_mV();
	double rate = 8343.0/volt;
	left*=rate;
	right*=rate;	
#endif
#if !defined(MAKE_RASPIKE)
	left = accel_L(left,left_err);
	right = accel_R(right,right_err);
#endif
	mLeftMotor->setPWM(left);
	mRightMotor->setPWM(right);
}

void Odometry::setBrake(bool brake)
{
	mLeftMotor->setBrake(brake);
	mRightMotor->setBrake(brake);
}

void Odometry::setTailpwm(int tail)
{
	mTailMotor->setPWM(tail);
}

void Odometry::setArmpwm(int arm)
{
	mArmMotor->setPWM(arm);
}

static double acc=0.1;
int Odometry::accel_L(int target,int err)
{
    static float spd=0;
    if (target==0 || spd*target<0 ) {
        spd=0;
        return (int)spd;
    }
	if(err==0) {
		if(target>spd) {
			spd+=acc;
		} else {
			spd-=acc;
		}
		if(target>0 && spd>target) {
			spd-=acc;
			//spd=target;
		} 
		if(target<0 && spd<target) {
			spd+=acc;
			//spd=target;
		} 
	} else {
		if(target>0) {
			spd+=acc;
		} else {
			spd-=acc;
		}
				
	}
	printf("Lspd %f\n",spd);
 
    return (int)spd;
}

int Odometry::accel_R(int target,int err)
{
    static float spd=0;
    if (target==0 || spd*target<0 ) {
        spd=0;
        return (int)spd;
    }
	if(err==0) {

		if(target>spd) {
			spd+=acc;
		} else {
			spd-=acc;
		}

		if(target>0 && spd>target) {
			spd-=acc;
//			spd=target;
		} 
		if(target<0 && spd<target) {
			spd+=acc;
			//spd=target;
		} 
	} else {
		if(target>0) {
			spd+=acc;
		} else {
			spd-=acc;
		}
		
	}
 		printf("Rspd %f\n",spd);

    return (int)spd;
}