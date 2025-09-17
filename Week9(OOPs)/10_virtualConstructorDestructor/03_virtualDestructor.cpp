/*
Can we make virtual dtor?
    - yes
    - it is really important to handle proper desctruction of Derived classes
*/

#include<iostream>
using namespace std;

class Base
{
public:
    Base()
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

/*
Output:
Base ctor
Derived ctor
Base dtor

we can see that constructor of both the classes has been called but why not the destructor?
    - so how to call destructor of base class, by use virtual key word-> see next solution
*/

