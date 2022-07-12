# 物件(object)
#### 一群**記憶體的集合**
#### 擁有
1. 資料成員(Attribute)
2. 成員函式(Method)
---

# 物件導向(object-oriented)
#### 除了儲存資料外，還能運算資料
#### C 的 struct 只能儲存資料
#### C++ 的 class 的型別使資料與運算的函式屬於同一個物件下的成員。

#### 因為可能歸屬於不同的變數下
1. 相同名稱的**資料成員**，但它的值不見得一樣。
2. 相同名稱的**成員函式**，但它運算的結果不一定一樣。
---

# 類別(class)
#### 一種型別，像 C++ 裡的 int 一樣
#### **依照物件的需求進行開發設計**

#### 類別裡包含
1. 物件成員=> 物件資料成員，物件成員函式
2. 類別成員=> 類別資料成員，類別成員函式
3. 建構函式(建構子)
4. 其他

### class 和 object 的差別: class 只是方法，object 是照著 class 這個方法所實際生成(實例化)的東西
---

# 物件變數(object variable)
- 宣告
> 變數宣告時，環境會依照類別中的宣告來建立物件，並將物件的記憶體位址指派給變數。
>>     ClassName objectName;

- 成員存取
>     objectName.dataMember    // 資料成員
>
>     objectName.memberFunction()    // 成員函式

- 指派
> 變數和物件是綁定的，即此變數不能再被指派另一個物件的**記憶體位址** ，指派時是將 '=' 右邊的物件的資料成員的**值**，複製給 '=' 左邊的物件的資料成員。
>>     Circle c1, c2
>>     ...
>>     c1 = c2    // 此處僅將 c2 裡的值(value)複製給 c1. 兩變數的位址(address)並不會改變

- 物件變數參數
> 物件變數當參數傳遞時，會先複製出一個新物件(objectName_new)，此新物件與原物件(objectName_origin)僅有值相同，而地址並不相同；新物件的改動不影響原物件，即 implementation 內若 function 更動 objectName_new 的值時不會影響到 objectName_origin 的值
>>     void function(ClassName objectName_new){}    // interface:
>>
>>     function(objectName_origin);    // function call
- 物件變數返回值(返回物件 ClassName)
>     ClassName function(){}      // interface:
> 
>     ClassName objectName = function();    // function call

---
# 物件指標(object pointer)
- 宣告
> 不直接指派
>>     ClassName *pointerName;
>
> 直接指派(新增物件，使指標指向該物件)
>>     ClassName *pointerName = new ClassName;

- 建立物件
> 普通形式
>>      new ClassName
>
> ctor(constructor)
>>      new ClassName()

- 指派
> 與值會被綁定在物件身上不同，指標可以隨意指派至任意相同型別的物件位址
> 
>      pointerName = memoryAddress;
> 1.
>>     pointerName = new ClassName;
> 2.
>>     pointerName = &objectName;
> 3.
>>     pointerName = otherPointerName;

#### 物件指標需避免 memory leak，要先進行釋放

- 成員存取(用**指標->成員**的方式，存取物件成員)
>     pointerName->dataMeber    // 資料成員
> 
>     pointerName->memberFunction()    // 成員函式

- 物件指標參數
>     void function(ClassName *pointer){}    // interface:
>
>     function(memoryAddress)    // function call

- 物件指標返回值(返回物件指標 ClassName* )
>     ClassName *function(){}    // interface:
> 
>     ClassName *pointer = function();    // function call

## 物件變數與物件指標的差別即 call by value 和 call by pointer 的差別

---
# 物件變數參考(Object Reference Variable)
- 宣告
>     ClassName &referenceName = objectName;
- 物件變數參考參數
>     void function(ClassName &referenceName){}    // interface:
> 
>     function(objectName);    // function call
- 物件變數參考返回值
>     ClassName &function(ClassName &referenctName)    // interface
> 
>     function(objectName)    // function call

# 物件指標參考(Object Reference Pointer)
#### 不常用，其可以想成是 call by pointer 的變形，多加一個 & 是為了限制指標不能為 NULL(因為 call by reference 的變數不能為 NULL)

- 宣告
>     ClassName *&referenceName = pointerName;
- 物件變數參考參數
>     void function(ClassName *&referenceName){}    // interface:
> 
>     function(pointerName);    // function call
- 物件變數參考返回值
>      ClassName *&function(ClassName *&referenceName)
> 
>     function(objectName)    // function call

---
# 封裝(Encapsulation)
#### 讓特定的物件不能被外界存取，是開發者(developer)用來限制使用者(user)的存取權限的手段。一般來說，只讓使用者接觸到開發者設定的 function interface 以進行調用，而禁止其直接存取變數或 function implementation

實現方式: 使用 private, protected, public

- private (default)
  - 只允許本類別(class)中的其他成員存取
- protected
  - 允許本類別(class)的子類別存取。
- public
  - 允許所有類別(class)存取
  
