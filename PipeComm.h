#ifndef _PIPE_COM_H
#define  _PIPE_COM_H
#include <stdio.h>
#include <string.h>

class PipeComm
{
    public:
        PipeComm(char *pname_s,char *pname_r);
        void open();
        char *request();
        void resetResponse();
        void getResponse(char *res);
    private:
        char pipename_s[256];
        char pipename_r[256];
        FILE *fp_s;
        FILE *fp_r;

        char response[256];


};

#endif