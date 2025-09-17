/* -> 3429

You are given an even integer n representing the number of houses arranged in a straight line, and a 2D array cost of size n x 3, where cost[i][j] represents the cost of painting house i with color j + 1.

The houses will look beautiful if they satisfy the following conditions:
    1. No two adjacent houses are painted the same color.

    2. Houses equidistant from the ends of the row are not painted the same color. For example, if n = 6, houses at positions (0, 5), (1, 4), and (2, 3) are considered equidistant.

Return the minimum cost to paint the houses such that they look beautiful.
 

Example 1:
    Input: n = 4, cost = [[3,5,7],[6,2,9],[4,8,1],[7,3,5]]
    Output: 9
    Explanation: The optimal painting sequence is [1, 2, 3, 2] with corresponding costs [3, 2, 1, 3]. This satisfies the following conditions:  
        -  No adjacent houses have the same color.
        -  Houses at positions 0 and 3 (equidistant from the ends) are not painted the same color (1 != 2).
        - Houses at positions 1 and 2 (equidistant from the ends) are not painted the same color (2 != 3).
    The minimum cost to paint the houses so that they look beautiful is 3 + 2 + 1 + 3 = 9.


Example 2:
    Input: n = 6, cost = [[2,4,6],[5,3,8],[7,1,9],[4,6,2],[3,5,7],[8,2,4]]
    Output: 18
    Explanation: The optimal painting sequence is [1, 3, 2, 3, 1, 2] with corresponding costs [2, 8, 1, 2, 3, 2]. This satisfies the following conditions:
        - No adjacent houses have the same color.
        - Houses at positions 0 and 5 (equidistant from the ends) are not painted the same color (1 != 2).
        - Houses at positions 1 and 4 (equidistant from the ends) are not painted the same color (3 != 1).
        - Houses at positions 2 and 3 (equidistant from the ends) are not painted the same color (2 != 3).
    The minimum cost to paint the houses so that they look beautiful is 2 + 8 + 1 + 2 + 3 + 2 = 18.
*/

/*
Approach:- 4D dp
    -- so i have taken two pointer i(0) and j(n-1) and then we have 6 combination to proceed and also i have taken two variable prevI and prevJ to check the adjacent color also, wo i have 4 variable -> TLE = brute force solution

    1. recursive solution
    2. memoization TC:- (4*4*n)

    this will give TLE if i use array for DP, since i have used unoredred_map for DP, all test cases passed

An optmised code -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;


// recursive solution
long long helper(int i, int j, int &n, vector<vector<int>> &cost, int prevI, int prevJ)
{
    if(i>=j){
        return 0LL;
    }

    long long int ans = INT_MAX;

    for(int clri=0 ; clri<3 ; clri++){
        for(int clrj=0; clrj<3; clrj++){
            if(clrj!=clri && clri+1!=prevI && clrj+1!=prevJ)
                ans = min(ans, cost[i][clri]+cost[j][clrj]+helper(i+1, j-1, n, cost, clri+1, clrj+1));
        }
    }

    return ans;
}

long long minCost(int n, vector<vector<int>>& cost)
{
    int i=0;
    int j=n-1;
    int prevI=0;
    int prevJ=0;
    long long ans = helper(i, j, n, cost, prevI, prevJ);

    return ans;
}


// memoization using unordered_map, because unneccesary space may be allocated if i use array
long long helper1(int i, int j, int &n, vector<vector<int>> &cost, int prevI, int prevJ, unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int,long long>>>> &dp)
{
    if(i>=j){
        return 0LL;
    }

    if(dp.count(i) && dp[i].count(j) && dp[i][j].count(prevI) && dp[i][j][prevI].count(prevJ))
        return dp[i][j][prevI][prevJ];

    long long int ans = INT_MAX;

    for(int clri=0 ; clri<3 ; clri++){
        for(int clrj=0; clrj<3; clrj++){
            if(clrj!=clri && clri+1!=prevI && clrj+1!=prevJ)
                ans = min(ans, cost[i][clri]+cost[j][clrj]+helper1(i+1, j-1, n, cost, clri+1, clrj+1, dp));
        }
    }

    dp[i][j][prevI][prevJ]=ans;

    return dp[i][j][prevI][prevJ];
}

long long minCost1(int n, vector<vector<int>>& cost)
{
    int i=0;
    int j=n-1;
    int prevI=0;
    int prevJ=0;

    // 4D dp but space will be taken less
    unordered_map<int, unordered_map<int, unordered_map<int, unordered_map<int,long long>>>> dp;

    long long ans = helper1(i, j, n, cost, prevI, prevJ, dp);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> cost = {
        {3,5,7},
        {6,2,9},
        {4,8,1},
        {7,3,5}
    };
    cout << minCost1(n, cost) << endl;
    return 0;
}