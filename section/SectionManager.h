#ifndef _SECTION_MANAGER_H_
#define _SECTION_MANAGER_H_

#include "Section.h"

typedef struct _Param11
{

    int flag;
    Section::WALKER_NO walk;
    Section::JUDGE_NO judge;
    float speed;
    float target;
    float kp;
    float ki;
    float kd;
    float angleTarget;
    float anglekp;

    float absangle;
    float round;

    float forward;
    float turn;

    bool edge; //true=left,false=right


    Judge::JUDGE_MODE jflag;

    float fangle;
    float flength;
    float bright1;
    float bright2;
    float color1;
    float color2;
    float count;
  
  
    bool vangle;

} wsParam;

class SectionManager {
    public:
        SectionManager();
        ~SectionManager();
        virtual bool run();
        void addSection(Section *);
        void reset();
        void setWalker(Section * sc);
        void setJudge(Section * sc);
        void setWalker(Section * sc,wsParam *wp,int cnt);
        void setJudge(Section * sc,wsParam *wp,int cnt);
        void setWPointer(wsParam *ptr);
        int getError();
    protected:
        Section *mSection[500];
        int mSectionIdx;
        int mLastIdx;
        wsParam *wp;
        wsParam param[500];
        int n;
        int error_code;

        static int msPrevWalker; 
    private:
};

#endif
