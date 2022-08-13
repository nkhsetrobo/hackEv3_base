#ifndef _SECTION_MANAGER_H_
#define _SECTION_MANAGER_H_

#include "Section.h"

typedef struct _Param11
{

    int flag;
    Section::WALKER_NO walk;
    Section::JUDGE_NO judge;
    double speed;
    double target;
    double kp;
    double ki;
    double kd;
    double angleTarget;
    double anglekp;

    double absangle;
    double round;

    double forward;
    double turn;

    int edge; //true=left,false=right


    Judge::JUDGE_MODE jflag;

    double fangle;  // arm, tail
    double flength;
    double bright1;
    double bright2;
    double color1;
    double color2;
    double count; //stop
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
