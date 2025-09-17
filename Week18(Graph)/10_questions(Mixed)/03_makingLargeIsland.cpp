/*-> 827

You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:
    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.


Example 2:
    Input: grid = [[1,1],[1,0]]
    Output: 4
    Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.


Example 3:
    Input: grid = [[1,1],[1,1]]
    Output: 4
    Explanation: Can't change any 0 to 1, only one island with area = 4.
*/

/*
Approach:- DFS, we can use BFS as well
    1. Super Brute force:- TLE
        -- just go in each cell and then call DFS
        TC:- greater than O(n^4)
        SC:- O(n^4)

    2. improving brute force:- TLE
        -- precompute the already max island using DFS or BFS
        -- then call DFS for only 0 value cell, and if we get island greater than alreadyMax, than update it
        TC:- O(n^4)
        SC:- O(n^4)

    3. optimal approach:- see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// 2. improved brute force
int dfs(int i, int j, int &n, vector<vector<int>>& grid, vector<vector<bool>>& visited)
{
    if (i < 0 || j < 0 || i >= n || j >= n || (grid[i][j]==0) || visited[i][j]) 
        return 0;

    visited[i][j] = true;

    int count=1;

    count += dfs( i + 1, j, n, grid, visited);
    count += dfs( i - 1, j, n, grid, visited);
    count += dfs( i, j + 1, n, grid, visited);
    count += dfs( i, j - 1, n, grid, visited);

    return count;
}

int largestIsland(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=n;

    // first finding the already max island
    int maxArea = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i = 0; i<m; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] == 1 && !visited[i][j]) {
                int size = dfs(i, j, n, grid, visited);
                maxArea = max(maxArea, size);
            }
        }
    }


    // now checking for each 0 value cell
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(grid[i][j] == 0)// Try converting each 0 to 1 
            { 
                grid[i][j] = 1;
                
                visited = vector<vector<bool>>(n, vector<bool>(n, false));
                
                int size = dfs(i, j, n, grid, visited);
                
                maxArea = max(maxArea, size);

                grid[i][j] = 0; // Backtrack
            }
        }
    }
    
    return (maxArea == 0) ? m * n : maxArea; // If the grid was full of 1s
}


int main()
{
    vector<vector<int>> grid={
        {0,1,0,1,0,0},
        {0,1,0,0,1,0},
        {1,0,1,1,1,1},
        {1,1,0,0,0,0},
        {1,1,0,1,1,1},
        {1,0,1,0,0,1}
    };
    cout << largestIsland(grid) << endl;
    return 0;
}

