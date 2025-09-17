/*
What about the member variables during inheritance?
    -> member variables are not inherited, only the member functions are inherited.
    -> but we can access the member variables of base class using the member functions of base class in derived class.
*/

#include <iostream>
using namespace std;

class Base {
public:
    int x = 10;
};

class Derived : public Base {
public:
    int x = 20; // hides Base::x
};

int main() {
    Derived d;

    cout << d.x << endl;        // prints 20 (Derived::x)
    cout << d.Base::x << endl;  // prints 10 (Base::x)
}
