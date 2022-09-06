#ifndef _GARAGE_SECTION_MANAGER_H_
#define _GARAGE_SECTION_MANAGER_H_
#include "SectionManager.h"


class GarageSectionManager : public SectionManager
{
    public :
        GarageSectionManager();
        void init();
    private :
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif

};

#endif
