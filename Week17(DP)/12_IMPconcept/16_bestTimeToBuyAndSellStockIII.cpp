/* -> 123

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:
    Input: prices = [3,3,5,0,0,3,1,4]
    Output: 6
    Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
    Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.


Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.


Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

/*
Approach:- DP
    -- same as part II, with one more variable paramter called transaction -> 3D

    TC:- O(n*2*2)
*/

#include<bits/stdc++.h>
using namespace std;

// recursive
int helper(vector<int> &prices, int i, int buy, int tran)
{
    if(i>=prices.size()){
        return 0;
    }
    
    int profit=0;

    //buy it
    if(buy==0 && tran<2){
        int buyIt = -prices[i] + helper(prices, i+1, 1, tran+1);

        int notBuyIt = 0 + helper(prices, i+1, 0, tran);

        profit = max(buyIt, notBuyIt);
    }
    else if(buy!=0)// sell it
    {
        int sellIt = prices[i] + helper(prices, i+1, 0, tran);

        int notSellIt = 0 + helper(prices, i+1, 1, tran);

        profit = max(sellIt, notSellIt);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int tran=0;

    return helper(prices, i, 0, tran);
}

// memoization
int helper1(vector<int> &prices, int i, int buy, int tran, vector<vector<vector<int>>> &dp)
{
    if(i>=prices.size()){
        return 0;
    }

    if(dp[i][buy][tran]!=-1){
        return dp[i][buy][tran];
    }

    int profit=0;

    //buy it
    if(buy==0 && tran<2){
        int buyIt = -prices[i] + helper1(prices, i+1, 1, tran+1,dp);

        int notBuyIt = 0 + helper1(prices, i+1, 0, tran,dp);

        profit = max(buyIt, notBuyIt);
    }
    else if(buy!=0)// sell it
    {
        int sellIt = prices[i] + helper1(prices, i+1, 0, tran,dp);

        int notSellIt = 0 + helper1(prices, i+1, 1, tran,dp);

        profit = max(sellIt, notSellIt);
    }

    dp[i][buy][tran] = profit;

    return dp[i][buy][tran];
}

int maxProfit1(vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int tran=0;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return helper1(prices, i, 0, tran, dp);
}

// tabulation method
int maxProfit2(vector<int> &prices)
{
    int n=prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));

    // if(i>=prices.size()){ return 0; }
    for(int buy=0;buy<2;buy++){
        for(int tran=0;tran<3;tran++){
            dp[n][buy][tran]=0;
        }
    }

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1; buy++){
            for(int tran=0 ; tran<=2 ; tran++)
            {
                int profit=0;

                //buy it
                if(buy==0 && tran<2){
                    int buyIt = -prices[i] + dp[i+1][1][tran+1];

                    int notBuyIt = 0 + dp[i+1][0][tran];

                    profit = max(buyIt, notBuyIt);
                }
                else if(buy!=0)// sell it
                {
                    int sellIt = prices[i] + dp[i+1][0][tran];

                    int notSellIt = 0 + dp[i+1][1][tran];

                    profit = max(sellIt, notSellIt);
                }

                dp[i][buy][tran] = profit;
            }
        }
    }

    return dp[0][0][0];
}


// space optimization
int maxProfit3(vector<int> &prices)
{
    int n=prices.size();

    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1; buy++){
            for(int tran=0 ; tran<=2 ; tran++)
            {
                int profit=0;

                //buy it
                if(buy==0 && tran<2){
                    int buyIt = -prices[i] + next[1][tran+1];

                    int notBuyIt = 0 + next[0][tran];

                    profit = max(buyIt, notBuyIt);
                }
                else if(buy!=0)// sell it
                {
                    int sellIt = prices[i] + next[0][tran];

                    int notSellIt = 0 + next[1][tran];

                    profit = max(sellIt, notSellIt);
                }

                curr[buy][tran] = profit;
            }
        }

        next = curr;
    }

    return next[0][0];
}


int main()
{
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << maxProfit3(prices) << endl;
    return 0;
}

