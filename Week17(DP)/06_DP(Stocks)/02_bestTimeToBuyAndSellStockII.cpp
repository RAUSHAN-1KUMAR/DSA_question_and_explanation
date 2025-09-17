/* -> 122

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.


Example 1:
    Input: prices = [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
    Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Total profit is 4 + 3 = 7.

Example 2:
    Input: prices = [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
    Total profit is 4.


Example 3:
    Input: prices = [7,6,4,3,1]
    Output: 0
    Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.
*/

/*
Approach:-
    1. recursive:-
        -- we have two options at each recursive call
            i) buy(but only if previously not buied)
                a) buy it
                b) not buy it

            ii) sell(but only if previous action was buy)
                a) sell it
                b) not sell it

        - but in doing so, we will have two changing variable into the recurisive call, it means while while applying dp it would be -> O(n^2): TLE, so What we do
        - we can use a varable buy: it it is 0 then it means we can buy it and it it is 1 then it means we can sell the stock

        TC:- O(n*2) while applying memoization

Greedy approach with O(n) -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
int helper(vector<int> &prices, int i, int buy)
{
    if(i>=prices.size()){
        return 0;
    }

    int profit=0;

    //buy it
    if(buy==0){
        int buyIt = -prices[i] + helper(prices, i+1, 1);

        int notBuyIt = 0 + helper(prices, i+1, 0);

        profit = max(buyIt, notBuyIt);
    }
    else// sell it
    {
        int sellIt = prices[i] + helper(prices, i+1, 0);

        int notSellIt = 0 + helper(prices, i+1, 1);

        profit = max(sellIt, notSellIt);
    }

    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n=prices.size();

    int i=0;

    return helper(prices, i, 0);
}


// memoization
int helper1(vector<int> &prices, int i, int buy, vector<vector<int>> &dp)
{
    if(i>=prices.size()){
        return 0;
    }

    if(dp[i][buy]!=-1)  
        return dp[i][buy];

    int profit=0;

    //buy it
    if(buy==0){
        int buyIt = -prices[i] + helper1(prices, i+1, 1, dp);

        int notBuyIt = 0 + helper1(prices, i+1, 0, dp);

        profit = max(buyIt, notBuyIt);
    }
    else// sell it
    {
        int sellIt = prices[i] + helper1(prices, i+1, 0, dp);

        int notSellIt = 0 + helper1(prices, i+1, 1, dp);

        profit = max(sellIt, notSellIt);
    }

    dp[i][buy] = profit;

    return dp[i][buy];
}

int maxProfit1(vector<int> &prices)
{
    int n=prices.size();

    vector<vector<int>> dp(n, vector<int> (2, -1));

    int i=0;
    return helper1(prices, i, 0, dp);
}


// tabulation method
int maxProfit2(vector<int> &prices)
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
                int sellIt = prices[i] + dp[i+1][0];

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
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit2(prices) << endl;
    return 0;
}

