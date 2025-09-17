
/*
empty()-> used to check empty or not, if empty output will be 1 i.e., true
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "";

    cout << s1.empty() << endl;
    cout << s2.empty() << endl;

    return 0;
}