/* -> 410

Given an integer array 'nums' and an integer k, split 'nums' into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.


Example 1:
    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


Example 2:
    Input: nums = [1,2,3,4,5], k = 2
    Output: 9
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/

/*
Approach:- Question is similar to book allocation problem, so we can use the same logic/code here also

This Question could also be solve using Dynamic programming -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int returnSum(vector<int> &nums, int &j, int &i){
    int sum=0;
    for(int k=i ; k<=j ; k++){
        sum+=nums[k];
    }
    return sum;
}

int helper(vector<int> &nums, int i, int k, int &n, vector<vector<int>> &dp){
    if(k==1){
        int sum=0;
        for(int j=i ; j<n ;j++){
            sum+=nums[j];
        }

        return sum;
    }

    if(dp[i][k]!=-1)
        return dp[i][k];

    int ans=INT_MAX;
    for(int j=i ; j<=(n-k) ; j++){
        int sum = returnSum(nums, j, i);
        sum=max(sum, helper(nums, j+1, k-1, n, dp));

        ans=min(ans, sum);
    }

    dp[i][k]=ans;

    return dp[i][k];
}

int splitArray(vector<int> &nums, int k){
    int i=0;
    int n=nums.size();

    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    return helper(nums, i, k, n, dp);
}

int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2; 

    cout << splitArray(nums, k) << endl;

    return 0;
}