e.g.
```
// Circle.h

class Circle{
private:
    int radius;
    int height;
public:
    // getter and setter
    double getArea();
    double getVolume();
    void setRadius(int r);
    void setHeight(int h);
};

double Circle::getArea(){
    return radius * radius * 3.14;
}
double Circle::getVolume(){
    return getArea() * height;
}
void Circle::setRadius(int r){
    if(r > 0)
        radius = r;
}
void Circle::setHeight(int h){
    if(h > 0)
        height = h;
}
```
```
// Circle.cpp

#include <iostream>
#include "Circle.h"
using namespace std;

int main(){
    Circle c1;
    c1.radius = 10;     // error
    c1.height = 5       // error
    c1.setRadius(10);
    c1.setHeight(5);
    cout << c1.getArea() << endl;
    cout << c1.getVolume() << endl;
    return 0;
}
```
---
# 繼承(Inheritance)

- 子類別/衍生類別(Child class/Derived class): 繼承已有物件
- 父類別/基礎類別(Parent class/Base class): 被繼承物件

#### 當子繼別繼承父類別時，就擁有父類別的所有成員，可避免 duplication 及降低維護困難度

### _**子類別擁有父類別的所有成員，不代表有相應的存取權，子類別不能存取父類別的 private 成員(雖有繼承但不能直接存取)，而僅能存取 protected 和 public 的成員**_

