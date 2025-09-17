/* 1922 
A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
    - For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.

Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.
 

Example 1:
Input: n = 1
Output: 5
Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".

Example 2:
Input: n = 4
Output: 400

Example 3:
Input: n = 50
Output: 564908303
*/

/*
we can apply formula of PnC:-
    ex: if n=4, then we have 4 places _ _ _ _ with total 5 even numbers and 4 prime numbers between 0-9:
        applying PnC:- 5 * 4 * 5 * 4 = 400
*/

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// a better to find the power of any integer
long long Power(long long x, long long y, long long m)
{
    if(y==0) return 1;

    long long int ans = 1;

    while(y>0)
    {
        // if y is odd
        if(y&1) ans = (ans*x) % m;

        x = (x*x)%m;

        y >>= 1;// or y = y/2
    }
    
    return ans%m;
}

int countGoodNumbers(long long n) 
{
    long long odd = n/2; // total no. of odd position within given n
    long long even = n/2 + n%2; // total no. of even position within given n

    long long mod = 1000000007;

    // now 5^(even_postions)*4^(odd_positions)
    return (Power(5,even,mod) * Power(4,odd,mod)) % mod;
}

int main()
{
    long long int n = 10;

    cout << countGoodNumbers(n) << endl;

    return 0;
}