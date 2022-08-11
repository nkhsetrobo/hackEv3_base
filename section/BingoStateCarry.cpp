#include "BingoStateCarry.h"
#include "BingoStateCarryData.h"

BingoStateCarry::BingoStateCarry(BlockSectionManager *bsm)
    :BingoState(bsm)
{

}

void BingoStateCarry::init()
{
    printf("====bingo state carry init====\n");
    wParam param[30];
    int cnt=0;
    int from_idx=10;
    int to_idx=1;

    error_code = 0;

    Runner *runner = mArea->getRunner();
    BlockPlace *run_pos = runner->getStart();
    int run_node = run_pos->getNodeid();
    int run_idx = run_pos->getCircleidx(); // 絶対座標系
    int run_dir = runner->getDir();
    Block *block = mArea->getBlockPlace(run_node)->getBlock();
    COLOR block_col = block->getColor();
    int bc_idxs[5];
    mArea->getBlockCircles(block_col,bc_idxs); // 運搬候補
    rotIdxs(run_dir,bc_idxs);   // 相対座標へ変換
    
    int error;
    from_idx = c_abs2ref[cnv2[run_dir]][run_idx];
    int sel_circle = selectCircle(from_idx,bc_idxs,error);    // 相対座標系
    //to_idx = b_abs2ref[cnv2[run_dir]][sel_circle];
    to_idx = sel_circle;
    printf("Runner %d/%d %d  block %d block_circle %d %d *%d* %d->%d\n",run_node,run_idx,run_dir, block_col, bc_idxs[0],bc_idxs[1] ,sel_circle, from_idx,to_idx);

    // for(int i=0;i<16;i++) {
    //     for(int j=0;j<8;j++) {
    //         printf("address %d,%d  %d!!\n",i,j,carry_list[i][j]);
    //     }
    // }

    BINGO_SEC *carry_pt = carry_list[from_idx][to_idx];
   // printf("address %d!!\n",carry_pt);
    if(error!=0 || carry_pt==0) {
        printf("ROUTE NOT FOUND!!! %d->%d\n",from_idx,to_idx);
        error_code= BingoState::NOROTUE;
        return;
    }
    for(cnt=0;carry_pt[cnt].walker!=-1;cnt++) {
        //printf("        %d,%f %d,%f!!\n",carry_pt[cnt].walker,carry_pt[cnt].w_param[0], carry_pt[cnt].judge,carry_pt[cnt].j_param[0]);
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
        param[cnt].bright2 = carry_pt[cnt].j_param[3];

        if(param[cnt].judge==Section::COLOR) {
            int color_node= carry_pt[cnt].j_param[4];
            int color_idx= c_abs2ref[cnv[run_dir]][color_node];
            int node = idx2node[color_idx];
            int color =(int)((CrossCircle*)(mArea->getBlockPlace(node)))->getColor();
            printf("node %d->%d->%d color %d    H%f S%f\n",color_node,color_idx,node,color,   color2hue[color],color2satu[color]);
            param[cnt].color1 = color2hue[color];
            param[cnt].color2 = color2satu[color];
            //param[cnt].color2 = carry_pt[cnt].j_param[5];
        }
        param[cnt].count = carry_pt[cnt].j_param[6];
        param[cnt].vangle = carry_pt[cnt].j_param[7];
    }
    param[cnt].flag = -1;

    //mBsm->setWPointer(param);
    mBsm->reset();
    for (int cnt = 0; param[cnt].flag != -1; cnt++)
    {

        Section *sc = new Section();

        mBsm->setWalker(sc,param,cnt);
       // printf("BSC setJudger %d\n", param[cnt].judge);
        mBsm->setJudge(sc,param,cnt);

        mBsm->addSection(sc);
    }

    // 走行体更新
    printf("RUNNER update %d,%d,%d\n" ,run_dir,from_idx,to_idx);
    int next_runner = c_abs2ref[cnv[run_dir]][runner_list[from_idx][to_idx]]; // 終了時相対位置 →　絶対位置
    int next_dir = run_dir + dir_list[from_idx][to_idx]; // 相対方向　→　絶対方向
    if(next_dir>3) next_dir-=4;
    if(next_dir<0) next_dir+=4;
    BlockPlace *bp = mArea->getBlockPlace(convSmall2Big(next_runner));
    runner->setStart(bp);
    runner->setDir((DIR)next_dir);
    // ブロック移動更新
    Block *move_block = mArea->getBlockPlace(run_node)->getBlock();
    mArea->getBlockPlace(run_node)->delBlock();

    to_idx = b_abs2ref[cnv[run_dir]][sel_circle];
    mArea->getBlockPlace(convSmall2BigBC(to_idx))->addBlock(move_block);

 //   mBsm->setState(BlockSectionManager::msMoveState);
}


int BingoStateCarry::selectCircle(int current,int idxs[], int &error)
{
    error=0;
   // printf("selectCircle %d (%d %d)\n",current,idxs[0],idxs[1]);
    if(idxs[1]==-1)
        return idxs[0];

    if(cost[current][idxs[0]]<cost[current][idxs[1]]) {
        if(cost[current][idxs[0]]>=999) error=1;
        return idxs[0];
    } else {
        if(cost[current][idxs[1]]>=999) error=1;
        return idxs[1];
    }
}

void BingoStateCarry::rotIdxs(int dir,int idxs[])
{
    for (int i=0;idxs[i]!=-1;i++) {
        if (idxs[i]!=-1) {
            idxs[i] = b_abs2ref[cnv2[dir]][idxs[i]];
        }
    }
}