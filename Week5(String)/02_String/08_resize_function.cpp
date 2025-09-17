
/*
resize(given_value)-> resize is used to change the capacity of string, its capacity will increases to 'given_value'.
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "";

    cout << s1.capacity() << endl;
    s1.resize(30);
    cout << s1.capacity() << endl;
    cout << s2.capacity() << endl;

    return 0;
}



