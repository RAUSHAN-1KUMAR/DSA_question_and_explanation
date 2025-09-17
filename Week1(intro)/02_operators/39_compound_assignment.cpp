/*
compound assignment:-
    Ex:- +=, -=, *=, /=, %=, &=, |=, <<=, >>=
*/

#include<iostream>
using namespace std;

int main ()
{
    int a = 5;//-> a = 0101
    int b = 4;//-> b = 0100
    
    cout << "value of a before action: " << a << endl;

    a &= b;//-> a = 0101 & 0100 = 0100 = 4

    cout << "value of a after action1: " << a << endl;

    a <<= b+3;//-> b + 3 = 7, a = a * 2^7 => a = 512

    cout << "value of a after action2: " << a << endl;

    return 0;
}