#include "BingoState.h"
#include "BlockSectionManager.h"
int BingoState::NOROTUE = 1;

BingoState::BingoState(BlockSectionManager *bsm)
    :mBsm(bsm)
{
    mArea = BlockSectionManager::msArea;
    error_code=0;
}

void BingoState::init()
{
    
 
}

bool BingoState::run()
{

}

int BingoState::getError()
{
    return error_code;
}

int BingoState::convSmall2Big(int node)
{
    int convert[] = {0,2,4,6, 14,16,18,20, 28,30,32,34, 42,44,46,48};
    printf("conv small %d -> big %d\n",node,convert[node]);
    return convert[node];
}

int BingoState::convSmall2BigBC(int node)
{
    int convert[] = {8,10,12, 22, 26, 36,38,40};
    printf("conv small BC %d -> big %d\n",node,convert[node]);
    return convert[node];
}