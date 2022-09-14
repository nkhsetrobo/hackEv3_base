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
        int color;

    protected:

    private:
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::LEFTEDGE;
        #endif
        
float normal_spd=31;
float turn_spd=45;
float angle_offset=+0;
float rkp0=18,rki0=9,rkd0=3.1;
//float rkp=50,rki=10,rkd=6.5;
float rkp=30,rki=12,rkd=3.5;
//float rkp2=35,rki2=25,rkd2=6.0;
//float rvkp=20,rvki=1.0,rvkd=2.1;
//float rvkp=60,rvki=20.0,rvkd=10.0;
float rvkp=45,rvki=50,rvkd=10.0;  // lowpass 0.85
float lvkp=15,lvki=10.0,lvkd=9.0; // lowpass 0.85
float rkp2=35,rki2=25,rkd2=6.0;

float tkp=10,tki=5,tkd=0.2;

float base_pos=0;
int ONBOARD=10;
int CALIB=11;
int RESET_ANG=12;
int SEL_COLOR=13;

wParam a[100] = {
            {0, Section::TRACER, Section::LENGTH,  48, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0 , 0, Section::JNONE},
            {0, Section::TRACER, Section::LENGTH,  45, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0, 0 , 0, Section::JNONE},
            {CALIB, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
            {ONBOARD, Section::TURN, Section::TURNANGLE, 0, 0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0,turn_spd, false,Judge::UNUPDATE, 3, 0, 0.0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
            {RESET_ANG, Section::TRACER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 5.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
            {0, Section::WALKER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UPDATEALL, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},
            //１本目
            {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, -36, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -24, 0 /*setparam*/, 0, +18.0, 0, 0, true,Judge::UNUPDATE, +30+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, +30+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,6.0, 0, 0, 0, 0, 0, Section::JNONE},
            //2-3
            {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, +24, 0 /*setparam*/, 0, -16.5, 0, 0, true,Judge::UNUPDATE, -20+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -20+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,14.5, 0, 0, 0, 0, 0, Section::JNONE},


            {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 0, +13.0, 0, 0, true,Judge::UNUPDATE, +0+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::TURN, Section::TURNANGLE, 0, -0.0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*0.8, false,Judge::UNUPDATE, 20.0+angle_offset, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd*0.5, 0, 0 /*setparam*/, 20.0+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,12, 0, 0, 0, 0, 0, 0,Section::JNONE},
            //抜けた
            {0, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -10, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::BRIGHTNESS,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -10 ,0, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, 0, 0, 0, false, Section::JNONE},
            //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -19.5, 0, 0, true,Judge::UNUPDATE, -5+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
            //{0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -5 ,0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, false, Section::JNONE},

            //色
            {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 6.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
                {0, Section::WALKER, Section::BRIGHTNESS, 30, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false,Judge::UNUPDATE, 0, 0, 0.6, 1, 0, 0, 0,0, Section::JNONE},
            {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, -15, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UPDATE, 45+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 45+angle_offset ,0, 0, 0, true,Judge::UPDATE, 0,4, 0, 0, 0, 0, 0, false, Section::COLORSTATUS},
            {0, Section::VIRTUAL2, Section::LENGTH,  -40,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -180+45+angle_offset ,0, 0, 0, true,Judge::UNUPDATE, 0,-1, 0, 0, 0, 0, 0, false, Section::JNONE},
                {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
            {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                //ラインキャッチ
            {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 13,0, 0, 0, 0, 0 , 0, Section::JNONE},

            {12, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, +turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
            {0, Section::VIRTUAL2, Section::LENGTH,  normal_spd,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -35, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -20, 0 /*setparam*/, 0, +13.5, 0, 0, true,Judge::UNUPDATE, +40+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
            {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0,0, Section::JNONE},
            {0, Section::WALKER, Section::BRIGHTNESS, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0,0, Section::JNONE},

            {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0,0, 0 , false, Section::JNONE},
            {0, Section::TRACER, Section::COLOR,  40, -0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.1, 0 , false, Section::JNONE},
            //    {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

            // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
            {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
};

        wParam r1[100] = {
                        {0, Section::TRACER, Section::LENGTH,  49, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 53, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::TRACER, Section::LENGTH,  45, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {CALIB, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {ONBOARD, Section::TURN, Section::TURNANGLE, 0, 0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0,turn_spd, false,Judge::UNUPDATE, 3, 0, 0.0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
                        {RESET_ANG, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 4.8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UPDATEALL, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},
                    //１本目
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                        //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, -36, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -24, 0 /*setparam*/, 1, +18.0, base_pos+13.5, 12.0, true,Judge::UNUPDATE, +17+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, lvkp,lvki,lvkd, 0, 0 /*setparam*/, +17+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,21.0, 0, 0, 0, 0, 0, Section::JNONE},
                    //2-3
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, +24, 0 /*setparam*/, 1, -17.5 ,base_pos+42.5, -14.0, true,Judge::UNUPDATE, -34+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -34+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,5.5, 0, 0, 0, 0, 0, Section::JNONE},


                        //{0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 1, +13.0, base_pos+67.5, 7.5, true,Judge::UNUPDATE, +0+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 1, +18.5, base_pos+64.5, 14.5, true,Judge::UNUPDATE, -5+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                                   {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -5.0+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,0.5, 0, 0, 0, 0, 0, 0,Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*0.8, false,Judge::UNUPDATE, 27.0+angle_offset, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 27.0+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,9, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    //抜けた
                        //{0, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        //{0, Section::VIRTUAL, Section::BRIGHTNESS,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0 ,-30, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, 0, 0, 0, false, Section::JNONE},
                        //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -19.5, 0, 0, true,Judge::UNUPDATE, -5+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        //{0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -5 ,0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, false, Section::JNONE},

                        //色
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki*0.1,rkd*0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 12.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 15.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
//                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                           {0, Section::WALKER, Section::BRIGHTNESS, 30, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false,Judge::UNUPDATE, 0, 0, 0.3, 1, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, -15, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UPDATE, 45+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        {SEL_COLOR, Section::VIRTUAL2, Section::LENGTH,  30,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 45+angle_offset ,0, 0, 0, true,Judge::UPDATE, 0,4, 0, 0, 0, 0, 0, false, Section::COLORSTATUS},
                        {0, Section::VIRTUAL2, Section::LENGTH,  -40,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -180+45+angle_offset ,0, 0, 0, true,Judge::UNUPDATE, 0,-1, 0, 0, 0, 0, 0, false, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           //ラインキャッチ
                       {RESET_ANG, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATEALL, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},

                        {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, +turn_spd, false,Judge::UPDATEALL, -33, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  normal_spd,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -35, 0, 0, 0, true,Judge::UPDATE, 0,9, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -20, 0 /*setparam*/, 0, +19.5, 18.5, 14.0, true,Judge::UNUPDATE, +37+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::WALKER, Section::TURNANGLE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/3, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::WALKER, Section::BRIGHTNESS, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/2, false,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0,0, Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.1, 0 , false, Section::JNONE},
                    //    {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
        };
        wParam r2[100] = {
                        {0, Section::TRACER, Section::LENGTH,  49, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 53, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::TRACER, Section::LENGTH,  45, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {CALIB, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {ONBOARD, Section::TURN, Section::TURNANGLE, 0, 0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0,turn_spd, false,Judge::UNUPDATE, 3, 0, 0.0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
                        {RESET_ANG, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 4.8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UPDATEALL, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},
                    //１本目
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                        //{0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, -36, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -24, 0 /*setparam*/, 1, +18.0, base_pos+13.5, 12.0, true,Judge::UNUPDATE, +17+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, lvkp,lvki,lvkd, 0, 0 /*setparam*/, +17+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,21.0, 0, 0, 0, 0, 0, Section::JNONE},
                    //2-3
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, +24, 0 /*setparam*/, 1, -17.5 ,base_pos+42.5, -14.0, true,Judge::UNUPDATE, -34+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -34+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,5.5, 0, 0, 0, 0, 0, Section::JNONE},


                        //{0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 1, +13.0, base_pos+67.5, 7.5, true,Judge::UNUPDATE, +0+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 1, +18.5, base_pos+64.5, 14.5, true,Judge::UNUPDATE, -5+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                                   {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -5.0+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,10, 0, 0, 0, 0, 0, 0,Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd*0.8, false,Judge::UNUPDATE, 27.0+angle_offset, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 27.0+angle_offset, 0, 0, 0, true,Judge::UPDATE, 0,, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    //抜けた
                        //{0, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        //{0, Section::VIRTUAL, Section::BRIGHTNESS,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0 ,-30, 0, 0, true,Judge::UPDATE, 0,0, 0, 0, 0, 0, 0, false, Section::JNONE},
                        //{0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -19.5, 0, 0, true,Judge::UNUPDATE, -5+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        //{0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -5 ,0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, false, Section::JNONE},

                        //色
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki*0.1,rkd*0.1, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 12.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 15.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
//                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                           {0, Section::WALKER, Section::BRIGHTNESS, 30, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false,Judge::UNUPDATE, 0, 0, 0.3, 1, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, -15, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UPDATE, 45+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        {SEL_COLOR, Section::VIRTUAL2, Section::LENGTH,  30,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, 45+angle_offset ,0, 0, 0, true,Judge::UPDATE, 0,4, 0, 0, 0, 0, 0, false, Section::COLORSTATUS},
                        {0, Section::VIRTUAL2, Section::LENGTH,  -40,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -180+45+angle_offset ,0, 0, 0, true,Judge::UNUPDATE, 0,-1, 0, 0, 0, 0, 0, false, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           //ラインキャッチ
                       {RESET_ANG, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 30, 0, _EDGE, Judge::UPDATEALL, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},

                        {0, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, +turn_spd, false,Judge::UPDATEALL, -33, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  normal_spd,0,lvkp,lvki,lvkd, 0, 0 /*setparam*/, -35, 0, 0, 0, true,Judge::UPDATE, 0,9, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -20, 0 /*setparam*/, 0, +19.5, 18.5, 14.0, true,Judge::UNUPDATE, +37+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::WALKER, Section::TURNANGLE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/3, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::WALKER, Section::BRIGHTNESS, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/2, false,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0,0, Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 10, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  40, -0.2,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.1, 0 , false, Section::JNONE},
                    //    {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
        };

                wParam a2[100] = {
                        {0, Section::TRACER, Section::LENGTH,  48, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 55, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::TRACER, Section::LENGTH,  45, 0,rkp0,rki0,rkd0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UNUPDATE, 0, 60, 0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {CALIB, Section::TURN, Section::TURNANGLE, 0, -0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UPDATE, 30, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {ONBOARD, Section::TURN, Section::TURNANGLE, 0, 0, tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0,turn_spd, false,Judge::UNUPDATE, 3, 0, 0.0, 0, 0, 0, 0, 0,Section::SONERSTATUS},
                        {0, Section::TRACER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 4.8,0, 0, 0, 0, 0 , 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH,  35, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 35, 0, _EDGE, Judge::UPDATE, 0, 0.2,0, 0, 0, 0, 0 , 0, Section::JNONE},
                    //１本目
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UPDATE, -35, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, -36, 0, 0, 0, true,Judge::UPDATE, 0,2, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, -24, 0 /*setparam*/, 0, +18.0, 0, 0, true,Judge::UPDATE, 0, 25.8, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,9.5, 0, 0, 0, 0, 0, Section::JNONE},
                    //2-3
                        {0, Section::VIRTUAL, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, +24, 0 /*setparam*/, 0, -16.5, 0, 0, true,Judge::UPDATE, 0, 14.5, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,3.0, 0, 0, 0, 0, 0, Section::JNONE},


                        {0, Section::VIRTUAL, Section::LENGTH, normal_spd, 0, rvkp,rvki,rvkd, -22, 0 /*setparam*/, 0, +12.5, 0, 0, true,Judge::UPDATE, 0, 15.5, 0, 0, 0, 0, 0, Section::JNONE},
                       // {12, Section::TURN, Section::TURNANGLE, 0, -0.0,tkp,tki,tkd, 0, 0 /*setparam*/, 0, 0, 0, -turn_spd, false,Judge::UNUPDATE, 24.5+angle_offset, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 50,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH, normal_spd, 0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 0, 2, 0, 0, true,Judge::UPDATE, 0,19, 0, 0, 0, 0, 0, 0,Section::JNONE},
           {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},
                    //抜けた
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, +15, 0 /*setparam*/, 0, -19.5, 0, 0, true,Judge::UNUPDATE, -0+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},

                        //色
                        {0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -0 ,0, 0, 0, true,Judge::UPDATE, 0,5, 0, 0, 0, 0, 0, false, Section::JNONE},
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 5.0,0, 0, 0, 0, 0 , 0, Section::JNONE},
                           {0, Section::WALKER, Section::BRIGHTNESS, 30, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 30, 0, false,Judge::UNUPDATE, 0, 0, 0.6, 1, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 30, 0, rvkp,rvki,rvkd, -15, 0 /*setparam*/, 0, +10.0, 0, 0, true,Judge::UNUPDATE, 45+angle_offset, 0, 0, 0, 0, 0, 0, false,Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  30,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, 45+angle_offset ,0, 0, 0, true,Judge::UPDATE, 0,4, 0, 0, 0, 0, 0, false, Section::COLORSTATUS},
                        {0, Section::VIRTUAL2, Section::LENGTH,  -40,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -180+45+angle_offset ,0, 0, 0, true,Judge::UNUPDATE, 0,-1, 0, 0, 0, 0, 0, false, Section::JNONE},
                           {0, Section::WALKER, Section::STOP, 15, -0.0, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 100,0, Section::JNONE},
                        {0, Section::TURN, Section::TURNANGLE, 0, -0.0, 5, 5, 0.1, 0, 0 /*setparam*/, 0, 0, 0, turn_spd, false,Judge::UNUPDATE, -80, 0, 0, 0, 0, 0, 0, 0,Section::JNONE},
                           //ラインキャッチ
                       {0, Section::TRACER, Section::LENGTH,  30, 0,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 13,0, 0, 0, 0, 0 , 0, Section::JNONE},

                        {12, Section::TURN, Section::TURNANGLE, 0, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, +turn_spd, false,Judge::UPDATE, -38, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::VIRTUAL2, Section::LENGTH,  normal_spd,0,rvkp,rvki,rvkd, 0, 0 /*setparam*/, -38, 0, 0, 0, true,Judge::UPDATE, 0,3, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::VIRTUAL, Section::TURNANGLE, normal_spd, 0, rvkp,rvki,rvkd, -20, 0 /*setparam*/, 0, +14.0, 0, 0, true,Judge::UNUPDATE, +35+angle_offset, 0, 0, 0, 0, 0, 0, Section::JNONE},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0,0, Section::JNONE},
                        {0, Section::WALKER, Section::BRIGHTNESS, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, normal_spd, normal_spd/4, false,Judge::UPDATE, 0, 30, 0, 0, 0, 0, 0,0, Section::JNONE},

                    {0, Section::TRACER, Section::LENGTH,  40, -0.1,rkp,rki,rkd*0.8, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 15, 0, 0, 0,0, 0 , false, Section::JNONE},
                    {0, Section::TRACER, Section::COLOR,  40, -0.1,rkp,rki,rkd, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE, Judge::UPDATE, 0, 0, 0, 0, BLUE_H, 0.08, 0 , false, Section::JNONE},
                    //    {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UPDATE, 0, 1000, 0, 0, 0, 0, 0, 0,Section::JNONE},

                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, false,Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0,0, Section::JNONE},
        };

        wParam b[100] = {
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={r1,r1,r2,r2};
        wParam *wp;

};

#endif
