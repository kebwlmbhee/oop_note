# Outline
- [物件(Object)](#物件object)
- [物件導向(Object-Oriented)](#物件導向object-oriented)
- [類別(Class)](#類別class)
- [Friend Class](#friend-class)
- [物件變數(Object variable)](#物件變數object-variable)
- [物件指標(Object Pointer)](#物件指標object-pointer)
- [物件變數參考(Object Reference Variable)](#物件變數參考object-reference-variable)
- [物件指標參考(Object Reference Pointer)](#物件指標參考object-reference-pointer)
- [封裝(Encapsulation)](#封裝encapsulation)
- [Polymorphism -- Overloading](#polymorphism----overloading)
- [繼承(Inheritance)](#繼承inheritance)
- [建構函式(Constructor)](#建構函式constructor下稱-ctor)
- [Initialization List](#initialization-list)
- [Polymorphism -- Overriding](#polymorphism----overriding)
  - [Is-a vs. Has-a](#is-a-vs-has-a)
  - [指派(Assign)](#指派assign)
  - [虛擬函式(virtual function)](#虛擬函式virtual-function)
  - [Dynamic Casting](#dynamic-casting)
  - [純虛函式(Pure virtual function)](#純虛函式pure-virtual-function)
  - [override & final](#override--final-specifierc11)
- [動態記憶體配置(Dynamic Memory Allocation)](#動態記憶體配置dynamic-memory-allocation)
- TODO: [Inline function](#inline-function)
- TODO: [模版(Template)](#模板template) 
- TODO: [File I/O](#file-io)
- TODO: [Exception & RTTI](#exception--rtti)
- TODO: [STL(Standard Template Library)](#stlstandard-template-library)
- [Reference](#Reference)

# 物件(Object)
#### 一群**記憶體的集合**
#### 擁有
1. 資料成員(Attribute)
2. 成員函式(Method)
---

# 物件導向(Object-Oriented)
#### 除了儲存資料外，還能運算資料
#### C 的 struct 只能儲存資料
#### C++ 的 class 的型別使資料與運算的函式屬於同一個物件下的成員。

#### 因為可能歸屬於不同的變數下
1. 相同名稱的**資料成員**，但它的值不見得一樣。
2. 相同名稱的**成員函式**，但它運算的結果不一定一樣。
---

# 類別(Class)
#### 一種型別，像 C++ 裡的 int 一樣
#### **依照物件的需求進行開發設計**

#### 類別裡包含
1. 物件成員=> 物件資料成員，物件成員函式
2. 類別成員=> 類別資料成員，類別成員函式
3. 建構函式(建構子)
4. 其他

### class 和 object 的差別: class 只是方法，object 是照著 class 這個方法所實際生成(實例化)的東西
---
# Friend Class
#### 前備知識: private, protected, public(參[封裝(Encapsulation)](#封裝encapsulation))
- Friend Class
  - 如果 B_Class 宣告成 A_Class 的 friend class，則 B_Class 可以直接存取 A_Class 的所有成員(private, protected, public)
  
  ```
  #include <iostream>
  using namespace std;

  class ABC {   // A_Class
  private:
      char ch='A';
  protected:
      int num = 11;

      friend class XYZ;
  };
  class XYZ {   // B_Class
  public:
      void show(ABC &obj){
          cout << obj.ch << endl;   // can access cuz friend class
          cout << obj.num << endl;  // can access cuz friend class
      }
  };
  int main() {
      ABC abc;
      XYZ xyz;
      xyz.show(abc);      // A
                          // 11
      return 0;
  }
  ```
- Friend Function
  - 如果 X_Function 宣告成 A_Class 的 friend function，則可以透過 X_Function 直接存取 A_Class 的所有成員(private, protected, public)
  ```
  #include <iostream>
  using namespace std;

  class ABC {   // A_Class
  private:
      char ch='A';
  protected:
      int num = 11;

      friend void show(ABC &obj);   // X_Function
  };

  void show(ABC &obj){
      cout << obj.ch << endl;   // can access cuz friend function
      cout << obj.num << endl;  // can access cuz friend function
  }

  int main() {
      ABC abc;
      show(abc);          // A
                          // 11
      return 0;
  }
  ```
---

# 物件變數(Object Variable)
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
# 物件指標(Object Pointer)
- 宣告
> 不直接指派
>>     ClassName *pointerName;
>>     pointerName = new ClassName;
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

### 物件變數與物件指標的差別即 call by value 和 call by pointer 的差別

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

Example:

|   Name   |   Link   |
| -------- | -------- |
| Circle.h | [Circle.h](Encapsulation/Circle.h) |
| Circle.cpp | [Circle.cpp](Encapsulation/Circle.cpp) |


實現方式: 使用 private, protected, public

- private (default)
  - 只允許本類別(class)中的其他成員存取
- protected
  - 允許本類別(class)的子類別存取。
- public
  - 允許所有類別(class)存取

---
# 多型(Polymorphism)
#### 多型(Polymorphism): 父類別指標或參考的物件，因指派的物件不同而有不同的實現機制，並以此簡化實現機制的方法，具體實現方法有 Overloading 和 Overriding，以下依序介紹

--- 
# Polymorphism -- Overloading
#### 可以簡化函式，允許函式同名但有不同的 function signature
function signature: 參數順序，數量，型態，不包含 return type & value

- Function Overloading
  ```
  #include <iostream>
  using namespace std;
  
  void add(int a, int b)
  {
    cout << "sum = " << (a + b);
  }
  
  void add(double a, double b)
  {
      cout << endl << "sum = " << (a + b);
  }
  
  int main()
  {
      add(10, 2);       // 12
      add(5.3, 6.2);    // 11.5
      return 0;
  }
  ```
- Constructor Overloading
  - 參[建構函式(Constructor)](#建構函式constructor下稱-ctor)範例
- Operator Overloading
  ```
  #include<iostream>
  using namespace std;
  
  class Complex {
  private:
      int real, imag;
  public:
      Complex(int r = 0, int i = 0) {real = r;   imag = i;}
      
      // This is automatically called when '+' is used with
      // between two Complex objects
      Complex operator + (Complex const &obj) {
          Complex res;
          res.real = real + obj.real;
          res.imag = imag + obj.imag;
          return res;
      }
      void print() { cout << real << " + i" << imag << '\n'; }
  };
  
  int main()
  {
      Complex c1(10, 5), c2(2, 4);
      Complex c3 = c1 + c2;
      c3.print();   // 12 + i9
  }
  ```

---
# 繼承(Inheritance)
#### 繼承: 建立一個以現有的 class(父類別) 為基礎的新 class(子類別)

#### Example:

|   Name   |   Link   |
| -------- | -------- |
| myHeader.h | [myHeader.h](Inheritance/myHeader.h) |
| main.cpp | [main.cpp](Inheritance/main.cpp) |

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

#### 子類別在宣告繼承父類別的時候，可以用存取修飾詞限制父類別的成員在子類別中的新存取層級。

#### Example:
>     class Circle : private Shape{};
>     class CRectangle : protected Shape{};
>     class CTriangle : public Shape{};

### 繼承存取限制

- private (上限改為 private)
  - 子類別繼承的所有父類別成員皆為 private

- protected (上限改為 protected，其餘固定)
  - 在子類別中繼承自父類別的 private 與 protected 的成員不變，public 成員改為 protected。

- public (上限為 public，其餘固定)
  - 在子類別中繼承自父類別的所有成員等級均不變。

|            | private | protected | public     |
| ---------- | ------- | --------- | ---------- |
| private    | private | private   | private    |
| protected  | private | protected | protected  |
| public     | private | protected | public     |


---
# 建構函式(Constructor，下稱 ctor)
#### 建構函式: 實現物件初始化，可指定資料成員的初值，讓 user 可以不用進行完整的初值設定，

#### Example:

|   Name   |   Link   |
| -------- | -------- |
| myHeader2.h | [myHeader2.h](Constructor/myHeader2.h) |
| main.cpp | [main.cpp](Constructor/main.cpp) |

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

# Initialization List
#### 不會有歧異性
#### 不能使用 this pointer

#### Example:
>     Circle(int r = 0) : radius(r){}
> 
>     Rectangle(int length = 0, int width = 0) : length(length), width(width){}

---
# Polymorphism -- Overriding
#### 允許子類別對 function 進行個別實作，替換父類別的 function，子類別 override 時，function signature 和回傳型別需與父類別相同，又稱為 subtyping

Example:

```
#include<iostream>
using namespace std;

class BaseClass
{
public:
    void Display()
    {
        cout << "\nThis is Display() method"
                " of BaseClass";
    }
};

class DerivedClass : public BaseClass
{
public:
    void Display()
    {
        cout << "\nThis is Display() method"
               " of DerivedClass";
    }
};

int main()
{
    DerivedClass dr;
    BaseClass &bs = dr;
    bs.Display();               // This is Display() method of BaseClass
    dr.Display();               // This is Display() method of DerivedClass
                                // **Problem here: 同一個 dr object 因為使用不同的調用而產生不同的結果
                                
    dr.BaseClass::Display();    // This is Display() method of BaseClass
}
```
### 上方的程式碼中同一個 dr object 因為使用不同的調用而產生不同的結果，顯然這沒有達到 Override 的效果

---
## Is-a vs. Has-a
#### _兩者都是用來描述**類別與類別間的關係**_

### Note: is-a代表類別之間階層的父子關係。has-a代表類別之間的whole/part關係。

- Is-a(用於繼承): 子類別 is-a 父類別

  - A is-a B，代表著 A 其實也是一種 B. 
    
    Example: 
    
    Circle 也是一種 Shape
    > ```
    > class Shape{ };
    > 
    >class Circle : public Shape{ };
    > ```

    Example: 
    
    有父子關係的型別：電子設備 -> 電話 -> 行動電話 -> 智慧型手機。
    >
    > 物件：你身上的手機。
    >
    > 你身上的手機 is-a 智慧型手機 is-a 行動電話 is-a 電話 is-a 電子設備
    >
    > "你身上的手機"是一個物件，也是一個型別"為智慧型手機"的物件，也是一個型別為"行動電話"的物件，也是一個型別為"電話"的物件，也是一個型別為"電子設備"的物件。
    > 
    > 你身上的手機可以宣告為"你身上的手機"，也可以宣告為"智慧型手機"，也可以宣告為"行動電話"，也可以宣告為"電話"，也可以宣告為"電子設備"

- Has-a: 手機 has-a 晶片
  
  Example:
  
  Phone has-a Chip.(手機與晶片都是 object)

    > ```
    > class Chip{};
    >  
    > class Phone{
    >    Chip chip;
    > };

---
## 指派(Assign)
#### 子類別宣告的物件指派到父類別宣告的物件，反之則不可行。是物件的複製(copy-by-value)，_**不是多型的應用**_

### 父類別**不可**指派到子類別 => 替子送死(X)
### _**子類別指派到父類別 => 代父出征(O)**_

  1. 指標(Pointer)
  2. 參考(Reference)
  3. 群體(Group)
  4. 參數(Parameter)

### 子類別內如果定義與父類別相同的成員函式
1. 如果子類別沒有指派到父類別，會執行子類別定義的成員函式
2. 如果子類別指派到父類別，仍會執行父類別的成員函式(除非使用 virtual keyword 才可以 override)

---
## 虛擬函式(Virtual Function)
#### C++ 使用 virtual 實現 Overriding

#### Example:

|   Name   |   Link   |
| -------- | -------- |
| CShape.h | [CShape.h](Virtual%20Function/CShape.h) |
| CShape.cpp | [CShape.cpp](Virtual%20Function/CShape.cpp) |
| CCircle.h | [CCircle.h](Virtual%20Function/CCircle.h) |
| CCircle.cpp | [CCircle.cpp](Virtual%20Function/CCircle.cpp) |
| CRectangle.h | [CRectangle.h](Virtual%20Function/CRectangle.h) |
| CRectangle.cpp | [CRectangle.cpp](Virtual%20Function/CRectangle.cpp) |
| main.cpp | [main.cpp](Virtual%20Function/main.cpp) |

- 父類別

  - A. 宣告虛擬函式
  
    > 在函式宣告敘述前加入 keyword virtual.
    >
    > Example:
    >
    >     virtual void showInfo();    // declare in .h
    >
    >     void Classname::showInfo(){ // define in .cpp
    >         ...
    >     }

  - B. 宣告虛擬解構函式(**一定要宣告**)
  
    > 在 class dtor 前加入 keyword virtual.
    > 
    > Example:
    >
    >     virtual ~ClassName(){}
- 子類別
  - A. Override 父類別宣告的虛擬函式
  
    > 再次宣告及定義父類別中的虛擬函式
    >
    > Example:
    >
    >     virtual void showInfo();    // declare in .h
    >
    >     void Classname::showInfo(){ // define in .cpp
    >         ...
    >     }

  - B. 以指標或參考呼叫虛擬函式
    > 執行子類別 override 的內容，指標使用 (->)，參考使用 (.)
    >
    > Example:
    >
    > ```
    > CCircle cc4;
    > cc4.setRadius(100);
    > csPtr = &cc4;
    > csRef = cc4;
    > csPtr->showInfo();
    > csRef.showInfo();
    > ```

[Polymorphism -- Overriding](#polymorphism----overriding) 的 Example 使用了 virtual 後，正常 override Display function

```
#include<iostream>
using namespace std;

class BaseClass
{
public:
    virtual void Display()    // add virtual
    {
        cout << "\nThis is Display() method"
                " of BaseClass";
    }
};

class DerivedClass : public BaseClass
{
public:
    void Display()
    {
        cout << "\nThis is Display() method"
               " of DerivedClass";
    }
};

int main()
{
    DerivedClass dr;
    BaseClass &bs = dr;
    bs.Display();               // This is Display() method of DerivedClass
    dr.Display();               // This is Display() method of DerivedClass
                                // **Problem has been solved

    dr.BaseClass::Display();    // This is Display() method of BaseClass
}
```
    
## Dynamic Casting
#### 大原則: 父類別不能指派給子類別(不能替子送死)
#### 當定義時為子類別，傳遞 Parameter 是父類別時，可以透過 Dynamic Casting 轉為原先定義時的子類別

- A. 指標
  > dynamic_cast<type*>(pointer)
  > 
  > 失敗時返回 NULL pointer
  >
  > Example:
  >
  >     CCircle *ccPtr = dynamic_cast<CCircle *>(csPtr);

- B. 參考
  > 
  > 失敗時拋出 bad_cast Exception。
  >
  > dynamic_cast<type&>(reference)
  >
  > Example:
  >
  > ```
  > CCircle cc4;
  > cc4.setRadius(100);
  > csPtr = &cc4;
  > csRef = cc4;
  > csPtr->showInfo();
  > csRef.showInfo();
  > ```

---
## 純虛函式(Pure Virtual Function)
#### _**類別中若宣告或繼承了一個或多個純虛函式，此類別即為抽象類別(Abstract Class)。**_
#### _**子類別一定要 override 父類別的純虛函式，否則子類別也會變成 Abstract class。**_

#### Example:

|   Name   |   Link   |
| -------- | -------- |
| CShape.h | [CShape.h](Pure%20Virtual%20Function/CShape.h) |
| CShape.cpp | [CShape.cpp](Pure%20Virtual%20Function/CShape.cpp) |
| CCircle.h (與 virtual function 範例相同) | [CCircle.h](Pure%20Virtual%20Function/CCircle.h) |
| CCircle.cpp (與 virtual function 範例相同) | [CCircle.cpp](Pure%20Virtual%20Function/CCircle.cpp) |
| CRectangle.h (與 virtual function 範例相同) | [CRectangle.h](Pure%20Virtual%20Function/CRectangle.h) |
| CRectangle.cpp (與 virtual function 範例相同) | [CRectangle.cpp](Pure%20Virtual%20Function/CRectangle.cpp) |
| main.cpp | [main.cpp](Pure%20Virtual%20Function/main.cpp) |

(註: 僅修改 main.cpp, CShape.h, CShape.cpp，其餘檔案和[虛擬函式(virtual function)](#虛擬函式virtual-function)的範例相同)

- A. 宣告純虛擬函式
  > 純虛擬函式只有宣告，沒有定義
  >
  > virtual type_name (parameter list) = 0;
  > 

- B. Abstract class
  >
  > 1. 不可建立 object，但可建立及使用 object pointer or object reference
  > 2. 可以做為實作多型的差別，單純做父類別讓子類別繼承
  
#### Pure virtual function 是為了強迫子類別進行 override

### Summary for virtual function
- virtual function: 讓子類別決定要不要 override 父類別的 function，不 override 就會使用父類別的 function
- Pure virtual function: 強迫子類別 override virtual function，否則無法建立 object
---
## override & final Specifier(C++11)
#### override 指示符通常加在子類別 function 後，確認子類別是否會 override 父類別的實作，若否則報 Error

#### Example 1:
```
#include <iostream>

using namespace std;

class A
{
public:
    virtual void foo() const{    //因為 A::foo() 多了 const keyword，所以 B::foo() 沒有 override A::foo()
        cout << "Base Class" << endl;
    }
};

class B : public A
{
public:
    void foo() /*override*/{
        cout << "Derived Class" << endl;
    }
};

int main(){
    A *ptr = new B();
    ptr->foo();
    return 0;
}
```
Output: Base Class

if uncomment override specifier, error: 'void B::foo()' marked 'override', but does not override


#### Example 2:
```
#include <iostream>

using namespace std;

class A
{
public:
     void bar() {    //因為 A::bar() 沒有 virtual keyword，所以 B::bar() 沒有 override A::bar()   
        cout << "Base Class" << endl;
    }
};

class B : public A
{
public:
    void bar() /*override*/{
        cout << "Derived Class" << endl;
    }
};

int main(){
    A *ptr = new B();
    ptr->bar();
    return 0;
}
```
Output: Base Class

if uncomment **override** specifier, error: 'void B::bar()' marked 'override', but does not override
<br><br/>

#### final 指示符通常加在父類別 function 後，確認是否會有子類別 override 父類別的實作，若是則報 Error

#### Example:
```
#include <iostream>

using namespace std;

class A
{
public:
     virtual void bar() final {    //因為 B::bar() override A::bar()
        cout << "Base Class" << endl;
    }
};

class B : public A
{
public:
    void bar() {
        cout << "Derived Class" << endl;
    }
};

int main(){
    A *ptr = new B();
    ptr->bar();
    return 0;
}
```
error: virtual function 'virtual void B::bar()' overriding final function

if comment out **final** specifier, output: Derived Class


---
# 動態記憶體配置(Dynamic Memory Allocation)
####
- 靜態配置: 在 compile time 時決定變量的內存空間，一旦決定就不得再更改
- 動態配置: 在 runtime 時依照預先編寫好的程式進行空間的分配，可依據指令隨時改變(通常在不確定使用者會輸入多少內容時使用)

- C
  - Allocate: malloc() (分配失敗返回 NULL pointer)
    >     void *malloc(size_t size);

  - Deallocate: free()
    >     void free(void *ptr);
[Dynamic_Allocation.c](Dynamic%20Memory%20Allocation/Dynamic_Allocation.c)

- C++
  - Allocate: new()
    >     void *operator new(size_t size);
  - Deallocate: delete()
    >     void operator delete(void* ptr);
[Dynamic_Allocation.cpp](Dynamic%20Memory%20Allocation/Dynamic_Allocation.cpp)

### malloc/free vs. new/delete
- 計算占用內存: malloc 需使用 sizeof() 指定內存大小；new 則交由 compiler 自己計算
- 配置成功: malloc 返回 void* 類型，仍需進行強制轉型；new 返回指定類型的指標
- 配置失敗: malloc 返回 NULL pointer；new 會拋出 bad_alloc Exception
- new/delete 有 Constructor/Destructor，可以 Overloading，此處不再過多闡釋
---

# Inline function

---

# 模板(Template)

---

# File I/O

---

# Exception & RTTI

---

# STL(Standard Template Library)
#### [C++ STL 成員及用法](https://docs.google.com/spreadsheets/u/0/d/1cmD2xblurWh9j3DD7j_BeHqnXWa1xlovzXzSJg64I4A/pub?output=html)

---
# Reference
[C++ 進階教學 : 物件導向的基本觀念](https://cpproadadvanced.blogspot.com/2020/03/c_9.html)

[C++ 進階教學 - 物件導向(全)](https://www.youtube.com/playlist?list=PLnKth7bLoeC4llLBt1p_Sy0BzlMEHqnwZ)