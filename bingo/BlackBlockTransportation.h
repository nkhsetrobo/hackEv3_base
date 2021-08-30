#ifndef _BLACKBLOCK_TRANSPORTATION_H_
#define _BLACKBLOCK_TRANSPORTATION_H_

#include "BlockList.h"

class BlackBlockTransportation : public RootDetermination
{
    public:
    BlackBlockTransportation();
    private:
    BlockList *blocklist;
};

#endif