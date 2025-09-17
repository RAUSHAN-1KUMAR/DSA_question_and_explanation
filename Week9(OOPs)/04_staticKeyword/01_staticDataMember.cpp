/*
Static data member: that variable is going to share memory with all of the class instances.
*/

#include<iostream>
using namespace std;

class abc
{
public:
    // static data member:- x and y sirf ek hi h, baki sab object ek hi x aur y ko point krengen
    static int x, y; // This tells the compiler: “There is a static variable named x associated with the class. But it does not create storage for x, unless it is declared outside of the class"

    void print() const
    {
        cout << x << " " << y << endl;
    }
};

// necessary code
// this tells the compiler: Allocate memory for abc::x. 
// without this line, the compiler knows x exixts, but has no memory allocated to store its value
int abc::x;
int abc::y;

// :: is scope resolution Operator, like std::cout -> means the cout that belongs to the std namespace


int main()
{
    abc obj1;
    obj1.x = 1;
    obj1.y = 2;
    obj1.print();

    abc obj2;
    obj2.x = 10;
    obj2.y = 20;

    obj1.print();
    obj2.print();

    return 0;
}

