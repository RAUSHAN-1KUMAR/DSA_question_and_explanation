/*
static member function: there is no instances of that class being passed into that method.
    -- this pointer does not exist for static function kyuki wo ab ek puri class ka function h naki kisi object ka and that's why we can only use static member inside static function.

Static member variables and static member functions in C++ belong to the class itself, not to any specific object.
*/

#include<iostream>
using namespace std;

class abc
{
public:
    int x, y;

    abc():x(0),y(0){}

    // static member function, i.e., this print function belongs to class only
    static void print()
    {
        // cout << x << endl; //error -> we can only use static member inside static member function
        cout << "I am in Static " << __FUNCTION__ << endl;
    }
};


int main()
{
    abc obj1;
    obj1.print();
    abc::print();

    abc obj2;

    abc::print();
    obj2.print();

    return 0;
}

