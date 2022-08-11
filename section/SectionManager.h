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

    Section::JUDGE_NO statusjudge;

} wParam;

class SectionManager {
    public:
        SectionManager();
        ~SectionManager();
        virtual bool run();
        void addSection(Section *);
        void reset();
        //void setWalker(Section * sc);
        //void setJudge(Section * sc);
        void setWalker(Section * sc,wParam *wp,int cnt);
        void setJudge(Section * sc,wParam *wp,int cnt);
        void setStatusJudge(Section * sc,wParam *wp,int cnt);
        void setWPointer(wParam *ptr);
        int getError();
        void init(wParam *ptr);
        virtual void init()=0;
    protected:
        Section *mSection[500];
        int mSectionIdx;
        int mLastIdx;
        wParam *wp;
        wParam param[500];
        int n;
        int error_code;

        static int msPrevWalker; 
        wParam *array;
    private:
};

#endif
