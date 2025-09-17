/* -> 64
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example 1:
    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7
    Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.


Example 2:
    Input: grid = [[1,2,3],[4,5,6]]
    Output: 12
*/

/*
Approach:- Question is similar to previous Unique path1

TC: O(2^(n+m)) for recursive solution
TC: O(n*m) for memoization
*/

#include<bits/stdc++.h>
using namespace std;

void dpArrayPrint(vector<vector<int>>& dp)
{
    for(auto vec:dp)
    {
        for(auto num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }
}

// recursive solution
int helper(vector<vector<int>> &grid, int &m, int &n, int row, int col)
{
    // base cases
    if(row==m-1 && col==n-1)
        return grid[row][col];


    int rightMove=INT_MAX;
    if(col+1<n)
        rightMove = grid[row][col] + helper(grid, m, n, row, col+1);

    int downMove=INT_MAX;
    if(row+1<m)
        downMove = grid[row][col] + helper(grid, m, n, row+1, col);

    int mini = min(rightMove, downMove);

    return mini;
}

int minPathSum(vector<vector<int>> &grid)
{
    int row=0;
    int col=0;
    int m=grid.size();
    int n=grid[0].size();

    return helper(grid, m, n, row, col);
}


// top-down(memoization)
int helper1(vector<vector<int>> &grid, int &m, int &n, int row, int col,  vector<vector<int>> &dp)
{
    // base cases
    if(row>=m || col>=n)
        return INT_MAX;
    
    if(row==m-1 && col==n-1)
        return grid[row][col];

    //Step3:
    if(dp[row][col]!=-1)
        return dp[row][col];


    int rightMove = helper1(grid, m, n, row, col+1, dp);
    int downMove = helper1(grid, m, n, row+1, col, dp);

    int mini = min(rightMove, downMove);

    //Step2:
    dp[row][col]=grid[row][col]+mini;

    return dp[row][col];
}

int minPathSum1(vector<vector<int>> &grid)
{
    int row=0;
    int col=0;
    int m=grid.size();
    int n=grid[0].size();

    // Step1:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper1(grid, m, n, row, col, dp);
}


// space optimization
int minPathSum2(vector<vector<int>> &grid)
{
    int m=grid.size();
    int n=grid[0].size();

    vector<int> singleArray(n+1, INT_MAX);
    singleArray[n-1] = grid[m-1][n-1];

    for(int row = m-1 ; row>=0 ; row--)
    {
        for(int col = n-1 ; col>=0 ; col--)
        {
            if(row==m-1 && col==n-1)
                continue;

            int rightMove = singleArray[col+1];
            int downMove = singleArray[col];

            int mini = min(rightMove, downMove);

            singleArray[col]=grid[row][col]+mini;
        }
    }

    return singleArray[0];
}


int main()
{
    vector<vector<int>> grid = {
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };

    cout << minPathSum(grid) << endl;

    return 0;
}