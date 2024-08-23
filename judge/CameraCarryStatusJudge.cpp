#include "CameraCarryStatusJudge.h"
extern PipeComm *gPcomm2;

CameraCarryStatusJudge::CameraCarryStatusJudge()
{
    mPcomm  = gPcomm2;

}

void CameraCarryStatusJudge::init()
{
    mPcomm->resetResponse();
    act_tsk(SEND_RCV_TASK2);
}


float CameraCarryStatusJudge::status()
{
    char res[256];

    mPcomm->getResponse(res);
    double val = atof(res);
    printf(" %s %f\n",res,val);
    return val;
}
