#ifndef __BINGO_STATE_CARRY_DATA__
#define __BINGO_STATE_CARRY_DATA__

        // //  float BingoStateCarry::bkp=39,BingoStateCarry::bki=25.0,BingoStateCarry::bkd=5.0;
        //  float BingoStateCarry::fwd=20;
        //  float BingoStateCarry::bspd = 24.0;
        //  float BingoStateCarry::bspd2 = 12.0;
        //  float BingoStateCarry::_EDGE = true;
        //  float BingoStateCarry::sign=1.0;

#define bkp 39
#define bki 25.0
#define bkd 5.0
#define bspd 24.0
#define bspd2 12.0
#define _EDGE true
#define sign 1.0


        //  float BingoStateCarry::end_r_angle = -2.0;
        // float  BingoStateCarry::end_l_angle = 2.0;

#define end_r_angle -2.0
#define end_l_angle 2.0


        //　1  右
         BINGO_SEC BingoStateCarry::c1_2[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 15, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  2 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // R1 右旋回　1区画  右
         BINGO_SEC BingoStateCarry::c1_3[] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };
        // R2 右旋回 2区画　 左
         BINGO_SEC BingoStateCarry::c1_6[] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki*2, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-94*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, 10.0, 2.0, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
                Section::LENGTH,{00, 28, 0, 0,0, 0, 0},Judge::UNUPDATE},

            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 46, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　R1R1 右旋回 １区画　右旋回　１区画　右
         BINGO_SEC BingoStateCarry::c2_0[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 右旋回　直入れ
         BINGO_SEC BingoStateCarry::c2_1[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

         BINGO_SEC BingoStateCarry::c2_2[] = {
          // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, -4, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}                      
        };

        //　R1R1 右旋回 １区画　右旋回　１区画　左
        //  BINGO_SEC BingoStateCarry::*c2_3=0;
         BINGO_SEC BingoStateCarry::c2_3[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };


        // R1 右旋回　1区画  左
         BINGO_SEC BingoStateCarry::c2_4[] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -7.0*sign, 0, 0, false},
               Section::TURNANGLE,{-115*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},

            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            // {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
            //    Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };

        // R2R1 右旋回 2区画　右旋回 1区画 左
         BINGO_SEC BingoStateCarry::c2_5[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1/*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd , 1, 1/*setparam*/, 0, -14.0*sign, 0, 0, false},
               Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1/*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UNUPDATE},


        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // R2 右旋回 2区画　 右
        //  BINGO_SEC BingoStateCarry::*c2_6=0;
         BINGO_SEC BingoStateCarry::c2_6[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{00, 2, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };


        // R2 右旋回 2区画　 左
         BINGO_SEC BingoStateCarry::c2_7[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2.0, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　R1R1 右旋回 １区画　右旋回　１区画　右
         BINGO_SEC BingoStateCarry::c3_1[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // R1R2 右旋回　1区画　右旋回　2区画 右
         BINGO_SEC BingoStateCarry::c3_0[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        
        // 右旋回　直入れ
         BINGO_SEC BingoStateCarry::c3_2[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.5, 0, (float)_EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.6, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 5, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 4.5, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

        // R1R2 右旋回　1区画　右旋回　2区画
         BINGO_SEC BingoStateCarry::c3_3[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, // 左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // R1 右旋回　1区画  右
         BINGO_SEC BingoStateCarry::c3_4[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };

        // R1R2 右旋回　2区画　右旋回　2区画 左
         BINGO_SEC BingoStateCarry::c3_5[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 49, 0, 0,0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN

            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 9999, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 右旋回 2区画　右旋回　1区画 左
         BINGO_SEC BingoStateCarry::c3_6[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, // 左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -14.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0,  12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // R2 右旋回 2区画　
         BINGO_SEC BingoStateCarry::c3_7[] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-120*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},

            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            // {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
            //    Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd*2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1, 1  /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　右旋回 １区画　右旋回　１区画
         BINGO_SEC BingoStateCarry::c6_3[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -9.5*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 19, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, -12.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 右旋回　1区画　右旋回　2区画　右旋回
         BINGO_SEC BingoStateCarry::c7_0[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false}, // 中央
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 2.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
         // R1R1R1  右旋回　1区画　右旋回　1区画　右旋回　1区画
         BINGO_SEC BingoStateCarry::c7_1[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.8, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},  //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            
        // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 左旋回　直入れ
         BINGO_SEC BingoStateCarry::c7_2[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2*0.5, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 9.0*sign, 0, 0, false},
               Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 5, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 4, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{270*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -1, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          
       

        };
 
        // R1R2 右旋回　1区画　右旋回　2区画 右
         BINGO_SEC BingoStateCarry::c7_3[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-95*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 3, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        // 右旋回　直入れ
         BINGO_SEC BingoStateCarry::c7_4[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.75, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 1, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-4, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };
        // R1R2 右旋回　1区画　右旋回　2区画 左
         BINGO_SEC BingoStateCarry::c7_5[] = {

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10.0*sign, 0, 0, false},
               Section::TURNANGLE,{-88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},   //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-105*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0,  16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0,  1, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        //　R1R1 右旋回 １区画　右旋回　１区画　左
         BINGO_SEC BingoStateCarry::c7_6[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -10*sign, 0, 0, false},
               Section::TURNANGLE,{-90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)_EDGE}, //左エッジ
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -(float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{-100*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -6.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // R1 右旋回　1区画  右
         BINGO_SEC BingoStateCarry::c7_7[] = {
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.6, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -11*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.5, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -6.0*sign, 0, 0, false},
               Section::TURNANGLE,{-115*sign, 0, 0, 0, 0, 0, 0}, Judge::UNUPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::BRIGHTNESS,{0, 0, -0.5, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2*0.8, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 12, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -5.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}   
         };

        // L1 初手 黄色
         BINGO_SEC BingoStateCarry::c10_1[] = {
        // 左旋回
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{00, 3, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{0*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //  直入れ　左　初手　赤
         BINGO_SEC BingoStateCarry::c10_4[] = {
        // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 直入れ　右　（初手　緑）
         BINGO_SEC BingoStateCarry::c10_7[] = {
          // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0/*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, -4, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}                      
        };


        // L1 初手　青
         BINGO_SEC BingoStateCarry::c10_2[] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 5, 0, 0,0, 0, 0},Judge::UPDATE},
        // 設置開始
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{00, 2, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, -0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            
        };

        // L1L2 左旋回　1区画　左旋回　2区画　
         BINGO_SEC BingoStateCarry::c11_0[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        //　L1L1 左旋回 １区画　左旋回　１区画 右
         BINGO_SEC BingoStateCarry::c11_1[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 左旋回　1区画  左
         BINGO_SEC BingoStateCarry::c11_2[] = {
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 17, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        // L1L2  左旋回　1区画　左旋回　2区画
         BINGO_SEC BingoStateCarry::c11_3[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 9.5*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 12, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 左旋回　直入れ
         BINGO_SEC BingoStateCarry::c11_4[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
                 Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

        // L1L2 左旋回　1区画　左旋回　2区画
         BINGO_SEC BingoStateCarry::c11_5[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd*0.8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false}, // 中央
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        //　R1R1 右旋回 １区画　右旋回　１区画　右
        //　L1L1L1 左旋回 １区画　左旋回　１区画　左旋回　１区画　右
         BINGO_SEC BingoStateCarry::c11_6[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 1, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, (float)9.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 0.1, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 1, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE}         
        };

        // 右旋回　直入れ
         BINGO_SEC BingoStateCarry::c11_7[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, -8.0*sign, 0, 0, false},
               Section::TURNANGLE,{-170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 4, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 4.5*sign, 0, 0, false},
                 Section::TURNANGLE,{-270*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

        // L2 左旋回 2区画　 右
         BINGO_SEC BingoStateCarry::c13_1[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},

            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1/*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　1L1 １区画　左旋回　１区画 右
         BINGO_SEC BingoStateCarry::c13_4[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE}, 
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -2.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };
        // 直入れ 左
         BINGO_SEC BingoStateCarry::c13_6[] = {
        // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };


        //　1 左
         BINGO_SEC BingoStateCarry::c13_7[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 15, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 30, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  14 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 1.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // L2L1 左旋回　2区画　左旋回　1区画
         BINGO_SEC BingoStateCarry::c14_0[] = {
           {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},

            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0, 10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

           {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0,(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp,bki,bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN

        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}                      
        };

        // L2 左旋回 2区画　
         BINGO_SEC BingoStateCarry::c14_1[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::WALKER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, bspd2, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0,  16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };
        // L2 左旋回 2区画　
         BINGO_SEC BingoStateCarry::c14_2[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*1.5, 0, (float)_EDGE},
                Section::LENGTH,{00, 10, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        //　L1L1 左旋回 １区画　左旋回　１区画
         BINGO_SEC BingoStateCarry::c14_3[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
           {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };
        // 左旋回　1区画  右
         BINGO_SEC BingoStateCarry::c14_4[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -3.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        //　L1L1 左旋回 １区画　左旋回　１区画
         BINGO_SEC BingoStateCarry::c14_5[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            // {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 12.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{},Judge::UPDATE},
        };

        // 左旋回　直入れ
         BINGO_SEC BingoStateCarry::c14_6[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -2, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
                 Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };
        // 右　直入れ
         BINGO_SEC BingoStateCarry::c14_7[] = {
        // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{00, 1, 0, 0,0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0,bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // L2L2  左旋回　2区画　左旋回　2区画 右
         BINGO_SEC BingoStateCarry::c15_0[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  7 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
            //     Section::LENGTH,{ 0, 99999, 0, 0, 0, 0, 0},Judge::UPDATE},

            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)(float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  6 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  5 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // 左旋回 2区画 左旋回　1区画
         BINGO_SEC BingoStateCarry::c15_1[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{0, 0 ,0, 0 , 11, 0.3,0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 18, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 14.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},

            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{0, 0 ,0, 0 , 6, 0.3,0, 0},Judge::UNUPDATE},
        // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // L2 左旋回 2区画 　
         BINGO_SEC BingoStateCarry::c15_2[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 4, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
               
            {Section::TRACER,{bspd2, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd*2, 0, (float)_EDGE},
                Section::LENGTH,{ 0, 10, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::TRACER,{bspd, 0, bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{0, 0 ,0, 0 , 7, 0.3,0, 0},Judge::UNUPDATE},
        // 設置開始
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
            //     Section::LENGTH,{ 0, 2, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::VIRTUAL,{bspd, 0, bkp, bki, bkd, 1, 1  /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1, 1  /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -3.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}
        };

        // L1L2  左旋回　1区画　左旋回　2区画
         BINGO_SEC BingoStateCarry::c15_3[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -18.5*sign, 0, 0, false},
               Section::TURNANGLE,{-40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, -16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_r_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };
        // 左旋回　1区画  左
         BINGO_SEC BingoStateCarry::c15_4[] = {
            // {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}            };

        // L1L2  左旋回　1区画　左旋回　2区画
         BINGO_SEC BingoStateCarry::c15_5[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, (float)10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 15, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd,1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd, 0, (float)_EDGE},
                Section::LENGTH,{0, 10, 0, 0, 0, 0, 0},Judge::UPDATE}, // GREEN
            {Section::TRACER,{bspd, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 14, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  9 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        // L1L1  左旋回　1区画　左旋回　1区画 左
         BINGO_SEC BingoStateCarry::c15_6[] = {
            //  {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
            //     Section::LENGTH,{0, 3, 0, 0,0, 0, 0}, Judge::UPDATE},
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::VIRTUAL,{bspd2, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 10.0*sign, 0, 0, false},
               Section::TURNANGLE,{90*sign, 0, 0, 0, 0, 0, 0}, Judge::UPDATE},
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 16, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  10 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
       // 設置開始
            {Section::VIRTUAL,{bspd, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 18.5*sign, 0, 0, false},
               Section::TURNANGLE,{40*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,20},Judge::UPDATE}, 
         // 設置完了 
            {Section::VIRTUAL,{-8, 0, bkp, 1.0, 1.0, 0.3, 1.0 /*setparam*/, 0, 16.0*sign, 0, 0, false},
                 Section::TURNANGLE,{end_l_angle*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::VIRTUAL2,{-8, 0, bkp*.5, 0.1, 0.5, 1.0, 1.0 /*setparam*/, 0*sign, 0, 0, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, -4.0, 0, 0,0, 0,0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE},
            {Section::WEND,{},Section::JEND,{}}          

        };

        //　左旋回　直入れ
         BINGO_SEC BingoStateCarry::c15_7[] = {
             {Section::WALKER,{ 0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::LENGTH,{0, 2, 0, 0,0, 0, 0}, Judge::UPDATE},
       // 設置開始
            {Section::VIRTUAL,{bspd2*0.8, 0, bkp, 1.0, 1.0, 1.0, 1.0 /*setparam*/, 0, 8.0*sign, 0, 0, false},
               Section::TURNANGLE,{170*sign, 0, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 3, 0, 0,0, 0,20},Judge::UPDATE}, 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,40},Judge::UPDATE}, 
         // 設置完了 
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, -bspd2, 0, (float)_EDGE},
                 Section::LENGTH,{ 00, 0, 0, 0,0, 0,20},Judge::UNUPDATE}, 
            {Section::VIRTUAL,{-8, 0, bkp, bki, bkd, 1.0, 1.0 /*setparam*/, 0, 5.0*sign, 0, 0, false},
                 Section::TURNANGLE,{88*sign, 0, 0, 0, 0, 0, 0},Judge::UNUPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, 0, 0, (float)_EDGE},
                 Section::STOP,{ 00, 0, 0, 0,0, 0,50},Judge::UPDATE}, 
            {Section::TRACER,{bspd2, 0,bkp, bki, bkd, 1, 1 /*setparam*/, 0, 0, 0, 0, (float)!_EDGE},
                Section::LENGTH,{ 0, 13, 0, 0, 0, 0, 0},Judge::UPDATE},
            {Section::WALKER,{0, 0, 0, 0.0, 0.0, 0, 0 /*setparam*/, 0, 0, bspd2, 0, (float)_EDGE},
                Section::COLOR,{00, 0, 0, 0,  11 ,0.3, 0, 0},Judge::UPDATE}, // GREEN
            {Section::WEND,{},Section::JEND,{}}          

        };

         BINGO_SEC *BingoStateCarry::carry_list[16][8] = {
            {},
            {0,0,BingoStateCarry::c1_2, BingoStateCarry::c1_3, 0,0,BingoStateCarry::c1_6},
            {BingoStateCarry::c2_0, BingoStateCarry::c2_1, BingoStateCarry::c2_2, BingoStateCarry::c2_3, BingoStateCarry::c2_4, BingoStateCarry::c2_5, BingoStateCarry::c2_6, BingoStateCarry::c2_7},
            {BingoStateCarry::c3_0, BingoStateCarry::c3_1, BingoStateCarry::c3_2,  BingoStateCarry::c3_3,  BingoStateCarry::c3_4, BingoStateCarry::c3_5, BingoStateCarry::c3_6, BingoStateCarry::c3_7},
            {},
            {},
            {},
            {BingoStateCarry::c7_0, BingoStateCarry::c7_1, BingoStateCarry::c7_2, BingoStateCarry::c7_3, BingoStateCarry::c7_4, BingoStateCarry::c7_5, BingoStateCarry::c7_6,BingoStateCarry::c7_7 },          
            {},
            {},
            {0,BingoStateCarry::c10_1,BingoStateCarry::c10_2,    0,BingoStateCarry::c10_4,    0,0,BingoStateCarry::c10_7},        
            {BingoStateCarry::c11_0, BingoStateCarry::c11_1, BingoStateCarry::c11_2,   BingoStateCarry::c11_3,BingoStateCarry::c11_4,  BingoStateCarry::c11_5,BingoStateCarry::c11_6, BingoStateCarry::c11_7},
            {},
            {0, BingoStateCarry::c13_1,0,0,BingoStateCarry::c13_4,0,BingoStateCarry::c13_6,BingoStateCarry::c13_7},          
            {BingoStateCarry::c14_0, BingoStateCarry::c14_1,BingoStateCarry::c14_2, BingoStateCarry::c14_3, BingoStateCarry::c14_4,BingoStateCarry::c14_5,BingoStateCarry::c14_6,  BingoStateCarry::c14_7},
            {BingoStateCarry::c15_0,BingoStateCarry::c15_1,BingoStateCarry::c15_2,BingoStateCarry::c15_3,BingoStateCarry::c15_4,BingoStateCarry::c15_5,BingoStateCarry::c15_6, BingoStateCarry::c15_7},
        };

#endif