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

        static BINGO_SEC c1_0[50],c1_1[50],c1_2[50],c1_3[50],c1_4[50],c1_5[50],c1_6[50],c1_7[50];
        static BINGO_SEC c2_0[50],c2_1[50],c2_2[50],c2_3[50],c2_4[50],c2_5[50],c2_6[50],c2_7[50];
        static BINGO_SEC c3_0[50],c3_1[50],c3_2[50],c3_3[50],c3_4[50],c3_5[50],c3_6[50],c3_7[50];
        static BINGO_SEC c4_0[50],c4_1[50],c4_2[50],c4_3[50],c4_4[50],c4_5[50],c4_6[50],c4_7[50];
        static BINGO_SEC c5_0[50],c5_1[50],c5_2[50],c5_3[50],c5_4[50],c5_5[50],c5_6[50],c5_7[50];
        static BINGO_SEC c6_0[50],c6_1[50],c6_2[50],c6_3[50],c6_4[50],c6_5[50],c6_6[50],c6_7[50];
        static BINGO_SEC c7_0[50],c7_1[50],c7_2[50],c7_3[50],c7_4[50],c7_5[50],c7_6[50],c7_7[50];
        static BINGO_SEC c8_0[50],c8_1[50],c8_2[50],c8_3[50],c8_4[50],c8_5[50],c8_6[50],c8_7[50];
        static BINGO_SEC c9_0[50],c9_1[50],c9_2[50],c9_3[50],c9_4[50],c9_5[50],c9_6[50],c9_7[50];
        static BINGO_SEC c10_0[50],c10_1[50],c10_2[50],c10_3[50],c10_4[50],c10_5[50],c10_6[50],c10_7[50];
        static BINGO_SEC c11_0[50],c11_1[50],c11_2[50],c11_3[50],c11_4[50],c11_5[50],c11_6[50],c11_7[50];
        static BINGO_SEC c12_0[50],c12_1[50],c12_2[50],c12_3[50],c12_4[50],c12_5[50],c12_6[50],c12_7[50];
        static BINGO_SEC c13_0[50],c13_1[50],c13_2[50],c13_3[50],c13_4[50],c13_5[50],c13_6[50],c13_7[50];
        static BINGO_SEC c14_0[50],c14_1[50],c14_2[50],c14_3[50],c14_4[50],c14_5[50],c14_6[50],c14_7[50];
        static BINGO_SEC c15_0[50],c15_1[50],c15_2[50],c15_3[50],c15_4[50],c15_5[50],c15_6[50],c15_7[50];
    
    protected:

    private:


        // float bkp=39,bki=25.0,bkd=5.0;
        // float fwd=20;
        // float bspd = 24.0;
        // float bspd2 = 12.0;
        // float _EDGE = true;
        // float sign=1.0;

        // float end_r_angle = -2.0;
        // float end_l_angle = 2.0;

    //     //　1  右
    //     BINGO_SEC c1_2[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 15, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // R1 右旋回　1区画  右
    //     BINGO_SEC c1_3[20] = {
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}   
    //      };
    //     // R2 右旋回 2区画　 左
    //     BINGO_SEC c1_6[20] = {
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki*2, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-94*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},

    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 46, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //　R1R1 右旋回 １区画　右旋回　１区画　右
    //     BINGO_SEC c2_0[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // 右旋回　直入れ
    //     BINGO_SEC c2_1[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
    //              Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     BINGO_SEC *c2_2 = c10_7;

    //     //　R1R1 右旋回 １区画　右旋回　１区画　左
    //     BINGO_SEC *c2_3=0;
    //     // BINGO_SEC c2_3[20] = {
    //     //      {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //         Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //     //     {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
    //     //        Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //     //     {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     //         Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //         Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     //     {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //     //        Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //     //     {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //     //         Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //         Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // // 設置開始
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     //         Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //     //        Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     //          Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //     //  // 設置完了 
    //     //     {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //     //          Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //     //     {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //     //          Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     //          Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //     //     {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     // };


    //     // R1 右旋回　1区画  左
    //     BINGO_SEC c2_4[20] = {
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-115*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},

    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         // {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //         //    Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}   
    //      };

    //     // R2R1 右旋回 2区画　右旋回 1区画 左
    //     BINGO_SEC c2_5[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1/*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd , 1, 1/*setparam*/, 0, -14.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1/*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UNUPDATE},


    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     // R2 右旋回 2区画　 右
    //     BINGO_SEC *c2_6=0;
    //     // BINGO_SEC c2_6[20] = {
    //     //     // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //     //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //     //     {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
    //     //        Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //     //     // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //     //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //     //     {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //     //         Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //         Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
    //     //         Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

    //     //     {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //     //         Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //     //         Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // // 設置開始
    //     //     {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //     //         Section::LENGTH,{00, 2, 0, 0,0, 0, 0},Judge::UPDATE},
    //     //     {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //     //        Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     //          Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //     //  // 設置完了 
    //     //     {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //     //          Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //     //     {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //     //          Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //     //     {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //     //          Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //     //     {Section::WEND,{},Section::JEND,{}}
    //     // };


    //     // R2 右旋回 2区画　 左
    //     BINGO_SEC c2_7[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //　R1R1 右旋回 １区画　右旋回　１区画　右
    //     BINGO_SEC c3_1[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // R1R2 右旋回　1区画　右旋回　2区画 右
    //     BINGO_SEC c3_0[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
        
    //     // 右旋回　直入れ
    //     BINGO_SEC c3_2[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.5, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.6, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 5, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 4.5, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
    //              Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // R1R2 右旋回　1区画　右旋回　2区画
    //     BINGO_SEC c3_3[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, // 左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // R1 右旋回　1区画  右
    //     BINGO_SEC c3_4[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}   
    //      };

    //     // R1R2 右旋回　2区画　右旋回　2区画 左
    //     BINGO_SEC c3_5[50] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::LENGTH,{00, 49, 0, 0,0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN

    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 9999, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // 右旋回 2区画　右旋回　1区画 左
    //     BINGO_SEC c3_6[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, // 左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -14.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0,  12, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     // R2 右旋回 2区画　
    //     BINGO_SEC c3_7[20] = {
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-120*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},

    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         // {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
    //         //    Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd*2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //　右旋回 １区画　右旋回　１区画
    //     BINGO_SEC c6_3[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 19, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // 右旋回　1区画　右旋回　2区画　右旋回
    //     BINGO_SEC c7_0[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false}, // 中央
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 2.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //      // R1R1R1  右旋回　1区画　右旋回　1区画　右旋回　1区画
    //     BINGO_SEC c7_1[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            
    //     // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // 左旋回　直入れ
    //     BINGO_SEC c7_2[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.5, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 5, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 4, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
    //              Section::TURNANGLE,{270*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -1, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          
       

    //     };
 
    //     // R1R2 右旋回　1区画　右旋回　2区画 右
    //     BINGO_SEC c7_3[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //     // 右旋回　直入れ
    //     BINGO_SEC c7_4[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.75, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-4, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
    //              Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //     // R1R2 右旋回　1区画　右旋回　2区画 左
    //     BINGO_SEC c7_5[50] = {

    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},   //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0,  16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0,  1, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     //　R1R1 右旋回 １区画　右旋回　１区画　左
    //     BINGO_SEC c7_6[20] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
    //            Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -6.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // R1 右旋回　1区画  右
    //     BINGO_SEC c7_7[20] = {
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.6, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -11*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-115*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::BRIGHTNESS,{0, 0, -0.5, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -5.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}   
    //      };

    //     // L1 初手 黄色
    //     BINGO_SEC c10_1[20] = {
    //     // 左旋回
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 3, 0, 0,0, 0, 0},Judge::UPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //  直入れ　左　初手　赤
    //     BINGO_SEC c10_4[10] = {
    //     // 設置開始
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // 直入れ　右　（初手　緑）
    //     BINGO_SEC c10_7[10] = {
    //       // 設置開始
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd, 0, (float)_EDGE},
    //         //     Section::LENGTH,{00, -4, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}                      
    //     };


    //     // L1 初手　青
    //     BINGO_SEC c10_2[20] = {
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
    //     // 設置開始
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 2, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0,bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}            
    //     };

    //     // L1L2 左旋回　1区画　左旋回　2区画　
    //     BINGO_SEC c11_0[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //     //　L1L1 左旋回 １区画　左旋回　１区画 右
    //     BINGO_SEC c11_1[20] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // 左旋回　1区画  左
    //     BINGO_SEC c11_2[20] = {
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}            };

    //     // L1L2  左旋回　1区画　左旋回　2区画
    //     BINGO_SEC c11_3[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // 左旋回　直入れ
    //     BINGO_SEC c11_4[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // L1L2 左旋回　1区画　左旋回　2区画
    //     BINGO_SEC c11_5[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false}, // 中央
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     //　R1R1 右旋回 １区画　右旋回　１区画　右
    //     //　L1L1L1 左旋回 １区画　左旋回　１区画　左旋回　１区画　右
    //     BINGO_SEC c11_6[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, (float)9.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE}         
    //     };

    //     // 右旋回　直入れ
    //     BINGO_SEC c11_7[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 4, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 4.5*sign, 0, 0, false},
    //              Section::TURNANGLE,{-270*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // L2 左旋回 2区画　 右
    //     BINGO_SEC c13_1[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //　1L1 １区画　左旋回　１区画 右
    //     BINGO_SEC c13_4[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };
    //     // 直入れ 左
    //     BINGO_SEC *c13_6 = c10_4;


    //     //　1 左
    //     BINGO_SEC c13_7[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 15, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 1.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // L2L1 左旋回　2区画　左旋回　1区画
    //     BINGO_SEC c14_0[15] = {
    //        {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0, 10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //        {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}                      
    //     };

    //     // L2 左旋回 2区画　
    //     BINGO_SEC c14_1[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::WALKER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, bspd2, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0,  16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };
    //     // L2 左旋回 2区画　
    //     BINGO_SEC c14_2[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
    //             Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     //　L1L1 左旋回 １区画　左旋回　１区画
    //     BINGO_SEC c14_3[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //        {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };
    //     // 左旋回　1区画  右
    //     BINGO_SEC c14_4[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -3.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}            };

    //     //　L1L1 左旋回 １区画　左旋回　１区画
    //     BINGO_SEC c14_5[20] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
    //     };

    //     // 左旋回　直入れ
    //     BINGO_SEC c14_6[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -2, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //     // 右　直入れ
    //     BINGO_SEC *c14_7 = c10_4;

    //     // L2L2  左旋回　2区画　左旋回　2区画 右
    //     BINGO_SEC c15_0[50] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //         //     Section::LENGTH,{ 0, 99999, 0, 0, 0, 0, 0},Judge::UPDATE},

    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // 左旋回 2区画 左旋回　1区画
    //     BINGO_SEC c15_1[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{0, 0 ,0, 0 , 11, 0.3,0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{0, 0 ,0, 0 , 6, 0.3,0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     // L2 左旋回 2区画 　
    //     BINGO_SEC c15_2[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
               
    //         {Section::TRACER,{bspd2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
    //             Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{0, 0 ,0, 0 , 7, 0.3,0, 0},Judge::UNUPDATE},
    //     // 設置開始
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //         //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1  /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1  /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -3.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}
    //     };

    //     // L1L2  左旋回　1区画　左旋回　2区画
    //     BINGO_SEC c15_3[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };
    //     // 左旋回　1区画  左
    //     BINGO_SEC c15_4[20] = {
    //         // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}            };

    //     // L1L2  左旋回　1区画　左旋回　2区画
    //     BINGO_SEC c15_5[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     // L1L1  左旋回　1区画　左旋回　1区画 左
    //     BINGO_SEC c15_6[50] = {
    //         //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //         //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
    //            Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     //　左旋回　直入れ
    //     BINGO_SEC c15_7[50] = {
    //          {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
    //    // 設置開始
    //         {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
    //            Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
    //      // 設置完了 
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
    //              Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
    //         {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
    //              Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
    //              Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
    //         {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
    //             Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
    //         {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
    //             Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
    //         {Section::WEND,{},Section::JEND,{}}          

    //     };

    //     BINGO_SEC *carry_list[16][8] = {
    //         {},
    //         {0,0,c1_2,c1_3, 0,0,c1_6},
    //         {c2_0, c2_1, c2_2,c2_3,c2_4,c2_5,c2_6,c2_7},
    //         {c3_0, c3_1, c3_2,  c3_3,  c3_4,c3_5,c3_6, c3_7},
    //         {},
    //         {},
    //         {},
    //         {c7_0,c7_1,c7_2, c7_3,c7_4, c7_5,c7_6,c7_7 },          
    //         {},
    //         {},
    //         {0,c10_1,c10_2,    0,c10_4,    0,0,c10_7},        
    //         {c11_0, c11_1, c11_2,   c11_3,c11_4,  c11_5,c11_6, c11_7},
    //         {},
    //         {0, c13_1,0,0,c13_4,0,c13_6,c13_7},          
    //         {c14_0, c14_1,c14_2, c14_3, c14_4,c14_5,c14_6,  c14_7},
    //         {c15_0,c15_1,c15_2,c15_3,c15_4,c15_5,c15_6, c15_7},
    //     };
        static float bkp,bki,bkd;
        static float fwd;
        static float bspd;
        static float bspd2;
        static float _EDGE;
        static float sign;

        static float end_r_angle;
        static float  end_l_angle;


        int self=10;
        int cost[16][8] = 
        {
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, // 0 なし
            { self,   5,  15,   35,  45,   45,  55,  55}, // 1
            {  65, self,   5,   65,  35,   75,  45,  45},  // 2
            {  75,  65, self,   75,  35,  105,  95,  95},  // 3           
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //4 なし
            { self,   5,  15,  self,  15,  35,  35,  45}, //5 
            {  95, self,   5,   65,   5,  65,  35,  35}, // 6
            { 105, 105, self,   75, self,   35,  65, 35}, //7             
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //8 なし
            {  35,  35,  45,  self,  15,  self,   5,  15}, //9
            {1000,  20,  20, 1000,  10, 1000,1000,  10}, //10
            {  75,  65,  35,   75,self,  105,  95, self}, //11           
            {1000,1000,1000, 1000,1000, 1000,1000,1000}, //12 なし
            {  45,  45,  55,   35,  45,  self,   5,  15}, //13
            {  85,  55,  55,   35,  45,  65, self,    5}, //14 
            {  85,  75,  45,  75,  35,  75,  65,  self},  //15          
        };

        //走行体の終了方向リスト
        int dir_list[16][8] = {
            {},//0
            {0,0,0,1,0,0,1},//1
            {-2,1,0, -2,1, -2,1,1},//2
            {-2,-2,1, -2, 1,  -2,-2,1},//3
            {},//4
            {},//5
            {},//6
            {-1,-1,1, -2, 1,  -2, -2, 1}, //7         
            {},//8
            {},//9
            {-2,-1,-1,  0, 0, 0,0,0},//10        
            {-2,-2,-1, -2, -1, 1, 1,-1},//11
            {},//12
            {0,-1,0,0,-1,0,0,0},//13          
            {-2,-1,-1,-2, -1, -2, -1,0},//14
            {-2,-2,-1,-2,-1,-2, -2, -1},//15
        };

        //走行体の終了位置リスト
        int runner_list[16][8] = {
            {},
            {0,0,2, 5,0, 0,9},
            {5,6,2, 5,6, 9,10,10}, //2
            {5,6,7, 5,7, 9,10,11},//3
            {},
            {},
            {},
            {5,6,7, 9,11,  9,10,11},//7          
            {},
            {},
            {0,6,6,0,10,0,0,10},        
            {5,6,7, 5,7, 9,10,11}, //11
            {},
            {0,5,0,0,10,0,13,14 }, //13         
            {5,6,6, 9,10 ,9,10,14}, //14
            {5,6,7,  9,11,  9,10,11}, //15 
        };

        static BINGO_SEC *carry_list[16][8];
};
#endif