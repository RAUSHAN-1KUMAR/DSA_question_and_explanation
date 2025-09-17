/*
Can we make virtual dtor?
    - yes
    - it is really important to handle proper destruction of Derived classes

so jab bhi ager ham inheritance apply ker rhe h to it is really important ki proper destruction ho objects ka using virtual dtor.
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

    virtual ~Base()
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

