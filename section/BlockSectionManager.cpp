#include "BlockSectionManager.h"
#include "Section.h"

BingoState *BlockSectionManager::msCarrayState;

BlockSectionManager::BlockSectionManager()
  :SectionManager()
{
    BlockSectionManager::msCarrayState = new BingoStateCarry(this);
    setState(BlockSectionManager::msCarrayState);
}

void BlockSectionManager::init()
{
  mState->init();
}


void BlockSectionManager::setState(BingoState *bst)
{
  mState = bst;
}