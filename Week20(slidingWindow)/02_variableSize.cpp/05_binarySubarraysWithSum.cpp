/* 930

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.


Example 1:
    Input: nums = [1,0,1,0,1], goal = 2
    Output: 4
    Explanation: The 4 subarrays are bolded and underlined below:
    [1,0,1, 0,1]
    [1,0,1,0, 1]
    [1, 0,1,0,1]
    [1,0, 1,0,1]

Example 2:
    Input: nums = [0,0,0,0,0], goal = 0
    Output: 15

*/

/*
Approach: keeping track of all sum
    -- the goal is to keep track of all the prefix sum and their frequency so that at each step we can find out the occurent of current_prefix_sum - goal in the map and add it to the count, add becuase the freq says the occurent of the subarray with sum equal to current_prefix_sum - goal which will eventually give us the subarray with sum equal to goal

    -- isme ye dhyan rakhna h ki map me prefix_sum ak freq store kerna h naaki index
*/

#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal)
{
    int n = nums.size();

    int startWindow=0;
    int endWindow=0;

    int prefixSum=0;
    int count=0;

    unordered_map<int,int> mp; // to store the prefix sum and its frequency

    // VVI line
    mp[0] = 1; // to handle the case when prefixSum itself is equal to goal

    while(endWindow<n)
    {
        prefixSum += nums[endWindow];

        int rem = prefixSum - goal;

        if(mp.find(rem)!=mp.end())
        {
            count += mp[rem];
        }

        mp[prefixSum]++;

        endWindow++;
    }

    return count;
}

int main()
{
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}