// increment or decrement of a number to a pointer

#include<iostream>
using namespace std;

int main()
{
    int i = 34;
    int *ptr = &i;
    cout << "The value of ptr is " << ptr << endl;// output-> address of i
    ptr++; //--> According to my compiler one integer take space of 4 bytes.
    cout << "The value of ptr after ptr++ " << ptr << endl;// output-> address of other memory considering as a integer data type
    ptr--;
    cout << "The value of ptr after ptr-- " << ptr << endl;
    ptr = ptr - 1; //--> -4
    ptr = ptr + 2; //--> +(4)*2
    ptr += 1;
    cout << "The value of ptr is " << ptr << endl;
    cout << "The address of i is " << &i << endl;

    cout << endl;

    char c = '3';
    char *str = &c;
    cout << "The value of str is " << str << endl;//output-> address of c
    str++; //--> According to my compiler one character take space of 1 bytes.
    cout << "The value of str after str++ " << str << endl;//output-> address of other memory considering as a character data type
    str--;
    cout << "The value of str after str-- " << str << endl;
    str = str - 1; //--> -1
    str = str + 2; //--> +(1)*2
    str += 1;
    cout << "The value of str is " << str << endl;
    cout << "The address of c is " << &c << endl;

    cout << endl;

    float x = 3.4;
    float *ntr = &x;
    cout << "The value of ntr is " << ntr << endl;//output-> address of x
    ntr++; //--> According to my compiler one float take space of 4 bytes.
    cout << "The value of ntr after ntr++ " << ntr << endl;//output-> address of other memory considering as a floating point data type.
    ntr--;
    cout << "The value of ntr after ntr-- " << ntr << endl;
    ntr = ntr - 1; //--> -4
    ntr = ntr + 2; //--> +(4)*2
    ntr += 1; //--> +4
    cout << "The value of ntr is " << ntr << endl;
    cout << "The address of x is " << &x << endl;

    return 0;
}