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
Approach:- using 1D dp array
    -- Optimisation is similar to how we did for "Paint House II"

TC:- O(n)
SC:- O(6)
*/

#include<bits/stdc++.h>
using namespace std;

long long minCost(int n, vector<vector<int>>& cost)
{
    int half = n/2;

    // this 1D array will contain the prev selected pairs
    // 0th index => 0(front),1(back) i.e., color(1, 2)
    // 1th index => 0(front),2(back) i.e., color(1, 3)
    // 2th index => 1(front),2(back) i.e., color(2, 3)
    // 3th index => 1(front),0(back) i.e., color(2, 1)
    // 4th index => 2(front),0(back) i.e., color(3, 1)
    // 5th index => 2(front),1(back) i.e., color(3, 2)
    vector<long long> dp(6, 0), temp(6, 0);

    // initialization(first front and back pair)
    dp[0] = cost[0][0] + cost[n-1][1];
    dp[1] = cost[0][0] + cost[n-1][2];
    dp[2] = cost[0][1] + cost[n-1][2];
    dp[3] = cost[0][1] + cost[n-1][0];
    dp[4] = cost[0][2] + cost[n-1][0];
    dp[5] = cost[0][2] + cost[n-1][1];

    // now rest of the half indexes
    for (int i = 1; i < half; ++i) 
    {
        // as for current index i, we are taking pair(0, 1), then we have to exclude the other pairs whose front is 0 or back 1, and that's why we are taking the min of do[2],d[3],dp[4], not all
        temp[0] = min({dp[2], dp[3], dp[4]}) + cost[i][0] + cost[n-i-1][1]; 

        // similarly for these fellows also
        temp[1] = min({dp[3], dp[4], dp[5]}) + cost[i][0] + cost[n-i-1][2]; 
        temp[2] = min({dp[0], dp[4], dp[5]}) + cost[i][1] + cost[n-i-1][2]; 
        temp[3] = min({dp[0], dp[1], dp[5]}) + cost[i][1] + cost[n-i-1][0]; 
        temp[4] = min({dp[0], dp[1], dp[2]}) + cost[i][2] + cost[n-i-1][0]; 
        temp[5] = min({dp[1], dp[2], dp[3]}) + cost[i][2] + cost[n-i-1][1]; 

        // shifting
        dp = temp; 
    }

    return *min_element(dp.begin(), dp.end());
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