#include "PipeComm.h"

PipeComm::PipeComm(char *pname_s,char *pname_r)
{
    strcpy(pipename_s,pname_s);
    strcpy(pipename_r,pname_r);
    fp_s = nullptr;
    fp_r = nullptr;
}

void PipeComm::open()
{
    printf("rcv pipe open %s\n",pipename_r);
    fp_r = fopen(pipename_r,"rw");
    printf("send pipe open %s\n",pipename_s);
    fp_s = fopen(pipename_s,"w");
    printf("pipe opened\n");
}

char *PipeComm::request()
{
    char rcv_data='\0';
    if (fp_s!=nullptr) {
      fprintf(fp_s,"c\n");
      fflush(fp_s);
    }
    if (fp_r!=nullptr) {
        int cnt=0;
        while((response[cnt]=fgetc(fp_r))!='\n') {
            cnt++;
        }
        response[cnt]='\0';
        printf("RECV:%s\n",response);
    }
    return response;
}

void  PipeComm::resetResponse()
{
    response[0]='\0';
}

void PipeComm::getResponse(char *res)
{
    strcpy(res,response);
}





