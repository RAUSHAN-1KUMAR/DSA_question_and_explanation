/*
Deep copy:- A deep copy duplicates not only the object's top-level structure but also the elements pointed to by the object. This means that the copied object has its own separate copy of the dynamically allocated memory, ensuring that modifications to one object do not affect the other and preventing issues like double deletion.

the deep copy constructor, it is just a custom copy constructor but allocating new heap memory for pointers
*/

#include<iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y):x(_x), y(new int(_y)){}

    // deep copy constructor
    abc(const abc& obj)
    {
        x = obj.x;
        y = new int(*obj.y); // allocating new heap memory
    }

    void print() const
    {
        cout << "X: " << x << endl;
        cout << "PTR Y: " << y << endl;
        cout << "Content of Y (*y): " << *y << endl;
        cout << endl;
    }
};


int main()
{
    abc a(1,2);
    a.print();

    abc b(a);
    b.print();

    // now issue resolved
    *b.y = 20;
    
    b.print();
    a.print();

    return 0;
}

