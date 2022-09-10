#include "SlalomSectionManager.h"
#include "Section.h"
#include "MyColorSensor.h"
#include "util.h"

extern MyColorSensor *gColor;
extern Odometry *gOdo;

SlalomSectionManager::SlalomSectionManager():
  SectionManager()
{

}



  void SlalomSectionManager::init()
  {
    wParam *wp;

#if defined(MAKE_RIGHT)
      wp = array[0];
#else
      wp = array[0];
#endif
    init(wp);
  }


bool SlalomSectionManager::run()
{
    error_code=0;
    if(mSection[mSectionIdx]==nullptr)
        return true;

    if(mSection[mSectionIdx]->run()) {
      
       if(mSection[mSectionIdx]->getID()==ONBOARD ) {
          adjustLength();
       } 
       if(mSection[mSectionIdx]->getID()==CALIB ) {
            gColor->calibMax();
       } 
       if(mSection[mSectionIdx]->getID()==RESET_ANG ) {
            gOdo->reset();
       } 
       
        mSectionIdx++;
        printf("nextSection %d =============================\n",mSectionIdx);
    }

    return false;
}


void SlalomSectionManager::adjustLength()
{
      float dist = mSection[mSectionIdx]->getStatus();

      printf("adjust %f\n",dist);

      LengthJudge *j = (LengthJudge*)(mSection[mSectionIdx+1]->getJudge());

      float offset=3.0;
      float dist_adjust = 1.0;
      if( dist>17) {
        dist_adjust = 9.5;
      }else if( dist>16) {
        dist_adjust = 9.0;
      } else if(dist>15) {
        dist_adjust = 8.0;
      }else if( dist>14) {
        dist_adjust = 7.5;
      }else if( dist>13) {
        dist_adjust = 6.5;
      } else if( dist>12) {
        dist_adjust = 5.5;
      } else if( dist>11) {
        dist_adjust = 4.0;
      } else if( dist>10) {
        dist_adjust = 3.5;
      } else if(dist>9) {
        dist_adjust = 3.0;
      } else if(dist>8) {
        dist_adjust = 2.5;
      }else if(dist>7) {
        dist_adjust = 2.0;
      }

      j->setFinLength(dist_adjust+offset);


}

/*
void SlalomSectionManager::adjustLength()
{
      float dist = mSection[mSectionIdx]->getStatus();

      printf("adjust %f\n",dist);

      LengthJudge *j = (LengthJudge*)(mSection[mSectionIdx+1]->getJudge());

      float offset=2.5;
      float dist_adjust = 1.0;
      if( dist>20) {
        dist_adjust = 5.0;
      }else if( dist>18) {
        dist_adjust = 4.0;
      } 

      j->setFinLength(dist_adjust+offset);


}
*/