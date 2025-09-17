/*
Shallow copy:- A shallow copy duplicates an object's top-level structure but does not copy the elements that are pointed to by the object. In other words, the copied object shares references to the same dynamically allocated memory as the original object. This can lead to issues such as double deletion or unintended modifications.
*/

#include<iostream>
using namespace std;

class abc
{
public:
    int x;
    int *y;

    abc(int _x, int _y):x(_x), y(new int(_y)){}

    void print() const
    {
        cout << "X: " << x << endl;
        cout << "PTR Y: " << y << endl; // address
        cout << "Content of Y (*y): " << *y << endl; // value at address
        cout << endl;
    }
};

int main()
{
    abc a(1,2);
    a.print();

    // shallow copy
    abc b(a);  
    b.print();

    // lets obeserve the issue with shallow copy
    *b.y = 20;
    b.print();
    a.print();

    return 0;
}

/*
Output:-
X: 1
PTR Y: 0x1001990
Content of Y (*y): 2

X: 1
PTR Y: 0x1001990
Content of Y (*y): 2

In the output we can see that value get copied to object b but the PTR Y of each object is holding the same memory address, and that means both object's points to same memory address, it means for object b there is not any other memory allocated in heap for its PTR Y.
    -- so problem is that if both points to the same memory location then it means we delete that heap allocated memory by one oject then it will get deleted for other objects also
*/

