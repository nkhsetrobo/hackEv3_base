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
    // act_tsk(SEND_RCV_TASK);
    rcv_data='\0';
    sta_cyc(SEND_RCV_CYC);
}
bool CameraColorJudge::run()
{
   // printf("CameraColorJudge %c\n",rcv_data);
    if (rcv_data!='\0' &&  rcv_data!='x') {
        stp_cyc(SEND_RCV_CYC);
        return true;
    }

   // act_tsk(SEND_RCV_TASK);
    return false;
}