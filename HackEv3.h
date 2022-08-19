#ifndef __HACKEV3_H__
#define __HACKEV3_H__

#if defined(MAKE_SIM)
const float D_RIGHT=9.00;
const float D_LEFT=9.0;
const float TREAD=13.8;
#elif defined(MAKE_RASPIKE)
const float D_RIGHT=10.00;
const float D_LEFT=10.0;
const float TREAD=12.83;
#else
const float D_RIGHT=10.00;
const float D_LEFT=10.0;
const float TREAD=13.8;
#endif
//14.3

#define GREEN_H 118
#define RED_H 0
#define YELLOW_H 62
#define BLUE_H 225

#define PRIMARY

#if defined(MAKE_RASPIKE)
#define MAKE_RIGHT
#endif

#endif
