#include "GarageSectionManager.h"
#include "Section.h"
#include "util.h"

GarageSectionManager::GarageSectionManager():
  SectionManager()
{

}

void GarageSectionManager::init()
  {
    wParam *wp;

#if defined(MAKE_RIGHT)
      wp = array[0];
#else
      wp = array[0];
#endif
    init(wp);
  }
  