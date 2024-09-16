#include "BrightnessJudge.h"

BrightnessJudge::BrightnessJudge(){
    brightness = 0.0;
    flag = 0;
}
void BrightnessJudge::setBrightness(float x, int i){
    //変数の初期化
    brightness = x;
    flag = i;
}

bool BrightnessJudge::run(){
    //色の判定
    if(flag == 1){
        if(mBrightness->getValue() >= brightness){
            return true;
        }else{
            return false;
        }
    }else{
        if(mBrightness->getValue() <= brightness){
            return true;
        }else{
            return false;
        }
    }
}