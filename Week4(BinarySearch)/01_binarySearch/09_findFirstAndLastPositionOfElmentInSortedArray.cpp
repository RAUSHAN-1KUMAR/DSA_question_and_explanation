/* -> 34

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.


Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

/*
Appraoch:- Question is same as first and last occurrence problem
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int firstOccurrence(vector<int> &nums, int target)
{
    int s=0;
    int e=nums.size()-1;
    int ans = -1;

    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(nums[mid]==target){
            ans = mid;
            e = mid-1;
        }
        else if(target>nums[mid]) s = mid+1;
        else e = mid-1;
    }

    return ans;
}

int lastOccurrence(vector<int> &nums, int target)
{
    int s=0;
    int e=nums.size()-1;
    int ans = -1;

    while(s<=e)
    {
        int mid = s+(e-s)/2;

        if(nums[mid]==target){
            ans = mid;
            s = mid+1;
        }
        else if(target>nums[mid]) s = mid+1;
        else e = mid-1;
    }

    return ans;
}


vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> ans;

    int first = firstOccurrence(nums, target);
    int last = lastOccurrence(nums, target);

    ans.push_back(first);
    ans.push_back(last);

    return ans;
}


int main()
{
    vector<int> nums = {};
    int target = 6;

    vector<int> ans = searchRange(nums, target);

    for(auto num:ans){
        cout << num << " ";
    }

    return 0;
}