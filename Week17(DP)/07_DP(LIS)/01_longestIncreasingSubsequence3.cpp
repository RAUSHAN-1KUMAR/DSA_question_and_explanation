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
Appraoch:- Using O(n) space(single array): signify longest increasing subsequence till ith index
    -- initially array will be assigned to 1 which shows that single element also signify a subsequence of length 1
    -- then iterating through given nums, from 0->n and iterating our single array from 0->upperloop search of max suitable combination

Still TC-> O(n^2)

This approach will help us to print the LIS. -> see next solution
*/


#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n, 1);
    int maxi = -1;

    for(int i=0 ; i<n; i++)
    {
        for(int prev = 0; prev<i ; prev++)
        {
            // if we got a ele less than curr(i) ele then store the max of his count+1 and myCurrent count
            if(nums[prev]<nums[i]){
                dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main()
{
    vector<int> nums = {7,7,7,7};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}

