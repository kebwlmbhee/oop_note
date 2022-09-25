#include <iostream>
#include <exception>
#include <typeinfo>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"
using namespace std;

void showArea(CShape *csPtr){
    cout << "The area is: " << csPtr->getArea() << endl;
}

void doubleShape(CShape *csPtr){
    // CCircle *ccPtr = csPtr;  // error: invalid conversion from 'CShape*' to 'CCircle*'
    CCircle *ccPtr = dynamic_cast<CCircle *>(csPtr);
    if(ccPtr != NULL)
        ccPtr->setRadius(ccPtr->getRadius() * 2);

    CRectangle *crPtr = dynamic_cast<CRectangle *>(csPtr);
    if(crPtr != NULL)
        crPtr->setValues(crPtr->getLength() * 2, crPtr->getWidth() * 2);
}

void doubleShape(CShape &csRef){
    // CCircle &ccRef = csRef;  // error: invalid initialization of reference of type 'CCircle&' from expression of type 'CShape'
    // handle exception
    try{
        CCircle &ccRef = dynamic_cast<CCircle &>(csRef);
        ccRef.setRadius(ccRef.getRadius() * 2);
    }
    catch(bad_cast &b){
        CRectangle &crRef = dynamic_cast<CRectangle &>(csRef);
        crRef.setValues(crRef.getLength() * 2, crRef.getWidth() * 2);
    }
}

int main()
{
    cout << " ------------ Assign(copy by value) ------------ " << endl;
    CShape cs;
    cout << cs.getArea() << endl;     // Output: 0

    CCircle cc(10);
    cout << cc.getArea() << endl;     // Output: 314

    CRectangle cr;
    cr.setValues(10, 8);
    cout << cr.getArea() << endl;     // Output: 80

    cs = cc;    // 將子類別物件 copy 一份給父類別物件
    cout << "After cs = cc => cs Area: " << cs.getArea() << endl;     // Output: 314

    cc.setRadius(100);
    cout << "After cc.setRadius = 100 => cc Area: " << cc.getArea() << endl;     // Output: 31400

    // 是 cc 複製一份相同的值(copy by value)給 cs
    cout << "After cs = cc, we have "
        << (cs.getArea() == cc.getArea() ? "one object"
                                        : "two object, one of that is copy-by-value from cc") << endl;       // Output: two object

    cout << endl << "------------ Assign ------------ " << endl;

    cout << " --- pointer --- " << endl;
    CCircle cc2;
    cc2.setRadius(100);

    // 子類別宣告為父類別，代父出征
    CShape *csPtr = &cc2;
    cout << "cs Area: " << csPtr->getArea() << endl << endl;     // Output: 31400

    cout << endl << " --- reference --- " << endl;
    // 子類別宣告為父類別，代父出征
    CShape &csRef = cc2;
    cout << "cs Area: " << csRef.getArea() << endl;     // Output: 31400


    cout << endl << " --- Group --- " << endl;
    // 每個 class 都有 getArea()，哪個物件型態進行呼叫就使用該 class 的 function

    CShape *array[5];   // array of pointer, 指標陣列
    array[0] = &cc;
    array[1] = &cr;
    array[2] = new CCircle();
    array[3] = new CRectangle();
    cout << "array[0] Area: " << array[0]->getArea() << endl;     // Output: 31400
    cout << "array[1] Area: " << array[1]->getArea() << endl;     // Output: 80
    cout << "array[2] Area: " << array[2]->getArea() << endl;     // Output: 0
    cout << "array[3] Area: " << array[3]->getArea() << endl;     // Output: 0


    cout << endl << " --- Parameter --- " << endl;
    CCircle cc3(123);
    showArea(&cc3);

    CRectangle cr3;
    cr3.setValues(12, 3);
    showArea(&cr3);
    /*
    Output:
    The area is: 47505.1
    The area is: 36
    */

    cout << endl << " ------------ Overriding(virtual) ------------ " << endl;
    CCircle cc4;
    cc4.setRadius(100);
    csPtr = &cc4;
    csRef = cc4;
    csPtr->showInfo();
    /*
    Output:
    CCircle's area : 31400
    CCircle's girth : 628
    */
    csRef.showInfo();
    /*
    Output:
    CCircle's area : 31400
    CCircle's girth : 628
    */

    CRectangle cr4;
    cr4.setValues(123, 456);
    csPtr = &cr4;
    csPtr->showInfo();
    /*
    Output:
    CRectangle's area : 56088
    CRectangle's girth : 1158
    */

    cout << endl << " ------------ Dynamic Casting ------------ " << endl;
    CCircle cc5;
    cc5.setRadius(10);

    cout << endl << " --- Call by Pointer(CCircle) --- " << endl;
    doubleShape(&cc5);
    cout << "After radius * 2, cc5 radius: " << cc5.getRadius() << endl;        // Output: 20
    cout << "cc5 Area: " << cc5.getArea() << endl;        // Output: 1256

    cout << endl << " --- Call by Reference(CCircle) --- " << endl;
    doubleShape(cc5);
    cout << "After radius * 2, cc5 radius: " << cc5.getRadius() << endl;        // Output: 40
    cout << "cc5 Area: " << cc5.getArea() << endl;        // Output: 5024

    CRectangle cr5;
    cr5.setValues(10, 5);
    cout << endl << " --- Call by Pointer --- " << endl;
    doubleShape(&cr5);
    cout << "cr5 Area: " << cr5.getArea() << endl;        // Output: 200

    cout << endl << " --- Call by Reference --- " << endl;
    doubleShape(cr5);
    cout << "cr5 Area: " << cr5.getArea() << endl;        // Output: 800

    return 0;
}
