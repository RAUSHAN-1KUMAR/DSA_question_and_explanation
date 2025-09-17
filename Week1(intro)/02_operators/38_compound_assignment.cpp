/*
compound assignment:-
    Ex:- +=, -=, *=, /=, %=, &=, |=, <<=, >>=
*/

#include<iostream>
using namespace std;

int main ()
{
    int a = 10, b = 6, c = 15;
    int sum = 5;

    cout << "sum before action: " << sum << endl;

    sum += c;//-> sum = sum + c
    sum -= a,b;//-> sum = sum - a
    sum *= (a,b);//-> sum = sum * b

    cout << "sum after action1: " << sum << endl;

    sum += a+b+c;//-> sum = sum + (a + b + c)

    cout << "sum after action2: " << sum << endl;

    sum += (a+b)*c;//-> sum = sum + ((a+b)*c)

    cout << "sum after action3: " << sum << endl;

    return 0;
}