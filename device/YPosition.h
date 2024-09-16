#ifndef _YPOSITION_H_
#define _YPOSITION_H_

#include "Measure.h"

class YPosition : public Measure{
    public:
        YPosition();
        float getvalue();
        void update(float y);

    private:
        float mYPosition;

};

#endif
