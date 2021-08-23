#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"
#include "SlalomSectionManager.h"
#include "GarageSectionManager.h"
#include "BlockSectionManager.h"

class Scene{
    public:
        Scene();
        bool run();
        void execUndefined();
        void execStart();
        void execSpeed();
        void initBingo();
        void execBingo();
        void initSlalom();
        void execSlalom();
        void initGarage();
        void execGarage();
        void initSpeed();
        void execEnd();

    private:
        enum State {
            UNDEFINED,
            START,
            INIT_SPEED,
            SPEED,
            INIT_BINGO,
            BINGO,
            INIT_SLALOM,
            SLALOM,
            INIT_GARAGE,
            GARAGE,
            FINISH
        };

        State mState;

        SpeedSectionManager *mSsm;
        SlalomSectionManager *mSlm;
        GarageSectionManager *mGsm;
        BlockSectionManager *mBsm;
};
#endif
