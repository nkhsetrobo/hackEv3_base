#include "ColorStatus_RJudge.h"
ColorStatus_RJudge::ColorStatus_RJudge()
{
    mOtherCol=false;
}

float ColorStatus_RJudge::status()
{

    double r,g,b,y;
    double base_sat=0.1;
    r = RED_H;
    g = GREEN_H;
    b = BLUE_H;
    y = YELLOW_H;
    base_sat=0.005;
/*
#if defined(PRIMARY)
    r = SLALOM_RED_H;
    g = SLALOM_GREEN_H;
    b = SLALOM_BLUE_H;
    y = SLALOM_YELLOW_H;
    base_sat=0.1;

#else
    r = RED_H;
    g = GREEN_H;
    b = BLUE_H;
    y = YELLOW_H;
    base_sat=0.01;
#endif
*/
    double hue = mHsvHue->getValue();
    double sat = mHsvSatu->getValue();
    
        if(subhue(hue,g)<35 && sat>base_sat*2) {
            color[1]++;
            mOtherCol=true;
        } 
        if(subhue(hue,g)<35 && sat>base_sat) {
            color[1]++;
            mOtherCol=true;
        } 
        if(subhue(hue,r)<30 && sat>base_sat*2) {
            color[0]++;
        } 
        if(subhue(hue,r)<30 && sat>base_sat) {
            color[0]++;
        } 
         if(subhue(hue,b)<35 && sat>base_sat) {
            color[2]++;
            mOtherCol=true;
        } 
        if(subhue(hue,b)<35 && sat>base_sat*2) {
            color[2]++;
            mOtherCol=true;
        } 
         if(subhue(hue,y)<35 && sat>base_sat*2) {
           // color[3]++;
        }         
         if(subhue(hue,y)<35 && sat>base_sat) {
           // color[3]++;
        }         
    color_id=-1;
    int max_col=0;
    int startcol=0;
    if(mOtherCol) {
        printf("赤以外で\n");
        startcol=1;
    }
    for(int i=startcol;i<4;i++) {
        if(max_col<color[i]) {
            color_id=i;
            max_col=color[i];
        }
    }
    
    printf("hue %f sat %f color_id %d (r %d g %d b %d y %d) \n",hue,sat,color_id, color[0],color[1],color[2],color[3]);
    return color_id;
}
