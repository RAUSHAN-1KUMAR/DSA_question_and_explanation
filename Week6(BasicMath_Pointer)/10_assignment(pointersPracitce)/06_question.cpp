
/*
Assume the memory address of variable 'a' is 400 (and an integer takes 4 bytes), what will be the output of below code
*/

#include<iostream>
using namespace std;

int main()
{
    int a = 7;
    int *c = &a;

    cout << c << endl;

    c = c+3;

    cout << c << endl;

    return 0;
}