
/*
insert()-> used to insert a substring into a string at a specified position.

Function of insert():-
    -- syntax:- 
            1. str.insert(digit,string);
            2. str.insert(digit1,string,digit2);
            3. str.insert(digit1,digit2,char);
        
        : digit1 is the position at which to insert the substring, it is zero-based position.
        : string is the string to be inserted.
        : digit2 is for how much characters you want to insert.
        : char is the single character to be inserted.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";

    // insert(digit,string)
    cout << s1 << endl;
    s1.insert(2,s2);
    cout << s1 << endl;


    // insert(digit1,string,digit2);
    cout << s2 << endl;
    s2.insert(3,"appple",3);
    cout << s2 << endl;

    //insert(digit1,digit2,char);
    cout << s1 << endl;
    s1.insert(2,3,'s');
    cout << s1 << endl;

    return 0;
}

