#include <iostream>
#include "myHeader2.h"
using namespace std;

int main(){
    Circle c1;  // ㊣⊿Τ把计 ctor
    Circle c2(10);  // ㊣Τ把计 ctor
    cout << "c1.getRadius: " << c1.getRadius() << endl;
    cout << "c2.getRadius: " << c2.getRadius() << endl;
    cout << endl;

    Rectangle r1;
    Rectangle r2(10, 10);
    Rectangle r3(10);

    cout << "r1.getLength(): " << r1.getLength() << endl;
    cout << "r1.getWidth(): " << r1.getWidth() << endl;
    cout << "r2.getLength(): " << r2.getLength() << endl;
    cout << "r2.getWidth(): " << r2.getWidth() << endl;
    cout << "r3.getLength(): " << r3.getLength() << endl;
    cout << "r3.getWidth(): " << r3.getWidth() << endl;
    return 0;
}
