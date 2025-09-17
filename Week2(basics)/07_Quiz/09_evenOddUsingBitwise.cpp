/*
To check whether a number is even or odd using bitwise oeprator
*/

#include<iostream>
using namespace std;

bool isEven(int n){
    if(n & 1 == 1) return 0;
    return 1;
}

int main()
{
    int n = 9;

    isEven(n) ? cout <<"Even" : cout << "Odd";

    return 0;
}