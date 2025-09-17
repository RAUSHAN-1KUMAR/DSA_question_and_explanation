
/*
swap()-> used to swap to whole string.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello Rohit, How are you";
    string s2 = "world";

    s2.swap(s1);
    cout << s2 << endl;

    return 0;
}