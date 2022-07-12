#include <iostream>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"
using namespace std;

void showArea(CShape *csPtr){
    cout << "The area is: " << csPtr->getArea() << endl;
}

int main()
{
    cout << " ------------ Assign ------------ " << endl;
    CShape cs;
    cout << cs.getArea() << endl;

    CCircle cc(10);
    cout << cc.getArea() << endl;

    CRectangle cr;
    cr.setValues(10, 8);
    cout << cr.getArea() << endl;

    cs = cc;    // 將子類別物件 copy 一份給父類別物件
    cout << "After cs = cc => cs.getArea() = " << cs.getArea() << endl;

    cc.setRadius(100);
    cout << "After cc.setRadius = 100 => cc.getArea = " << cc.getArea() << endl;

    // 是 cc 複製一份相同的值(copy by value)給 cs
    cout << "After cs = cc, we have " << (cs.getArea() == cc.getArea() ? "one object" : "two object, one of that is copy-by-value from cc") << endl << endl;


    cout << " ------------ Polymorphism pointer ------------ " << endl;
    CCircle cc2;
    cc2.setRadius(100);

    // 子類別宣告為父類別，代父出征
    CShape *csPtr = &cc2;
    cout << "csPtr->getArea() = " << csPtr->getArea() << endl << endl;

    cout << " ------------ Polymorphism reference ------------ " << endl;
    // 子類別宣告為父類別，代父出征
    CShape &csRef = cc2;
    cout << "csRef.getArea() = " << csRef.getArea() << endl << endl;


    cout << " ------------ Polymorphism Group ------------ " << endl;
    // 大家都有 getArea()，哪個物件型態進行呼叫就使用該 class 的 function

    CShape *array[5];   // array of pointer, 指標陣列
    array[0] = &cc;
    array[1] = &cr;
    array[2] = new CCircle();
    array[3] = new CRectangle();
    cout << "array[0]->getArea() = " << array[0]->getArea() << endl;
    cout << "array[1]->getArea() = " << array[1]->getArea() << endl;
    cout << "array[2]->getArea() = " << array[2]->getArea() << endl;
    cout << "array[3]->getArea() = " << array[3]->getArea() << endl;


    cout << " ------------ Polymorphism Parameter ------------ " << endl;
    CCircle cc3(123);
    showArea(&cc3);

    CRectangle cr3;
    cr3.setValues(12, 3);
    showArea(&cr3);

    return 0;
}
