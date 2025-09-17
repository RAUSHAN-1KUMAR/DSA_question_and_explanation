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
Solution1:
    -- first we will find the pivot element just like the previous question.
    -- and then if the target lie between the first element to pivot element of the array, apply BS within them only and if the target lie between pivot element to last element of the array, apply BS within them only.

Solution2:
    -- without finding the pivot element
    -- Logic-> identify the sorted half: left or right of mid

Solution3:
    -- same as previous solution2, the only difference is that now we can have dublicate elements

*/


#include<iostream>
#include<vector>
using namespace std;

// Solution1
int findPivotIndex(vector<int> &arr)
{
    int start = 0;
    int end = arr.size()-1;
    int n = arr.size();

    while(start<=end)
    {
        int mid = start + (end-start)/2;

        if(start==end) return start;

        if(arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid] < arr[start]) end = mid-1;
        else start = mid+1;
    }

    return -1;
}

int binarySearch(vector<int> &arr, int s, int e, int target)
{
    int mid = s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==target) return mid;
        else if(target > arr[mid]) s = mid+1;
        else e = mid-1;

        mid = s + (e-s)/2;
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    int pivotIndex = findPivotIndex(nums);

    int n = nums.size();
    int ans = -1; 

    if(target >= nums[0] && target <= nums[pivotIndex]){
        ans = binarySearch(nums, 0, pivotIndex, target);
    }
    else{
        ans = binarySearch(nums, pivotIndex+1, n-1, target);
    }

    return ans;
}


// Solution2:
int search1(vector<int> &nums, int target)
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


// Solution3:
bool search2(vector<int> &nums, int target)
{
    int low=0;
    int high=nums.size()-1;

    while (low<=high)
    {
        int mid = (low+high)/2;

        if(nums[mid]==target) 
            return true;

        // ek aur case ko handle kerna padega, if it matches then do this...
        if(nums[mid]==nums[low] && nums[mid]==nums[high])
        {
            high=high-1;
            low=low+1;
            continue;
        }
        

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
    
    return false;
}



int main()
{
    vector<int> v = {3,1};
    int target = 1;

    cout << search(v,target) << endl;
    
    return 0;
}