#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> &nums, int curr, int prev, vector<vector<int> > &dp)
{
    if(curr>=nums.size())
        return 0;

    if(dp[curr][prev+1]!=-1){
        return dp[curr][prev+1];
    }

    int include = (prev==-1 || nums[curr]>nums[prev] ? 
        1 + helper(nums, curr+1, curr, dp) :
        0
    );

    int exclude = 0 + helper(nums, curr+1, prev, dp);

    dp[curr][prev+1]=max(include, exclude);

    return dp[curr][prev+1];
}

int lengthOfLIS(vector<int> &nums)
{
    int n=nums.size();
    int curr=0;
    int prev=-1;
    vector<vector<int>> dp(n, vector<int> (n+1, -1));
    return helper(nums, curr, prev, dp);
}

int main()
{
    vector<int> nums = {0,1,0,3,2,3};

    cout << lengthOfLIS(nums) << endl;

    return 0;
}
