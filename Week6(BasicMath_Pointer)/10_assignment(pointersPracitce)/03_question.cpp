
/*
Guess the output
*/

#include<iostream>
using namespace std;

int main()
{
    int *ptr = 0;//-> 0 means it is pointing to null
    int a = 10;
    *ptr = a;

    cout << *ptr << endl; //-> since it was pointing to null so it will give run time error

    return 0;
}