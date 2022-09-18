#include "SlalomSectionManager.h"
#include "Section.h"
#include "MyColorSensor.h"
#include "util.h"
#include "Scene.h"
#include "HackEv3.h"

extern MyColorSensor *gColor;
extern Odometry *gOdo;

SlalomSectionManager::SlalomSectionManager():
  SectionManager()
{
  mIdx=0;
  #if defined(MAKE_RIGHT) && defined(PAT1)
      printf("@@@@@@@@@@@@@@@@@@@@@@@@@@ PRIMARY RIGHT PAT1\n");
      mIdx=0;
#elif defined(MAKE_RIGHT) && defined(PAT2)
      printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@ PRIMARY RIGHT PAT2\n");
      mIdx=1;
#elif !defined(MAKE_RIGHT) && defined(PAT1)
      printf("############################ PRIMARY LEFT PAT1\n");
      mIdx=2;
#else
      printf("############################ PRIMARY LEFT PAT2\n");
      mIdx=3;
#endif

}



  void SlalomSectionManager::init()
  {
    wParam *wp;
    // 0: LEFT PAT1, 1: LEFT,PAT2
    //3:RIGHT,PAT1.  4:RIGHT,PAT2
    if(Scene::COURSE==0) {
      mIdx=LPAT-1;      
      printf("############################ PRIMARY PAT %d\n",mIdx);
    }
    else {
      mIdx=RPAT+1;   
      printf("############################ PRIMARY PAT %d\n",mIdx);
    }

    wp = array[mIdx];
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
            //gColor->calibBright();
       } 
       if(mSection[mSectionIdx]->getID()==RESET_ANG ) {
            gOdo->reset();
       } 
       if(mSection[mSectionIdx]->getID()==SEL_COLOR ) {
            color = (int)mSection[mSectionIdx]->getStatus();
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

      float offset=2.0;
      float dist_adjust = 1.0;
      if( dist>17) {
        dist_adjust = 9.5;
      }else if( dist>16) {
        dist_adjust = 9.0;
      } else if(dist>15) {
        dist_adjust = 8.5;
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
        dist_adjust = 2.5;
      } else if(dist>8) {
        dist_adjust = 2.0;
      }else if(dist>7) {
        dist_adjust = 1.0;
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