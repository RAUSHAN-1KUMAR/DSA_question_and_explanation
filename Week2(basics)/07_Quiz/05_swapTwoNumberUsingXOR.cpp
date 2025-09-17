/*
To use XOR operator to swap two numbers
*/

#include<iostream>
#include<bitset>

using namespace std;

int main(){

    int a = 5, b = 9;

    cout << a << " " << b << endl;

    // code to swap
    a = a^b;
    b = a^b;
    a = a^b;

    cout << a << " " << b << endl;

    return 0;
}