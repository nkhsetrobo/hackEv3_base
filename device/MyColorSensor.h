#ifndef __MYCOLORSENSOR_H__
#define __MYCOLORSENSOR_H__

#include "spike.h"
//#include "ColorSensor.h"
#include "Brightness.h"
#include "HsvHue.h"
#include "HsvSatu.h"

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
        MyColorSensor(pbio_port_id_t  port,
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

        pup_color_rgb_t getRgb();
        void calibMax();
        void calibBright();

    private:
        pbio_port_id_t  mPort;
        Brightness *mBrightness;
        //ColorSensor *mColor;
        pup_device_t *mColor;

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

        pup_color_rgb_t  raw;


};

#endif

