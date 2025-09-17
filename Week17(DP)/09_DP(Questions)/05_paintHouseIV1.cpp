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
Approach:- using 3D dp array
    -- same approach as previous one, but removing variable 'j', as j can be determined by n-(i+1)

    TC:- O(4*4*n)

What if we needed tabulation method?? -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

long long helper1(int i, int &n, vector<vector<int>> &cost, int prevI, int prevJ, vector<vector<vector<long long>>> &dp)
{
    if(i>=n/2){
        return 0LL;
    }

    if(dp[i][prevI][prevJ]!=-1)
        return dp[i][prevI][prevJ];

    long long int ans = LLONG_MAX;

    int j=n-i-1;// our j

    for(int clri=0 ; clri<3 ; clri++){
        for(int clrj=0; clrj<3; clrj++){
            if(clrj!=clri && clri+1!=prevI && clrj+1!=prevJ)
                ans = min(ans, cost[i][clri]+cost[j][clrj]+helper1(i+1, n, cost, clri+1, clrj+1, dp));
        }
    }

    dp[i][prevI][prevJ]=ans;

    return dp[i][prevI][prevJ];
}

long long minCost(int n, vector<vector<int>>& cost)
{
    int i=0;
    int prevI=0;
    int prevJ=0;

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(4, vector<long long>(4, -1)));

    long long ans = helper1(i, n, cost, prevI, prevJ, dp);

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
    cout << minCost(n, cost) << endl;
    return 0;
}