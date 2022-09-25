#include <iostream>
#include "myHeader2.h"
using namespace std;

int main(){
    Circle c1;  // 呼叫沒有參數列的 ctor
    Circle c2(10);  // 呼叫有參數列的 ctor
    cout << c1.getRadius() << endl;     // Output: 0
    cout << c2.getRadius() << endl;     // Output: 10
    cout << endl;

    Rectangle r1;
    Rectangle r2(10, 10);
    Rectangle r3(10);

    cout << r1.getLength() << endl;     // Output: 0
    cout << r1.getWidth() << endl;      // Output: 0
    cout << r2.getLength() << endl;      // Output: 10
    cout << r2.getWidth() << endl;      // Output: 10
    cout << r3.getLength() << endl;      // Output: 10
    cout << r3.getWidth() << endl;      // Output: 0
    return 0;
}
