/*
Ex:- 10%4 = 2
    OR 10%(2)^2 = 2

    So we are gonna find for: X % 2^k = X&((1<<k)-1)

The logic is to get the last k-1 bits of X
    Suppose out X is 00001100110111

    i) 2^k = 1000000..ktimes
    ii) 2^k-1 = 0111111..ktimes & X
        => 00001100110111 & 00000000011111
        => 10111 we get the last k-1 bits which is remainder
*/ 


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int a=10;

    // 10/4 or 10/2^2 -> k=2
    cout << (a&((1<<2)-1)) << endl;

    return 0;
}