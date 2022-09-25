#include <iostream>
#include "CShape.h"
#include "CCircle.h"
#include "CRectangle.h"
using namespace std;

int main()
{
    // 純虛函式在不需要建立物件時使用，一旦有了純虛函式後，建立物件會 error
    // CShape *cs = new CShape();   // not necessary to create CShape object
    CCircle cc(10);
    cc.showInfo();
    /*
    Output:
    CCircle's area : 314
    CCircle's girth : 62.8
    */

    cout << endl;

    CRectangle cr;
    cr.setValues(5, 10);
    cr.showInfo();
    /*
    Output:
    CRectangle's area : 50
    CRectangle's girth : 30
    */

    return 0;
}
