#ifndef __MYCOLORSENSOR_H__
#define __MYCOLORSENSOR_H__


#include "ColorSensor.h"
#include "Brightness.h"
#include "HsvHue.h"
#include "HsvSatu.h"

using namespace ev3api;

typedef struct hsv_t {
    float h;
    float s;
    float v;
} HSV_T;

typedef struct rgb_f_t {
    float r;
    float g;
    float b;
} RGB_F_T;

class MyColorSensor 
{
    public:
        MyColorSensor(ePortS port,
                    Brightness *br,
                    HsvHue *h,
                    HsvSatu *s);
        void update();
        void calcHSV();
        float normBrightness(float br,float min,float max);
        float normColor(float br,float min,float max);
        void getHSV(rgb_f_t rgb, hsv_t& hsv);

        static const int BRIGHT;
        static const int COLOR;

        rgb_raw_t getRgb();

    private:
        ePortS mPort;
        Brightness *mBrightness;
        ColorSensor *mColor;

        HsvHue *mHue;
        HsvSatu *mSatu;

        bool mColorMode;
        bool mNorm;

        int mMax_brightness;
        int mMin_brightness;

        int mMax_R;
        int mMin_R;
        int mMax_G;
        int mMin_G;
        int mMax_B;
        int mMin_B;

        float mBright;
        float mNorm_bright;

        rgb_f_t mRgb;
        hsv_t mHsv;

        rgb_raw_t  raw;

};

#endif

