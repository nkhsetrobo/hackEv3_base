#ifndef __HACKEV3_H__
#define __HACKEV3_H__

#if defined(MAKE_SIM)
const float D_RIGHT=9.00;
const float D_LEFT=9.0;
const float TREAD=13.8;
#else
const float D_RIGHT=10.00;
const float D_LEFT=10.0;
//const float TREAD=12.83;
const float TREAD=12.7;
#endif
//14.3

#define GREEN_H 148
#define GREEN_S 0.08

#define RED_H 353
#define RED_S 0.3

#define YELLOW_H 42
#define YELLOW_S 0.25

#define BLUE_H 212
#define BLUE_S 0.15

#define SLALOM_GREEN_H 159
#define SLALOM_RED_H 0
#define SLALOM_YELLOW_H 51
#define SLALOM_BLUE_H 222

#define PRIMARY
#define LPAT 0  //pat.txtに移行につき未使用
#define RPAT 0

//#define DEBUG_NOMOVE
// #define SKIP_SPEED
// #define SKIP_BONUS

#if defined(MAKE_RASPIKE)
//#define MAKE_LEFT
#endif

#define  mode0 (0) // 通常モード
#define  mode1 (1) // 継続モード
#define  mode2 (2) // 現在の方向へ進むモード
#define  mode3 (3) // 座標へ進むモード

#define BLEN (28)
#define CLEN (7)
#define CLEN_CENT (3)

#define CSPD (40)

#define BLK_TGT (0.15)

#endif
