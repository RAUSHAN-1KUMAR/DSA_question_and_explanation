/* -> 162

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:
    Input: nums = [1,2,3,1]
    Output: 2
    Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
    Input: nums = [1,2,1,3,5,6,4]
    Output: 5
    Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/


#include<bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int> &nums)
{
    int ans = -1;
    int low = 0;
    int high = nums.size() - 1;

    // base conditions
    if(nums.size()==1) return 0;
    if(nums[0]>nums[1]) return 0;
    if(nums[high]>nums[high-1]) return high;


    // now for other
    low+=1;
    high-=1;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            ans = mid;
            break;
        }
        else if(nums[mid]<nums[mid-1] && nums[mid]>nums[mid+1])
        {
            high=mid-1;
        }
        else
            low=mid+1;

    }
    
    return ans;
}


int main()
{
    vector<int> vrr = {1,2,1,3,4,3,2,4,5,6,2};

    cout << findPeakElement(vrr) << endl;

    return 0;
}
