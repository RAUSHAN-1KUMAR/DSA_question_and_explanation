/*
Literals are values assigned to variables and constants.
    Ex:- int a = 10; here '10' is a literal
*/

#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = 012;//-> output: 10, because 012 is in octal form. So, the octal to decimal of 012 is 10.
    int c = 0X41;//-> ourput: 65, because 0X41 is in hexadecimal form. So, the hexadecimal to decimal of 0X41 is 65.

    cout << a << " " << b << " " << c << endl;
    
    return 0;
}