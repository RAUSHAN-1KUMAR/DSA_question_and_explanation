/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Example 1:
    Input: nums = [10,5,2,6], k = 100
    Output: 8
    Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
    Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
    Input: nums = [1,2,3], k = 0
    Output: 0
*/

/*
Approach:- sliding window
    -- our window is not fixed
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if(k<=1) return 0;

    int start = 0;
    int end = 0;
    int prod = 1;
    int n = nums.size();
    int count = 0;

    while(end<n)
    {
        //expansion phase
        prod = prod * nums[end];

        // shrinking phase
        while(prod>=k)
        {
            prod = prod/nums[start];
            start++;
        }

        count += (end-start+1);
        end++;
    }

    return count;
}

int main()
{
    vector<int> num = {10,5,2,6};

    int output = numSubarrayProductLessThanK(num,100);

    cout << output << endl;

    return 0;
}