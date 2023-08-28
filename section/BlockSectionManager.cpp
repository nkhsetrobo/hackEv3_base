#include "BlockSectionManager.h"
#include "Scene.h"

//BingoState *BlockSectionManager::msCarryState;
//BingoState *BlockSectionManager::msMoveState;
//Area *BlockSectionManager::msArea;

BlockSectionManager::BlockSectionManager()
  :SectionManager(),
  mState(UNDEFINED)
{
    //BlockSectionManager::msArea = new Area(0);
    //BlockSectionManager::msCarryState = new BingoStateCarry(this);
    //BlockSectionManager::msMoveState = new BingoStateMove(this);
    //setState(BlockSectionManager::msCarryState);

}

void BlockSectionManager::init()
{
  printf("block");
   // mState->init();
    wParam *wp;
    if(Scene::COURSE==0) {
      wp = array[1];
      setReverse(-1);
    } else
      wp = array[1];

    //init(wp);
}

bool BlockSectionManager::run()
{
  switch(mState) {
    case UNDEFINED:
      mState = INITENTER;
    break;
    case AREASEARCH:
      execAreaSearch();
    break;
    case INITBONUSMOVE:
      initBonusMove();
    break;
    case BONUSMOVE:
      execBonusMove();
    break;
    case INITMOVE:
      initMove();
    break;
    case MOVE:
      execMove();
    break;
    case EXITMOVE:
        exitMove();
    break;
    case INITENTER:
      initEnter();
    break;
    case ENTER:
      execEnter();
    break;
    case INITCOLOR:
      initColor();
    break;
    case COLOR:
      execColor();
    break;
    case INITCARRY:
      initCarry();
    break;
    case CARRY:
      execCarry();
    break;
    case END:
      return true;
  }
  return false;

}




void BlockSectionManager::execAreaSearch()
{
  if(run_section()) {
    mState = INITBONUSMOVE;
   // mState = INITMOVE;
  }
}

void  BlockSectionManager::initBonusMove()
{
  int area = getBonusArea(bonus_col);
  wParam *bonus_param[] = {carry_bonus_0,carry_bonus_1,carry_bonus_2,carry_bonus_3};
  int endpt[] = {4,1,7,13}; // 走行体現在位置
  cur_no = next_pos = endpt[area];
  printf("initBonusMove col %d -> area %d  robot %d\n",bonus_col,area,cur_no);
    reset();
    init(bonus_param[area]);  
    mState = BONUSMOVE;

}

void  BlockSectionManager::initEnter()
{
    init(enter);
    mState = ENTER;
}

void  BlockSectionManager::execEnter()
{
  if(run_section()) {
    mState = INITMOVE;
  }
}



void  BlockSectionManager::execBonusMove()
{
  if(run_section()) {
    mState = INITMOVE;
  }
}

void BlockSectionManager::initMove()
{
    static int to_block_list[16][8] = {
      {},//未使用
      {1,8,14,7},//時計回り
      {2,11,13,4},//反時計回り
      {},//未使用

      {4,2,11,13},//反時計回り
      {},//未使用
      {},//未使用
      {7,1,8,14},//時計回り

      {8,14,7,1},//時計回り
      {},//未使用
      {},//未使用
      {11,13,4,2},//反時計回り

      {},//未使用
      {13,4,2,11},//反時計回り
      {14,7,1,8},//時計回り
      {},//未使用

    };
    reset();
    /*
    if(cur_no==7) {
        printf("Move 7 ->7\n");
        init(m_7_7);
    }else {
        printf("Move 13 ->13\n");
        init(m_13_13);
    }
    */
    //max_curno = 2;
    if (block_phase==0) {
      init(movePhase1[cur_no++]);
      if (movePhase1[cur_no]==nullptr) {
          block_phase=1;
          cur_no=0;
      }

    } else if (block_phase==1) { //１つ目
        int idx=0;
        if(color==0) { //赤ならすべて確定
          idx=1;
          block_fix=true;
        } 
        init(carryPhase1[idx]); 
        block_phase=2;
        cur_no=0;
    }
    else if (block_phase==2) { //１つ目の処理
      init(movePhase2[cur_no++]);
      if (block_fix && cur_no==1) { //確定なら色チェックをスキップ
          block_phase=3;
          cur_no=0;
      }
      if (movePhase2[cur_no]==nullptr) {
          block_phase=3;
          cur_no=0;
      }
    } else if (block_phase==3) {// ２つ目
        int idx=0;
        printf("2nd Block color %d\n",color);
        if (!block_fix) { //１つ目が青で確定していない
          if(color==0) {
            block_color[0]=1;
            block_color[1]=0; //赤確定
            block_color[2]=1;

          } else  {
            block_color[0]=1;
            block_color[1]=1;
            block_color[2]=0; //赤確定
          }
        }
        block_fix=true; //ここで必ず確定する
        if(block_color[1]==0) {
          idx=1;
        }
        init(carryPhase2[idx]);
        block_phase=4;
        cur_no=0;
    } else if (block_phase==4) {
        init(movePhase3[0]);
        block_phase=5;
        cur_no=0;
    }else if (block_phase==5) {  
        int idx=0;
        if (block_color[2]==0) {
          idx=1;
        }
        init(carryPhase3[idx]);
        block_phase=6;

    } else if (block_phase==6) {  
      init(exitPhase[0]);
    }
    mState = MOVE;
    return;
#if 0
    for(int cnt=0;cnt<4;cnt++) {
      int to_block_node = to_block_list[cur_no][cnt];
      if (block_list_in_area[node_to_block[to_block_node]]==1) {     // ブロックが未処理である   
        printf("================ MOVE %d -> %d\n",cur_no,to_block_node);
        block_list_in_area[node_to_block[to_block_node]]=0; // ブロックを処理済みへ
        if(move_list[cur_no][to_block_node]!=nullptr) {
          init(move_list[cur_no][to_block_node]);
        //  cur_no = to_block_node; // 次の走行体位置更新
         // cur_no=next_pos;  // 次の走行体位置更新
          mState = MOVE;
        } else {
          printf("move route NOT found\n");
          mState = END;
        }
        return;
      } 
    }
    printf("NO move block \n");
    mState = END;
#endif
}

