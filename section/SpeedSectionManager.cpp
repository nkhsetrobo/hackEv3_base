#include "SpeedSectionManager.h"
#include "Section.h"
#include "Scene.h"


SpeedSectionManager::SpeedSectionManager() : SectionManager()
{




}



  void SpeedSectionManager::init()
  {
    wParam *wp;
 
 
    if(Scene::COURSE==0) 
      mIdx=1;    
    else 
      mIdx=0;    

    wp = array[mIdx];
    init(wp);
  }
  
