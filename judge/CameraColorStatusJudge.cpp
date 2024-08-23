#include "CameraColorStatusJudge.h"
extern PipeComm *gPcomm;

CameraColorStatusJudge::CameraColorStatusJudge()
{
    mPcomm  = gPcomm;
}

float CameraColorStatusJudge::status()
{
    char res[256];
    mPcomm->getResponse(res);
    printf("color %s\n",res);
    if(res[0]=='r')
        return 0;
    else 
        return 1;
}
