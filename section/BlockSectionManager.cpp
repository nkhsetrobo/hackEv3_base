#include "BlockSectionManager.h"
#include "Section.h"

BingoState *BlockSectionManager::msCarryState;
BingoState *BlockSectionManager::msMoveState;
Area *BlockSectionManager::msArea;

BlockSectionManager::BlockSectionManager()
  :SectionManager()
{
    BlockSectionManager::msArea = new Area(0);
    BlockSectionManager::msCarryState = new BingoStateCarry(this);
    BlockSectionManager::msMoveState = new BingoStateMove(this);
    setState(BlockSectionManager::msCarryState);

}

void BlockSectionManager::init()
{
    mState->init();
}

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

void BlockSectionManager::setState(BingoState *bst)
{
  mState = bst;
}

