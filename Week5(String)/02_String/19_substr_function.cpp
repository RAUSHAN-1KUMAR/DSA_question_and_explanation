
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello how are you";
    string s2 = "world";
    string s3 = "programming";
    string s4 = "coding";

    cout << s3 << endl;
    cout << s3.substr(3) << endl; //-> it will print the whole string starting from given index.
    cout << s3 << endl;
    cout << s3.substr(3,4)<< endl; //-> first digit is for starting point and the second digit indicates how many character you want?

    string s5 = s2[0] + s2.substr(2);
    cout << s5 << endl;


    return 0;
}