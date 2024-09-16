#ifndef _SCENE_H_
#define  _SCENE_H_

#include "SpeedSectionManager.h"
#include "BingoSectionManager.h"

class Scene{
    public:
        Scene();
        bool run();    //実行する
        void execUndefined();
        void execStart();
        void execSpeed();
        void execBingo();
        void initSpeed();
        void initBingo();

        void finish();
        static BingoSectionManager *mBsm;

    private:
        enum State {
            UNDEFINED,
            START,
            INIT_SPEED,
            SPEED,
            INIT_BINGO,
            BINGO,
            END
        };

        State mState;    //状態を保持する列挙型

        SpeedSectionManager *mSsm;
};
#endif
