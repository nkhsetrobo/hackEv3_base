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

unsigned char PipeComm::request()
{
    char rcv_data='\0';
    if (fp_s!=nullptr) {
      fprintf(fp_s,"c\n");
      fflush(fp_s);
    }
    if (fp_r!=nullptr) {
      rcv_data=fgetc(fp_r);
      fgetc(fp_r); // return skip
      printf("RECV:%c %d\n",rcv_data,rcv_data);
    }
    response = rcv_data;
    return rcv_data;
}

void  PipeComm::resetResponse()
{
    response='\0';
}

unsigned char  PipeComm::getResponse()
{
    return response;
}





