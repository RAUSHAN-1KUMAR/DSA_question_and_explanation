/* -> 930

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 
Example 1:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1]
[1,0,1,0]
[0,1,0,1]
[1,0,1]

Example 2:
Input: nums = [0,0,0,0,0], goal = 0
Output: 15
*/

/*
Appraoch:-sliding window,, appraoch is same as we did in [Week3 -> 10_question -> 15]
    -- i.e., subarray having k different integers
*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int helper(vector<int>&nums, int goal)
{
    int i = 0;
    int j = 0;
    int count = 0;
    int sum = 0;
    
    while (j<nums.size())
    {
        sum += nums[j];

        while (sum>goal && i<=j)// catch condition-> i<=j
        {
            sum -= nums[i];
            i++;
        }
        
        count += j-i+1;
        j++;
    }

    return count;
}

int numSubarraysWithSum(vector<int>&nums, int goal)
{

    return helper(nums,goal)-helper(nums,goal-1);    
}

int main()
{
    vector<int> nums = {0,0,0,0,0};
    int k = 0;

    int ans = numSubarraysWithSum(nums, k);

    cout << ans << endl;

    return 0;
}