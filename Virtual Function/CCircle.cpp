#include "CCircle.h"
#include <iostream>
using namespace std;

CCircle::CCircle(int radius)
{
    this->radius = 0;
    setRadius(radius);
}

CCircle::~CCircle()
{
    //dtor
}

// overriding
void CCircle::showInfo(){
    cout << "CCircle's area : " << getArea() << endl;
    cout << "CCircle's girth : " << getGirth() << endl;
}
