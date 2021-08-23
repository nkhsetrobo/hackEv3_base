#ifndef _BLOCK_STATE_CARRY_H_
#define _BLOCK_STATE_CARRY_H_

#include "BingoState.h"
#include "Section.h"
#include "BlockSectionManager.h"

class BingoStateCarry : public BingoState
{
    public:
        BingoStateCarry(BlockSectionManager *bsm);

        void init();
        //bool run();

    protected:

    private:

        double YELLOW = 55;
        double GREEN = 138;
        double RED = 0;
        double BLUE = 207;

        float bkp=30,bki=1.0,bkd=2.0;
        float fwd=20;
        double bspd = 11.5;
        double bspd2 = bspd*0.6;
        float _EDGE = true;
        float sign=1.0;
        // 初手 黄色
        BINGO_SEC c10_1[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  GREEN,0.3, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{50*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };
        // 初手　緑
        BINGO_SEC c10_7[10] = {
          // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{50*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          
        };
        // 初手　赤
        BINGO_SEC c10_4[10] = {
          // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-50*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{-0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // 初手　青
        BINGO_SEC c10_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  GREEN,0.3, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-50*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{-0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            
        };

        BINGO_SEC *carry_list[16][8] = {
            {},
            {},
            {},
            {},
            {},
            {},
            {},
            {},          
            {},
            {},
            {0,c10_1,c10_2,0,c10_4,0,0,c10_7},        
            {},
            {},
            {},          
            {},
            {},
        };
};
#endif