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
    if(Scene::COURSE==0)
      wp = array[0];
    else
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
    case INITMOVE:
    break;
    case MOVE:
    break;
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
  printf("initBonusMove col %d -> area %d\n",bonus_col,area);
  wParam *bonus_param[] = {carry_bonus_3,carry_bonus_3,carry_bonus_2,carry_bonus_3};
    reset();
    init(bonus_param[area]);  
    mState = BONUSMOVE;

}

void  BlockSectionManager::execBonusMove()
{
  if(SectionManager::run()) {
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
  if(SectionManager::run()) {
    mState = INITCARRY;
  }
}

void BlockSectionManager::initCarry()
{
    reset();
    init(c_8_2);
    mState = CARRY;
}

void BlockSectionManager::execCarry()
{
  if(SectionManager::run()) {
    mState = INITMOVE;
  }
}


void BlockSectionManager::changeBonusBlock(int area,BkCol col)
{ 
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
            bonus_col = (BkCol)color;
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