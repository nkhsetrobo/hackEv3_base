#ifndef _BLOCK_SECTION_MANAGER_H_
#define _BLOCK_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "BingoState.h"
#include "BingoStateCarry.h"
#include "BingoStateMove.h"
#include "Area.h"

class BlockSectionManager : public SectionManager {
    public:
        BlockSectionManager();

        void setState(BingoState *bst);
        void init();
        bool run();        
        int getError();

        void initArea();
    
        static BingoState *msCarryState;
        static BingoState *msMoveState;
        static Area *msArea;

    protected:


    private:
        BingoState *mState;
        int error_code;


};

#endif
