#include "CameraColorJudge.h"
#include <cmath>
#include "util.h"

#include "spike.h"
extern char rcv_data;

CameraColorJudge::CameraColorJudge()
{
}
void CameraColorJudge::setColor(int col_num)
{
}
void CameraColorJudge::init()
{
    act_tsk(SEND_RCV_TASK);
}
bool CameraColorJudge::run()
{
    if (rcv_data!='\0')
        return true;

    return false;
}