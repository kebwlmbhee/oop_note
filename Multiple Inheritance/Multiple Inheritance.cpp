#include <iostream>
using namespace std;

class FooA {
public:
    FooA() {
        cout << "FooA Ctor" << endl;
    }

    ~FooA() {
        cout << "FooA Dtor" << endl;
    }
};

class FooB {
public:
    FooB() {
        cout << "FooB Ctor" << endl;
    }

    ~FooB() {
        cout << "FooB Dtor" << endl;
    }
};

class FooC : public FooA, public FooB {
public:
    FooC() {    // FooA 和 FooB 的 ctor 若有初始化參數，必須寫成 FooC() : FooA(FooA parameter) : FooB(FooB parameter)
        cout << "FooC Ctor" << endl;
    }

    ~FooC() {
        cout << "FooC Dtor" << endl;
    }
};

int main() {
    FooC c;

    cout << endl;

    return 0;
}

/*
Output:
FooA Ctor
FooB Ctor
FooC Ctor

FooC Dtor
FooB Dtor
FooA Dtor
*/
