
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello how are you";
    string s2 = "world";
    string s3 = "programming";
    string s4 = "coding";

    cout << s4.front() << endl; //-> used to print first character of the string.
    
    cout << s4.back() << endl; //-> used to print last character of the string.(leaving null character)

    return 0;
}