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
    -- previous we started from n and then went to zero, and we here having the approach:-> at each n either we had come by taking one step or two step so we were doing fun(n-1)+fun(n-2);

    -- now we will start form zero and at each step either we can take one step or two step, so we will do that
*/

#include<iostream>
#include<vector>
using namespace std;

int helper(int n, int index)
{
    if(index==n) return 1;

    // take one step
    int oneStep = helper(n, index+1);

    // or take two step
    int twoStep = 0;
    if(index+2<=n)  
        twoStep = helper(n, index+2);

    return oneStep+twoStep;
}

int climbStairs(int n) 
{
    int i=0;
    return helper(n, i);
}

int main()
{
    cout << climbStairs(7) << endl;
    return 0;
}