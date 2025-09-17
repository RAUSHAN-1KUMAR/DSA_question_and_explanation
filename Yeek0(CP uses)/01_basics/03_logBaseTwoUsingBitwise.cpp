/*
we are going to find log base 2 of a number using bitwise operator
*/

#include<bits/stdc++.h>
using namespace std;

// TC:- O(logn)
int log2_bitwise(int n)
{
    int logValue=0;

    n=n>>1;
    while(n){
        logValue++;
        n=n>>1;
    }

    return logValue;
}

// TC:- O(1)
int log2_builtin(int n)
{
    // __builtin_clz(n) -> counts the number of leading zeros in the binary representation of n
    // for long long use -> __builtin_clzll(n)
    return (31 - __builtin_clz(n));
}

int main()
{
    int n = 20;
    cout << log2_bitwise(n) << endl;
    cout << log2_builtin(n) << endl;
    return 0;
}