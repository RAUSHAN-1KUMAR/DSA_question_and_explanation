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
Approach:- intuition based logic
    -- it is asking to find two equal sum subsets, then sum of their sum is basically the sum of total elements of the given array, so basically we have to find the sum/2
    
    -- find the overall sum of the given array: let say {1,2,11,5} = 22.
    -- sum/2 -> 22/2 = 11;
    -- now if a subset present in the given array whose element's sum = 11, return true

    1. recursion
    2. top-down approach
    3. bottom-up approach

Arr.size()<=200; half of it would be 100 and still 2^(100) is very large. 

So, DP solution is correct way to solve it
*/

#include<bits/stdc++.h>
using namespace std;

// recursion
bool targetSum(vector<int> &nums, int i, int sum, int &target)
{
    // base case
    if(i==nums.size()){
        return (target==sum);
    }


    //include
    bool caseB = targetSum(nums, i+1, sum+nums[i], target);

    //exclude
    bool caseA = targetSum(nums, i+1, sum, target);

    return (caseA||caseB);
}

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) // is sum is odd, we can't find the sum, return false
    {
        return false;
    }

    int target = sum/2;

    return targetSum(nums, 0, 0, target);
}


// top-down approach
bool targetSum1(vector<int> &nums, int i, int sum, int &target, vector<vector<int>> &dp)
{
    // base cases
    if(i==nums.size()){
        return (target==sum);
    }

    // Step3: return answer if already exists in dp array 
    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }

    bool caseB = targetSum1(nums, i+1, sum+nums[i], target, dp);

    bool caseA = targetSum1(nums, i+1, sum, target, dp);

    //Step2: store the result in dp array
    dp[i][sum] = (caseA||caseB);

    return (caseA||caseB);
}

bool canPartition1(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1)
    {
        return false;
    }

    int target = sum/2;

    // Step1: create dp array
    vector<vector<int>> dp(nums.size()+1, vector<int>(target+1, -1));

    bool ans = targetSum1(nums, 0, 0, target, dp);

    return ans;
}


// bottom up-approach
bool canPartition2(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return false;

    int target = sum/2;

    // Step1 and 2: create dp array and initialize the array using the base case of top-down approach->if(sum>target) return false; and if(i==nums.size()){return false;}
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    // if(sum==target) return 1;
    for(int row=0 ; row<=n ; row++) 
    {
        dp[row][target]=1;
    }

    // Step3: now fill the remaining dp array using the logic of top-down approach and index aur sum kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int index=n-1 ; index>=0 ; index--)
    {
        for(int s=target; s>=0; s--)
        {

            bool caseB = false;
            if((s+nums[index])<=target) 
                caseB = dp[index+1][s+nums[index]];

            bool caseA = dp[index+1][s];

            //Step2: store the result in dp array
            dp[index][s] = (caseA||caseB);
        }
    }


    return dp[0][0];
}


// space optimzation
bool canPartition3(vector<int> &nums)
{
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);

    if(sum&1) return false;

    int target = sum/2;

    // Step1: create curr and next array
    vector<int> currRow(target+1,0);
    vector<int> nextRow(target+1,0);

    // Step2: initialize it with base case
    currRow[target]=1;
    nextRow[target]=1;

    // Step3: modify the same code of bottom-up approach w.r.t the currRow and nextRow array
    for(int index=n-1 ; index>=0 ; index--)
    {
        for(int s=target; s>=0; s--)
        {
            int sumTemp = s+nums[index];

            bool caseB = false;
            if(sumTemp<=target) 
                caseB = nextRow[s+nums[index]]; // dp[index+1][s+nums[index]] -> index+1 matlab nextRow

            bool caseA = nextRow[s]; // dp[index+1][s] -> index+1 matlab nextRow

            //Step2: store the result in dp array
            currRow[s] = (caseA||caseB); // dp[index][s] -> index matlab currRow
        }

        // shifting
        nextRow = currRow;
    }


    return nextRow[0];
}


int main()
{
    vector<int> nums = {1,2,5};

    if(canPartition3(nums)) cout << "true";
    else cout << "false";

    return 0;
}