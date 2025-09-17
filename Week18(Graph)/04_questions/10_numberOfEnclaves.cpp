/* -> 1020

You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:
    Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 3
    Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

Example 2:
    Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
    Output: 0
    Explanation: All 1s are either on the boundary or can reach the boundary.
*/

/*
Approach:-
    -- same as previous one
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, int &n, int &m){
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || grid[i][j]==2) return;

    grid[i][j]=2;

    dfs(grid, i+1, j, n, m);
    dfs(grid, i-1, j, n, m);
    dfs(grid, i, j+1, n, m);
    dfs(grid, i, j-1, n, m);
}

int numEnclaves(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();

    // first converting connected corners 'O' -> '#' using dfs
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            if((i==0 || i==n-1) && grid[i][j]==1){
                dfs(grid, i, j, n, m);
            }
            else if((j==0 || j==m-1) && grid[i][j]==1){
                dfs(grid, i, j, n, m);
            }
        }
    }

    // then coverting all left 'O' to 'X' and '#' to 'O'
    int ans=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0; j<m ; j++){
            if(grid[i][j]==1){
                ans++;
            }
        }
    } 

    return ans;
}


int main()
{
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << numEnclaves(grid) << endl;

    return 0;
}



