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
    -- include and exclude will be same as we did in coinChangeI, the only difference is that there they asked to return minimum but here the asked to return number of possible ways. SO, we will add the exclude and include -> return (include+exclude)
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int solve(vector<int>& coins, int index, int amount)
{
    // base case
    if(index==0) return (amount%coins[0]==0);

    int exclude = solve(coins, index-1, amount);
    
    int include = 0;
    if(coins[index]<=amount)
        include = solve(coins, index, amount-coins[index]);// we didn't did -> index-1, because each coins can be used infinite times

    return include+exclude;
}

int change(int amount, vector<int>& coins)
{
    int i=coins.size();

    int ans = solve(coins, i-1, amount);

    return ans;
}


// memoization
int solve1(vector<int> &coins, int index, int amount, vector<vector<int>> &dp)
{
    // base case
    if(index==0) return (amount%coins[0]==0);

    if(dp[index][amount] != -1)
        return dp[index][amount];

    int exclude = solve1(coins, index-1, amount, dp);
    
    int include = 0;
    if(coins[index]<=amount)
        include = solve1(coins, index, amount-coins[index], dp);// we didn't did -> n-1, because each coins can be used infinite times

    dp[index][amount] = include+exclude;

    return dp[index][amount];
}

int change1(int amount, vector<int>& coins)
{
    int i=coins.size();

    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

    int ans = solve1(coins, i-1, amount, dp);

    return ans;
}


// tabulation
int change2(int amount, vector<int>& coins)
{
    int i=coins.size();

    vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));

    // initalization of base case: if(index==0) return (amount%coins[0]==0);
    for(int t=0 ; t<=amount ; t++)
    {
        dp[0][t] = (t%coins[0]==0);
    }

    for(int index=1 ; index<i ; index++)
    {
        for(int target=0 ; target<=amount ; target++)
        {

            int exclude = dp[index-1][target];
            
            int include = 0;
            if(coins[index]<=target)
                include = dp[index][target-coins[index]];

            dp[index][target] = include+exclude;
        }
    }

    return dp[i-1][amount];
}


int main()
{
    vector<int> coins = {1,2,5};
    int amount = 5;

    cout << change2(amount, coins) << endl;

    return 0;
}


