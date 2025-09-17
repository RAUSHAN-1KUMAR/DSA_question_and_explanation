/* -> 279

Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.


Example 1:
Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.

Example 2:
Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
*/

/*
Approach:- DP(1D)
    1. recursion: TC -> (sqrt(n)^n)
    2. top-down approach: TC -> (nsqrt(n)) = O(n)
    3. bottom-up approach: TC -> (nsqrt(n))
    4. space optimization -> we can't
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<climits>
using namespace std;

// recursion
int numSquares(int n)
{
    if(n==0) return 0;
    
    int ans = INT_MAX;
    for(int i=1 ; i<=sqrt(n) ; i++)
    {
        int aggeKaAns = 1 + numSquares(n - i*i);
        ans = min(ans, aggeKaAns);
    }

    return ans;
}

// top-down approach
int numSquaresHelper(int n, vector<int> &dp)
{
    if(n==0) return 0;

    // Step3
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    
    int ans = INT_MAX;
    for(int i=1 ; i<=sqrt(n) ; i++)
    {
        int aggeKaAns = 1 + numSquaresHelper(n - i*i, dp);
        ans = min(ans, aggeKaAns);
    }

    // Step2
    dp[n] = ans;

    return dp[n];
}

int numSquares(int n)
{
    // Step1
    vector<int> dp(n+1, -1);

    int ans = numSquaresHelper(n, dp);

    return ans;
}


// bottom-up approach
int numSquares(int n)
{
    // Step1
    vector<int> dp(n+1, -1);

    // Step2
    dp[0] = 0;

    // Step3
    for(int n_i=1 ; n_i<=n ; n_i++)
    {
        int ans = INT_MAX;
        for(int i=1 ; i<=sqrt(n_i) ; i++)
        {
            int aggeKaAns = 1 + dp[n_i - i*i];
            ans = min(ans, aggeKaAns);
        }

        dp[n_i] = ans;
    }

    return dp[n];
}


int main()
{
    cout << numSquares(13) << endl;

    return 0;
}