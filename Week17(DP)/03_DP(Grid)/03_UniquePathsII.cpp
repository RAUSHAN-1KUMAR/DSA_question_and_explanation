/* -> 63
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 10^9.


Example 1:
    Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    Output: 2
    Explanation: There is one obstacle in the middle of the 3x3 grid above.
    There are two ways to reach the bottom-right corner:
    1. Right -> Right -> Down -> Down
    2. Down -> Down -> Right -> Right


Example 2:
    Input: obstacleGrid = [[0,1],[0,0]]
    Output: 1
*/


/*
Approach:-
    1. Recursive solution:-
        -- In this question we have same thing as previous question, so we will do the same, we will move both direction at every position
        -- but we will now have one more extra base case, i.e., if any obstable is there return 0;
        -- and also need to rearrange the base cases wisely

        TC:- O(2^(m+n)) = 2^m.2^n => (forEachRow.forEachCOl), because call also goes to right i.e, column
        
        SC:- O(m+n) -> stack space

    2. Top-down approach (memoization)
        TC:- O(m*n)
        SC:- O(m+n)+O(m*n)

    3. Bottom-up approach (tabulation)
        TC:- O(m*n)
        SC:- O(m*n)

    4. Space optimzation:- Not done, but can be done...
        TC:- O(m*n)
        SC:- O(n) -> singleArray
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
int helper(vector<vector<int>>& obstacleGrid, int &m, int &n, int row, int col)
{
    // base cases
    if(row>=m || col>=n)
        return 0;
    if(obstacleGrid[row][col]==1) 
        return 0; // one more extra case
    if(row==m-1 && col==n-1)
        return 1;

    // move right and left
    int rightMov = helper(obstacleGrid, m, n, row, col+1);
    int downMov = helper(obstacleGrid, m, n, row+1,col);

    return rightMov+downMov;
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    int row=0;
    int col=0;
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    return helper(obstacleGrid, m, n, row, col);
}


// memoization
int helper1(vector<vector<int>>& obstacleGrid, int &m, int &n, int row, int col, vector<vector<int>> &dp)
{
    if(row>=m || col>=n)
        return 0;
    if(obstacleGrid[row][col]==1) return 0; // one more extra case
    if(row==m-1 && col==n-1)
        return 1;

    //Step3:
    if(dp[row][col]!=-1)
        return dp[row][col];

    int rightMov = helper1(obstacleGrid, m, n, row, col+1, dp);
    int downMov = helper1(obstacleGrid, m, n, row+1,col, dp);


    //Step2:
    dp[row][col]=rightMov+downMov;

    return dp[row][col];
}

int uniquePathsWithObstacles1(vector<vector<int>>& obstacleGrid)
{
    int row=0;
    int col=0;
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    // Step1:
    vector<vector<int>> dp(m, vector<int>(n, -1));

    return helper1(obstacleGrid, m, n, row, col, dp);
}


// tabulation method
int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid)
{
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();

    // Step1:
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Step2: if(row==m-1 && col==n-1) return 1;
    dp[m-1][n-1]=1;

    //Step3
    for(int row=m-1 ; row>=0 ; row--)
    {
        for(int col=n-1 ; col>=0 ; col--)
        {
            if(obstacleGrid[row][col]==1)
            {
                dp[row][col]=0;
                continue;
            }

            if(row==m-1 && col==n-1) // catch condition
                continue;

            int rightMov = dp[row][col+1];
            int downMov = dp[row+1][col];

            dp[row][col]=rightMov+downMov;
        }
    }

    // print dp array
    dpArrayPrint(dp);

    return dp[0][0];
}


int main()
{
    vector<vector<int>> obstacleGrid ={
        {0,0,0},
        {0,1,0},
        {0,0,1}
    };

    cout << uniquePathsWithObstacles2(obstacleGrid) << endl;

    return 0;
}