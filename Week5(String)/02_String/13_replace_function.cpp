
/*
replace()-> replace is used replace a portion of a string with another string or character sequence.

Function of replace():-
    -- Syntax:
        1. ch.replace(digit1, digit2, str):- replacing total digit2 characters starting from index digit1 of ch with str.
        2. replace(ch.begin()+digit1, ch.begin()+digit2, str):- replacing from begin to end index, excluding end.
        3. ch.replace(digit1,digit2, str, num1,num2):- replace total digit2 characters starting from index digit1 to total num2 chracters starting from num1 of str to a given string ch.
        4. ch.replace(digit1,digit2,str,num):- num is to replace first num characters of string str.
        5. ch.replace(digit1,digit2,digit3,char):- digit 1 is starting index, digit2 is for total replacing characters, digit3 is for how much char you want to insert
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello Rohit, How are you";
    string s2 = "world";

    // replace(digit1, digit2, str)
    cout << s1.replace(2,3,s2) << endl;

    return 0;
}

