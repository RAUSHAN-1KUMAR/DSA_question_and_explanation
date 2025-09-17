/* 45

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.



Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2

*/

/*
Approach:
1. DP:
    -- O(n^2) time complexity

2. Greedy
*/

#include <bits/stdc++.h>
using namespace std;

// DP approach
int helper(vector<int> &nums, int i, int &n, vector<int> &dp)
{
    if (i == n - 1){
        return 0;
    }

    if (dp[i] != -1)
        return dp[i];

    int ans = INT_MAX;
    for (int j = 1; j <= nums[i]; j++) // lets jump to all possible position ans..
    {
        if (i + j < n)
        {
            int call = helper(nums, i + j, n, dp);
            if (call != INT_MAX)
                ans = min(ans, 1 + call); // ..and return the min of them
        }
    }

    dp[i] = ans;

    return dp[i];
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    vector<int> dp(n + 1, -1);
    return helper(nums, i, n, dp);
}


// greedy approach
int jump2(vector<int> &nums)
{
    int n = nums.size();
    int jumps = 0; // number of jumps made
    int currentEnd = 0; // farthest we can reach with the current number of jumps
    int farthest = 0; // farthest we can reach with one more jump

    for (int i = 0; i < n - 1; i++) // no need to jump from the last element
    {
        farthest = max(farthest, i + nums[i]); // update the farthest we can reach

        if (i == currentEnd) // if we have reached the end of the current jump
        {
            jumps++; // we need to make another jump
            currentEnd = farthest; // update the end for the next jump

            if (currentEnd >= n - 1) // if we can reach or exceed the last index
                break;
        }
    }

    return jumps;
}



int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    return 0;
}