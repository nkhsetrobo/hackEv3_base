#ifndef _GARAGE_SECTION_MANAGER_H_
#define _GARAGE_SECTION_MANAGER_H_
#include "SectionManager.h"


class GarageSectionManager : public SectionManager
{
    public :
        GarageSectionManager();
        void init();
        using SectionManager::init;

    private :
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif

float normal_spd=35;
float turn_spd=60;
float angle_offset=+0;
float rkp0=18,rki0=9,rkd0=3.1;
//float rkp=50,rki=10,rkd=6.5;
float rkp=30,rki=12,rkd=3.0;
float rkp2=35,rki2=25,rkd2=6.0;
//float rvkp=20,rvki=1.0,rvkd=2.1;
float rvkp=100,rvki=30.0,rvkd=9.0;
float tkp=10,tki=5,tkd=0.2;

        wParam a[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +170, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +88, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, +90, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, +90, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -10, 0, 0, 0, true,Judge::UPDATE, 0,5, 0.0, 0, 0, 0, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={a,a};
        wParam *wp;

};

#endif
