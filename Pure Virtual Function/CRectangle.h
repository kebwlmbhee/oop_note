#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CShape.h"


class CRectangle : public CShape
{
    public:
        CRectangle();
        virtual ~CRectangle();

        void setValues(int length, int width) {
            this->length = length;
            this->width = width;
            setArea(length * width);
            setGirth((length + width) * 2);
        }
        int getLength() {
             return length;
        }
        int getWidth() {
            return width;
        }
        virtual void showInfo();
    protected:

    private:
        int length;
        int width;
};

#endif // CRECTANGLE_H
