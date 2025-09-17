
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int c = 10;

    int b = ++a * c++; // In this case, first c has taken then incremented but we use a++ in place of c++ like previous example in Important1.cpp file then first a will be incremented then taken.

    cout << b << endl;
    cout << a << endl;
    cout << c << endl;

    return 0;
}