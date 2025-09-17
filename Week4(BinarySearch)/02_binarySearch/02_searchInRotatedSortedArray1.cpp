/* -> 33
There is an integer array nums sorted in ascending order and also rotated (with distinct values).

Given an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.


Example 1:
    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

Example 2:
    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

Example 3:
    Input: nums = [1], target = 0
    Output: -1
*/


/*
Approach:- using Binary Search
    -- without finding the pivot element
    -- Logic-> identify the sorted half: left or right of mid
*/


#include<iostream>
#include<vector>
using namespace std;


int search(vector<int> &nums, int target)
{
    int low=0;
    int high=nums.size()-1;

    while (low<=high)
    {
        int mid = (low+high)/2;

        if(nums[mid]==target)
            return mid;
        
        //now indentify the sorted half for either left part is sorted or right part is sorted w.r.t mid
        if(nums[low]<=nums[mid]) //-> left part is sorted
        {
            if(nums[low] <= target && target <= nums[mid])
                high = mid-1;
            else
                low = mid+1;
        }
        else //-> right part is sorted
        {
            if(nums[mid]<=target && target<=nums[high])
                low = mid+1;
            else
                high = mid-1;
        }

    }
    
    return -1;
}

int main()
{
    vector<int> v = {3,1};
    int target = 1;

    cout << search(v,target) << endl;
    
    return 0;
}