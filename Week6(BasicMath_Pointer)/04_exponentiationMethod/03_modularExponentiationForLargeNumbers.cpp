/*
Implement pow(x, n) % M.
In other words, for a given value of x, n, and M, find (x^n) % M.

Example 1:
Input: x = 3, n = 2, m = 4
Output: 1
Explanation: 3^2 = 9. 9 % 4 = 1.

Example 2:
Input: x = 2, n = 6, m = 10
Output: 4
Explanation: 2^6 = 64. 64 % 10 = 4.
*/

#include<iostream>
using namespace std;

long long int powMod(long long int x, long long int n, long long int m)
{
    long long int ans = 1;

    while(n>0)
    {
        if(n&1) 
            ans = (ans*x) % m;

        x = (x*x)%m;

        n >>= 1;
    }
    
    return ans%m;
}


int main()
{
    int x=2;
    int n=6;
    int m=10;

    cout << powMod(2,6,10) << endl;

    return 0;
}