/*
6. Misc operators
    Ex-> sizeof() operator, Turnery operator, comma(,) operator, Dot(.) and arrow(->) operator, casting operator, address(&) operator, pointer(*) operator
       
        --sizeof(), this print the size in bytes of the data type present in bracket().
        --Turnery operator's syntex is this-> codition?Expression1:Expression2, Expression1 will executed if condition is true and Expression2 will executed if condition is false.
        --comma(,) operator, int y = 4,3,6; so the value of y is 6.
        --dot(.) operator is used in classes and arrow(->) operator is used in pointer.
        --casting operator, float b = 3.44 and if we write int(b) => b = 3.
        --address(&) operator, it tells the address of value stored.   
        --pointer(*) operator, this is used to point the other variable.
*/ 

#include<iostream>
using namespace std;

int main()
{
    int a = 4;
    cout << sizeof(a) << endl;//- output: 4
    char name = 'a';
    cout << sizeof(name) << endl;//- output: 1 

    bool flag;
    // using ternary operator(can only be used in place of if else statement not in case of else if and nested if)
    a == name ? flag = true : flag = false;
    cout << flag << endl;//- output: 0

    // address operator
    cout<< (&a) <<endl;

    return 0;
}
