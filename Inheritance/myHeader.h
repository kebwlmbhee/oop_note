// myHeader.h

class Shape{
    double area;
    double girth;
protected:
    void setArea(double a);
    void setGirth(double g);
public:
    // ctor
    Shape(){
        area = 0;
        girth = 0;
    }
    double getArea();
    double getGirth();
};

void Shape::setArea(double a){
    if(a > 0)
        area = a;
}
void Shape::setGirth(double g){
    if(g > 0)
        girth = g;
}

double Shape::getArea(){
    return area;
}
double Shape::getGirth(){
    return girth;
}

// inheritance
class Circle : public Shape{
    int radius;
    double area;
public:
    // ctor
    Circle(){
        radius = 0;
    }
    void setRadius(int r);
};
void Circle::setRadius(int r){
    if(r > 0){
        radius = r;
        area = radius * radius * 3.14;
        setArea(radius * radius * 3.14);  // 因為 base class 是 protected，若為 private 則會 error
        setGirth(radius * 2 * 3.14);  // 因為 base class 是 protected，若為 private 則會 error
    }
}

