/* -> 70

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

/*
Approach:-  
    -- similar to fibonacci series
        1. recursive -> TC: O(2^n), SC: O(n)
        2. top-down -> TC: O(n), SC: O(n)+O(n)
        3. space Opti -> TC: O(n), SC: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

// Normal recursive approach
int climbStairs(int n) 
{
    // base case
    if(n==1) return 1;
    if(n==2) return 2;

    // recursive call + process
    int oneStep = climbStairs(n-1);
    int twoStep = climbStairs(n-2);
    int ans = oneStep+twoStep;

    return ans;
}

// With DP(top-down appraoch)
int climbStairsWithDP(int n, vector<int> &dp)
{
    if(n==1) return 1;
    if(n==2) return 2;

    // Step3: just after base case
    // if answer already axists then return the answer
    if(dp[n]!= -1) return dp[n];

    int ans = climbStairsWithDP(n-1, dp) + climbStairsWithDP(n-2, dp);

    // Step2: store results in dp array
    dp[n] = ans;

    return ans;
}
int climbStairs1(int n)
{
    // Step1: create dp array
    vector<int> dp(n+1, -1);

    int ans = climbStairsWithDP(n, dp);

    return ans;
}

// space optimization
int climbStairs2(int n)
{
    int prev = 1;// for n==1
    int curr = 2;// for n==2

    if(n==1) return prev;
    if(n==2) return curr;

    // if n>2
    int ans;
    for(int i=3 ; i<=n ; i++)
    {
        ans = curr + prev;
        prev = curr;
        curr = ans;
    }

    return ans;
}

int main()
{
    cout << climbStairs1(7) << endl;
    return 0;
}