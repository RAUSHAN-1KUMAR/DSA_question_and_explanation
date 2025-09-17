/*
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since the answer can be large, return it modulo 10^9 + 7.


Examples:
Input : n = 2 k = 4
Output : 16
Explanation: We have 4 colors and 2 posts.
Ways when both posts have same color : 4
Ways when both posts have diff color : 4(choices for 1st post) * 3(choices for 2nd post) = 12

Input : n = 3 k = 2
Output : 6
*/

/* 
Appraoch:- DP
    1. top-down approach
    2. bottom-up approach
    3. space optimization
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// top-down appraoch
int getPaintWays(int n, int k, vector<int> &dp)
{
    if(n==1){
        return k;
    }
    if(n==2){
        return k*(k-1) + k;
    }

    //Step3: use the results that already exists in dp array
    if(dp[n]!=-1) return dp[n];

    int ans = (k-1)*(getPaintWays(n-1,k,dp) + getPaintWays(n-2,k,dp));

    //Step2: store the result in dp array
    dp[n] = ans;

    return ans;
}

// bottom-up approach
int getPaintWaysTabulation(int n, int k)
{
    //Step1: create a dp array
    vector<int> dp(n+1, -1);

    //Step2: initialize the dp array using the base case of top-down approach
    dp[0] = 0;
    dp[1] = k;
    dp[2] = k + k*(k-1);

    //Step3; fill the remaining dp array by using the same logic to top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=3 ; i<=n ; i++)
    {
        int ans = (k-1)*(dp[i-2] + dp[i-1]);

        dp[i] = ans;
    }

    return dp[n];
}

// space optimization
int getPaintWaysSpaceOptm(int n, int k)
{

    int prev = k; // n=1
    int curr = k + k*(k-1); // n=2

    //Step3;
    for(int i=3 ; i<=n ; i++)
    {
        int ans = (k-1)*(prev + curr);

        prev = curr;
        curr = ans;
    }

    return curr;
}

int main()
{ 
    int n=3;
    int k=3;

    //Step1: create a dp array
    vector<int> dp(n+1, -1);

    int ans = getPaintWays(n,k,dp);

    cout << ans << endl;


    return 0;
}