// myHeader2.h

class Circle{
    int radius;
public:
    // ctor(1)
    /*
    Circle(){
        radius = 0;
    }
    */

    // ctor(2) overloading ctor(1)
    /*
    Circle(int r){
        radius = 0;
        setRadius(r);
    }
    */

    // ctor(3)，參數列指定預設值，其功能可取代 ctor(1) 和 ctor(2)，如果有傳入 r，則會使用(2)進行指定；沒有則使用(1)進行初始化
    /*
    Circle(int r = 0){
        // this 在此處可省略，但當 object 裡的變數成員與 Argument 同名時，就可能會發生錯誤，如(4)
        this->radius = 0;
        setRadius(r);
    }
    */


    // ctor(4)
    /*
    Circle(int radius = 0){
        // radius = 0;     // 此處應初始化 Circle::radius，但沒寫 this 會變成在存取 ctor 裡的 local radius
        this->radius = 0;
        setRadius(radius);      // 沒寫 this 變成 setRadius(0)，有寫 this 就會正常給值
    }
    */

    // ctor(5), using initialization list, RECOMMEND
    Circle(int r = 0) : radius(r){}   // initialization list already disambiguate，不能用 this pointer

    void setRadius(int r);
    int getRadius();
};

void Circle::setRadius(int r){
    if(r > 0)
        radius = r;
}
int Circle::getRadius(){
    return radius;
}

class Rectangle{
    int length;
    int width;
public:

    // ctor using initialization list, RECOMMEND
    Rectangle(int length = 0, int width = 0) : length(length), width(width){}
    void setLength(int l);
    void setWidth(int w);
    int getLength();
    int getWidth();
};

void Rectangle::setLength(int l){
    if(l > 0)
        length = l;
}
void Rectangle::setWidth(int w){
    if(w > 0)
        width = w;
}

int Rectangle::getLength(){
    return length;
}
int Rectangle::getWidth(){
    return width;
}

