#include<iostream>
using namespace std;

int main()
{
    int m = 'a';
    cout << m << endl;

    char ch = 98;
    cout << ch << endl;

    int i = -5;
    cout << i << endl;

    unsigned int j = -5;
    cout << j << endl;
    
    char ph = 123456;// output: @ because overflow occured (Discussed later about overflow)
    cout << ph << endl;
    
    return 0;
}