#include "GarageSectionManager.h"
#include "Section.h"
#include "util.h"
#include "Scene.h"

GarageSectionManager::GarageSectionManager():
  SectionManager()
{
  color=0;
}

void GarageSectionManager::init()
  {
    wParam *wp;
    int base_idx=0;
    if(Scene::COURSE==0) 
      base_idx=0;      
    else 
      base_idx=4;   
    wp = array[base_idx+color];

    init(wp);
  }

void GarageSectionManager::setColor(int col)
{
  if (col<0 || col>4) col=3; // 識別できない色は黄色
  color = col;
}
  