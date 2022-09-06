#ifndef ODOMETRY_
#define ODOMETRY_

#include <math.h>
#include "util.h"

#include "Motor.h"
#include "Length.h"
#include "TurnAngle.h"
#include "Velocity.h"
#include "XPosition.h"
#include "YPosition.h"
#include "TailAngle.h"
#include "ArmAngle.h"

using namespace ev3api;

class Odometry
{
public:
	Odometry(Motor *left,
			Motor *right,
			Length *len,
			TurnAngle *angle,
			Velocity *velo,
			XPosition *xposition,
			YPosition *yposition,
			Motor *tail,
			TailAngle *tailangle,
			Motor *arm,
			ArmAngle *armangle);
	void update();
	void calc();
	void reset();
	void resetLength();
	void resetAngle();
	void setPwm(int left,int right);
	void setBrake(bool brake);
	void setTailpwm(int tail);
	void setArmpwm(int arm);

private:

	int accel_L(int target,int err);
	int accel_R(int target,int err);


	Motor *mLeftMotor;
	Motor *mRightMotor;
	Length *mLength;
	TurnAngle *mTurnAngle;
	Velocity *mVelocity;
	XPosition *mXPosition;
	YPosition *mYPosition;
	Motor *mTailMotor;
	TailAngle *mTailAngle;
	Motor *mArmMotor;
	ArmAngle *mArmAngle;

	int32_t current_rs1;
	int32_t current_rs2;
	
	int32_t prev_rs1;
	int32_t prev_rs2;

	double x;
	double y;

	double th;
	double rot;
	double dt;

	double deg;
	
	double sumx;
	double sumy;
	double sumth;
	double sumlen;

	int32_t current_rs3;
	int32_t current_rs4;


	int no_run_count_r=0;
	int no_run_count_l=0;

};

#endif
