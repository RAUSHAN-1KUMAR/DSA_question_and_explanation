/* -> 992

Given an integer array 'nums' and an integer k, return the number of good subarrays of 'nums'.

A good array is an array where the number of different integers in that array is exactly k.
    For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.

A subarray is a contiguous part of an array.

 
Example 1:
    Input: nums = [1,2,1,2,3], k = 2
    Output: 7
    Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
    Input: nums = [1,2,1,3,4], k = 3
    Output: 3
    Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
*/


/*
Approach:- sliding window + map
    -- we have to find the subArray having exactly k different integer means to find equal to k different integer. So, what we will do is: [no. of subarray having at most k different integer i.e., <= k different integer - no. of subarray having at most k-1 different integer i.e., <= k-1 different integer]

Note:- Good Question
*/

#include<bits/stdc++.h>
using namespace std;

int helper(vector<int>&nums,int k)
{
    unordered_map<int,int>mp;

    int i=0;
    int j=0;
    int n=nums.size();
    int count=0;

    while(j<n){
        //expansion
        mp[nums[j]]++;

        //shrinking 
        while(mp.size()>k && i<=j)
        {
            mp[nums[i]]--;

            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            i++;
        }

        count += (j-i+1);
        j++;
    }
    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k)
{
    int ans=helper(nums,k)-helper(nums,k-1);
    return ans;
}


int main()
{
    vector<int> nums = {1,2,1,2,3};

    int ans = subarraysWithKDistinct(nums,2);

    cout << ans << endl;

    return 0;
}

