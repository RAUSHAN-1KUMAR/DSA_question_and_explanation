

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a = 5;
    int b = 13;

    // lets swap
    a = a^b; // 5^13
    b = a^b; // 5^13^13 = 5
    a = a^b; // 5^13^5 = 13

    cout << a  << " " << b << endl;

    return 0;
}