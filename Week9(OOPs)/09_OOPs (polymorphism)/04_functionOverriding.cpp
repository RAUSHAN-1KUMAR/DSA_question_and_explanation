
/*
What if function is overridden and base class pointer is pointing to the derived class object?
*/

#include<iostream>
using namespace std;

class Base{
    public: 
        void fun(){
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

    ptr->fun(); // it will call the base class "fun" as compiler decides the inclusion of member function as per the pointer type untill vertual keyword is used -> see next solution

    return 0;
}
