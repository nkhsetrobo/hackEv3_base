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
        int selectCircle(int current,int idxs[], int &error);
        void rotIdxs(int dir,int idxs[]);

    protected:

    private:


        float bkp=32,bki=15.0,bkd=3.0;
        float fwd=20;
        float bspd = 12.0;
        float bspd2 = 6.0;
        float _EDGE = true;
        float sign=1.0;

        float end_r_angle = -2.0;
        float end_l_angle = 0.0;

        // R2 右旋回 2区画　 左
        BINGO_SEC c1_6[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki*2, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-94*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},

            {Section::TRACER,{bspd*2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 44, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // 右旋回　直入れ
        BINGO_SEC c2_1[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        //　R1R1 右旋回 １区画　右旋回　１区画　右
        BINGO_SEC c3_1[20] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };
        // 右旋回　1区画　右旋回　2区画
        BINGO_SEC c3_3[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-91*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd*1.5, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*1.5, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 50, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{-end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // R1 右旋回　1区画  右
        BINGO_SEC c3_4[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };


        // 右旋回 2区画　右旋回　1区画 左
        BINGO_SEC c3_6[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 22, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{00, 35, 0, 0,0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd*1.5, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 46, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -15.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0,  15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // R2 右旋回 2区画　
        BINGO_SEC c3_7[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-93*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 6, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd*2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 44, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　右旋回 １区画　右旋回　１区画
        BINGO_SEC c6_3[20] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.5*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 19, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 右旋回　1区画　右旋回　2区画　右旋回
        BINGO_SEC c7_0[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -15.0*sign, 0, 0, false}, // 中央
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
         // R1R1R1  右旋回　1区画　右旋回　1区画　右旋回　1区画
        BINGO_SEC c7_1[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -8*sign, 0, 0, false},
               Section::TURNANGLE,{-93*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

 
        // R1R2 右旋回　1区画　右旋回　2区画 左
        BINGO_SEC c7_3[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-93*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-93*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 25, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 43, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        // 右旋回　直入れ
        BINGO_SEC c7_4[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -7.5*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };
        // 右旋回　1区画　右旋回　2区画 左
        BINGO_SEC c7_5[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -8*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 25, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 43, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        //　R1R1 右旋回 １区画　右旋回　１区画　左
        BINGO_SEC c7_6[20] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // R1 右旋回　1区画  右
        BINGO_SEC c7_7[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-98*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };

        // 初手 黄色
        BINGO_SEC c10_1[20] = {
        // 左旋回
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // 初手　赤
        BINGO_SEC c10_4[10] = {
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 　（初手　緑）
        BINGO_SEC c10_7[10] = {
          // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 初手　青
        BINGO_SEC c10_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            
        };

        // 左旋回　1区画　左旋回　1区画　
        BINGO_SEC c11_0[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        //　左旋回 １区画　左旋回　１区画 右
        BINGO_SEC c11_1[20] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 13.0*sign, 0, 0, false},
               Section::TURNANGLE,{91*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 左旋回　1区画  左
        BINGO_SEC c11_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        // L1L2  左旋回　1区画　左旋回　2区画
        BINGO_SEC c11_3[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 左旋回　直入れ
        BINGO_SEC c11_4[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 7.5*sign, 0, 0, false},
               Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-10, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 左旋回　1区画　左旋回　2区画　左旋回
        BINGO_SEC c11_5[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 17.0*sign, 0, 0, false}, // 中央
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };


        // 右旋回　直入れ
        BINGO_SEC c11_7[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -7.5*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, _EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        BINGO_SEC c14_1[20] = {
        // 左旋回 2区画　
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 22, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd*1.5, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 53, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0 , 6, 0,0, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0,  16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };
        BINGO_SEC c14_2[20] = {
        // 左旋回 2区画　
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 22, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd*1.5, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // 左旋回　1区画  右
        BINGO_SEC c14_4[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        //　左旋回 １区画　左旋回　１区画
        BINGO_SEC c14_5[20] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 19, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 左旋回 2区画 左旋回　1区画
        BINGO_SEC c15_1[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 7.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{ 0, 25, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 50, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0 ,0, 0 , 6, 0.3,0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // 左旋回 2区画 　
        BINGO_SEC c15_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 7.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{ 0, 25, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd*2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 50, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0 ,0, 0 , 7, 0.3,0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // 左旋回　1区画  左
        BINGO_SEC c15_4[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        // L1L2  左旋回　1区画　左旋回　2区画
        BINGO_SEC c15_5[50] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, _EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, _EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        BINGO_SEC *carry_list[16][8] = {
            {},
            {0,0,0,0, 0,0,c1_6},
            {0, c2_1},
            {0, c3_1,    0,  c3_3,  c3_4,0   ,c3_6, c3_7},
            {},
            {},
            {},
            {c7_0,c7_1,0, c7_3,c7_4, c7_5,c7_6,c7_7 },          
            {},
            {},
            {0,c10_1,c10_2,    0,c10_4,    0,0,c10_7},        
            {c11_0, c11_1, c11_2,   c11_3,c11_4,  c11_5,0, c11_7},
            {},
            {},          
            {0, c14_1,c14_2,    0, c14_4,c14_5,0,    0},
            {0,    c15_1,c15_2,0,c15_4,c15_5},
        };

        int cost[16][8] = 
        {
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, // 0 なし
            { 500,   5,  15,   35,  45,   45,  55,  55}, // 1
            {  65, 500,   5,   65,  35,   75,  45,  45},  // 2
            {  75,  65, 500,   75,  35,  105,  95,  95},  // 3           
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //4 なし
            { 500,   5,  15,  500,  15,  35,  35,  45}, //5 
            {  95, 500,   5,   65,   5,  65,  35,  35}, // 6
            { 105, 105, 500,   75, 500,   35,  65,  75}, //7             
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //8 なし
            {  35,  35,  45,  500,  15,  500,   5,  15}, //9
            {1000,  20,  20, 1000,  10, 1000,1000,  10}, //10
            {  75,  65,  35,   75, 500,  105,  95, 500}, //11           
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //12 なし
            {  45,  45,  55,   35,  45,  500,   5,  15}, //13
            {  85,  55,  55,   35,  45,  65, 500,    5}, //14 
            {  85,  75,  45,  75,  35,  75,  65,  500},  //15          
        };

        //走行体の終了方向リスト
        int dir_list[16][8] = {
            {},//0
            {0,0,0,0,0,0,1},//1
            {0,1},//2
            {0,-2,0, -2, 1,  0,-2,1},//3
            {},//4
            {},//5
            {},//6
            {-1,-1,0, -2, 1,  -2, -2, 1}, //7         
            {},//8
            {},//9
            {-2,-1,-1,  0, 0, 0,0,0},//10        
            {-2,-2,-1, -2, -1, 1,1,1},//11
            {},//12
            {},//13          
            {0,-1,-1,0, -1, -2, 0,0},//14
            {0,-2,-1,0,-1,-2},//15
        };

        //走行体の終了位置リスト
        int runner_list[16][8] = {
            {},
            {0,0,0,0,0,0,9},
            {0,6},
            {0,6,0, 5,7, 0,0,11},
            {},
            {},
            {},
            {5,6,3, 9,11,  9,10,11},//7          
            {},
            {},
            {0,6,6,0,10,0,0,10},        
            {5,6,7, 5,7, 9,0,15}, //11
            {},
            {},          
            {0,6,6,0,10,9,0,0}, //14
            {0,6,7,0,11,9},
        };
};
#endif