// main.cpp

#include <iostream>
#include  "myHeader.h"
using namespace std;

int main(){
    Circle c1;
    c1.setRadius(10);
    cout << c1.getArea() << endl;  // 因為已繼承 Shape 的 private 和 public 成員
    cout << c1.getGirth() << endl;  // 因為已繼承 Shape 的 private 和 public 成員

    Rectangle r1;
    cout << r1.getArea() << endl;  // 因為已繼承 Shape 的 private 和 public 成員
    cout << r1.getGirth() << endl;  // 因為已繼承 Shape 的 private 和 public 成員
    return 0;
}
