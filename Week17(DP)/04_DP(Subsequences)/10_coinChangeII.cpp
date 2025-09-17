/* -> 518

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

RETURN the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is 'guaranteed' to fit into a signed '32-bit integer'.


Example 1:
    Input: amount = 5, coins = [1,2,5]
    Output: 4
    Explanation: there are four ways to make up the amount:
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1


Example 2:
    Input: amount = 3, coins = [2]
    Output: 0
    Explanation: the amount of 3 cannot be made up just with coins of 2.


Example 3:
    Input: amount = 10, coins = [10]
    Output: 1

*/

/*
Approach:-
    -- apna purana approach: taking my amount from amount->0 and at each function having a for loop on coins to select the coins

Lets solve it using exclude and include -> see next solution

Difference between coin change1 and coin change2
    - In coin change1 we have to return the no. of coins used to make up the amount
    - In coin change2 we have to return the no. of different ways to make up the amount
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int helper(int index, int amount, vector<int> &coins)
{
    // baes case
    if(amount==0) return 1;

    int ans = 0;
    for(int i=index ; i<coins.size(); i++)
    {
        if(coins[i]<=amount)
            ans += helper(i, amount-coins[i], coins);
    }

    return ans;
}

int change(int amount, vector<int>& coins)
{
    int i=0;

    return helper(i, amount, coins);
}


// memoization
int helper1(int index, int amount, vector<int> &coins, vector<vector<int>> &dp)
{
    // baes case
    if(amount==0) return 1;

    if(dp[index][amount] != -1)
        return dp[index][amount];

    int ans = 0;
    for(int i=index ; i<coins.size(); i++)
    {
        if(coins[i]<=amount)
            ans += helper1(i, amount-coins[i], coins, dp);
    }

    dp[index][amount] = ans;

    return ans;
}

int change1(int amount, vector<int>& coins)
{
    int i=0;

    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

    return helper1(i, amount, coins, dp);
}

int main()
{
    vector<int> coins = {2};
    int amount = 0;

    cout << change1(amount, coins) << endl;

    return 0;
}