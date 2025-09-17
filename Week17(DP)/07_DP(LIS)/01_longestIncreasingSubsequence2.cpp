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
Appraoch:- just by using Binary search(intuition based)
    -- how to get the intuition for this -> my output will be sorted

TC-> O(nlogn)

One More approach, Which is specially called tabulation Method -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int> &nums)
{
    vector<int> ans;

    //initial state
    ans.push_back(nums[0]);

    for(int i=1 ; i<nums.size() ; i++)
    {
        if(nums[i] > ans.back()) // ager mere ans_vector ke last element se hi mera aane wala number bada ho gya to no need to check just insert that number
        {
            ans.push_back(nums[i]);  
        }
        else // ager chota hua to, find the index of just bada wala number
        { 
            // lower_bound -> equal to or just greater than
            int index = lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin();

            ans[index] = nums[i];
        }
    }

    return ans.size();
}

int main()
{
    vector<int> nums = {7,7,7,7};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}

// we can build lowerBound function
int lowerBound(vector<int> &nums, int k)
{
    int s=0;
    int e=nums.size();

    int ans = nums.size();

    while(s<=e)
    {
        int mid=(s+e)/2;

        if(nums[mid]>=k)
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }

    return ans;
}

