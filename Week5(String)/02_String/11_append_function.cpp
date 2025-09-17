
/*
append()-> append is used to add content in a string, it will remove the null character and put it to the last of added string.

Function of append():-
    -- Syntax:
        1. ptr.append(str):- appending string str
        2. ptr.append(str,digit1,digit2):- appending total digit2 characters of string str from digit1 index.
        3. ptr.append(str,digit1):- to append first digit1 characters of string str.
        4. ptr.append(str.begin(), str.end()):- appending a range of characters using iterators.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";

    cout << s1 << endl;
    cout << s1.capacity() << endl;

    s1.append(s2);

    cout << s1 << endl;

    s1.append(", ho gya append");

    cout << s1 << endl;

    cout << s1.capacity() << endl;//-> Its capacity will be increased if the added string will leak out the previous available capacity.

    return 0;
}