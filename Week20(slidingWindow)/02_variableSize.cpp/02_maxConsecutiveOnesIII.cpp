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
Approach:- two pointer
    1. Brute force: used queue to store the first flipped index, so that whenever i hit zero and no any flip count is left then i can directly use the front of que to just to the first flipped index
        TC:- O(n)
        SC:- O(k)

    2. better approach: sliding window, to get the subarray having at most k zeroes and then store its length -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k)
{   
    int n = nums.size();

    queue<int> qu; // to store the flipped index

    int flip = k;
    int length = 0;
    int sw = 0;
    int ew = 0;
    while(ew<n)
    {
        if(nums[ew]==0 && flip)
        {
            qu.push(ew);
            flip--;
        }
        else if(nums[ew]==0 && !flip)
        {
            length = max(length, (ew-sw));
   
            if(!qu.empty())
            {
                int index = qu.front();qu.pop();

                sw = index+1;

                qu.push(ew);
            }
            else 
                sw = ew+1;

        }

        ew++;
    }

    // don't forget this
    length = max(length, (ew-sw));

    return length;
}

int main()
{
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 3;

    cout << longestOnes(nums, k) << endl;

    return 0;
}