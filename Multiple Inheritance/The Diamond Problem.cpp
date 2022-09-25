#include <iostream>
using namespace std;

class FooA {
public:
    FooA(int x) {
        cout << "FooA(int) Ctor" << endl;
    }
    FooA(){
        cout << "FooA Ctor" << endl;
    }
};

class FooB : /*virtual */public FooA {
public:
    FooB(int x) : FooA(x) {
        cout << "FooB(int) Ctor" << endl;
    }
};

class FooC : /*virtual */public FooA {
public:
    FooC(int x) : FooA(x) {
        cout << "FooC(int) Ctor" << endl;
    }
};
class FooD : /*virtual */public FooB, /*virtual */public FooC {
public:
    FooD(int x) : FooB(x), FooC(x) {
        cout << "FooD(int) Ctor" << endl;
    }
};

int main() {
    FooD D(10);

    return 0;
}

/*
未加 virtual
Output:
FooA(int) Ctor
FooB(int) Ctor
FooA(int) Ctor
FooC(int) Ctor
FooD(int) Ctor
*/

/*
加了 virtual，這裡需注意使用了 virtual 後，即使父類使用參數化 ctor，祖父類 ctor 仍是預設 ctor
Output:
FooA Ctor
FooB(int) Ctor
FooC(int) Ctor
FooD(int) Ctor
*/

/*
加了 virtual，29 行改為     FooD(int x) : FooB(x), FooC(x), FooA(x) {
Output:
FooA(int) Ctor
FooB(int) Ctor
FooC(int) Ctor
FooD(int) Ctor
*/
