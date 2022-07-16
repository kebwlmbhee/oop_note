#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CShape.h"

class CCircle : public CShape
{
    public:
        CCircle(int radius = 0);
        virtual ~CCircle();

        int getRadius() {
             return radius;
        }
        void setRadius(int radius){
            if(radius > 0){
                this->radius = radius;
                setArea(radius * radius * 3.14);
                setGirth(radius * 2 * 3.14);
            }
        }
        virtual void showInfo();
    protected:

    private:
        int radius;
};

#endif // CCIRCLE_H
