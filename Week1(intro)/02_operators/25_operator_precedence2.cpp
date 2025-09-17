#include <iostream>
using namespace std;

int main(){
    int x = 2;
    int y = 3;
    cout << "The value of 3*x - 8*y is: " << 3*x-8*y << endl; //--> this will give right answer according to maths as well as operators precedence in C.
    cout << "The value of 8*y / 3*x is: " << 8*y/3*x << endl; //--> this will give wrong answer according to maths, but it is correct according to operators precedence in C, because * and / follows left to right associativity.
    cout << "The value of 8*y / 3*x is: " << (8*y)/(3*x) << endl; //--> this will give right answer because of operator associativity. 
    return 0;
}