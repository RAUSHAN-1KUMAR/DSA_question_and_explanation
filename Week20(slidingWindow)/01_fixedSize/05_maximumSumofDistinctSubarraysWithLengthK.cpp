/* -> 2461

You are given an integer array nums and an integer k. Find the maximum subarray sum of all the subarrays of nums that meet the following conditions:
    - The length of the subarray is k, and
    - All the elements of the subarray are distinct.

Return the maximum subarray sum of all the subarrays that meet the conditions. If no subarray meets the conditions, return 0.

A subarray is a contiguous non-empty sequence of elements within an array.

 

Example 1:
1,5,3,4,5,5 k=5
    Input: nums = [1,5,4,2,9,9,9], k = 3
    Output: 15
    Explanation: The subarrays of nums with length 3 are:
    - [1,5,4] which meets the requirements and has a sum of 10.
    - [5,4,2] which meets the requirements and has a sum of 11.
    - [4,2,9] which meets the requirements and has a sum of 15.
    - [2,9,9] which does not meet the requirements because the element 9 is repeated.
    - [9,9,9] which does not meet the requirements because the element 9 is repeated.
    We return 15 because it is the maximum subarray sum of all the subarrays that meet the conditions

Example 2:
    Input: nums = [4,4,4], k = 3
    Output: 0
    Explanation: The subarrays of nums with length 3 are:
    - [4,4,4] which does not meet the requirements because the element 4 is repeated.
    We return 0 because no subarrays meet the conditions.

*/

#include<iostream>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int startWindow = 0;
    int endWindow = 0;
    int size = nums.size();
    int windowSize = k;

    // hashing to check the repeated number
    unordered_map<int,int> mp;

    long long sum=0;
    long long maxSum=0;

    while (endWindow<size)
    {
        // Store the sum and mark its fequency in map
        sum += nums[endWindow];
        mp[nums[endWindow]]++;

        // before checking the window size, check the frequency of inserted element
        if(mp[nums[endWindow]]>1)
        {
            // if the freq is more than 1 then we don't need to include that frequenc's element in our sum, so we will remove it from startWindow becuase if a element has more than 1 freq than it was previously added by startWindow
            while (mp[nums[endWindow]]>1)
            {
                sum-=nums[startWindow];
                mp[nums[startWindow]]--;
                startWindow++;
            }
        }
        // if there is no freq > 1 and window size is achieved
        else if(endWindow-startWindow+1 == windowSize)
        {
            maxSum = max(sum, maxSum);

            sum -= nums[startWindow];
            mp[nums[startWindow]]--;
            startWindow++;
        }

        endWindow++;
    }
    
    return maxSum;
}

int main()
{
    vector<int> nums = {5,3,3,1,1};

    int k=3;

    cout << maximumSubarraySum(nums, k) << endl;

    return 0;
}