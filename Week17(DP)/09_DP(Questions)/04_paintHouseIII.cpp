/* -> 1473

There is a row of m houses in a small city, each house must be painted with one of the n colors (labeled from 1 to n), some houses that have been painted last summer should not be painted again.

A neighborhood is a maximal group of continuous houses that are painted with the same color.
    - For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods [{1}, {2,2}, {3,3}, {2}, {1,1}].

Given an array houses, an m x n matrix cost and an integer target where:
    1. houses[i]: is the color of the house i, and 0 if the house is not painted yet.
    2. cost[i][j]: is the cost of paint the house i with the color j + 1.

Return the minimum cost of painting all the remaining houses in such a way that there are exactly target neighborhoods. If it is not possible, return -1.

 

Example 1:
    Input: houses = [0,0,0,0,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
    Output: 9
    Explanation: Paint houses of this way [1,2,2,1,1]
    This array contains target = 3 neighborhoods, [{1}, {2,2}, {1,1}].
    Cost of paint all houses (1 + 1 + 1 + 1 + 5) = 9.

Example 2:
    Input: houses = [0,2,1,2,0], cost = [[1,10],[10,1],[10,1],[1,10],[5,1]], m = 5, n = 2, target = 3
    Output: 11
    Explanation: Some houses are already painted, Paint the houses of this way [2,2,1,2,2]
    This array contains target = 3 neighborhoods, [{2,2}, {1}, {2,2}]. 
    Cost of paint the first and last house (10 + 1) = 11.

Example 3:
    Input: houses = [3,1,2,3], cost = [[1,1,1],[1,1,1],[1,1,1],[1,1,1]], m = 4, n = 3, target = 3
    Output: -1
    Explanation: Houses are already painted with a total of 4 neighborhoods [{3},{1},{2},{3}] different of target = 3.
*/

/*
Approach:- 3D dp
    -- at each position we have choices on the base upon
        i) if house is already painted last summer
        ii) prev house color

    1. recurive solutin
    2. memoization: TC:-(m*n*m) -> {i,prev,t}
*/

#include<bits/stdc++.h>
using namespace std;

// recursive soltuion
int helper(vector<int> &houses, vector<vector<int>> &cost, int &m, int &n, int i, int prev, int t)
{
    // base cases
    if(t<0) return 1e9;
    if(i>=m){
        if(t==0) return 0;

        return 1e9;
    }

    int ans=1e9;
    if(houses[i]!=0){
        ans = min(ans, ((houses[i]==prev)?helper(houses, cost, m, n, i+1, houses[i], t):helper(houses, cost, m, n, i+1, houses[i], t-1)));
    }
    else{
        for(int p=0 ; p<n; p++){
            if(prev!=p+1){
                ans = min(ans, cost[i][p]+helper(houses, cost, m, n, i+1,p+1,t-1));
            }
            else if(prev==p+1){
                ans = min(ans, cost[i][p]+helper(houses, cost, m, n, i+1, p+1, t));
            }
        }
    }

    return ans;
}

int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
{
    int i=0;// to iterate through the houses
    int prev=0; // to tell previous house color value, initially it is zero which signifies that no house is painted yet
    int t=target; // current neighbouring group

    int ans = helper(houses, cost, m, n, i, prev, t);

    return ans==1e9?-1:ans;
}


// memoization(observe how we have optimised the code for recursive calls)
int helper1(vector<int> &houses, vector<vector<int>> &cost, int &m, int &n, int i, int pClr, int t, vector<vector<vector<int>>> &dp)
{
    // base cases
    if(t<0) return 1e9;
    if(i>=m){
        if(t==0) return 0;

        return 1e9;
    }

    if(dp[i][pClr][t] != -1)
        return dp[i][pClr][t];

    int ans=1e9;
    if(houses[i]!=0)
    {
        ans = min(ans, helper1(houses, cost, m, n, i+1, houses[i], (houses[i]==pClr?t:t-1), dp));
        
        // ans = min(ans, ((houses[i]==pClr)?helper1(houses, cost, m, n, i+1, houses[i], t, dp):helper1(houses, cost, m, n, i+1, houses[i], t-1, dp)));
    }
    else{
        for(int clr=0 ; clr<n; clr++)
        {
            ans = min(ans, cost[i][clr]+helper1(houses, cost, m, n, i+1, clr+1, (pClr!=clr+1?t-1:t), dp));

            // if(pClr!=clr+1){
            //     ans = min(ans, cost[i][clr]+helper1(houses, cost, m, n, i+1,clr+1,t-1, dp));
            // }
            // else if(pClr==clr+1){
            //     ans = min(ans, cost[i][clr]+helper1(houses, cost, m, n, i+1, clr+1, t, dp));
            // }
        }
    }

    dp[i][pClr][t] = ans;

    return dp[i][pClr][t];
}

int minCost1(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target)
{
    int i=0;
    int pClr=0;
    int t=target;

    vector<vector<vector<int>>> dp(m, vector<vector<int>> (n+1, vector<int>(target+1, -1)));

    int ans = helper1(houses, cost, m, n, i, pClr, t, dp);

    return ans==1e9?-1:ans;
}


int main()
{
    vector<int> houses = {3,1,2,3};
    vector<vector<int>> cost = {
        {1,10},
        {10,1},
        {10,1},
        {1,10},
        {5,1}
    };
    int target=3;
    cout << minCost(houses, cost, cost.size(), cost[0].size(), target);
    return 0;
}

