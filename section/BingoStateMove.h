#ifndef _BLOCK_STATE_MOVE_H_
#define _BLOCK_STATE_MOVE_H_

#include "BingoState.h"
#include "Section.h"
#include "BlockSectionManager.h"

class BingoStateMove : public BingoState
{
    public:
        BingoStateMove(BlockSectionManager *bsm);

        void init();
        //bool run();
        int selectCircle(int current,int idxs[]);
        void rotIdxs(int dir,int idxs[]);

    protected:

    private:


        float bkp=30,bki=6.0,bkd=1.0;
        float fwd=20;
        float bspd =18.0;
        float bspd2 = 8.0;
        float _EDGE = true;
        float sign=1.0;

        // 2R2 2区画　右旋回　3区画
        BINGO_SEC c1_15[20] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 54, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-94*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 20, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 40, 0, 0, 0, 0, 0},Judge::UNUPDATE},

            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 52, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, _EDGE},
            //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 70, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
                
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // R3  右旋回　3区画
        BINGO_SEC c2_14[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-96*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 42, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 52, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN


             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 73, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
           {Section::WEND,{},Section::JEND,{}}                      
        };

        // 1区画 右旋回　3区画
        BINGO_SEC c2_15[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{ 0, 20, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-91*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 25, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 43, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 62, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
            //     Section::LENGTH,{00, 12, 0, 0,  0,0, 0, 0},Judge::UPDATE}, // GREEN
             {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 25, 0, 0, 0, 0, 0},Judge::UPDATE},

            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, _EDGE},
            //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
           {Section::WEND,{},Section::JEND,{}}                      
        };

        // 右旋回 1区画 右旋回　3区画　右旋回 1区画
        BINGO_SEC c3_0[20] = {
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -12*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 25, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0,_EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 60, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, _EDGE},
            //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

             {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 75, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  4 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

           {Section::WEND,{},Section::JEND,{}}                      
        };

        // R1 右旋回　1区画
        BINGO_SEC c3_7[10] = {
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };   

        // L1L1 左旋回　1区画　左旋回　1区画  
        BINGO_SEC c5_0[10] = {
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{91*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  0 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　1区画
        BINGO_SEC c5_1[10] = {
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // 2区画　右旋回　1区画
        BINGO_SEC c5_3[10] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 30, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 50, 0, 0, 0, 0, 0},Judge::UNUPDATE},

            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 2  2区画前進
        BINGO_SEC c5_7[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*2.0, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 60, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}            
        };
        
        // 左旋回　1区画　左旋回　1区画
        BINGO_SEC c6_1[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };


        // 1L1 1区画　左旋回　1区画
        BINGO_SEC c6_3[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  7 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // 1区画前進
        BINGO_SEC c6_7[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}            
        };

        // 右旋回　2区画　右旋回　2区画
        BINGO_SEC c6_12[10] = {
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -11.0*sign, 0, 0, false},
               Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -13.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd*2, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  12 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 1区画　右旋回　2区画
        BINGO_SEC c6_15[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 34, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  7 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 47, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 2L2 2区画　左旋回　2区画
        BINGO_SEC c9_3[20] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 28, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 52, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},

            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 30, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 48, 0, 0, 0, 0, 0},Judge::UNUPDATE},

            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 2  2区画前進
        BINGO_SEC c9_11[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, _EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*2.0, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 60, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}            
        };
        // R1 右旋回　1区画
        BINGO_SEC c9_13[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };   

        // 1R1 1区画　右旋回　1区画
        BINGO_SEC c9_14[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 35, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 2区画　右旋回　1区画
        BINGO_SEC c9_15[10] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 30, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 55, 0, 0, 0, 0, 0},Judge::UNUPDATE},

            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　2区画　左旋回　1区画
        BINGO_SEC c12_1[10] = {
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 11.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 13.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd*2, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　2区画　左旋回　1区画
        BINGO_SEC c10_1[10] = {
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 4, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 15, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd*2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  1 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };



        // 初手　青
        BINGO_SEC c10_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
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
        // 1L2 1区画　左旋回　2区画
        BINGO_SEC c10_3[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 35, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　1区画　左旋回　1区画   （初手）
        BINGO_SEC c10_5[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{91*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　1区画  （２手目）
        BINGO_SEC c10_6[10] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 1区画　左旋回　1区画
        BINGO_SEC c10_7[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 32, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
               Section::TURNANGLE,{92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // 1区画前進
        BINGO_SEC c10_11[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  11  ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}            
        };

                // 右旋回　1区画　右旋回　1区画
        BINGO_SEC c10_13[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -13.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, _EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0, 13 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // 右旋回　1区画
        BINGO_SEC c10_14[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-92*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // 1区画　右旋回　1区画
        BINGO_SEC c10_15[10] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 12, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 35, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  11 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  15 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        // L3  左旋回　3区画
        BINGO_SEC c14_2[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 25, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 60, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, _EDGE},
            //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 75, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
           {Section::WEND,{},Section::JEND,{}}                      
        };


        // 1区画　左旋回　3区画
        BINGO_SEC c14_3[20] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, _EDGE},
                Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd , 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{0, 0, 0, 0,  15 ,0.3, 0 , 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 25, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN
             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{00, 60, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0*2, 0, _EDGE},
            //     Section::LENGTH,{00, 10000, 0, 0,  0,0, 0, 0},Judge::UNUPDATE}, // GREEN

             {Section::TRACER,{bspd*2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 75, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  3 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
           {Section::WEND,{},Section::JEND,{}}                      
        };

        // 左旋回　1区画　左旋回　2区画
        BINGO_SEC c14_8[10] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, _EDGE},
                Section::LENGTH,{ 0, 25, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, !_EDGE},
                Section::LENGTH,{ 0, 45, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, _EDGE},
                Section::COLOR,{00, 0, 0, 0,  8 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}                      
        };
        BINGO_SEC *carry_list[16][16] = {
            {},
            {0,0,0,0,   0,0,0,0,   0,0,0,0, 0,0,0,c1_15},
            {0,0,0,0,   0,0,0,0,   0,0,0,0, 0,0,c2_14,c2_15},
            {c3_0,0,0,0, 0,0,0,c3_7},
            {},
            {c5_0,c5_1,0,c5_3,0,0,0,c5_7},
            {0,c6_1,0,c6_3, 0,0,0,c6_7, 0,0,0,0, c6_12,0,0,c6_15},
            {},

            {},
            {0,0,0,c9_3, 0, 0,0,0, 0,0,0,c9_11, 0,c9_13,c9_14,c9_15},
            {0,c10_1,0,0, 0,c10_5,c10_6,c10_7, 0,0,0,c10_11, 0,c10_13,c10_14,c10_15},        
            {0,c12_1},

            {},
            {},          
            {0,0,c14_2,c14_3,0 ,0 ,0, 0, c14_8},
            {},
        };

        int cost[16][16] = 
        {
            {1000,  70,1000, 210,   20,  60,  30,  50, 1000,1000,1000,1000, 1000,1000,1000,1000,}, // 0スタートはない
            { 270,1000,  10, 220,   60,  30,  40,  70,   70,  40,  70,  80,  280,  70,  80, 290,}, // 1
            { 300,  90,1000, 210,   70,  62,  30,  60,   80,  72,  40,  70,  310,  85,  50, 280,}, // 2
            { 110, 100,1000,1000,   80,  70,  60,  30,   90,  80,  70,  40,  100,  90,  80,  50,}, // 3 
            {1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000,}, // 4 ない
            { 260,  30,  40, 255, 1000,1000,  10,  20,   60,  30,  40,  50,  275,  40,  70, 280,}, // 5 
            { 270,  60,  30, 245,  100,1000,1000,  10,   70,  60,  30,  40,  280,  70,  40, 250,}, //6
            { 280,  70,  60, 230,  110, 100,1000,1000,   80,  70,  60,  30,  290,  80,  70, 240,}, //7
            {1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000,}, //8 ない
            { 270,  40,  50, 260,   60,  30,  40,  50, 1000,1000,  10,  20,  260,  30,  40, 255,}, //9 
            { 280,  70,  60, 250,   70,   4,   2,  40,  100,1000,1000,  10,  270,  60,  30, 245,}, //10
            { 290,  80,  70, 240,   80,  70,  60,  30,  110, 100,1000,1000,  280,  70,  60, 230,}, //11
            {1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000, 1000,1000,1000,1000,}, //12 ない
            { 280,  50,  60, 270,   70,  40,  50,  60,   60,  30,  40,  50, 1000,1000,  10, 220,}, //13
            { 290,  80,  50, 260,   80,  70,  40,  72,   70,  60,  30,  40,  300,  90,1000, 210,}, //14 
            { 100,  90,  80,  50,   90,  80,  70,  40,   80,  70,  60,  30,  110, 100,1000,1000,}, //15 
        };

        int dir_list[16][16] = {
            {}, //0
            {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1}, //1
            { 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,1}, //2
            {-1,0,0,0, 0,0,0,1 }, //3
            {}, //4
            {-2,-1,0,-1, 0,0,0,0, 0,0,0,0, 0,0,0,0}, //5
            {0,-2,0,-1, 0,0,0,0, 0,0,0,0, -2,0,0,1}, //6
            {},           //7
            {}, //8
            {0,0,0,-1, 0,0,0,0, 0,0,0,0, 0,1,1,1}, //9
            {0,-2,0,0, 0,-2,-1,-1, 0,0,0,0, 0,-2,1,1},  //10      
            {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}, //11
            {0,-2},//12
            {},//13          
            {0,0,-1,-1,0,0,0,0,-2},//14
            {},//15
        };        
};
#endif