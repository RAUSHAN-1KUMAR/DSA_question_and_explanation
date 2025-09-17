/*
There are two types of variable:
    1. global
    2. local

Can global and local variable have same name is C++? : Yes.
*/

#include<iostream>
using namespace std;

int glo = 6;//--> Global variable

void sum(){
    int a;
    cout << "The value of glo is " << glo << "\n";
}

int main(){
    int a = 14, b = 15;//--> local variables
    int glo = 9;/*If we remove int then the value of global glo will become 9. And if we comment the line then in both the output value of
    glo will be same as global glo.*/

    glo = 28;//-> with this only the value of local glo will be modified.

    sum();//--> Function Call
    cout << glo << "\n";
    cout << "The value of a is " << a << ".\nThe value of b is " << b << ".\n"; 

    return 0; 
}

