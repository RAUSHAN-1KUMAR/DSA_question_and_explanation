
#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    int b = a++;        // b = 10 then a = 10 + 1 = 11
    cout << b << " ";
    b = ++a;            // a = 11 + 1 = 12 then b = 12
    cout << a << endl;
    cout << b;
    return 0;
}
