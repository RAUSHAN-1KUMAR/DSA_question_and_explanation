/*
pointer is constant but data is not
    -- If i write const after '*'
*/

#include<iostream>
using namespace std;

int main()
{
    int *const a = new int(2);
    *a = 20;//-> value is reassigned because data is not constant
    cout << *a << endl;    

    int b=10;
    a = &b;//-> error, pointer is constant

    return 0;
}
