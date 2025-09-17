/*
When you don't use virtual, the function call is resolved at compile time based on the type of the pointer, not the actual object.

When we use virtual, the function call is resolved at run-time and we say it run-time polymorphism because as we have same functions with different behaviours and we are deciding which one to call at run-time using virtual keyword

So run-time polymorphism is achieved using virtual function, overrided function, base class pointer and child class object
*/

/*
virtual function-> just we used in hybrid inheritance
    -- When a function is declared as virtual in a base class, it indicates that the function can be overridden in any derived class, and the appropriate version of the function is called based on the type of the object that is referred to or pointed to, rather than the type of the reference or pointer itself
*/

#include<iostream>
using namespace std;

class Base{
    public: 
        //-> virtual function: Adding virtual tells the compiler "When someone calls fun through a pointer/reference to Base, don't decide now. Instead, wait untill runtime and check the actual object"
        virtual void fun(){ 
            cout << "fun of Base class." << endl;
        }
};

class Derived:public Base{
    public:
        void fun(){
            cout << "fun of Derived class." << endl;
        }
};

int main()
{
    Base *ptr = new Derived();
    ptr->fun();
    return 0;
}


