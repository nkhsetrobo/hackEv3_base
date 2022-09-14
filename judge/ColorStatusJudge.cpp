#include "ColorStatusJudge.h"

#include "math.h"
ColorStatusJudge::ColorStatusJudge()
{
    color[0]=0; //red
    color[1]=0; //green
    color[2]=0; //blue
    color[3]=0; //yellow
}

float ColorStatusJudge::status()
{

    double r,g,b,y;
#if defined(PRIMARY)
    r = SLALOM_RED_H;
    g = SLALOM_GREEN_H;
    b = SLALOM_BLUE_H;
    y = SLALOM_YELLOW_H;
#else
    r = RED_H;
    g = GREEN_H;
    b = BLUE_H;
    y = YELLOW_H;
#endif
    float hue = mHsvHue->getValue();
    float sat = mHsvSatu->getValue();

        if(subhue(hue,g)<30 && sat>0.1) {
            color[1]++;
        } 
        if(subhue(hue,r)<30 && sat>0.3) {
            color[0]++;
        } 
         if(subhue(hue,b)<30 && sat>0.1) {
            color[2]++;
        } 
         if(subhue(hue,y)<30 && sat>0.1) {
            color[3]++;
        }         

    color_id=-1;
    int max_col=0;
    for(int i=0;i<4;i++) {
        if(max_col<color[i]) {
            color_id=i;
            max_col=color[i];
        }
    }
    
    printf("hue %f sat %f color_id %d (r %d g %d b %d y %d) \n",hue,sat,color_id, color[0],color[1],color[2],color[3]);
    return color_id;
}

float ColorStatusJudge::subhue(float h1, float h2)
{
    float diff =  h1 - h2;
    if(fabs(diff)>180) {
        diff = 360- fabs(diff);
    }   
    return fabs(diff);
}

