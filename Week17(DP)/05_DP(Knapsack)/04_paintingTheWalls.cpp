/* 2742
You are given two 0-indexed integer arrays, cost and time, of size n representing the costs and the time taken to paint n different walls respectively. There are two painters available:

    - A paid painter that paints the ith wall in time[i] units of time and takes cost[i] units of money.
    - A free painter that paints any wall in 1 unit of time at a cost of 0. But the free painter can only be used if the paid painter is already occupied.

Return the minimum amount of money required to paint the n walls.

 

Example 1:
    Input: cost = [1,2,3,2], time = [1,2,3,2]
    Output: 3
    Explanation: The walls at index 0 and 1 will be painted by the paid painter, and it will take 3 units of time; meanwhile, the free painter will paint the walls at index 2 and 3, free of cost in 2 units of time. Thus, the total cost is 1 + 2 = 3.

Example 2:
    Input: cost = [2,3,4,2], time = [1,1,1,1]
    Output: 4
    Explanation: The walls at index 0 and 3 will be painted by the paid painter, and it will take 2 units of time; meanwhile, the free painter will paint the walls at index 1 and 2, free of cost in 2 units of time. Thus, the total cost is 2 + 2 = 4.
*/

/*
Approach: include-exclude approach
    -- This is a variation of the knapsack problem where we have two choices: either use the paid painter or the free painter.
    -- We can use recursion with memoization to solve this problem efficiently.
    -- The idea is to keep track of the current wall index and the remaining time units available for painting.
*/

#include<bits/stdc++.h>
using namespace std;

// memoization solution
int helper(int &n, vector<int> &cost, vector<int> &time, int i, int unit, vector<vector<int>> &dp)
{
    // base case
    if(unit==0)
        return 0;
    else if(i>=n)
        return 1e9;

    if(dp[i][unit] != -1)   
        return dp[i][unit];

    int include=cost[i];
    if(time[i]<unit){
        include += helper(n, cost, time, i+1, unit-time[i]-1, dp);
    }

    int exclude = helper(n, cost, time, i+1, unit, dp);

    dp[i][unit]=min(include, exclude);

    return dp[i][unit];
}

int paintWalls(vector<int>& cost, vector<int>& time) 
{
    int n=cost.size();
    int i=0;
    int unit = n; // total walls to be painted

    vector<vector<int>> dp(n+1, vector<int> (unit+1, -1));

    return helper(n, cost, time, i, unit, dp);
}



// tabulation solution
int paintWallsTabulation(vector<int>& cost, vector<int>& time) 
{
    int n = cost.size();
    int unit = n; // total walls to be painted

    vector<vector<int>> dp(n+1, vector<int> (unit+1, -1));

    // initializing the base case
    for(int j=0; j<=unit; j++){
        dp[n][j] = 1e9;
    }

    for(int i=0; i<=n; i++){
        dp[i][0] = 0; // if no time left, cost is 0
    }


    for(int i=n-1; i>=0; i--)
    {
        for(int u=1; u<=unit; u++)
        {
            int include = cost[i];
            if(time[i] < u){
                include += dp[i+1][u-time[i]-1];
            }

            int exclude = dp[i+1][u];

            dp[i][u] = min(include, exclude);
        }
    }

    return dp[0][unit];
}

int main()
{
    vector<int> cost = {2,3,4,2};
    vector<int> time = {1,1,1,1};

    cout << paintWallsTabulation(cost, time) << endl;

    return 0;
}

