/* -> 416

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.



Example 1:
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:
    Input: nums = [1,2,3,5]
    Output: false
    Explanation: The array cannot be partitioned into equal sum subsets.
*/

/*
Approach:- 
    -- exclude-include, but in a differenct way. I have taken two variable sum1 and sum2, and then 
        CaseA: we are gonna add nums[i] in sum1 but not in sum2
        CaseB: we are gonna add nums[i] in sum2 but not in sum1

    1. recursion -> TLE
    2. top-down approach(3D dp) -> MLE

Better appraoch-> see next solution
*/


#include<bits/stdc++.h>
using namespace std;

// recursion
bool canPartitionHelper(vector<int> &nums, int sum1, int sum2, int i)
{
    if(i>=nums.size())
    {
        if(sum1==sum2) return true;

        return false;
    }

    // include the element into sum1
    sum1 += nums[i];
    bool caseA = canPartitionHelper(nums,sum1,sum2,i+1);
    sum1-=nums[i];

    // include the element into sum2
    sum2+=nums[i];
    bool caseB = canPartitionHelper(nums, sum1, sum2, i+1);

    return (caseA || caseB);
}

bool canPartition(vector<int> &nums)
{
    int sum1=0;
    int sum2=0;

    int index=0;

    return canPartitionHelper(nums, sum1, sum2, index);
}


// top-down approach
bool canPartitionHelper1(vector<int> &nums, int sum1, int sum2, int i, vector<vector<vector<int>>> &dp)
{
    if(i>=nums.size())
    {
        if(sum1==sum2) return true;

        return false;
    }

    //Step3: return if answer already exist
    if(dp[i][sum1][sum2]!=-1)
    {
        return dp[i][sum1][sum2];
    }


    sum1 += nums[i];
    bool caseA = canPartitionHelper1(nums,sum1,sum2,i+1, dp);
    sum1-=nums[i];

    sum2+=nums[i];
    bool caseB = canPartitionHelper1(nums, sum1, sum2, i+1, dp);

    // Step2: store the results in dp array
    bool ans = (caseA||caseB);
    if(ans)
        dp[i][sum1][sum2] = 1;
    else
        dp[i][sum1][sum2] = 0;


    return dp[i][sum1][sum2];
}


bool canPartition1(vector<int> &nums)
{
    int sum1=0;
    int sum2=0;

    int index=0;

    int totalSum = accumulate(nums.begin(), nums.end(), 0);

    // Step1: create 3D dp array
    vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>>(totalSum+1, (vector<int>(totalSum+1, -1))));

    int ans = canPartitionHelper1(nums, sum1, sum2, index, dp);

    return ans;
}


int main()
{
    vector<int> num = {5,6,5,4};

    if(canPartition1(num)) cout << "True" << endl;
    else cout << "False" << endl;

    return 0;
}