/* -> 3098

You are given an integer array nums of length n, and a positive integer k.

The power of a subsequence is defined as the minimum absolute difference between any two elements in the subsequence.

Return the sum of powers of all subsequences of nums which have length equal to k.

Since the answer may be large, return it modulo 10^9 + 7.

 

Example 1:
    Input: nums = [1,2,3,4], k = 3
    Output: 4
    Explanation: There are 4 subsequences in nums which have length 3: [1,2,3], [1,3,4], [1,2,4], and [2,3,4]. The sum of powers is |2 - 3| + |3 - 4| + |2 - 1| + |3 - 4| = 4.

Example 2:
    Input: nums = [2,2], k = 2
    Output: 0
    Explanation: The only subsequence in nums which has length 2 is [2,2]. The sum of powers is |2 - 2| = 0.

Example 3:
    Input: nums = [4,3,-1], k = 2
    Output: 10
    Explanation: There are 3 subsequences in nums which have length 2: [4,3], [4,-1], and [3,-1]. The sum of powers is |4 - 3| + |4 - (-1)| + |3 - (-1)| = 10.
*/

/*
Approach: 4D DP   
    -- subsequence boleto include and exclude wala case
    -- there is a change in memoization technique, we can't use dp of vectors for memoization, becuase mini can go 2*10^8 also, so we will use unordered_map

    TC:- O(n^5), i->n, k->n, prev->n, but mini can go to 10^8 but the max no. of different mini can go to n^2 => n^5 => but this gave TLE
    SC:- O(n^5)

    But we can optimie it to O(n^4) -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int mod=1e9;
int mod2=1e9+7;

// recursive solution
int helper(vector<int> &nums, int i, int prev, int limit, int mini)
{
    if(limit==0) return mini;
    if(i>=nums.size()) return 0;

    
    // include it
    int newMini = min(mini, prev==-1?mod:nums[i]-nums[prev]);
    int include = helper(nums, i+1, i, limit-1, newMini);

    // exculde it
    int exclude = helper(nums, i+1, prev, limit, mini);

    return (include+exclude)%mod2;
}

int sumOfPowers(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());

    int i=0;
    int prev=-1;
    int limit=k;
    int mini=mod;

    return helper(nums, i, prev, limit, mini);
}

// memoization(TC:- O(n^5))
ll helper1(vector<int> &nums, int i, int prev, int k, int mini, unordered_map<ll, unordered_map<ll, unordered_map<ll, unordered_map<ll,ll>>>> &dp)
{
    if(k==0) return mini%mod2;
    if(i>=nums.size()) return 0;


    if(dp.count(i) && dp[i].count(prev) && dp[i][prev].count(k) && dp[i][prev][k].count(mini)){
        return dp[i][prev][k][mini];
    }
    
    int newMini = min(mini, prev==-1?mod:nums[i]-nums[prev]);
    int include = helper1(nums, i+1, i, k-1, newMini, dp);

    int exclude = helper1(nums, i+1, prev, k, mini, dp);

    dp[i][prev][k][mini] = (include+exclude)%mod2;

    return dp[i][prev][k][mini];
}

int sumOfPowers1(vector<int>& nums, int k)
{
    sort(nums.begin(), nums.end());

    int i=0;
    int prev=-1;
    int mini=mod;

    unordered_map<ll, unordered_map<ll, unordered_map<ll, unordered_map<ll,ll>>>> dp;

    ll ans = helper1(nums, i, prev, k, mini, dp);

    return ans%mod2;
}


int main()
{
    vector<int> nums={4,3,-1};
    int k=2;
    cout << sumOfPowers1(nums, k) << endl;
    return 0;
}

