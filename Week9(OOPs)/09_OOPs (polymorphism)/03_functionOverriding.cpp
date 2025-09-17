
/*
Function overriding means:- Having same function name and also same paramenter input in parent and child class

Function overloading means:- Having having same name but different parameter input.

Function overriding occurs when a child class redefines a function of the parent class with the same signature (name, parameters, and return type). It allows the child class to provide a specific implementation for a function that is already defined in the parent class.

Virtual function: The base class function should be marked with virtual to enable runtime polymorphism.

Runtime behavior: The function call is resolved at runtime (dynamic dispatch).
*/

#include<iostream>
using namespace std;

class Base{
    public:
        void display(){
            cout << "Display of Base" << endl;
        }
};

class Derived:public Base{
    public:
        void display(){
            cout << "Display of Derived" << endl;
        }
};

int main(){

    Base b;
    b.display();

    Derived d;
    d.display();

    return 0;
}