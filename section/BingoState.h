#ifndef _BLOCK_STATE_H_
#define _BLOCK_STATE_H_

#include "Section.h"
#include "SectionManager.h"
#include "Area.h"

class BlockSectionManager;

#define _YELLOW  55
#define _GREEN  138
#define _RED  0
#define _BLUE  207

#define _YELLOW_S  0.4
#define _GREEN_S  0.25
#define _RED_S  0.25
#define _BLUE_S  0.7



typedef struct __BINGO_SEC {
    Section::WALKER_NO walker;
    float w_param[20];
    Section::JUDGE_NO judge;
    double j_param[10];
    Judge::JUDGE_MODE update;
} BINGO_SEC;

class BingoState
{
    public:
        BingoState(BlockSectionManager *bsm);

        virtual void init();
        virtual bool run();
        int convSmall2Big(int node);
        int convSmall2BigBC(int node);
        int getError();

    protected:
        static int NOROTUE;
        int error_code;

        int c_abs2ref[4][16] = {
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} , //0 
            {12,8,4,0,13,9,5,1,14,10,6,2,15,11,7,3} , //-90
            {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} , //180
            {3,7,11,15,2,6,10,14,1,5,9,13,0,4,8,12} , //90
        };

        int b_abs2ref[4][8] = {
            {0,1,2,3,4,5,6,7},
            {5,3,0,6,1,7,4,2},
            {7,6,5,4,3,2,1,0},
            {2,4,7,1,6,0,3,5},
        };
        int idx2node[16] = {0,2,4,6, 14,16,18,20,  28,30,32,34, 42,44,46,48};
        float color2hue[4] = {_RED,_GREEN,_BLUE,_YELLOW};
        float color2satu[4] = {_RED_S,_GREEN_S,_BLUE_S,_YELLOW_S};

        int cnv[4] = {1,0,3,2}; //絶対→相対 -90度回転 
        int cnv2[4] = {3,0,1,2}; //相対→絶対 90度回転 

        BlockSectionManager *mBsm;
        Area *mArea;
    private:

};
#endif
