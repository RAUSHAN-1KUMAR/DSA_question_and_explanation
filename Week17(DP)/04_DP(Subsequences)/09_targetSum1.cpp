/* -> 494
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

    - For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

RETURN the number of different expressions that you can build, which evaluates to target.


Example 1:
    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
    Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
*/

/*
Approach:- using the logic of the question "partition with given difference" 
    -- if we assign negative or positive to our element of the given array, ultimately at the end we will have a part(s1) with positive sign element and other part(s2) with negative sign element, 
        - so if there sum = s1-s2 == target, we have a way increase the count
        - we can see that ultimately we just have to find different combination of s1, s2 such that there diff(s1-s2) is equal to target
*/

#include<bits/stdc++.h>
using namespace std;

// recursion solution
int helper(vector<int> &nums, int i, int sum)
{
    // base case
    if(i==0)
    {
        if(sum==0 && nums[i]==0) return 2;// because we have two option either we take it or not take it

        if(sum==0 || sum==nums[i]) return 1;// if nums[i]==sum or sum==0, we have only one option

        return 0;
    }

    int exclude = helper(nums, i-1, sum);

    int include= 0;
    if(nums[i]<=sum)
        include = helper(nums, i-1, sum-nums[i]);

    return include+exclude;
}

int findTargetSumWays(vector<int>& nums, int target)
{
    int n=nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // if totalsum<target or totalSum is odd, return false
    if((totalSum-target<0) || (totalSum-target)%2) return 0;

    int sum = (totalSum-target)/2;

    int ans = helper(nums, n-1, sum);

    return ans;
}


// memoization
int helper1(vector<int> &nums, int i, int sum, vector<vector<int>> &dp)
{
    // base case
    if(i==0)
    {
        if(sum==0 && nums[i]==0) return 2;
        if(sum==0 || sum==nums[i]) return 1;

        return 0;
    }

    //Step3
    if(dp[i][sum]!=-1)
        return dp[i][sum];

    int exclude = helper1(nums, i-1, sum, dp);

    int include= 0;
    if(nums[i]<=sum)
        include = helper1(nums, i-1, sum-nums[i], dp);

    //Step2;
    dp[i][sum]=include+exclude;

    return include+exclude;
}

int findTargetSumWays1(vector<int>& nums, int target)
{
    int n=nums.size();
    int totalSum = accumulate(nums.begin(), nums.end(), 0);
    if((totalSum-target<0) || (totalSum-target)%2) return 0;

    int sum = (totalSum-target)/2;

    //Step1;
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));

    int ans = helper1(nums, n-1, sum, dp);

    return ans;
}

int main()
{
    vector<int> nums = {1,1,1,1,1,1};
    int target = 0;

    cout << findTargetSumWays1(nums, target) << endl;

    return 0;
}
