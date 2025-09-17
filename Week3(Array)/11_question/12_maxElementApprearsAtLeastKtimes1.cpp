/*
Question:- Count subarrays where Max Element Appears at least k times.

You are given an integer array(nums) and a positive integer(k). Return the number of sub arrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 
Example 1:
    Input: nums = [1,3,2,3,3], k = 2
    Output: 6
    Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
    Input: nums = [1,4,2,1], k = 3
    Output: 0
    Explanation: No subarray contains the element 4 at least 3 times.
*/

/*
Appraoch:- sliding window
    -- our window is not fixed
*/

#include<bits/stdc++.h>

using namespace std;

int countSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    int maxElement = INT_MIN;

    for(int i = 0 ; i<n ; i++)
    {
        if(nums[i]>maxElement) maxElement = nums[i];
    }

    int start=0;
    int end=0;
    int count = 0;
    int maxElementFreqCount=0;

    while(end<n)
    {
        // expansion phase
        if(nums[end]==maxElement)
        {
            maxElementFreqCount++;
        }

        // shrinking phase
        while(maxElementFreqCount==k)
        {
            count = count + (n-end);
            if(nums[start]==maxElement)
            {
                maxElementFreqCount--;
            }
            start++;
        }
        
        end++;
    }

    return count;
}


int main()
{
    vector<int> num = {28,5,58,91,24,91,53,9,48,85,16,70,91,91,47,91,61,4,54,61,49};

    int output = countSubarrays(num,2);

    cout << output << endl;


    return 0;
}