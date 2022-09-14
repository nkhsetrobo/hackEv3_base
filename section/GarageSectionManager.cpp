#include "GarageSectionManager.h"
#include "Section.h"
#include "util.h"

GarageSectionManager::GarageSectionManager():
  SectionManager()
{
  color=0;
}

void GarageSectionManager::init()
  {
    wParam *wp;

#if defined(MAKE_RIGHT)
      wp = array[color];
#else
      wp = array[color];
#endif
    init(wp);
  }

void GarageSectionManager::setColor(int col)
{
  if (col<0 || col>4) col=0;
  color = col;
}
  