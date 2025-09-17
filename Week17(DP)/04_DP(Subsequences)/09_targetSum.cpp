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
Approach:- I solve it
    -- i have two choices at each index, ya to uss element sum me add(+) kerdo ya to ussko sum me sub(-) kerdo.
    -- but sum value can go negative. So, how we are gonna apply DP(memoization or tabulation technique) on it, we have to think about the index shifting of maximum negative value => -(totalSum), So, the total index shifting value will be totalSum

Is there any other approach -> yes -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// recursion solution
int helper(vector<int> &nums, int i, int sum, int &target)
{
    if(i>=nums.size())
    {
        if(sum==target) return 1;
        else return 0;
    }

    // sum me add kerdo
    int takingAdd = helper(nums, i+1, sum+nums[i], target);
    int takingSub = helper(nums, i+1, sum-nums[i], target);

    return takingAdd+takingSub;
}

int findTargetSumWays(vector<int>& nums, int target)
{
    int i=0;
    int sum=0;

    return helper(nums,i,sum,target);
}


// memoization(observe the index shifting)
int helper1(vector<int> &nums, int i, int sum, int &target, int &indexShiftSum, vector<vector<int>> &dp)
{
    if(i>=nums.size())
    {
        if(sum==target) return 1;
        else return 0;
    }

    //Step3
    if(dp[i][sum+indexShiftSum]!=-1)
        return dp[i][sum+indexShiftSum];

    int takingAdd = helper1(nums, i+1, sum+nums[i], target, indexShiftSum, dp);

    int takingSub = helper1(nums, i+1, sum-nums[i], target, indexShiftSum, dp);

    //Step2
    dp[i][sum+indexShiftSum] = takingAdd+takingSub;

    return dp[i][sum+indexShiftSum];
}

int findTargetSumWays1(vector<int>& nums, int target)
{
    int i=0;
    int sum=0;

    // since minimum sum can be -(totalSum), that's why indexShift is taken as totalSum
    int indeShift = accumulate(nums.begin(), nums.end(), 0);

    //Step1: index shifting is req so size of the vector will be doubled
    vector<vector<int>> dp(nums.size(), vector<int>(indeShift*2+1, -1));

    return helper1(nums,i,sum,target,indeShift,dp);
}

int main()
{
    vector<int> nums = {1,1,1,1,1};
    int target = 3;

    cout << findTargetSumWays1(nums, target) << endl;

    return 0;
}
