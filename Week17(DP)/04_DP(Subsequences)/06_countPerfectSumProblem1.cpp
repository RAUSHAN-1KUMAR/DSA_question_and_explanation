/* GFG 
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Note: It is guaranteed that the product of the length of arr and target will not exceed 106

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
    -- taking the variable target from target->0

Now lets solve it using meet in the middle -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(vector<int> &arr, int i, int sum)
{
    // base case
    if(i==0)
    {
        if(sum==0 && arr[i]==0) return 2;// because we have two option either we take it or not take it
        
        if(sum==0 || sum==arr[i]) return 1;// if arr[i]==sum or sum==0, we have only one option

        return 0;
    }

    int exclude = helper(arr, i-1, sum);

    int include= 0;
    if(arr[i]<=sum)
        include = helper(arr, i-1, sum-arr[i]);

    return include+exclude;
}

int perfectSum(vector<int> &arr, int target)
{
    int n=arr.size();

    int ans = helper(arr, n-1, target);// you can see that i have taken i as n-1

    return ans;
}


// memoization 
int helper1(vector<int> &arr, int i, int sum, vector<vector<int>> &dp)
{
    // base case
    if(i==0)
    {
        if(sum==0 && arr[i]==0) return 2;
        
        if(sum==0 || sum==arr[i]) return 1;

        return 0;
    }

    //Step3
    if(dp[i][sum]!=-1)
        return dp[i][sum];

    int exclude = helper1(arr, i-1, sum, dp);

    int include= 0;
    if(arr[i]<=sum)
        include = helper1(arr, i-1, sum-arr[i], dp);

    //Step2
    dp[i][sum] = exclude+include;

    return include+exclude;
}

int perfectSum1(vector<int> &arr, int target)
{
    int n=arr.size();

    //Step1:
    vector<vector<int>> dp(n, vector<int>(target+1, -1));

    int ans = helper1(arr, n-1, target, dp);

    return ans;
}


// tabulation
int perfectSum2(vector<int> &arr, int target)
{
    int n=arr.size();

    //Step1:
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    //Step2: initialization
    if(arr[0]==0) dp[0][0] = 2; // if(sum==0 && arr[i]==0) return 2;
    else dp[0][0] = 1;          // if(sum==0 || sum==arr[i]) return 1;

    if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]] = 1; // sum==arr[i] return 1;

    //Step3:
    for(int i=1 ; i<n ; i++)
    {
        for(int sum=0 ; sum<=target ; sum++)
        {
            int exclude = dp[i-1][sum];

            int include= 0;
            if(arr[i]<=sum)
                include = dp[i-1][sum-arr[i]];

            dp[i][sum] = exclude+include;
        }
    }

    return dp[n-1][target];
}

int main()
{
    vector<int> arr = {0,10,0};
    int target = 0;

    cout << perfectSum2(arr, target) << endl;

    return 0;
}
