// main.cpp

#include <iostream>
#include  "myHeader.h"
using namespace std;

int main(){
    Circle c1;  // 因為已繼承 Shape 的 private 和 public 成員
    c1.setRadius(10);
    cout << c1.getArea() << endl;     // Output: 314
    cout << c1.getGirth() << endl;     // Output: 62.8
    return 0;
}
