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
    1. Using DFS or BFS:
        -- similar to no. of provinces question, in which index was treated as a vertex. But in this question, each cell would be considered as a vertex

        -- traversing four direction for each cell, and marking true in a visited matrix

DFS -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// Using BFS
bool isPossibleMov(int &row, int &col, int &n, int &m)
{
    if(row<0 || col<0 || row>=n || col>=m)
        return false;

    return true;
}

void bfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int &i, int &j)
{
    int n=grid.size();
    int m=grid[0].size();

    queue<pair<int,int> > que;
    que.push({i,j});
    visited[i][j]=true;

    while(!que.empty())
    {
        auto pos = que.front();
        que.pop();

        int currRow=pos.first;
        int currCol=pos.second;

        // explore all four direction and push it into que if grid[][] = 1 and not visited
        int x[] = {-1,1,0,0}; // up, down, left, right
        int y[] = {0,0,-1,1};

        for(int i=0 ; i<4 ; i++)
        {
            int newRow=currRow+x[i];
            int newCol=currCol+y[i];

            if(isPossibleMov(newRow, newCol, n, m) && !visited[newRow][newCol] && grid[newRow][newCol]=='1')
            {
                visited[newRow][newCol]=true;
                que.push({newRow, newCol});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false)); //-> we can also solve this question by not using visited matrix, How? -> we can use grid[i][j] as '2' means visited

    int regions=0;

    // every cell is considered as vertex, so calling bfs for each cell
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<m ; j++)
        {
            if(grid[i][j]=='1' && !visited[i][j])
            {
                bfs(grid, visited, i, j);
                regions++;
            }
        }
    }

    return regions;
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

