// Circle.cpp

#include <iostream>
#include "Circle.h"
using namespace std;

int main(){
    Circle c1;
    // c1.radius = 10;     // error
    // c1.height = 5       // error
    c1.setRadius(10);
    c1.setHeight(5);
    cout << c1.getArea() << endl;       // Output: 314
    cout << c1.getVolume() << endl;     // Output: 1570
    return 0;
}

