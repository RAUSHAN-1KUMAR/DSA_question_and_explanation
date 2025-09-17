
/*
max_size()-> it will give the maximum block that can be available in the string
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";

    cout << s1.max_size() << endl;
    cout << s2.max_size() << endl;

    return 0;
}