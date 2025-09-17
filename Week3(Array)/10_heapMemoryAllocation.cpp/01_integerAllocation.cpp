/*
Allocation integer inside heap using new keyword
*/

#include<iostream>
using namespace std;

int main()
{
    int *ptr = new int;//-> allocate an integer

    cout << ptr << endl;//-> address of allocated memory
    cout << *ptr << endl;//-> garbage value

    *ptr = 42;

    cout << *ptr << endl;

    // deallocation is good practice
    delete ptr;

    return 0;
}

