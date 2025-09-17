/* -> 322 (already done in Week7)

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.


Example 1:
Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:
Input: coins = [2], amount = 3
Output: -1

Example 3:
Input: coins = [1], amount = 0
Output: 0
*/

/*
Approach:- DP
    1. Top-down approach: TC:- O(coins.size() * amount)
    2. Bottom-up approach
    3. space optimization not possible

TC: for recusive solution -> O(coins.size()^amount)
SC:- O(amount)
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// top-down approach
int solve(vector<int>& coins, int amount, vector<int> &dp)
{
    if(amount==0) return 0;

    //STEP3: return the answer which already exists in dp array 
    if(dp[amount] != -1) return dp[amount];

    int mini = INT_MAX;
    for(int i=0 ; i<coins.size(); i++)
    {
        if(amount-coins[i] >= 0)
        {
            int aageKaAns = solve(coins, amount-coins[i], dp);
            if(aageKaAns != INT_MAX)
            {
                int ans = 1+aageKaAns;
                mini = min(mini, ans);
            }
        }
    }

    // STEP2: store results in dp array
    dp[amount] = mini;

    return dp[amount];
}

int coinChange(vector<int>& coins, int amount)
{
    //STEP1: create dp array
    vector<int> dp(amount+1, -1);

    int ans = solve(coins, amount, dp);

    return ans==INT_MAX ? -1 : ans;
}


// bottom-up approach
int coinChange1(vector<int> &coins, int amount)
{
    // Step1: create dp array
    vector<int> dp(amount+1, INT_MAX);

    // initialize the dp array using the base case
    dp[0] = 0;

    // fill the remaining dp array using the logic of top-down approach and index kha se kha tak ja rha tha wo bhi dhayan m rakhna bhut zarurui h
    for(int i=1 ; i<=amount ; i++)
    {
        int mini = INT_MAX;
        for(int j=0 ; j<coins.size() ; j++)
        {
            if(i-coins[j] >= 0)//Change
            {
                int aageKaAns = dp[i-coins[j]];
                if(aageKaAns != INT_MAX)
                {
                    int ans = 1+aageKaAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[i] = mini;
    }

    if(dp[amount]==INT_MAX) return -1;

    return dp[amount];
}

int main()
{
    vector<int> coins = {1,2,5};
    int amount = 11;

    cout << coinChange(coins, amount) << endl;

    return 0;
}



