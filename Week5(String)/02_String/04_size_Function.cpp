
/*
size()-> it will count the number of character except null character just like length() function
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";

    cout << s1.size() << endl;
    cout << s2.size() << endl;

    return 0;
}