// myHeader2.h

class Circle{
    int radius;
public:
    /*
    // ctor......(1)
    Circle(){
        radius = 0;
    }
    // ctor overloading......(2)
    Circle(int r){
        radius = 0;
        setRadius(r);
    }
    */

    // ctor......(3)，參數列指定預設值，其功能可取代(1)和(2)的 ctor，如果 user 有傳入 r，則會使用(2)進行指定；沒有則使用(1)進行初始化
    Circle(int r = 0){
        // this 在此處可省略，但當 Argument 與 object 裡的變數成員同名時，就可能會發生錯誤，如(4)
        this->radius = 0;
        setRadius(r);
    }
    /*
    // ctor......(4)
    Circle(int radius = 0){
        // radius = 0;     // 此處應為 object 的變數成員，但沒寫 this 就會變成在存取 ctor 的 Argument
        this->radius = 0;
        setRadius(radius);      // 沒寫 this 變成 setRadius(0)，有寫 this 就會正常給值;
    }
    */
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
    /*
    // ctor......(1)
    Rectangle(){
        length = 0;
        width = 0;
    }
    // ctor overloading......(2)
    Rectangle(int a, int b){
        length = 0;
        width = 0;
        setLength(a);
        setWidth(b);
    }
    */
    // 參數列指定預設值，其功能可取代上面兩個 ctor，如果 user 有傳入 r，則會使用(2)進行指定；沒有則使用(1)進行初始化
    Rectangle(int a = 0, int b = 0){
        length = 0;
        width = 0;
        setLength(a);
        setWidth(b);
    }
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
