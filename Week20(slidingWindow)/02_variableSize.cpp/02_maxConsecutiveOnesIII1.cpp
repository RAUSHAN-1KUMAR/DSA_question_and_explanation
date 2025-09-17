/* -> 1004

Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

 

Example 1:
    Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
    Output: 6
    Explanation: [1,1,1,0,0,1,1,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.


Example 2:
    Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
    Output: 10
    Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
    Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
*/

/*
Approach:- two pointer + sliding window
    better approach: sliding window, get the subarray having at most k zeroes and then store its length, and then move start one by one at first found zero + 1.

    TC:- O(2n)
    SC:- O(1)

Optimal solution:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k)
{   
    int n = nums.size();
    int maxLen = 0;
    
    int sw = 0;
    int ew = 0;
    int flip = 0;

    while(ew<n){ //-> O(n)
        if(nums[ew]==0) flip++;

        while(flip>k){ //-> O(n) -> max possible
            if(nums[sw]==0) flip--;
            sw++;
        }

        if(flip<=k){
            int len = ew-sw+1;
            maxLen = max(maxLen, len);
        }

        ew++;
    }

    return maxLen;
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;

    cout << longestOnes(nums, k) << endl;

    return 0;
}