-  private 代表不接受子類別及物件存取
-  protected 代表接受子類別但不接受物件存取(最好用於成員函式而非變數成員，可規避潛在風險，詳見 [protected 的真正用法](https://www.youtube.com/watch?v=qLe0LQ-5Oxc&list=PLnKth7bLoeC4llLBt1p_Sy0BzlMEHqnwZ&index=8))
-  public 代表接受物件存取

子類別可以
- 新增父類沒有的成員
- 新增父類已有的成員，會取代父類的成員
  
(註: 成員包含變數成員和成員函式)

e.g.
```
// myHeader.h

class Shape{
    double area;
    double girth;
protected:
    void setArea(double a);
    void setGirth(double g);
public:
    // ctor
    Shape(){
        area = 0;
        girth = 0;
    }
    double getArea();
    double getGirth();
};

void Shape::setArea(double a){
    if(a > 0)
        area = a;
}
void Shape::setGirth(double g){
    if(g > 0)
        girth = g;
}

double Shape::getArea(){
    return area;
}
double Shape::getGirth(){
    return girth;
}

// inheritance
class Circle : public Shape{
    int radius;
    double area;
public:
    // ctor
    Circle(){
        radius = 0;
    }
    void setRadius(int r);
};
void Circle::setRadius(int r){
    if(r > 0){
        radius = r;
        area = radius * radius * 3.14;
        setArea(radius * radius * 3.14);  // 因為 base class 是 protected，若為 private 則會 error
        setGirth(radius * 2 * 3.14);  // 因為 base class 是 protected，若為 private 則會 error
    }
}

class Rectangle : public Shape{

};
```

```
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
```
---
# 建構函式(Constructor，下稱 ctor)
#### 物件初始化的程式碼，可指定資料成員的初值，讓 user 可以不用進行完整的初值設定，

與 function 類似，惟以下幾點需要注意
- ctor 名稱須與 class 名稱相同(case sensitivity)
- 可以有參數列
- 不可以有返回型別
- 參數列可以指定預設值

#### 預設呼叫沒有參數的 ctor，若開發者沒有建立 ctor，**compiler 會自動生成沒有參數的 ctor，_該 ctor 不會初始化成員_**，但只有要任一 ctor，compiler 就不會自動生成(如果寫了一個有參數的 ctor，沒參數的 ctor 也必須要寫，因為 compiler 不會再進行自動生成)

#### Overloading Constructor
除了沒有參數的 ctor，也可以使用 overloading 建立多個 ctor

#### this pointer
每個成員函式都隱含著指標 this，this 會指向呼叫成員函式的 object 

功用: 
1. 在 IDE 中可讓 user 由參數名稱中判斷功能
2. 避免重名時變數的 scope holes

#### 

```
// myHeader2.h

class Circle{
    int radius;
public:
    /*
    // ctor......(1)
    Circle(){
        radius = 0;
    }
    // ctor overloading......(2)
    Circle(int r){
        radius = 0;
        setRadius(r);
    }
    */

    // ctor......(3)，參數列指定預設值，其功能可取代(1)和(2)的 ctor，如果 user 有傳入 r，則會使用(2)進行指定；沒有則使用(1)進行初始化
    Circle(int r = 0){
        // this 在此處可省略，但當 Argument 與 object 裡的變數成員同名時，就可能會發生錯誤，如(4)
        this->radius = 0;
        setRadius(r);
    }
    /*
    // ctor......(4)
    Circle(int radius = 0){
        // radius = 0;     // 此處應為 object 的變數成員，但沒寫 this 就會變成在存取 ctor 的 Argument
        this->radius = 0;
        setRadius(radius);      // 沒寫 this 變成 setRadius(0)，有寫 this 就會正常給值;
    }
    */
    void setRadius(int r);
    int getRadius();
};

void Circle::setRadius(int r){
    if(r > 0)
        radius = r;
}
int Circle::getRadius(){
    return radius;
}

class Rectangle{
    int length;
    int width;
public:
    /*
    // ctor......(1)
    Rectangle(){
        length = 0;
        width = 0;
    }
    // ctor overloading......(2)
    Rectangle(int a, int b){
        length = 0;
        width = 0;
        setLength(a);
        setWidth(b);
    }
    */
    // 參數列指定預設值，其功能可取代上面兩個 ctor，如果 user 有傳入 r，則會使用(2)進行指定；沒有則使用(1)進行初始化
    Rectangle(int a = 0, int b = 0){
        length = 0;
        width = 0;
        setLength(a);
        setWidth(b);
    }
    void setLength(int l);
    void setWidth(int w);
    int getLength();
    int getWidth();
};

void Rectangle::setLength(int l){
    if(l > 0)
        length = l;
}
void Rectangle::setWidth(int w){
    if(w > 0)
        width = w;
}

int Rectangle::getLength(){
    return length;
}
int Rectangle::getWidth(){
    return width;
}
```

```
#include <iostream>
#include "myHeader2.h"
using namespace std;

int main(){
    Circle c1;  // 呼叫沒有參數列的 ctor
    Circle c2(10);  // 呼叫有參數列的 ctor
    cout << c1.getRadius() << endl;
    cout << c2.getRadius() << endl;

    Rectangle r1;
    Rectangle r2(10, 10);
    Rectangle r3(10);
    cout << "r1.getLength() = " << r1.getLength() << endl;
    cout << "r1.getWidth() = " << r1.getWidth() << endl;
    cout << "r2.getLength() = " << r2.getLength() << endl;
    cout << "r2.getWidth() = " << r2.getWidth() << endl;
    cout << "r3.getLength() = " << r3.getLength() << endl;
    cout << "r3.getWidth() = " << r3.getWidth() << endl;
    return 0;
}
```
---
# 多型(Polymorphism)和虛擬(virtual)函式

## 多型(Polymorphism): 父類別指標或參考的物件，因指派的物件不同而有不同的實現機制，並以此簡化實現機制的方法

## is-a vs. has-a
#### _兩者都是用來描述**類別與類別間的關係**_

### Note: is-a代表類別之間階層的父子關係。has-a代表類別之間的whole/part關係。

- is-a(用於繼承): 子類別 is-a 父類別


    > e.g. Circle is-a Shape.
    > ```
    > class Shape{ };
    > 
    >class Circle : public Shape{ };
    > ```
  - A is-a B，代表著 A 其實也是一種 B. e.g. Circle 也是一種 Shape


    > e.g. 有父子關係的型別：電子設備 -> 電話 -> 行動電話 -> 智慧型手機。
    >
    > 物件：你身上的手機。
    >
    > 你身上的手機 is-a 智慧型手機 is-a 行動電話 is-a 電話 is-a 電子設備
    >
    > 你身上的手機是一個物件，是一個型別為智慧型手機的物件，也是一個型別為行動電話的物件，也是一個型別為電話的物件，也是一個型別為電子設備的物件。

- has-a: 手機 has-a 晶片，e.g. Phone has-a Chip.(手機與晶片都是 object)

    > ```
    > class Chip{};
    >  
    > class Phone{
    >    Chip chip;
    > };
## Polymorphism -- Dynamic/Runtime binding 
*指派(Assign): 子類別宣告的物件指派到父類別宣告的物件，反之則不可行。是物件的複製(copy-by-value)，不是多型的應用
### _**子類別指派到父類別宣告 => 代父出征(O)**_
### 父類別**不可**指派到子類別宣告 => 替子送死(X, error)

### Dynamic binding 實現依賴於 object-oriented 指標或引用的類型
1. 指標(Pointer)
2. 參考(Reference)
3. 群體(Group)
4. 參數(Parameter)

### 子類別內如果定義與父類別相同的成員函式
1. 如果子類別沒有指派到父類別宣告，會執行子類別定義的成員函式
2. 如果子類別指派到父類別宣告(使用 Polymorphism 宣告時)，仍會執行父類別的成員函式(除非使用 virtual keyword 才可以 override)

e.g. 

[CShape.h](CShape.h)

[CShape.cpp](CShape.cpp)

[CCircle.h](CCircle.h)

[CCircle.cpp](CCircle.cpp)

[CRectangle.h](CRectangle.h)

[CRectangle.cpp](CRectangle.cpp)

[main.cpp](main.cpp)
---
## Polymorphism -- Subtyping(virtual)


---
# Reference
[C++ 進階教學 : 物件導向的基本觀念](https://cpproadadvanced.blogspot.com/2020/03/c_9.html)

[C++ 進階教學 - 物件導向(全)](https://www.youtube.com/playlist?list=PLnKth7bLoeC4llLBt1p_Sy0BzlMEHqnwZ)