#ifndef _CAMERA_COLOR_H_
#define _CAMERA_COLOR_H_
#include "Judge.h"
#include "PipeComm.h"

class CameraColorJudge :public Judge{
    public:
    CameraColorJudge();
    void setColor(int col_num);
    void init();
    bool run();

    private:
        PipeComm *mPcomm;




};



#endif



