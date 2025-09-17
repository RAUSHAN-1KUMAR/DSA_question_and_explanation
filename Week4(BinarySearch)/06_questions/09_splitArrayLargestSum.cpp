/* -> 410

Given an integer array 'nums' and an integer k, split 'nums' into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.


Example 1:
    Input: nums = [7,2,5,10,8], k = 2
    Output: 18
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


Example 2:
    Input: nums = [1,2,3,4,5], k = 2
    Output: 9
    Explanation: There are four ways to split nums into two subarrays.
    The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.
*/

/*
Approach:- Question is similar to book allocation problem, so we can use the same logic/code here also

This Question could also be solve using Dynamic programming -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &nums, int &sol)
{
    int totalSum=0;
    int count=1;
    for(int num:nums)
    {
        if(totalSum+num > sol)
        {
            count++;
            totalSum=num;// totalSum = num: kerna h naki 0
        }
        else
        {
            totalSum += num;
        }
    }

    return count;
}

int splitArray(vector<int> &nums, int k)
{

    int start = *max_element(nums.begin(), nums.end());
    int end = accumulate(nums.begin(), nums.end(), 0);

    int ans = -1;

    while(start<=end)
    {
        int mid = (start + end)/2;

        if(countStudents(nums,mid)>k)
        {
            start=mid+1;
        }
        else
        {
            ans = mid;
            end = mid-1;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2; 

    cout << splitArray(nums, k) << endl;

    return 0;
}

