/*
Data is constant but pointer is not
    -- if I write const before '*' 
*/

#include<iostream>
using namespace std;

int main()
{
    const int *a = new int;// const data and non-const pointer
    *a = 2;//-> error, we have to specify the value at the time of initialization
    a = new int(5); // pointer can be reassigned
    cout << *a << endl;

    const int* b = new int(10);
    // OR
    // int const* b = new int(10);
    cout << *b << endl;

    // pointer ka content reassign nhi hoga but pointer kisi aur ko point ker sakta h

    int c = 20;
    b = &c;
    cout << *b << endl;

    return 0;
}
