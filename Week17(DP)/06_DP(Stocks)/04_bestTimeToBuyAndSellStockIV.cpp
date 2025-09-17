/* -> 188

You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


Example 1:
    Input: k = 2, prices = [2,4,1]
    Output: 2
    Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.


Example 2:
    Input: k = 2, prices = [3,2,6,5,0,3]
    Output: 7
    Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
*/

/*
Approach:- DP
    -- same as part III, the only difference is that now we have k transactions

    TC:- O(n*2*t)

In this approach, we are decreasing tran-1 when we buy something, OR we can also do tran-1 when we sell something becuase sell can also represent that transaction has been made
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
    if(buy==0 && tran>0){
        int buyIt = -prices[i] + helper(prices, i+1, 1, tran-1);

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

int maxProfit(int k, vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int tran=k;

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
    if(buy==0 && tran>0){
        int buyIt = -prices[i] + helper1(prices, i+1, 1, tran-1,dp);

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

int maxProfit1(int k, vector<int> &prices)
{
    int n=prices.size();

    int i=0;
    int tran=k;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));

    return helper1(prices, i, 0, tran, dp);
}

// tabulation method
int maxProfit2(int k, vector<int> &prices)
{
    int n=prices.size();

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));

    // if(i>=prices.size()){ return 0; }
    for(int buy=0;buy<2;buy++){
        for(int tran=0;tran<=k;tran++){
            dp[n][buy][tran]=0;
        }
    }

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1; buy++){
            for(int tran=0 ; tran<k+1 ; tran++)
            {
                int profit=0;

                //buy it
                if(buy==0 && tran>0){
                    int buyIt = -prices[i] + dp[i+1][1][tran-1];

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

    return dp[0][0][k];
}


// space optimization
int maxProfit3(int k, vector<int> &prices)
{
    int n=prices.size();

    vector<vector<int>> next(2, vector<int>(k+1, 0));
    vector<vector<int>> curr(2, vector<int>(k+1, 0));

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1; buy++){
            for(int tran=0 ; tran<k+1 ; tran++)
            {
                int profit=0;

                //buy it
                if(buy==0 && tran>0){
                    int buyIt = -prices[i] + next[1][tran-1];

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

    return next[0][k];
}


int main()
{
    vector<int> prices = {3,2,6,5,0,3};
    int k=2;
    cout << maxProfit3(k, prices) << endl;
    return 0;
}

