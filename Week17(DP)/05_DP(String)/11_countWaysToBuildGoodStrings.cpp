/* -> 2466

Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
    1. Append the character '0' zero times.
    2. Append the character '1' one times.

This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 10^9 + 7.

 

Example 1:
    Input: low = 3, high = 3, zero = 1, one = 1
    Output: 8
    Explanation: 
    One possible valid good string is "011". 
    It can be constructed as follows: "" -> "0" -> "01" -> "011". 
    All binary strings from "000" to "111" are good strings in this example.


Example 2:
    Input: low = 2, high = 3, zero = 1, one = 2
    Output: 5
    Explanation: The good strings are "00", "11", "000", "110", and "011".
*/

/*
Approach:- include or exclude
    -- In recusive we have to call for each low to high and add up the result, but in case of memoization we don't need a seperate dp array for each call we can just call use that common dp array as many times as needed.

    1D dp
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(int n, int &zero, int &one)
{
    if(n==0) return 1;

    // include zero
    int incZero = 0;
    if(zero<=n) incZero = helper(n-zero, zero, one);

    // include one
    int incOne = 0;
    if(one<=n) incOne = helper(n-one, zero, one);

    return incZero+incOne;
}

int countGoodStrings(int low, int high, int zero, int one)
{
    int ans=0;
    for(int i=low ; i<=high; i++){
        ans += helper(i, zero, one);
    }

    return ans;
}


// memoization
int helper1(int n, int &zero, int &one, vector<int> &dp)
{
    if(n==0) return 1;

    if(dp[n]!=-1)
        return dp[n];

    // include zero
    int incZero = 0;
    if(zero<=n) incZero = helper1(n-zero, zero, one, dp);

    // include one
    int incOne = 0;
    if(one<=n) incOne = helper1(n-one, zero, one, dp);

    dp[n] = (incOne+incZero)%1000000009;

    return dp[n];
}

int countGoodStrings1(int low, int high, int zero, int one)
{
    vector<int> dp(high+1, -1);

    int ans=0;

    for(int i=low;i<=high;i++){
        ans=(ans+helper1(i, zero, one, dp))%1000000007;
    }

    return ans;
}


int main()
{
    int low=2;
    int high=3;
    int zero=1;
    int one=2;

    cout << countGoodStrings1(low, high, zero, one) << endl;

    return 0;
}

