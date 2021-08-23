#ifndef _BLOCK_STATE_H_
#define _BLOCK_STATE_H_

#include "Section.h"
#include "SectionManager.h"


class BlockSectionManager;


typedef struct __BINGO_SEC {
    Section::WALKER_NO walker;
    float w_param[20];
    Section::JUDGE_NO judge;
    float j_param[10];
    Judge::JUDGE_MODE update;
} BINGO_SEC;

class BingoState
{
    public:
        BingoState(BlockSectionManager *bsm);

        virtual void init();
        virtual bool run();

    protected:
        int c_abs2ref[4][16] = {
            {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15} ,
            {12,8,4,0,13,9,5,1,14,10,6,2,15,11,7,3} ,
            {15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0} ,
            {3,7,11,15,2,6,10,14,1,5,9,13,0,4,8,12} ,
        };

        int b_abs2ref[4][8] = {
            {0,1,2,3,4,5,6,7},
            {5,3,0,6,1,7,4,2},
            {7,6,5,4,3,2,1,0},
            {2,4,7,1,6,0,3,5},
        };

        BlockSectionManager *mBsm;
    private:

};
#endif
