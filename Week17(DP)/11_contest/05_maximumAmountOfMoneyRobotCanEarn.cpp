/* -> 3418

You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

The grid contains a value coins[i][j] in each cell:
    1. If coins[i][j] >= 0, the robot gains that many coins.

    2. If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.

The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

Note: The robot's total coins can be negative.

Return the maximum profit the robot can gain on the route.

 

Example 1:
    Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]
    Output: 8
    Explanation: An optimal path for maximum coins is:
    Start at (0, 0) with 0 coins (total coins = 0).
    Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
    Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
    Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
    Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).

Example 2:
Input: coins = [[10,10,10],[10,10,10]]
Output: 40
Explanation: An optimal path for maximum coins is:
Start at (0, 0) with 10 coins (total coins = 10).
Move to (0, 1), gaining 10 coins (total coins = 10 + 10 = 20).
Move to (0, 2), gaining another 10 coins (total coins = 20 + 10 = 30).
Move to (1, 2), gaining the final 10 coins (total coins = 30 + 10 = 40).
*/

#include<bits/stdc++.h>
using namespace std;

// memoization
int helper(vector<vector<int>>& coins, int i, int j, int k, int &n, int &m, vector<vector<vector<int>>>& dp)
{
    if (i >= n || j >= m) {
        return -1e8; 
    }

    if (i == n - 1 && j == m - 1) {
        if (coins[i][j] < 0) {
            return dp[i][j][k] = (k == 2) ? coins[i][j] : 0;
        }
        return dp[i][j][k] = coins[i][j];
    }

    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    int right = INT_MIN, down = INT_MIN;

    // Right move
    if (coins[i][j] < 0){
        if (k == 2){ // let robber steal
            right = coins[i][j] + helper(coins, i, j + 1, k, n, m, dp);
        } else {
            // Neutralize robber
            right = max(right, helper(coins, i, j + 1, k + 1, n, m, dp));

            // Let robber steal
            right = max(right, coins[i][j] + helper(coins, i, j + 1, k, n, m, dp));

        }
    }else{
        right = coins[i][j] + helper(coins, i, j + 1, k, n, m, dp);
    }

    // Down move
    if (coins[i][j] < 0) {
        if (k == 2) {
            down = coins[i][j] + helper(coins, i + 1, j, k, n, m, dp);
        } else {
            // Neutralize robber
            down = max(down, helper(coins, i + 1, j, k + 1, n, m, dp));

            // Let robber steal
            down = max(down, coins[i][j] + helper(coins, i + 1, j, k, n, m, dp));
        }
    } else {
        down = coins[i][j] + helper(coins, i + 1, j, k, n, m, dp);
    }

    return dp[i][j][k] = max(right, down);
}

int maximumAmount(vector<vector<int>>& coins)
{
    int n = coins.size();
    int m = coins[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));

    return helper(coins, 0, 0, 0, n, m, dp);// i, j, k all zero
}

// an optimised memozation code(include and exclude approach)
int helper1(vector<vector<int>>& coins, int i, int j, int k, int &n, int &m, vector<vector<vector<int>>>& dp)
{
    if (i >= n || j >= m) {
        return -1e8; 
    }

    if (i == n - 1 && j == m - 1) {
        if (coins[i][j] < 0) {
            return dp[i][j][k] = (k == 2) ? coins[i][j] : 0;
        }
        return dp[i][j][k] = coins[i][j];
    }

    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    int takeIt = INT_MIN, notTakeIT = INT_MIN;

    takeIt = coins[i][j] + max(helper1(coins, i+1, j, k, n, m,dp), helper1(coins, i, j+1, k, n, m, dp));

    // not take it only if we have k left and robber is there
    if(k<2 && coins[i][j]<0){
        notTakeIT = max(helper1(coins, i+1, j, k+1, n, m, dp), helper1(coins, i, j+1, k+1, n, m, dp));
    }

    return dp[i][j][k] = max(takeIt, notTakeIT);
}

int maximumAmount1(vector<vector<int>>& coins)
{
    int n = coins.size();
    int m = coins[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, -1)));

    return helper1(coins, 0, 0, 0, n, m, dp);// i, j, k all zero
}

int main()
{
    vector<vector<int>> coins={
        {0,1,-1},
        {1,-2,3},
        {2,-3,4}
    };
    cout << maximumAmount(coins) << endl;
    return 0;
}