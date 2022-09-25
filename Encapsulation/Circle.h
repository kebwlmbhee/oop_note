// Circle.h

class Circle{
private:
    int radius;
    int height;
public:
    // getter and setter
    double getArea();
    double getVolume();
    void setRadius(int r);
    void setHeight(int h);
};

double Circle::getArea(){
    return radius * radius * 3.14;
}
double Circle::getVolume(){
    return getArea() * height;
}
void Circle::setRadius(int r){
    if(r > 0)
        radius = r;
}
void Circle::setHeight(int h){
    if(h > 0)
        height = h;
}

