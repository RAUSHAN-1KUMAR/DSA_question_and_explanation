/* -> GFG

There is an array arr of heights of stone and Geek is standing at the first stone and can jump to one of the following: Stone i+1, i+2, ... i+k stone, where k is the maximum number of steps that can be jumped and cost will be |hi-hj| is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches the last stone.


Example:
    Input: k = 3, arr[]= [10, 30, 40, 50, 20]
    Output: 30
    Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum


    Input: k = 1, arr[]= [10, 20, 10]
    Output: 20
    Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

*/


/*
Approach:- similar to coin change
    1. recursive -> TC: O(k^n), SC: O(n)
    2. top-down -> TC: O(n*k), SC: O(n)+O(n)
    3. bottom-up -> TC: O(n*k), SC: O(n)
    4. space Opti -> possible or not
        -- yes possible because steps are linear, 1->2->3.. not like random coins in case of coin change.
        SC: O(k) -> array of size k, observe the code that how the access and update has done

*/


#include<bits/stdc++.h>
using namespace std;

// recursive solution -> TLE
int helper(int k, vector<int>& arr, int n)
{
    if(n==0) return 0;
    if(n<0) return INT_MAX;
    
    int mini = INT_MAX;
    int step=k;
    for(int i = step ; i>=1 ; i--)
    {
        int stepTaken = helper(k, arr, n-i);
        if(stepTaken!=INT_MAX)
        {
            int ans = abs(arr[n]-arr[n-i]) + stepTaken;
            mini = min(ans,mini);
        }
    }
    
    return mini;
}

int minimizeCost(int k, vector<int>& arr)
{   
    return helper(k, arr, arr.size()-1);
}


// memoization
int helper1(int k, vector<int>& arr, int n, vector<int> &dp)
{
    if(n==0) return 0;
    if(n<0) return INT_MAX;

    // Step3:
    if(dp[n]!=-1)
        return dp[n];
    
    int mini = INT_MAX;
    int step=k;
    for(int i = step ; i>=1 ; i--)
    {
        int stepTaken = helper1(k, arr, n-i, dp);
        if(stepTaken!=INT_MAX)
        {
            int ans = abs(arr[n]-arr[n-i]) + stepTaken;
            mini = min(ans,mini);
        }
    }

    //Step2:
    dp[n]=mini;
    
    return dp[n];
}

int minimizeCost1(int k, vector<int>& arr)
{   
    // Step1:
    vector<int> dp(arr.size(), -1);

    return helper1(k, arr, arr.size()-1, dp);
}


// tabulation approach
int minimizeCost2(int k, vector<int>& arr)
{   
    // Step1:
    vector<int> dp(arr.size(), -1);

    // Step2:
    dp[0] = 0;
    
    // Step3: fill the remaining using recusive logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int n=1 ; n<arr.size() ; n++)
    {
        int mini = INT_MAX;
        int step=k;
        for(int i = step ; i>=1 ; i--)
        {
            if(n-i >= 0)
            {
                int stepTaken = dp[n-i];
                if(stepTaken!=INT_MAX)
                {
                    int ans = abs(arr[n]-arr[n-i]) + stepTaken;
                    mini = min(ans,mini);
                }
            }
        }

        dp[n]=mini;
    }
    
    return dp[arr.size()-1];
}


// space optimization
int minimizeCost3(int k, vector<int>& arr)
{   
    // observe1, k size array
    vector<int> dp(k, -1);
    dp[0] = 0;
    
    // use the same for loop of tabulation method
    for(int n_i=1 ; n_i<arr.size() ; n_i++)
    {
        int mini = INT_MAX;
        for(int step = k ; step>=1 ; step--)
        {
            if(n_i-step >= 0)
            {
                int stepTaken = dp[(n_i-step)%k];// observe2
                if(stepTaken!=INT_MAX)
                {
                    int ans = abs(arr[n_i]-arr[n_i-step]) + stepTaken;
                    mini = min(ans,mini);
                }
            }
        }

        dp[n_i%k]=mini;// observe3
    }
    
    // observe4
    return dp[(arr.size()-1)%k];
}


int main()
{
    vector<int> arr = {10,30,40,50,20};
    int k=3;

    cout << minimizeCost2(k, arr) << endl;

    return 0;
}

