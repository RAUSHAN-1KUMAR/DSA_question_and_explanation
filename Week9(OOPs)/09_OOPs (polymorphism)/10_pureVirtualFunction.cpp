/*
What is a Pure Virtual Function?
    - A pure virtual function is a virtual function with no definition in the base class.
    - It is declared using = 0 syntax.
*/

#include<bits/stdc++.h>
using namespace std;

class Base {
public:
    virtual void display() = 0;  // pure virtual function, its like a blueprint/imaginary and must be overridden in every derived class of Base class
};

class Derived:public Base{
public:
    void display(){
        cout << "Drived display function" << endl;
    }
};


int main()
{
    Derived d;
    d.display();

    return 0;
}