/* GFG

Given an array arr[] of size n, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum. 

If there is a set S with n elements, then if we assume Subset1 has m elements, Subset2 must have n-m elements and the value of abs(sum(Subset1) - sum(Subset2)) should be minimum.


Example: 
    Input: arr = [1, 6, 11, 5]
    Output: 1
    Explanation: S1 = [1, 5, 6], sum = 12,  S2 = [11], sum = 11,  Absolute Difference (12 - 11) = 1

    Input: arr = [1, 5, 11, 5]
    Output: 0
    Explanation: S1 = [1, 5, 5], sum = 11, S2 = [11], sum = 11, Absolute Difference (11 - 11) = 0 
*/


/*
Approach:- N = size of arr 
    -- previously we have to divide the arr into two subset of equal length 'n'(n+n=N) but now we just have to find two subset
    -- so we can use the tabulation method of 'subset sum problem' but only if sum of all element not exceed 10^6
        - the last array of 2D DP will represent the possible sum exist
*/

#include<bits/stdc++.h>
using namespace std;
void printDP(vector<vector<int>> &dp);


// recusive solution of subset sum problem
bool helper(vector<int> &arr, int n, int target)
{
    if(n==0)
        return (arr[0]==target);
    else if(target==0)
        return true;

    bool notTake = helper(arr, n-1, target);

    bool take;
    if(arr[n]<=target)
        take = helper(arr, n-1, target-arr[n]);
    else
        take = false;

    return (take || notTake);
}

bool isSubsetSum(vector<int> &arr, int target)
{
    int n=arr.size();

    return helper(arr, n, target);
}


// tabulation method of subset sum problem
int partitionSetIntoTwoSubset(vector<int> &arr)
{
    int n=arr.size();
    int totalSum=accumulate(arr.begin(), arr.end(), 0);
    
    // Step1:
    vector<vector<int>> dp(n, vector<int>(totalSum+1, 0));
    
    // Step2: if i was going from i=n->0, and i==0
    if(arr[0]<=totalSum) dp[0][arr[0]] = true; // when target == arr[0]

    for(int row=0 ; row<n ; row++)
        dp[row][0] = true;
    
    
    for(int i=1 ; i<=n-1 ; i++)
    {
        for(int tgt=0 ; tgt<=totalSum ; tgt++)
        {
            bool notTake = dp[i-1][tgt];
            
            bool take=false;
            if(arr[i]<=tgt) take = dp[i-1][tgt-arr[i]];
            
            dp[i][tgt] = (take||notTake);
        }
    }


    // using the last row of dp to find the answer
    int ans=INT_MAX;
    for(int j=totalSum ; j>=0 ; j--)
    {
        if(dp[n-1][j]){
            ans = min(ans, abs(2*j - totalSum));
        }
    }

    return ans;
}


int main()
{
    vector<int> arr = {2,2,2,2};
   cout << partitionSetIntoTwoSubset(arr) << endl;

    return 0;
}


void printDP(vector<vector<int>> &dp){
    for(auto &vec:dp){
        for(int &num:vec){
            cout << num << " "; 
        }
        cout << endl;
    }
    cout << endl;
}

