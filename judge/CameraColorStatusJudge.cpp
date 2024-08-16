#include "CameraColorStatusJudge.h"
extern PipeComm *gPcomm;

CameraColorStatusJudge::CameraColorStatusJudge()
{
    mPcomm  = gPcomm;
}

float CameraColorStatusJudge::status()
{
    unsigned char res=mPcomm->getResponse();
    printf("color %c\n",mPcomm->getResponse());
    if(res=='r')
        return 0;
    else 
        return 1;
}
