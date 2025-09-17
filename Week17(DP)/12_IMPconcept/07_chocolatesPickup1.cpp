/* -> GFG and 1463

You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.

You have two robots that can collect chocolates for you:
    1. Robot #1 is located at the top-left corner (0, 0), and
    2. Robot #2 is located at the top-right corner (0, cols - 1).

Return the maximum number of chocolates collection using both robots by following the rules below:
    - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
    - When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
    - When both robots stay in the same cell, only one takes the chocolates.
    - Both robots cannot move outside of the grid at any moment.
    - Both robots should reach the bottom row in grid.


Example:
    Input: n = 4, m = 3, grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
    Output: 24
    Explanation: Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.

*/

// good code, not TC

#include<bits/stdc++.h>
using namespace std;

// memoization
int helper(int &n, int &m, vector<vector<int>> &grid, int roboi, int roboj1, int roboj2, vector<vector<vector<int> >> &dp)
{
    if(roboi>=n || roboj1<0 || roboj1>=m || roboj2<0 || roboj2>=m){
        return 0;
    }

    if(dp[roboi][roboj1][roboj2]!=-1)
        return dp[roboi][roboj1][roboj2];

    int ans=0;
    for(int j1=-1 ; j1<=1 ; j1++){
        for(int j2=-1 ; j2<=1 ; j2++){
            ans = max(ans, grid[roboi][roboj1] + (roboj1==roboj2 ? 0 : grid[roboi][roboj2]) + helper(n, m, grid, roboi+1, roboj1+j1, roboj2+j2, dp));
        }
    }

    dp[roboi][roboj1][roboj2]=ans;

    return dp[roboi][roboj1][roboj2];
}

int solve(int n, int m, vector<vector<int>> &grid)
{
    int roboi = 0;
    int roboj1 = 0;
    int roboj2 = m-1;

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(m, -1)));

    return helper(n, m, grid, roboi, roboj1, roboj2, dp);
}


// tabulation
int solve1(int n, int m, vector<vector<int>> &grid)
{

    vector<vector<vector<int> > > dp(n, vector<vector<int> >(m, vector<int>(m, -1)));

    for(int roboi=n-1 ; roboi>=0 ; roboi--){
        for(int roboj1=0 ; roboj1<m ; roboj1++){
            for(int roboj2=0 ; roboj2<m ; roboj2++)
            {
                int ans=0;
                for(int j1=-1 ; j1<=1 ; j1++){
                    for(int j2=-1 ; j2<=1 ; j2++){
                        ans = max(ans, grid[roboi][roboj1] + (roboj1==roboj2 ? 0 : grid[roboi][roboj2]) + (roboi+1>=n || roboj1+j1<0 || roboj1+j1>=m || roboj2+j2<0 || roboj2+j2>=m ? 0 : dp[roboi+1][roboj1+j1][roboj2+j2]));
                    }
                }
                dp[roboi][roboj1][roboj2]=ans;
            }
        }
    }

    return dp[0][0][m-1];
}



int main()
{
    vector<vector<int>> grid = {
        // {3,1,1},
        // {2,5,1},
        // {1,5,5},
        // {2,1,1}
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5}
    };

    int n = grid.size();
    int m = grid[0].size();

    cout << solve(n, m, grid) << endl;

    return 0;
}

