/*
Given an integer array nums, return the length of the longest strictly increasing subsequence


Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


Example 2:
    Input: nums = [0,1,0,3,2,3]
    Output: 4


Example 3:
    Input: nums = [7,7,7,7,7,7,7]
    Output: 1
*/

/* 
Appraoch:- Using tabulation method to print the LIS.

We can also print the LIS from our own dp wala tabulation method
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(int n, vector<int>& arr)
{
    vector<int> dp(n, 1), parent(n);
    int maxi = -1;
    int lastIndex = 0;

    for(int i=0 ; i<n; i++)
    {
        parent[i]=i;
        for(int prev = 0; prev<i ; prev++)
        {
            if(arr[prev]<arr[i] && 1+dp[prev]>dp[i])
            {
                dp[i] = 1 + dp[prev];
                parent[i] = prev;
            }
        }

        if(dp[i]>maxi)
        {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    // form answer
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while(parent[lastIndex] != lastIndex)
    {
        lastIndex = parent[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}


int main()
{
    vector<int> nums = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};

    for(auto num:longestIncreasingSubsequence(nums.size(), nums))
    {   
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

