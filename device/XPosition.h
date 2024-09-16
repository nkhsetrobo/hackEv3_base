#ifndef _XPOSITION_H_
#define _XPOSITION_H_

#include "Measure.h"

class XPosition : public Measure{
    public:
        XPosition();
        float getvalue();
        void update(float x);

    private:
        float mXPosition;

};

#endif
