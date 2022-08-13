#include "MyColorSensor.h"

#include "util.h"

 const int MyColorSensor::BRIGHT = false;
 const int MyColorSensor::COLOR = true;

MyColorSensor::MyColorSensor(ePortS port,
                            Brightness *br,
                            HsvHue *h,
                            HsvSatu *s):
    mPort(port),
    mBrightness(br),
    mColorMode(COLOR),
    mHue(h),
    mSatu(s),
    mNorm(true)
{
    mColor = new ColorSensor(mPort);

    mMax_brightness = 65;  //36
    mMin_brightness = 3;
#if defined(MAKE_SIM)
    mMax_R  = 129;
    mMin_R  = 4;
    mMax_G  = 120;
    mMin_G  = 5;
    mMax_B  = 165;
    mMin_B  = 8;
#else
    mMax_R  = 255;
    mMin_R  = 12;
    mMax_G  = 255;
    mMin_G  = 12;
    mMax_B  = 255;
    mMin_B  = 12;  
#endif 
}

void MyColorSensor::update()
{
   // ColorSensor col(PORT_2);

    if(mColorMode==BRIGHT) {
        mBright = mColor->getBrightness();
        mNorm_bright = normBrightness(mBright, mMin_brightness, mMax_brightness);
    } else {
        mColor->getRawColor(raw);
   //printf("RGB %d,%d,%d\n",raw.r,raw.g,raw.b);
        static int cnt=0;
    //     if (cnt%1000)
    //    // syslog(LOG_NOTICE,"%d,%d,%d",raw.r,raw.g,raw.b);
    //         printf("%d,%d,%d\n",raw.r,raw.g,raw.b);
    //         cnt=0;
        mRgb.r = normColor(raw.r,mMin_R,mMax_R);
        mRgb.g = normColor(raw.g,mMin_G,mMax_G);
        mRgb.b = normColor(raw.b,mMin_B,mMax_B);
        getHSV(mRgb,mHsv);
     //printf("rRGB  %f,%f,%f\n",mRgb.r,mRgb.g,mRgb.b);
     //printf("HSV %f,%f,%f\n",mHsv.h,mHsv.s,mHsv.v);
        mHue->update(mHsv.h);
        mSatu->update(mHsv.s);

        mBright =  0.298912 * mRgb.r  + 0.586611 * mRgb.g + 0.114478 * mRgb.b ;
        //syslog(LOG_NOTICE,"(x100) %d,%d,%d  %d",(int)(mRgb.r*100),(int)(mRgb.g*100),(int)(mRgb.b*100) , (int)(mBright));
        mNorm_bright = normBrightness(mBright, 0, 100);
        //if (cnt%100==0) {
            // printf("cnt %d : %d,%d,%d\n",raw.r,raw.g,raw.b);
            // printf(" %f,%f,%f  %f %f\n",(mRgb.r),(mRgb.g),(mRgb.b) , (mBright),mNorm_bright);
          //  cnt=0;
        //}
        //cnt++;

    }

    if(mNorm)
        mBrightness->update(mNorm_bright);
    else
        mBrightness->update(mBright);

    
}

float MyColorSensor::normBrightness(float br,float min, float max)
{
    float grayLevel = (max+min)/2.0;

    float rate = (br-grayLevel)/(max-grayLevel);
    if(rate>1.0) rate=1.0;
    if(rate<-1.0) rate=-1.0;
    
    return rate;
}

float MyColorSensor::normColor(float br,float min, float max)
{
    float rate = (br-min)/(max-min);
    if(rate>1.0) rate=1.0;
    if(rate<0) rate=0;

    return rate*100;
}

void MyColorSensor::getHSV(rgb_f_t rgb, hsv_t& hsv)
{
    float r = rgb.r;
    float g = rgb.g;
    float b = rgb.b;
               
    float h=0, s=0, v=0;
    
    if (r >= g && g >= b) { 
        
        if(r!=0)
            s = (r - b) / r;
        else 
            s=0;
        v = r;
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r- b);
    }
    if (r >= b && b >= g)
    {
        v = r;
        if(r!=0)
          s = (r - g) / r;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r - g) + 360.0;
    }
    if (g >= r && r >= b)
    {
        v = g;
        if(g!=0)
            s = (g - b) / g;
        else 
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - b) + 120.0;
    }
    if (g >= b && b >= r)
    {
        v = g;
        if(g!=0)
            s = (g - r) / g;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - r) + 120.0;
    }
    if (b >= r && r >= g)
    {
        v = b;
        if(b!=0)
            s = (b - g) / b;
        else
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - g) + 240.0;
    }
    if (b >= g && g >= r)
    {
        v = b;
        if(b!=0) 
            s = (b - r) / b;
        else
            s=0;
        
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - r) + 240.0;
    }

    hsv.h = h;
    hsv.s = s;
    hsv.v = v;

}

// debug用
rgb_raw_t MyColorSensor::getRgb()
{
    return raw;
}

void MyColorSensor::calibMax()
{
#if defined(MAKE_RASPIKE)
    mColor->getRawColor(raw);

    mMax_R  = raw.r;
    mMax_G  = raw.g;
    mMax_B  = raw.b;
#endif
    printf("calib %d,%d,%d\n",raw.r,raw.g,raw.b);

}