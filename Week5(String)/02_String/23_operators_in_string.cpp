
#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1 = "hello";
    string s2 = "world";
    string s3 = "programming";
    string s4 = "coding";

    // [] and = operator
    cout << s4[4] << endl;
    s4[4] = 'g';
    cout << s4 << endl << endl;

    // + and = operator
    string s5 = s3 + s4;
    cout << s3+s4 << " or " << s5 << endl;
    string s6 = s3 + " coding";
    cout << s6 << endl;
    return 0;
}