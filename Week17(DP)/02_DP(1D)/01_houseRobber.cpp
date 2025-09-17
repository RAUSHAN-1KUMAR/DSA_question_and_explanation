/* -> 198 (already done in Week7)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
 

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
*/


/*
Note:- DP
    1. Top-Down approach
    2. Bottom-up appraoch
    3. space optimization
*/


#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// Top-Down appraoch
int solve(vector<int>&nums, int index, vector<int> &dp)
{
    if(index >= nums.size())
    {
        return 0;
    }

    //Step3: return if answer already exits
    if(dp[index] != -1)
    {
        return dp[index];
    }

    int include = nums[index] + solve(nums, index+2, dp);
    int exclude = 0 + solve(nums, index+1, dp);

    // Step2: store the results in dp array
    dp[index] = max(include, exclude);

    return max(include, exclude);
}

int rob(vector<int> &nums)
{
    int index = 0;

    //Step1: create dp array
    vector<int> dp(nums.size(), -1);

    return solve(nums,index, dp);
}

// Bottom-up approach
int rob1(vector<int>&nums)
{
    int n = nums.size();

    // Step1: create dp array
    vector<int> dp(n+2, -1);

    // Step2: initialize the dp array using base case
    dp[n] = 0;
    dp[n+1] = 0;

    // Step3: fill the remaining dp array, use the same logic as done in top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=n-1 ; i>=0 ; i--)
    {
        int exclude = 0 + dp[i+1];
        int include = nums[i] + dp[i+2];

        dp[i] = max(exclude, include);
    }

    return dp[0]; 
}

// space optimization
int rob2(vector<int>&nums)
{
    int n = nums.size();

    //change1: space optimization h to sabse pehle taken dp array ko hatao
    // vector<int> dp(n, -1);

    //Change2: as vector has erased so its instances will also being erased
    // dp[n] = 0;
    // dp[n+1] = 0;

    //New data variable(O(1) space)
    //starting ke kuch aese variable jo initial known value ko store ker rhe h i.e., base case
    int next2 = 0;
    int next1 = 0;

    int ans = 0;
    for(int i=n-1 ; i>=0 ; i--)
    {
        int exclude = 0 + next1;
        int include = nums[i] + next2;

        ans = max(exclude, include);

        // shifting 
        next2 = next1;
        next1 = ans;
    }

    return ans;
}

int main()
{
    vector<int> houses = {1,2,3,1,4,6,7};

    cout << "Maximum Amount to be roobed is: " << rob(houses) << endl;

    return 0;
}