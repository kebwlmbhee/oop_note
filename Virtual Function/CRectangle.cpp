#include "CRectangle.h"
#include <iostream>
using namespace std;

CRectangle::CRectangle()
{
    length = 0;
    width = 0;
}

CRectangle::~CRectangle()
{
    //dtor
}

// overriding
void CRectangle::showInfo(){
    cout << "CRectangle's area : " << getArea() << endl;
    cout << "CRectangle's girth : " << getGirth() << endl;
}
