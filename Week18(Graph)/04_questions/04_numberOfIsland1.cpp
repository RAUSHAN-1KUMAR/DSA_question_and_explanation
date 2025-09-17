/* -> 200

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
 

Example 1:
    Input: grid = [
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"]
    ]
    Output: 1


Example 2:
    Input: grid = [
        ["1","1","0","0","0"],
        ["1","1","0","0","0"],
        ["0","0","1","0","0"],
        ["0","0","0","1","1"]
    ]
    Output: 3
*/

/*
Approach:-
    1. Using DFS 
*/

#include<bits/stdc++.h>
using namespace std;

// Using DFS
void dfs(int i, int j, vector<vector<bool>> &visited, vector<vector<char>> &grid, int n, int m)
{
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || grid[i][j]=='0')
        return;

    visited[i][j]=true;

    //movements
    dfs(i, j+1, visited, grid, n, m);
    dfs(i+1, j, visited, grid, n, m);
    dfs(i, j-1, visited, grid, n, m);
    dfs(i-1, j, visited, grid, n, m);
}


int numIslands(vector<vector<char>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int islands = 0;
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(grid[i][j]!='0' && !visited[i][j])
            {
                islands++;
                dfs(i, j, visited, grid, n, m);
            }
        }
    }

    return islands;
}


int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','1','0'},
        {'1','1','0','0','1'},
        {'0','0','1','0','1'},
        {'0','0','0','1','1'}
    };

    cout << numIslands(grid) << endl;

    return 0;
}

