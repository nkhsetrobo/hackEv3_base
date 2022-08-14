#include "BlockSectionManager.h"

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

    wp = array[0];

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
    init(c_0_1);
    mState = CARRY;
}

void BlockSectionManager::execCarry()
{
  if(SectionManager::run()) {
    mState = INITMOVE;
  }
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