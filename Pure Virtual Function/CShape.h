#ifndef CSHAPE_H
#define CSHAPE_H


class CShape
{
    public:
        CShape();
        virtual ~CShape();  // virtual dtor
        double getGirth() { return girth; }
        double getArea() { return area; }
        virtual void showInfo() = 0;    // declare pure virtual function
    protected:
        void setGirth(double val) { girth = val; }
        void setArea(double val) { area = val; }
    private:
        double girth;
        double area;
};

#endif // CSHAPE_H
