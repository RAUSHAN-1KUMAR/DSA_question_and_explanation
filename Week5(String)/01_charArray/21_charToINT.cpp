/*
Hint:-
    -- to convert digit into characterDigit:    digit + '0'
    -- to convert characterDigit into digit:    digitChar - '0'

ASCII value of '0' -> 48
    '1' → 49
    '2' → 50
    '3' → 51
    '4' → 52
    '5' → 53
    '6' → 54
    '7' → 55
    '8' → 56
    '9' → 57

Note:- works only in case of single digit.
*/

#include<iostream>
using namespace std;

int main()
{
    // digit to char
    int a=4;
    char b = a;

    cout  << "Before conversion to char: " << b << endl; //-> it will print the ASCII character corresponding to int 4.

    b = a+'0';

    cout << "After conversion to char: " << b << endl;


    //char to digit
    char ch = '8';
    int num =  ch;

    cout << "Before conversion to digit:" << num << endl;//-> it will print the ASCII value corresponding to char 8.

    num = ch-'0';

    cout << "After conversion to digit: " << num << endl;



    return 0;
}