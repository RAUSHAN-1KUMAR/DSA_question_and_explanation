/* -> 300
Given an integer array nums, return the length of the longest strictly increasing subsequence


Example 1:
    Input: nums = [10,9,2,5,3,7,101,18]
    Output: 4
    Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.


Example 2:
    Input: nums = [0,1,0,3,2,3]
    Output: 4


Example 3:
    Input: nums = [7,7,7,7,7,7,7]
    Output: 1
*/


/*
Appraoch:- recursion    
    -- explained in note copy

The question is -> how we are gonna handle negative prev, while doing memoization or tabulation -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

int lengthOfLIShelper(vector<int> &nums, int curr, int prev)
{
    if(curr == nums.size()) return 0;

    // include
    int include = 0;
    if(prev==-1 || nums[curr]>nums[prev])
    {
        include = 1+lengthOfLIShelper(nums, curr+1, curr);
    }

    // exclude 
    int exclude = 0 + lengthOfLIShelper(nums, curr+1,prev);

    return max(include, exclude);
}
 
int lengthOfLIS(vector<int> &nums)
{
    int curr = 0;
    int prev = -1;

    int ans = lengthOfLIShelper(nums, curr, prev);

    return ans;
}

int main()
{
    vector<int> nums = {7,7,7,7};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}

