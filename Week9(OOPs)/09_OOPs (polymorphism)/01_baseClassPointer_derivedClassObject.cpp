/*
Here we are gonna see that a pointer of Parent class pointing to the object of its child class

Is it possible that a pointer of different class point to the object of another class? -> the answer is No, unless there is a "is-a relationship" between the two classes or otherwise we have to do type-casting.
*/

#include<iostream>
using namespace std;

class Base{
    public:
        void fun1(){
            cout << "Fun1 of base." << endl;
        }
};

class Derived:public Base{
    public:
        void fun2(){
            cout << "fun2 of Derived" << endl;
        }
};


int main()
{
    Derived d;

    Base *ptr = &d; // yes it is possible, and it will be a "is-a relationship".

    ptr->fun1();
    // ptr->fun2();// -> error, because compiler only looks at the declared type of ptr when deciding which members are accessible. This is called compile time restriction

    // the reverse is not possible i.e., we cannot use child class pointer to point parent class objects
    Base b;
    // Derived *ptr = &b;// -> error
    
    return 0;
}

