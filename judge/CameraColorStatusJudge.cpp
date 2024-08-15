#include "CameraColorStatusJudge.h"

CameraColorStatusJudge::CameraColorStatusJudge()
{
    first=true;
    color_id=-1;
}

float CameraColorStatusJudge::status()
{
    if(first) {
          act_tsk(SEND_TASK);
    }
    act_tsk(RCV_TASK);
    return color_id;
}
