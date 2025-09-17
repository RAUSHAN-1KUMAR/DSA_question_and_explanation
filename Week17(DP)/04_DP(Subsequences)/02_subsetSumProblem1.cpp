/*
Given an array of positive integers, arr[] and a value, target, determine if there is a subset of the given set with sum equal to given target. 

Examples:
    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 9
    Output: true 
    Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.


    Input: arr[] = [3, 34, 4, 12, 5, 2], target = 30
    Output: false
    Explanation: There is no subset with target sum 30.


    Input: arr[] = [1, 2, 3], sum = 6
    Output: true
    Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/

/*
Approach:-
    --taking a varible sum=0; and taking it to the target

Lets solve it using meet in the middle
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<bool>> &arr);

// recursive solution
bool helper(vector<int> &arr, int i, int sum, int &target)
{
    // base case
    if(i>=arr.size())
        return false;

    // include
    sum+=arr[i];
    bool caseA = false; 

    if(sum==target)
        caseA = true;
    else if(sum>target)
        caseA = false;
    else
        caseA = helper(arr, i+1, sum, target);

    // exclude
    sum-=arr[i];
    bool caseB = helper(arr, i+1,sum, target);
    
    return (caseA || caseB);
}

bool isSubsetSum(vector<int> &arr, int target)
{
    int i=0;
    int sum=0;

    return helper(arr, i,sum, target);
}


// tabulation 
bool isSubsetSum1(vector<int> &arr, int target)
{
    int n=arr.size();

    vector<vector<bool>> dp(n+1, vector<bool>(target+1, 0));

    // Base case: if current sum == target, it's true
    for (int i = 0; i <= n; i++)
        dp[i][target] = true;

    // nested loops
    for (int i = n - 1; i >= 0; i--) 
    {
        for (int sum = target; sum >= 0; sum--) 
        {
            bool caseA = false;
            int newSum = sum + arr[i];
            if (newSum <= target)
                caseA = dp[i + 1][newSum];// take

            bool caseB = dp[i + 1][sum];// not take

            dp[i][sum] = caseA || caseB;
        }
    }

    printDpArray(dp);

    return dp[0][0];
}



int main()
{
    vector<int> arr = {4, 3, 5, 3};
    int target = 6;

    cout << isSubsetSum1(arr, target) << endl;

    return 0;
}


void printDpArray(vector<vector<bool>> &dp)
{
    for(auto vec:dp)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}



