/* -> 714

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:
    1. You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
    2. The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:
    Input: prices = [1,3,2,8,4,9], fee = 2
    Output: 8
    Explanation: The maximum profit can be achieved by:
    - Buying at prices[0] = 1
    - Selling at prices[3] = 8
    - Buying at prices[4] = 4
    - Selling at prices[5] = 9
    The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
    Input: prices = [1,3,7,5,10,3], fee = 3
    Output: 6
*/

/*
Approach:-
    -- we just have to do -tran whenever we sell
*/

#include<bits/stdc++.h>
using namespace std;

int helper1(vector<int> &prices, int i, int buy, vector<vector<int>> &dp, int &fee)
{
    if(i>=prices.size()){
        return 0;
    }

    if(dp[i][buy]!=-1)  
        return dp[i][buy];

    int profit=0;
    if(buy==0){
        int buyIt = -prices[i] + helper1(prices, i+1, 1, dp, fee);
        int notBuyIt = 0 + helper1(prices, i+1, 0, dp, fee);
        profit = max(buyIt, notBuyIt);
    }
    else
    {
        int sellIt = prices[i]-fee + helper1(prices, i+1, 0, dp, fee);
        int notSellIt = 0 + helper1(prices, i+1, 1, dp, fee);

        profit = max(sellIt, notSellIt);
    }

    dp[i][buy] = profit;

    return dp[i][buy];
}

int maxProfit(vector<int>& prices, int fee)
{
    int n=prices.size();

    vector<vector<int>> dp(n, vector<int> (2, -1));

    int i=0;

    return helper1(prices, i, 0, dp, fee);
}

// tabulation
int maxProfit1(vector<int> &prices, int fee)
{
    int n=prices.size();

    vector<vector<int>> dp(n+1, vector<int> (2, 0));

    for(int i=n-1 ; i>=0 ; i--){
        for(int buy=0 ; buy<=1 ; buy++){
            int profit=0;
            //buy it
            if(buy==0){
                int buyIt = -prices[i] + dp[i+1][1];

                int notBuyIt = 0 + dp[i+1][0];

                profit = max(buyIt, notBuyIt);
            }
            else// sell it
            {
                int sellIt = prices[i] - fee + dp[i+1][0];

                int notSellIt = 0 + dp[i+1][1];

                profit = max(sellIt, notSellIt);
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][0];
}


int main()
{
    vector<int> prices = {1,3,2,8,4,9};
    int fee=2;
    cout << maxProfit1(prices, fee) << endl;
    return 0;
}