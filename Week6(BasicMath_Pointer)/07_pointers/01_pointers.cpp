/*
Two types of variable: 
    1. data variable(which stores data)       
    2. address variable(which stores address of data)

Pointer is a variable which stores the address of data.
*/


#include<iostream>
using namespace std;

int main()
{
    int i = 34;
    // 'char *j' means j is a variable which stores the address of a character.
    // 'float *j' means j is a variable which stores the address of a floating value.
    // 'int *j' means j is a variable which stores the address of an integer.

    // '*' is a 'value at address' operator.

    int *j = &i; //--> It means j will now store the address of an integer i.'&' is a 'address of' operator.
    char *ptr;

    //sizeof pointer is independent to data it points to
    cout << sizeof(i) << " " << sizeof(j) << " " << sizeof(ptr) << endl;
    
    cout << "The value of i is " << i << endl;
    cout << "The value of i is " << *(&i) << endl; //--> *(&i) means value at address of i.
    cout << "The value of i is " << *j << endl; //--> since j == &i it means *j == *(&i)... *j ka matlab j ka jo value h uss address p kya value h.
    cout << "The address of i is " << &i << endl;
    cout << "The address of i is " << j << endl; //-->  here we want value of j which actually containing address of i. 
    cout << "The address of j is " << &j << endl;
    cout << "The value of j is " << *(&j) << endl; //--> *(&j) means value at address of j. output-> address of i
    cout << "The value of i is " << **(&j) << endl; //--> *(*(&j)) means j ke address p jo value h uss address p kya value h. output-> value of i.

    return 0;
}