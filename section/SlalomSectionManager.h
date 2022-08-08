#ifndef _SLALOM_SECTION_MANAGER_H_
#define _SLALOM_SECTION_MANAGER_H_
#include "SectionManager.h"



class SlalomSectionManager : public SectionManager
{
    public:
        SlalomSectionManager();
        void init();

    protected:

    private:
        #if defined(MAKE_RIGHT)
            const int _EDGE = LineTracer::LEFTEDGE;
        #else
            const int _EDGE = LineTracer::RIGHTEDGE;
        #endif
        
        int n;
        wParam a[100] = {
                        // {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::GYRO, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 18, 0, true,Judge::UPDATE, -10, 0, 0, 0, 0, 0, 0}, //test用
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 18, 0, true,Judge::UPDATE, -10, 15, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 7, 0, 0, 0.2, 0.8, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.6, 0.4, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0}, //昇段
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0.1, 0, true,Judge::UPDATE, 0, 0.1, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 2, -0.7, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, 40, 0, 0, true,Judge::UPDATE, 23, 16.7, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 9, 0, 0, 1, 1 /*setparam*/, 0, -27, 0, 0, true,Judge::UNUPDATE, -38.5, 33, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0, 0, 0.6, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 18, 8.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 4, 0, 8, 0, 0, 1, 1 /*setparam*/, 0, 15.44, 0, 0, true,Judge::UNUPDATE, 39, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 5, 0, 0, 1.4, 1 /*setparam*/, 0, -14, 0, 0, true,Judge::UPDATE, -13, 16, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 4, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, -16.4, 0, 0, true,Judge::UNUPDATE, -42.4, 20.288, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 10, -0.4, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, -1.5, true,Judge::UNUPDATE, 0, 11.27, -0.4, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 10.5, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 4, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, -10, 0, 0, true,Judge::UPDATE, -70, 20.3, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0.4, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::TURNANGLE, 5, -0.2, 30, 0, 0.8, 1.7, 1 /*setparam*/, 0, 0, 0, -30, false,Judge::UNUPDATE, -85, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 40, 0, false,Judge::UPDATE, 0, 48, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam b[100] = {
                        {0, Section::ARM, Section::ARMANGLE, 0, -60, 1.5, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -58, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 10, 0, 0, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, -5, 0, true,Judge::UPDATE, 0, -0.5, 0, 0, 0, 0, 0},
                        {0, Section::ARM, Section::ARMANGLE, 0, 30, 1, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 9.5, 0, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 22, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 600, 0.6, 0.4, 0.04, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 360, 0, 0, 0, 0, 0, 0}, // 600度目標で回すが、走行に制御を戻さないといけないので10度で終了
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 8, 0, true,Judge::UPDATE, 0, 2, 0, 0, 0, 0, 0}, //昇段
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0.1, 0, true,Judge::UPDATE, 0, 0.1, 0, 0, 0, 0, 0},
                        {0, Section::TAIL, Section::TAILANGLE, 0, 0, 1, 0.0, 0.00, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 6, 0, 0, 0, 0, 0, 0},// 尻尾をなめらかに本体の自重で落とす。早く走行に制御を戻すため、590度で終了
                        {0, Section::ARM, Section::ARMANGLE, 0, -50, 2, 0, 0, 0, 0/*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, -50, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::LENGTH, 4, -0.7, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 0, -30, true,Judge::UPDATE, 0, 10, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 6, 0, 0, 1, 1 /*setparam*/, 0, -40, 0, 0, true,Judge::UPDATE, -23, 16.7, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 7, 0, 9, 0, 0, 1, 1 /*setparam*/, 0, 27, 0, 0, true,Judge::UNUPDATE, 37, 33, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 30, 0, 0, 0.6, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 18, 8.5, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 8, 0, 0, 1, 1 /*setparam*/, 0, -15.8, 0, 0, true,Judge::UNUPDATE, -37, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 8, 0, 5, 0, 0, 1.4, 1 /*setparam*/, 0, -14, 0, 0, true,Judge::UPDATE, -13, 16, 0, 0, 0, 0, 0},
                        {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, 16.36, 0, 0, true,Judge::UNUPDATE, 44, 20.288, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, 0, true,Judge::UPDATE, 0, 20, -0.4, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::BRIGHTNESS, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 15, -2, true,Judge::UNUPDATE, 0, 11.27, -0.4, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 5, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, 30, 0, 0, true,Judge::UPDATE, 10.5, 22.5, 0, 0, 0, 0, 0},
                        // {0, Section::VIRTUAL, Section::TURNANGLE, 4, 0, 5, 0, 0, 1, 1 /*setparam*/, 0, -10, 0, 0, true,Judge::UPDATE, -70, 20.3, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::LENGTH, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 5, 0.4, true,Judge::UPDATE, 0, 17, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::TURNANGLE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 10, true,Judge::UPDATE, -40, 0, 0, 0, 0, 0, 0},
                        {0, Section::TRACER, Section::TURNANGLE, 5, -0.2, 30, 0, 0.14, 1/1.7, 1 /*setparam*/, 0, 0, 0, -30, true,Judge::UNUPDATE, 84, 20, 0, 0, 0, 0, 0},
                        {0, Section::WALKER, Section::LENGTH, 15, -0.4, 30, 0.2, 0.1, 1, 1 /*setparam*/, 0, 0, 40, 0, false,Judge::UPDATE, 0, 45, 0, 0, 0, 0, 0},
                        // {0, Section::WALKER, Section::STOP, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true,Judge::UPDATE, 0, 0, 0, 0, 0, 0, 10},
                        {-1, Section::WNONE, Section::JNONE, 0, 0, 0, 0, 0, 0, 0 /*setparam*/, 0, 0, 0, 0, true, Judge::UNUPDATE, 0, 0, 0, 0, 0, 0, 0}};

        wParam *array[10]={a,b};
        wParam *wp;

};

#endif
