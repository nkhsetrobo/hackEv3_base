#ifndef _SLALOM_SECTION_MANAGER_H_
#define _SLALOM_SECTION_MANAGER_H_
#include "SectionManager.h"



class SlalomSectionManager : public SectionManager
{
    public:
        SlalomSectionManager();
        void init();
        bool run();
        void adjustLength();

        using SectionManager::init;

    protected:

    private:
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::LEFTEDGE;
        #endif
        
float normal_spd=45;
float rkp=19,rki=15,rkd=2.9;
float rkp2=10,rki2=0.2,rkd2=1.2;
float rvkp=15,rvki=0.5,rvkd=2.1;

int ONBOARD=10;

        wParam a[100] = {
                     {0, Section::TRACER, Section::LENGTH,  48, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                     {0, Section::TRACER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 61, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                    {0, Section::WALKER, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -55, false,Judge::UPDATE, 45, 0, 0, 0, 0, 0, 0,0, Section::SONERSTATUS},
                        {ONBOARD, Section::WALKER, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 55, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
                        {0, Section::TRACER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 3, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 53, false,Judge::UPDATE, -45, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
//                        {0, Section::VIRTUAL2, Section::LENGTH, 33, 0, rkp,rki,rkd, 0, 0 /*setparam*/, -45, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, 18.5, 0, 0, true,Judge::UNUPDATE, +40, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, rkp,rki,rkd, 0, 0 /*setparam*/, +40, 0, 0, 0, true,Judge::UPDATE, 0,8, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, -10.0, 0, 0, true,Judge::UNUPDATE, -32, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 35, 0, rkp,rki,rkd, 0, 0 /*setparam*/, -31, 0, 0, 0, true,Judge::UPDATE, 0,8, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 35, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UNUPDATE, +30, 0, 0, 0, 0, 0, 0, Section::JNONE},
        
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},
   #if 0
                        {0, Section::VIRTUAL, Section::TURNANGLE, 33, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, -17.0, 0, 0, true,Judge::UNUPDATE, -33, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 33, 0, rkp,rki,rkd, 0, 0 /*setparam*/, -45, 0, 0, 0, true,Judge::UPDATE, 0,8, 0, 0, 0, 0, 0, Section::JNONE},
                       // {0, Section::WALKER, Section::TURNANGLE, 25, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -45, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 33, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, 15.0, 0, 0, true,Judge::UNUPDATE, +45, 0, 0, 0, 0, 0, 0, Section::JNONE},

                       // {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0, rkp,rki,rkd, 0, 0 /*setparam*/, 0, 16, 0, 0, true,Judge::UNUPDATE, +30, 0, 0, 0, 0, 0, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0,0, Section::JNONE},

#endif 
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
        };

        wParam b[100] = {
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={a,b};
        wParam *wp;

};

#endif