void BlockSectionManager::execMove()
{
  if(run_section()) {
   //mState = INITCOLOR;
    mState = INITMOVE;
  }
}

void BlockSectionManager::exitMove()
{
     mState = EXITMOVE;
}



void BlockSectionManager::initColor()
{
    reset();
    init(c_search);
    mState =COLOR;
}

void BlockSectionManager::execColor()
{
  if(run_section()) {
    mState = INITCARRY;
  }
}

// 色検出前の位置からブロック運搬
void BlockSectionManager::initCarry()
{
    reset();
#if defined(DEBUG_NOMOVE)
    //debug
      static BkCol c_list[] = {BKBLUE,BKRED,BKYELLOW,BKGREEN, BKBLUE,BKRED,BKYELLOW,BKGREEN};
      static int c_list_cnt=0;

      carry_block = c_list[c_list_cnt++];
      printf("DEBUG carry block %d\n",carry_block);
    //debug
#endif

    int dist_areano = getBonusArea(carry_block);


    printf("############# carry block %d -> area %d\n",cur_no,dist_areano);
    if(carry_list[cur_no][dist_areano]!=nullptr) {
        init(carry_list[cur_no][dist_areano]);
       //printf("prev cur_no %d %d\n",cur_no,dist_areano);
       // printf("DEBUG %d %d %d %d\n",arry_endpt[cur_no][0],arry_endpt[cur_no][1],arry_endpt[cur_no][2],arry_endpt[cur_no][3]);
        cur_no = arry_endpt[cur_no][dist_areano]; // 新しい走行体位置
        printf("cur_no %d \n",cur_no);
      // init(c_13_3);
        mState = CARRY;
    } else {
        printf("carry list no found.\n");
        mState = END;

    }
}

void BlockSectionManager::execCarry()
{
  if(run_section()) {
    mState = INITMOVE;
  }
}


void BlockSectionManager::changeBonusBlock(int area,BkCol col)
{ 
  if(col==-1) col = BKGREEN;
  if(bonus_area[area]==col) 
    return;
  int idx=0;
  for(;idx<4;idx++) {
    if(bonus_area[idx]==col) 
      break;
  }
  BkCol tmp = bonus_area[idx];
  bonus_area[idx] = bonus_area[area];
  bonus_area[area]=tmp;

  printf("BONUS AREA [%d,%d,%d,%d]\n",bonus_area[0],bonus_area[1],bonus_area[2],bonus_area[3]);
}

int BlockSectionManager::getBonusArea(BkCol col)
{
  printf("*****get Bonus Area [%d %d %d %d] %d\n",bonus_area[0],bonus_area[1],bonus_area[2],bonus_area[3],col);
  for(int i=0;i<4;i++) {
    if( bonus_area[i]==col) return i;
  }
  return 0;
}

bool BlockSectionManager::run_section()
{
    if(mSection[mSectionIdx]==nullptr)
        return true;
    //color=-1;
    if(mSection[mSectionIdx]->run()) {
        if(mSection[mSectionIdx]->getID()==100 ) {
            color = (int)mSection[mSectionIdx]->getStatus();
       } 
        mSectionIdx++;
    }

    return false;
}
/*
bool BlockSectionManager::run_section()
{
  int color;
    if(mSection[mSectionIdx]==nullptr)
        return true;

    if(mSection[mSectionIdx]->run()) {
       printf("Section Flag %d\n",mSection[mSectionIdx]->getID());
       if(mSection[mSectionIdx]->getID()==AREA0 ) {
            color = (int)mSection[mSectionIdx]->getStatus();
            changeBonusBlock(0,(BkCol)color);
       } 
       if(mSection[mSectionIdx]->getID()==AREA1 ) {
            color = (int)mSection[mSectionIdx]->getStatus();
            changeBonusBlock(1,(BkCol)color);
       } 
       if(mSection[mSectionIdx]->getID()==AREA2 ) {
            color = (int)mSection[mSectionIdx]->getStatus();
            changeBonusBlock(2,(BkCol)color);
       } 
       if(mSection[mSectionIdx]->getID()==BONUSBLOCK ) {
            color = (int)mSection[mSectionIdx]->getStatus();
            if(color!=-1)
              bonus_col = (BkCol)color;
            else
              bonus_col = BKGREEN; //読みきれなかったボーナスブロックは緑とする

       }
        if(mSection[mSectionIdx]->getID()==COLORBLOCK ) {
            color = (int)mSection[mSectionIdx]->getStatus();
            if(color!=-1)
              carry_block = (BkCol)color;
            else
              carry_block = BKGREEN; //読みきれなかったブロックは緑とする
            printf("setColorBlock %d\n",carry_block);
       }                
        mSectionIdx++;
        printf("nextSection %d =============================\n",mSectionIdx);
    }

    return false;
}
*/

/*
bool BlockSectionManager::run()
{
  if(mState->getError()!=0) {
    error_code = 1;
    return true;
  }

  if(SectionManager::run()) {
      if(getError()!=0) {
          error_code = 2;
      }
      return true;
  }
  error_code=0;
  return false;
}
*/

/*
void BlockSectionManager::setState(BingoState *bst)
{
  mState = bst;
}

*/