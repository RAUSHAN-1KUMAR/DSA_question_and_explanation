/* GFG 
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Note: It is guaranteed that the product of the length of arr and target will not exceed 10^6

Examples:
    Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
    Output: 3
    Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

    Input: arr[] = [2, 5, 1, 4, 3], target = 10
    Output: 3
    Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

    Input: arr[] = [5, 7, 8], target = 3
    Output: 0
    Explanation: There are no subsets of the array that sum up to the target 3.

    Input: arr[] = [35, 2, 8, 22], target = 0
    Output: 1
    Explanation: The empty subset is the only subset with a sum of 0.
*/

/*
Approach:-
    -- this question seem similar to subset sum, but it is not, because target can also be 0, and if it is 0 then we have to handle it carefully
    -- so that's why i have taken a another variable sum, which is going from 0->target, and on thus we are handling for target value zero also.
    -- we can also solve it by taking our sum from target->0, we just have to do some tweaking in our base case

if you want to take your sum from target->0 -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(vector<int> &arr, int i, int sum, int &target)
{
    // base case
    if(i>=arr.size())
        return 0;
    if(sum>target)
        return 0;


    sum+=arr[i];

    // include
    int include = 0;
    if(sum==target)
        include = 1 + helper(arr, i+1, sum+arr[i], target);
    else
        include = 0 + helper(arr, i+1, sum+arr[i], target);

    // exclude
    sum-=arr[i];
    int exclude = 0 + helper(arr, i+1, sum, target);

    return include+exclude;
}

int perfectSum(vector<int> &arr, int target)
{
    int i=0;
    int sum=0;

    int ans = helper(arr, i, sum, target);

    if(target==0) return ans+1;

    return ans;
}


// memoization
int helper1(vector<int> &arr, int i, int sum, int &target, vector<vector<int>> &dp)
{
    // base case
    if(i>=arr.size())
        return 0;
    if(sum>target)
        return 0;

    //Step3:
    if(dp[i][sum]!=-1) 
        return dp[i][sum];

    sum+=arr[i];
    
    int include = 0;
    if(sum==target)
        include = 1 + helper1(arr, i+1, sum, target, dp);
    else
        include = helper1(arr, i+1, sum, target, dp);

    sum-=arr[i];
    int exclude = helper1(arr, i+1, sum, target, dp);

    //Step2:
    dp[i][sum]=include+exclude;

    return dp[i][sum];
}

int perfectSum1(vector<int> &arr, int target)
{
    int i=0;
    int n = arr.size(); 
    int sum=0;

    //Step1:
    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    int ans = helper1(arr, i, sum, target, dp);

    if(target==0) return ans+1;

    return ans;
}


int main()
{
    vector<int> arr = {5,10,0};
    int target = 0;

    cout << perfectSum(arr, target) << endl;

    return 0;
}