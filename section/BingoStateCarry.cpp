#include "BingoStateCarry.h"


BingoStateCarry::BingoStateCarry(BlockSectionManager *bsm)
    :BingoState(bsm)
{

}

void BingoStateCarry::init()
{
    printf("bingo state init\n");
    wsParam param[30];
    int cnt=0;
    int from_idx=10;
    int to_idx=4;

    for(int i=0;i<16;i++) {
        for(int j=0;j<8;j++) {
            printf("address %d,%d  %d!!\n",i,j,carry_list[i][j]);
        }
    }

    BINGO_SEC *carry_pt = carry_list[from_idx][to_idx];
    printf("address %d!!\n",carry_pt);
    for(cnt=0;carry_pt[cnt].walker!=-1;cnt++) {
        printf("        %d,%f %d,%f!!\n",carry_pt[cnt].walker,carry_pt[cnt].w_param[0], carry_pt[cnt].judge,carry_pt[cnt].j_param[0]);
        param[cnt].flag = cnt;
        param[cnt].walk = carry_pt[cnt].walker;
        param[cnt].judge = carry_pt[cnt].judge;
        param[cnt].speed = carry_pt[cnt].w_param[0];
        param[cnt].target = carry_pt[cnt].w_param[1];
        param[cnt].kp = carry_pt[cnt].w_param[2];
        param[cnt].ki = carry_pt[cnt].w_param[3];
        param[cnt].kd = carry_pt[cnt].w_param[4];
        param[cnt].angleTarget = carry_pt[cnt].w_param[5];
        param[cnt].anglekp = carry_pt[cnt].w_param[6];
        param[cnt].absangle = carry_pt[cnt].w_param[7];
        param[cnt].round = carry_pt[cnt].w_param[8];
        param[cnt].forward = carry_pt[cnt].w_param[9];
        param[cnt].turn = carry_pt[cnt].w_param[10];
        param[cnt].edge = carry_pt[cnt].w_param[11];


        param[cnt].jflag = carry_pt[cnt].update;
        
        param[cnt].fangle = carry_pt[cnt].j_param[0];
        param[cnt].flength = carry_pt[cnt].j_param[1];
        param[cnt].bright1 = carry_pt[cnt].j_param[2];
        param[cnt].bright2 = carry_pt[cnt].j_param[3];;
        param[cnt].color1 = carry_pt[cnt].j_param[4];
        param[cnt].color2 = carry_pt[cnt].j_param[5];
        param[cnt].count = carry_pt[cnt].j_param[6];
        param[cnt].vangle = carry_pt[cnt].j_param[7];
    }
    param[cnt].flag = -1;

    //mBsm->setWPointer(param);
    for (int cnt = 0; param[cnt].flag != -1; cnt++)
    {

        Section *sc = new Section();

        mBsm->setWalker(sc,param,cnt);
       // printf("BSC setJudger %d\n", param[cnt].judge);
        mBsm->setJudge(sc,param,cnt);

        mBsm->addSection(sc);
    }
}


