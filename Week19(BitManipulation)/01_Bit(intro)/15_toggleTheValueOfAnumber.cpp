/*
Toggle a variable in between two value, for example if value of a varibale x is 10 then toggle it to 5 or vice versa
*/

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int x=10;
    x = x^10^5;
    cout << x << endl;
    return 0;
}

