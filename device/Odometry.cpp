#define _USE_MATH_DEFINES

#include "Odometry.h"
#include "math.h"
#include "HackEv3.h"

#define M_PI 3.14159265358979323846


Odometry::Odometry(Motor *left, Motor *right,
					Length *len,
					TurnAngle *angle,
					Velocity *velo):
	mLeftMotor(left),
	mRightMotor(right),
	mTurnAngle(angle),
	mLength(len),
	mVelocity(velo)
{
	mLeftMotor->reset();
	mRightMotor->reset();

	x=y=th=0.0;
	sumlen=0;
	prev_rs1=current_rs1=0;
	prev_rs2=current_rs2=0;

	current_lpwm=current_rpwm=0;
	pwm_rate=10;

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
	
	calc();
	mVelocity->update(current_rs1,current_rs2);

	prev_rs1=current_rs1;
	prev_rs2=current_rs2;
}

void Odometry::calc()
{

	static int count=0;

	float rs1 = current_rs1;
	float rs2 = current_rs2;

	//syslog(LOG_NOTICE,"rs1,rs2 = %d,%d <- %d,%d",(int)rs1,(int)rs2, prev_rs1,prev_rs2);

	float drs1=rs1-prev_rs1;
	float drs2=rs2-prev_rs2;

	float len_l = drs1*M_PI*D_LEFT/360.0;
	float len_r = drs2*M_PI*D_RIGHT/360.0;
	float dth=(len_r-len_l)/TREAD;
	
	x+= (len_r+len_l)/2.0*cos(th+dth/2.0); //進行方向 X軸 0度方向
	y+= (len_r+len_l)/2.0*sin(th+dth/2.0); //横	

	th+=dth; // 左旋回＋、右旋回-
	sumlen += (len_r+len_l)/2.0;

	mLength->update(sumlen);
	mTurnAngle->update(th);

}

void Odometry::setPwm(int left,int right)
{
<<<<<<< Updated upstream
	mLeftMotor->setPWM(left);
	mRightMotor->setPWM(right);
=======
	/*static char buf[256];
    sprintf(buf,"Left %d, Right %d",left,right);
    msg_log(buf);*/
	// double diff_r,diff_l;
	// double max=0.2;
	// static double max_l=0.1,max_r=0.1;
	// static int l_up,r_up;
	// int cur_l_up,cur_r_up;
	// if (current_lpwm<left) cur_l_up=1;
	// else if(current_lpwm>left) cur_l_up=-1;
	// else cur_l_up=0;
	// if (current_rpwm<right) cur_r_up=1;
	// else if(current_rpwm>right) cur_r_up=-1;
	// else cur_r_up=0;
	// if(cur_l_up!=l_up) 
	// 	max_l=0.2;
	// if(cur_r_up!=r_up) 
	// 	max_r=0.2;
	// l_up = cur_l_up;
	// r_up = cur_r_up;

	// // if(current_lpwm<left) 
	// // 	diff_l=(left-current_lpwm);
	// // else 
	// // 	diff_l=(current_lpwm-left);
	// diff_l=left-current_lpwm;
	// if(diff_l>max_l) diff_l=max_l;
	// if(diff_l<-max_l) diff_l=-max_l;
	// current_lpwm += diff_l;
	// max_l+=0.2;
	// if(max_l>20) max_l=20;

	// // if(current_rpwm<right) 
	// // 	diff_r=(right-current_rpwm);
	// // else 
	// // 	diff_r=(current_rpwm-right);
	// diff_r=right-current_rpwm;
	// if(diff_r>max_r) diff_r=max_r;
	// if(diff_r<-max_r) diff_r=-max_r;
	// current_rpwm += diff_r;
	// max_r+=0.2;
	// if(max_r>20) max_r=20;
	static double left_acc = 0.0;
	static double right_acc = 0.0;

	// if (left>current_lpwm)
	// 	left_acc += 0.2;
	// else if (left<current_lpwm)
	// 	left_acc -= 0.2;
	// else 
	// 	left_acc=0;

	// if (left_acc>2) left_acc=2;
	// if (left_acc<-2) left_acc=-2;

	// if (right>current_rpwm)
	// 	right_acc += 0.2;
	// else if(right<current_rpwm)
	// 	right_acc -= 0.2;
	// else 
	// 	right_acc=0;

	// if (right_acc>2) right_acc=2;
	// if (right_acc<-2) right_acc=-2;

	// current_lpwm += left_acc;
	// current_rpwm += right_acc;
	current_lpwm=left;
	current_rpwm=right;
	//printf("pwm %f %f\n",current_lpwm,current_rpwm);
	mLeftMotor->setPWM(current_lpwm);
	mRightMotor->setPWM(current_rpwm);
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
>>>>>>> Stashed changes
}