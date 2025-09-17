/* -> 1911

The alternating sum of a 0-indexed array is defined as the sum of the elements at even indices minus the sum of the elements at odd indices.

    - For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.

Given an array nums, return the maximum alternating sum of any subsequence of nums (after reindexing the elements of the subsequence).

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

Example 1:
    Input: nums = [4,2,5,3]
    Output: 7
    Explanation: It is optimal to choose the subsequence [4,2,5] with alternating sum (4 + 5) - 2 = 7.

Example 2:
    Input: nums = [5,6,7,8]
    Output: 8
    Explanation: It is optimal to choose the subsequence [8] with alternating sum 8.

Example 3:
    Input: nums = [6,2,1,2,4,5]
    Output: 10
    Explanation: It is optimal to choose the subsequence [6,1,5] with alternating sum (6 + 5) - 1 = 10.

*/

/*
Approach:- include exclude logic, 2D DP
    - top-down approach:    TC:- O(2*n)
    - bottom-up
    - space optimization
    - optimal code
*/

#include<bits/stdc++.h>
using namespace std;

// top-down approach
long long helper(vector<int> &nums, int i, int &n, int take, vector<vector<long long>> &dp)
{
    if(i>=n) return 0;

    if(dp[i][take]!=-1){
        return dp[i][take];
    }

    long long include=0;
    if(take){
        include = 1LL*nums[i] + helper(nums, i+1, n, 0, dp); 
    }
    else{
        include = 1LL*(-nums[i]) + helper(nums, i+1, n, 1, dp);
    }

    long long exclude = 0 + helper(nums, i+1, n, take, dp);

    dp[i][take]=max(include, exclude);

    return dp[i][take];
}

long long maxAlternatingSum(vector<int>& nums) {
    int n=nums.size();
    int i=0;
    int take=1;

    vector<vector<long long>> dp(n, vector<long long>(2, -1));

    return helper(nums, i, n, take, dp);
}

// tabulation method
long long maxAlternatingSum1(vector<int>& nums) {
    int n=nums.size();

    vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
    for(int i=0 ; i<2 ; i++){
        dp[n][i]=0;
    }

    for(int i=n-1 ; i>=0 ;i--)
    {
        for(int take=0 ; take<2 ; take++)
        {
            long long include=0;
            if(take){
                include = 1LL*nums[i] + dp[i+1][0]; 
            }
            else{
                include = 1LL*(-nums[i]) + dp[i+1][1];
            }

            long long exclude = 0 + dp[i+1][take];

            dp[i][take]=max(include, exclude);
        }
    }

    return dp[0][1];
}

// space optimization
long long maxAlternatingSum2(vector<int>& nums) {
    int n=nums.size();
    
    vector<long long> next(2, 0);
    vector<long long> curr(2, -1);

    for(int i=n-1 ; i>=0 ;i--)
    {
        for(int take=0 ; take<2 ; take++)
        {
            long long include = (take ? 1LL*nums[i] + next[0] : 1LL*(-nums[i]) + next[1]);

            long long exclude = 0 + next[take];

            curr[take]=max(include, exclude);
        }

        next = curr;// don't forget this

    }

    return curr[1];
}

// one more optimal code
long long maxAlternatingSum3(vector<int>& nums) {
    int n=nums.size();
    
    vector<vector<long long>> dp(n+1, vector<long long>(2, -1));
    for(int i=0 ; i<2 ; i++){
        dp[n][i]=0;
    }

    // even->0, odd->1
    for(int i=n-1 ; i>=0 ;i--)
    {
        // nums[i] at even position
        dp[i][0] = max(dp[i+1][1]-nums[i], dp[i+1][0]);// max(take, not take)

        // nums[i] at odd position
        dp[i][1] = max(dp[i+1][0]+nums[i], dp[i+1][1]);// max(take, not take)
    }

    return dp[0][1];
}

int main()
{
    vector<int> nums={5,6,7,8};
    cout << maxAlternatingSum3(nums) << endl;
    return 0;
}