#include "MyGyroSensor.h"

extern TurnAngle *gTurnAngle;

MyGyroSensor::MyGyroSensor(ePortS port,
                            AnglerVelocity* angv,
                            GyroAngle* ga):
    mPort(port),
    mAnglerVelocity(angv),
    mGyroAngle(ga),
    mTurnAngle(gTurnAngle)
    
{
    mGyro = new GyroSensor(mPort);
    angvel = 0.0;
    gang = 0.0;
    base_gang=-mGyro->getAngle();

    gang_v =0;

    clk = new Clock();
}

void MyGyroSensor::reset()
{
    mGyro = new GyroSensor(mPort);
    mGyro->reset();
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


    
#if defined(MAKE_RASPIKE)
    double hosei=1.0;
    static float angvel[2];
    angvel[0]=angvel[1];
    angvel[1] = mGyro->getAnglerVelocity();
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

