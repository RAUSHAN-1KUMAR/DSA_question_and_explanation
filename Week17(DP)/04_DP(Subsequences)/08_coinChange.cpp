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
Approach:- We have already solved in 1D Week, by taking a loop for coins on each amount
    -- lets solve it by using exclude and include -> 2D

Note:- observe the recursion code, because in this code we are iterating from last of the coins array to first and also having different base casess
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void printdpArray(vector<vector<int>> &dp);

// recursive solution
int solve(vector<int>& coins, int n, int amount)
{
    // base case
    if(amount==0) return 0;
    if(n==0)
    {
        if(amount%coins[n]==0) return amount/coins[n];

        return 1e9;
    }

    int exclude = 0 + solve(coins, n-1, amount);
    
    int include = INT_MAX;
    if(coins[n]<=amount)
        include = 1 + solve(coins, n, amount-coins[n]);// we didn't did -> n-1, because each coins can be used infinite times

    return min(exclude, include);
}

int coinChange(vector<int>& coins, int amount)
{
    int i=coins.size();

    int ans = solve(coins, i-1, amount);

    return ans==INT_MAX ? -1 : ans;
}


// memoization
int solve1(vector<int>& coins, int n, int amount, vector<vector<int>> &dp)
{
    // base case
    if(amount==0) return 0;
    if(n==0)
    {
        if(amount%coins[n]==0) return amount/coins[n];

        return 1e9;
    }

    //Step3
    if(dp[n][amount] != -1)
        return dp[n][amount];

    int exclude = 0 + solve1(coins, n-1, amount, dp);
    
    int include = INT_MAX;
    if(coins[n]<=amount)
        include = 1 + solve1(coins, n, amount-coins[n], dp);

    // Step2
    dp[n][amount] = min(exclude, include);

    return dp[n][amount];
}

int coinChange1(vector<int>& coins, int amount)
{
    int i=coins.size();

    // Step1:
    vector<vector<int>> dp(i, vector<int>(amount+1, -1));

    int ans = solve1(coins, i-1, amount, dp);

    return ans==INT_MAX ? -1 : ans;
}


// tabulation
int coinChange2(vector<int>& coins, int amount)
{
    int i=coins.size();

    // Step1:
    vector<vector<int>> dp(i, vector<int>(amount+1, -1));

    // Step2: initialization using base case
    // if(amount==0) return 0;
    for(int row=0 ; row<i ; row++)
        dp[row][0]=0;

    // if(n==0)
    for(int col=1 ; col<=amount ; col++)
    {
        if(col%coins[0]==0) dp[0][col] = col/coins[0];
        else dp[0][col] = 1e9;
    }

    // printdpArray(dp);

    //Step3
    for(int n=1 ; n<=i-1 ; n++)
    {
        for(int amt=1 ; amt<=amount ; amt++)
        {
            int exclude = 0 + dp[n-1][amt];
            
            int include = INT_MAX;
            if(coins[n]<=amt)
                include = 1 + dp[n][amt-coins[n]];

            dp[n][amt] = min(exclude, include);
        }
    }

    // printdpArray(dp);

    return dp[i-1][amount]==INT_MAX ? -1 : dp[i-1][amount];
}


int main()
{
    vector<int> coins = {3,2,5,6};
    int amount = 8;

    cout << coinChange2(coins, amount) << endl;

    return 0;
}



void printdpArray(vector<vector<int>> &dp)
{
    for(auto vec:dp)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}



