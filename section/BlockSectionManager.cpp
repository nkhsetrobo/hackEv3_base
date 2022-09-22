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
  
   // mState->init();
    wParam *wp;
    if(Scene::COURSE==0) {
      wp = array[1];
      setReverse(-1);
    } else
      wp = array[1];

    init(wp);
}

bool BlockSectionManager::run()
{
  switch(mState) {
    case UNDEFINED:
      mState = AREASEARCH;
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
  }
}

void  BlockSectionManager::initBonusMove()
{
  int area = getBonusArea(bonus_col);
  wParam *bonus_param[] = {carry_bonus_3,carry_bonus_3,carry_bonus_2,carry_bonus_3};
  int endpt[] = {13,13,7,13}; // 走行体現在位置
  cur_no = endpt[area];
  printf("initBonusMove col %d -> area %d  robot %d\n",bonus_col,area,cur_no);
    reset();
    init(bonus_param[area]);  
    mState = BONUSMOVE;

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
    for(int cnt=0;cnt<4;cnt++) {
      int to_block_node = to_block_list[cur_no][cnt];
      if (block_list_in_area[node_to_block[to_block_node]]==1) {     // ブロックが未処理である   
        printf("MOVE %d -> %d\n",cur_no,to_block_node);
        block_list_in_area[node_to_block[to_block_node]]=0; // ブロックを処理済みへ
        if(move_list[cur_no][to_block_node]!=nullptr) {
          init(move_list[cur_no][to_block_node]);
          cur_no = to_block_node; // 次の走行体位置更新
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
}

void BlockSectionManager::execMove()
{
  if(run_section()) {
    mState = INITCOLOR;
  }
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
    int dist_areano = getBonusArea(carry_block);
    printf("carry block %d -> %d\n",cur_no,dist_areano);
    if(carry_list[cur_no][dist_areano]!=nullptr) {
        init(carry_list[cur_no][dist_areano]);
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