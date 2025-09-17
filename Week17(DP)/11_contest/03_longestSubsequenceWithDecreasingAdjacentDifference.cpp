/* -> 3409

You are given an array of integers nums.

Your task is to find the length of the longest subsequence seq of nums, such that the absolute differences between consecutive elements form a non-increasing sequence of integers. In other words, for a subsequence seq0, seq1, seq2, ..., seqm of nums, |seq1 - seq0| >= |seq2 - seq1| >= ... >= |seqm - seqm - 1|.

Return the length of such a subsequence.

A subsequence is an non-empty array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:
    Input: nums = [16,6,3]
    Output: 3
    Explanation: 
    The longest subsequence is [16, 6, 3] with the absolute adjacent differences [10, 3].

Example 2:
    Input: nums = [6,5,3,4,2,1]
    Output: 4
    Explanation:
    The longest subsequence is [6, 4, 2, 1] with the absolute adjacent differences [2, 2, 1].

Example 3:
    Input: nums = [10,20,10,19,10,20]
    Output: 5
    Explanation: 
    The longest subsequence is [10, 20, 10, 19, 10] with the absolute adjacent differences [10, 10, 9, 9].
*/

/*
Approach:-
    -- At perticular value we are going back from diff as 300 to 0 and let say we choose current diff as 25 then we are gonna seek for the dp[x-25][25] or dp[x+25][25] then col[25] justify that if i choose the current diff as 25 then we need the prevoius value whose diff was >= 25

    SO this dp question is not uniform, like we use to solve it in a sense for moving one for loop from i=0ton and then nested for loop from j=iton, in this question, at particular x we are doing dp[x-y][y] or dp[x+y][y] so you can see that, x-y means below row and x+y means upper row, so yes its random but we are doing it
*/
/*
What does dp[x][y] signify 
    x -> the current value-> nums[i]
    y -> the difference, from 0 to 300
    ans dp will store the maximum length of subsequence if value is x and diff as y
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& nums)
{
    int n=nums.size();

    vector<vector<int>> dp(303,vector<int>(303, 0));
    int ans =0;
    
    for(int i=0;i<n;i++)
    {
        int mx = 0; // to store the max value for current nums[i] with each j(diff)
        for(int j=300;j>=0;j--)
        {
            int cur = 0;// to store the max of two value, either -j or +j

            int prevL = nums[i] - j;
            int prevG = nums[i] + j;

            // if current diff is j, then we should take the prev value whose diff was >= j -> dp[][j]
            if(prevL>=0)// to check underflow
            {
                int l = 1 + dp[prevL][j];
                cur = max(cur,l);
            }

            if(prevG<=300) // to check overflow
            {
                int l = 1 + dp[prevG][j];
                cur = max(cur,l);
            }

            mx = max(mx,cur);
            dp[nums[i]][j] = mx;
            
            ans = max(ans,mx);
        }
    }

    
    return ans;
}


int main()
{
    vector<int> nums = {10,20,10,19,10,20};
    cout << longestSubsequence(nums) << endl;
    return 0;
}

