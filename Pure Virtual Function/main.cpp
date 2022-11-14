#include <iostream>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"
using namespace std;

int main()
{
    // 純虛函式在不需要建立物件時使用，一旦有了純虛函式後，建立物件會 error
    // CShape *cs = new CShape();   // can not create CShape object cuz it is abstract class
    CCircle cc(10);
    cc.showInfo();

    cout << endl;

    CRectangle cr;
    cr.setValues(5, 10);
    cr.showInfo();
    return 0;
}
