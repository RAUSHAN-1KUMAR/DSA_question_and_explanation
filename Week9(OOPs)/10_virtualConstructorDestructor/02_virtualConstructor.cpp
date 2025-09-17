/*
Can we make virtual ctor?
    - No
    - constructor connot be virtual, becuase when constructor of a class is executed there is no virtual table in the memory, means no virtual pointer defined yet. So, the constructor should always be non-virtual.
    - A virtual call is a mechanism to get work done given partial information. In particular, "virtual" allows us to call a function knowing only any interfaces and not the exact type of the object. To create an object you need complete information. In particular, you need to know the exact type of what you want to create. Consequently, a "call to a constructor" cannot be virtual.

simple bhasa m samjhe to virtual ka matlab kya, ki wo function derived class m overridden h matlab derived class ke function ko call kerna h jab bhi call hoga but ek constructor to pura pura ek class ka hota h to usko kaise virtual ker sakte h, matlab usko kaise kisi aur class ke liye call ker sakte h
*/

#include<iostream>
using namespace std;

class Base
{
public:
    // not possible
    virtual Base()
    {
        cout << "Base ctor" << endl;
    }

    ~Base()
    {
        cout << "Base dtor" << endl;
    }
};

class Derived:public Base
{
public:
    Derived()
    {
        cout << "Derived ctor" << endl;
    }

    ~Derived()
    {
        cout << "Derived dtor" << endl; 
    }
};

int main()
{
    Base *b = new Derived;
    delete b;
    return 0;
}
