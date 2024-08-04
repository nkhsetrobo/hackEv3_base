#include "MyGyroSensor.h"

extern TurnAngle *gTurnAngle;

MyGyroSensor::MyGyroSensor( AnglerVelocity* angv,
                            GyroAngle* ga):
    mAnglerVelocity(angv),
    mGyroAngle(ga),
    mTurnAngle(gTurnAngle),
    mState(UNDEFINED)
    
{
    angvel = 0.0;
    gang = 0.0;
   // base_gang=-mGyro->getAngle();

    gang_v =0;
    ang_v[0]=ang_v[1]=ang_v[2]=0;
    hub_imu_init();

    init_cnt=0;

}

void MyGyroSensor::reset()
{
    hub_imu_init();
    //mGyro->setOffset(0);
    gang = 0;
    //base_gang=-mGyro->getAngle();
    base_gang=0;
//    for (int i=0;i<10000;i++) {
//        printf("reset ang %d %d\n",i,mGyro->getAngle());
//   }

}
void MyGyroSensor::update()
{
    switch (mState) {
        case UNDEFINED:
            mState=INIT;
            break;
        case INIT:
            execInit();
            break;
        case RUNNING:
            execUpdate();
            break;
    }
}

void MyGyroSensor::execInit()
{
    float imu[3];
    hub_imu_get_angular_velocity(imu);
    offset[0] += imu[0];
    offset[1] += imu[1];
    offset[2] += imu[2];

    init_cnt++;
    if(init_cnt==500) {
        offset[0] /=500;
        offset[1] /=500;
        offset[2] /=500;
        printf("imu offset %f,%f,%f\n",offset[0],offset[1],offset[2]);
        mState=RUNNING;
    }
}


void MyGyroSensor::execUpdate()
{

    
    
#if defined(MAKE_RASPIKE)
    double hosei=1.0;
    static float angvel[2];
    angvel[0]=angvel[1];
    float imu[3];
    hub_imu_get_angular_velocity(imu);
   // angvel[1]=imu[0]; //仮です
    ang_v[0] += (imu[0]-offset[0])/100.0;
    ang_v[1] += (imu[1]-offset[1])/100.0;
    ang_v[2] += (imu[2]-offset[2])/100.0;

    angvel[1] += ((imu[0]-offset[0])*0.8660254 + (imu[2]-offset[2])*0.5 )/100.0;
    
    printf("ang_v %f,%f,%f %f\n",ang_v[0],ang_v[1],ang_v[2], angvel[1]);

    gang -= (angvel[1]+angvel[0])*0.01/2;
  /*  
    double last_gang=gang;
    double hosei=0.95;

    gang = mGyro->getAngle();
    if(base_gang+gang - last_gang>180) {
        base_gang -= 360;
    }
    else if(base_gang+gang - last_gang<-180) {
        base_gang += 360;
    }
    gang += base_gang;
    */
   //printf("ANG %f: %d,%f\n",gang*hosei,mGyro->getAngle(),angvel[1] );
    //mTurnAngle->update(-gang*3.141592/180* hosei);

    //gang_v += angvel*0.01;
    //printf("ANGV %f %d\n",gang_v, clk->now() );
#else
    gang = mGyro->getAngle();
#endif

    mAnglerVelocity->update(angvel[1]);
    mGyroAngle->update(-gang);

}

