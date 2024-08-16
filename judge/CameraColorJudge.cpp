#include "CameraColorJudge.h"
#include <cmath>
#include "util.h"

#include "spike.h"
extern char rcv_data;
extern PipeComm *gPcomm;

CameraColorJudge::CameraColorJudge()
{
    mPcomm  = gPcomm;
}
void CameraColorJudge::setColor(int col_num)
{
}
void CameraColorJudge::init()
{
    // act_tsk(SEND_RCV_TASK);
    mPcomm->resetResponse();
    sta_cyc(SEND_RCV_CYC);
}
bool CameraColorJudge::run()
{
   // printf("CameraColorJudge %c\n",rcv_data);
    unsigned char res;
    res = mPcomm->getResponse();
    if (res!='\0' &&  res!='x') {
        stp_cyc(SEND_RCV_CYC);
        return true;
    }

   // act_tsk(SEND_RCV_TASK);
    return false;
}