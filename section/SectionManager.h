#ifndef _SECTION_MANAGER_H_
#define _SECTION_MANAGER_H_

#include "Section.h"

class SectionManager {
    public:
        SectionManager();
        ~SectionManager();
        virtual bool run();    //もしかしたらvirtualになるかも
        void addSection(Section *);
        void reset();

    protected:
        Section *mSection[100];
        int mSectionIdx;
        int mLastIdx;
    private:


};

#endif
