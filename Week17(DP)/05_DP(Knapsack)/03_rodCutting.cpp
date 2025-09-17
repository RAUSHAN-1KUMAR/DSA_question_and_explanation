/* -> GFG
Given a rod of length n(size of price) inches and an array of prices, 'price'. price[i] denotes the value of a piece of length i. Determine the 'maximum' value obtainable by cutting up the rod and selling the pieces.

Example:
    Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
    Output: 22
    Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

    Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
    Output: 24
    Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24 .

    Input: price[] = [1, 10, 3, 1, 3, 1, 5, 9]
    Output: 40
*/

/*
Approach:- question is similar to unboundKnapsack
    -- lets solve it using exclude and include
*/

#include<bits/stdc++.h>
using namespace std;

// recursive solution
int helper(vector<int> &price,int n, int length)
{
    if(n==0)
    {
        return length*price[0];
    }

    int exclude = 0 + helper(price, n-1, length);

    int include = 0;
    if(n+1<=length)
        include = price[n] + helper(price, n, length-(n+1));

    return max(include, exclude);
}

int cutRod(vector<int> &price)
{
    int length = price.size();

    return helper(price, length-1, length);
}


// memoization
int helper1(vector<int> &price,int n, int length, vector<vector<int>> &dp)
{
    if(n==0)
    {
        return length*price[0];
    }

    if(dp[n][length]!=-1)
        return dp[n][length];

    int exclude = 0 + helper1(price, n-1, length, dp);

    int include = 0;
    if(n+1<=length)
        include = price[n] + helper1(price, n, length-(n+1), dp);

    dp[n][length] = max(include, exclude);

    return dp[n][length];
}

int cutRod1(vector<int> &price)
{
    int length = price.size();

    vector<vector<int>> dp(length, vector<int>(length+1, -1));

    return helper1(price, length-1, length, dp);
}

int main()
{
    vector<int> price = {3,5,8,9,10,17,17,20};
    cout << cutRod1(price) << endl;
    return 0;
}
