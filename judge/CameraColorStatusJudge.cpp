#include "CameraColorStatusJudge.h"
extern char rcv_data;

CameraColorStatusJudge::CameraColorStatusJudge()
{

}

float CameraColorStatusJudge::status()
{
    printf("color %c\n",rcv_data);
    if(rcv_data=='r')
        return 0;
    else 
        return 1;
}
