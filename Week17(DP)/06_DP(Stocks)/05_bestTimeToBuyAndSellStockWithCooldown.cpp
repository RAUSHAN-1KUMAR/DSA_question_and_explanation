/* -> 309
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:
    Input: prices = [1,2,3,0,2]
    Output: 3
    Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:
    Input: prices = [1]
    Output: 0
*/

/*
Approach:- 
    -- so approach is kind of similar to 'best time to buy annd sell stock II', the only thing diff is that now we also have to also handle two diff possible value of cooldown(0 or 1)

    TC:- O(n*2*2)


Do we really need another variable cooldown ?? 
    -- no, if we sell the index, then next call will go to index+2
    -- clue-> house robber question
*/

#include<bits/stdc++.h>
using namespace std;

// recursion method
int helper(vector<int> &prices, int i, int cd, int b)
{
    if(i>=prices.size()) return 0;

    int ans=0;

    if(cd==1){
        ans = helper(prices, i+1, 0, b);
    }
    else if(b==0){
        int buyit = -prices[i] + helper(prices, i+1, 0, 1);
        int notbuyit = helper(prices, i+1, 0, 0);
        ans = max(buyit, notbuyit);
    }
    else if(b==1){
        int sellit = prices[i] + helper(prices, i+1, 1, 0);
        int notsellit = helper(prices, i+1, 0, 1);
        ans = max(sellit, notsellit);
    }

    return ans;
}

int maxProfit(vector<int> &prices)
{
    int i=0;
    int cd=0;
    int buy=0;
    return helper(prices, i, cd, buy);
}

// memoization1 (with cooldown variable)
int helper1(vector<int> &prices, int i, int cd, int b, vector<vector<vector<int>>> &dp)
{
    if(i>=prices.size()) return 0;

    if(dp[i][b][cd] !=-1){
        return dp[i][b][cd];
    }

    int ans=0;

    if(cd==1){
        ans = helper1(prices, i+1, 0, b, dp);
    }
    else if(b==0){
        int buyit = -prices[i] + helper1(prices, i+1, 0, 1, dp);
        int notbuyit = helper1(prices, i+1, 0, 0, dp);
        ans = max(buyit, notbuyit);
    }
    else if(b==1){
        int sellit = prices[i] + helper1(prices, i+1, 1, 0, dp);
        int notsellit = helper1(prices, i+1, 0, 1, dp);
        ans = max(sellit, notsellit);
    }

    dp[i][b][cd]=ans;

    return dp[i][b][cd];
}

int maxProfit1(vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int cd=0;
    int buy=0;

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(2, -1)));

    return helper1(prices, i, cd, buy, dp);
}


//memoization2 (without cooldown)
int helper2(vector<int> &prices, int i, int b, vector<vector<int>> &dp)
{
    if(i>=prices.size()) return 0;

    if(dp[i][b] !=-1){
        return dp[i][b];
    }

    int ans=0;

    if(b==0){
        int buyit = -prices[i] + helper2(prices, i+1, 1, dp);
        int notbuyit = helper2(prices, i+1, 0, dp);
        ans = max(buyit, notbuyit);
    }
    else if(b==1){
        int sellit = prices[i] + helper2(prices, i+2, 0, dp);
        int notsellit = helper2(prices, i+1, 1, dp);
        ans = max(sellit, notsellit);
    }

    dp[i][b]=ans;

    return dp[i][b];
}

int maxProfit2(vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int buy=0;

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return helper2(prices, i, buy, dp);
}

int main()
{
    vector<int> prices = {1,2,3,0,2};
    cout << maxProfit1(prices) << endl;
    return 0;
}