
/*
pop_back()-> used to remove character from the last of a string.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello Rohit, How are you";
    string s2 = "world";

    s2.pop_back();
    cout << s2 << endl;

    return 0;
}