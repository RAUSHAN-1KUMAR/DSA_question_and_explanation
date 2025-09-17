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
    -- Optimal solutions says whenever flip exceeds K, move sw to just maintain the maxLenth till you get nums[ew]=1
    -- we are not reaching to the first zero index when we exceeds flip count to k, we are just moving forward both sw and ew to maintain the current maxLength as it is, we move forward without decreasing flip till we hit nums[sw]=0;

    TC:- O(n);
    SC:- O(1)
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

    while(ew<n){
        if(nums[ew]==0) flip++;

        //Change: if, in place of while loop
        if(flip>k){
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

