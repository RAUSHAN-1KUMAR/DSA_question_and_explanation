
/*
push_back()-> used to add character in the last of a string.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello Rohit, How are you";
    string s2 = "world";

    s2.push_back('Z');
    cout << s2 << endl;

    return 0;
}