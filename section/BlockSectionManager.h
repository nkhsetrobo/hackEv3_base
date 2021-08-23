#ifndef _BLOCK_SECTION_MANAGER_H_
#define _BLOCK_SECTION_MANAGER_H_
#include "SectionManager.h"
#include "BingoState.h"
#include "BingoStateCarry.h"

class BlockSectionManager : public SectionManager {
    public:
        BlockSectionManager();

        void setState(BingoState *bst);
        void init();
       // bool run();
    protected:
        static BingoState *msCarrayState;


    private:
        BingoState *mState;

};

#endif
