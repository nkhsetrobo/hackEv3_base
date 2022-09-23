#ifndef _GARAGE_SECTION_MANAGER_H_
#define _GARAGE_SECTION_MANAGER_H_
#include "SectionManager.h"


class GarageSectionManager : public SectionManager
{
    public :
        GarageSectionManager();
        void init();
        using SectionManager::init;

        void setColor(int col);

    private :
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif
  const int _EDGE_L = LineTracer::RIGHTEDGE;
  const int _EDGE_R = LineTracer::LEFTEDGE;
  const int sign=-1;

        int color;

float normal_spd=35;
float turn_spd=62;
float angle_offset=+0;
float rkp0=18,rki0=9,rkd0=3.1;
//float rkp=50,rki=10,rkd=6.5;
float rkp=30,rki=15,rkd=3.5;
float rkp2=35,rki2=25,rkd2=6.0;
//float rvkp=20,rvki=1.0,rvkd=2.1;
//float rvkp=100,rvki=30.0,rvkd=9.0;
float tkp=10,tki=5,tkd=0.2;
float lvkp=15,lvki=10.0,lvkd=9.0; // lowpass 0.85
float rvkp=45,rvki=50,rvkd=10.0;  // lowpass 0.85

        wParam red[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +70, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +85, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +20, 0, 0, true,Judge::UPDATE, +85,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,30, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, +turn_spd, false,Judge::UPDATE, -90, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0,0, 0.6, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -24, 0, 0, true,Judge::UPDATE, -90 ,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -90, 0, 0, 0, true,Judge::UPDATE, 0,14, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -90, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, RED_H, 0.4, 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},


                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam green[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +70, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +85, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::WALKER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5, 0, 0, true,Judge::UPDATE, +120 ,8, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, GREEN_H, 0.1, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};


        wParam blue[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +70, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +85, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::WALKER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5, 0, 0, true,Judge::UPDATE, +120 ,8, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, BLUE_H, 0.1, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam yellow[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +70, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +85, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::WALKER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5, 0, 0, true,Judge::UPDATE, +120 ,8, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,40, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, YELLOW_H, 0.2, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
        wParam red_l[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*sign, false,Judge::UPDATE, +70*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_L, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*sign, false,Judge::UPDATE, +85*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85*sign, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd*sign, false,Judge::UPDATE, +100*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +20*sign, 0, 0, true,Judge::UPDATE, +85*sign,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85*sign, 0, 0, 0, true,Judge::UPDATE, 0,30, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, +turn_spd*sign, false,Judge::UPDATE, -90*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0,0, 0.6, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, +10*sign, 0 /*setparam*/, 0, -24*sign, 0, 0, true,Judge::UPDATE, -90*sign ,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -90*sign, 0, 0, 0, true,Judge::UPDATE, 0,14, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -90*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, RED_H, 0.4, 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},


                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};


        wParam green_l[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*1.5*sign, false,Judge::UPDATE, +70*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_L, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*1.5*sign, false,Judge::UPDATE, +80*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 35, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd*1.8*sign, false,Judge::UPDATE, +100*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  45, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45 ,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 45, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20*sign, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  45, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::VIRTUAL2, Section::COLOR,  50, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.13, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5*sign, 0, 0, true,Judge::UPDATE, +120*sign ,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 12*sign, 0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, GREEN_H, 0.1, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
#if 0
wParam blue[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +70, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_R, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, +85, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd, false,Judge::UPDATE, +100, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_R, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::WALKER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 40, 0, _EDGE_R, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5, 0, 0, true,Judge::UPDATE, +120 ,8, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, BLUE_H, 0.1, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};
#endif
        wParam blue_l[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*sign, false,Judge::UPDATE, +70*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_L, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*sign, false,Judge::UPDATE, +85*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +85*sign, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 30, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1/*setparam*/, 0, 0, 5, -turn_spd*1.8*sign, false,Judge::UPDATE, +100*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  normal_spd, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 50 ,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 50, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20*sign, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    //{0, Section::TRACER, Section::LENGTH,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UNUPDATE, 0, 33, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::VIRTUAL2, Section::COLOR,  40, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.15, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 40, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5*sign, 0, 0, true,Judge::UPDATE, +120*sign ,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120*sign, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, BLUE_H, 0.1, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam yellow_l[100] = {
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*1.5*sign, false,Judge::UPDATE, +70*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, !_EDGE_L, Judge::UPDATE, 0, 25, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -turn_spd*1.5*sign, false,Judge::UPDATE, +80*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 50, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,60, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,0, -0.1, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 45, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, +80*sign, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 35, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 5, -turn_spd*1.8*sign, false,Judge::UPDATE, +100*sign, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  45, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 12, 0, 0, 0,0, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::BRIGHTNESS, 45 ,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,0, 0.5, 1, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, 45, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, -20*sign, 0, 0, true,Judge::UPDATE, 0,15, 0.0, 0, 0, 0, 0, Section::JNONE},
                    {0, Section::TRACER, Section::LENGTH,  45, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE_L, Judge::UPDATEALL, 0, 30, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::VIRTUAL2, Section::COLOR,  50, -0.0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 2, 0, 0, _EDGE_L, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.13, 0 , false, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 45, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, +16.5*sign, 0, 0, true,Judge::UPDATE, +120*sign ,0, 0.0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120*sign, 0, 0, 0, true,Judge::UPDATE, 0,40, 0, 0, 0,0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::COLOR, 40, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 120, 0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, YELLOW_H, 0.2, 0, Section::JNONE},

                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={red_l,green_l,blue_l,yellow_l, red,green,blue,yellow};
        wParam *wp;

};

#endif
