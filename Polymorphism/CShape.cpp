#include "CShape.h"
#include <iostream>
using namespace std;

CShape::CShape()
{
    girth = 0;
    area = 0;
}

CShape::~CShape()
{
    //dtor
}

// 定義時不能加 virtual
void CShape::showInfo(){
    cout << "CShape's area : " << getArea() << endl;
    cout << "CShapes's girth : " << getGirth() << endl;
}
