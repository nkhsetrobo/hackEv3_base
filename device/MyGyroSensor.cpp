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
    base_gang=0;
}

void MyGyroSensor::update()
{

    angvel = mGyro->getAnglerVelocity();
    
#if defined(MAKE_RASPIKE)
    float last_gang=gang;
    gang = mGyro->getAngle();
    if(base_gang+gang - last_gang>180) {
        base_gang -= 360;
    }
    else if(base_gang+gang - last_gang<-180) {
        base_gang += 360;
    }
    gang += base_gang;
    //printf("ANG %f: %d\n",gang,mGyro->getAngle() );
    mTurnAngle->update(gang);
#else
    gang = mGyro->getAngle();
#endif

    mAnglerVelocity->update(angvel);
    mGyroAngle->update(gang);

}

