/* -> 1091

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
    - All the visited cells of the path are 0.
    - All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).

The length of a clear path is the number of visited cells of this path.

Example 1:
    Input: grid = [[0,1],[1,0]]
    Output: 2


Example 2:
    Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
    Output: 4


Example 3:
    Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
    Output: -1
*/

/*
Approach:- shortest path -> Think for BFS(always work in non-weighted)
    -- First lets understand why DFS gave TLE-> DFS do a depth first search it means it will choose a path and then proceed with it till it reaches its base case and we have 8 another path on each choosed path, so that's why DFS was giving TLE

    -- BFS traversal at once to all direction, so the very first we reach our destination then it will be our shortest path just like we did in 'shortest path in undirected unweighted graph', 
        - so we will reach to our destination fast using BFS as compare to DFS

    -- each cell represent vertex

This question can also be solved using dijkstra -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossibleMove(int &i, int &j, int &n)
{
    if(i<0 || j<0 || i>=n || j>=n) return false;

    return true;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    if(grid[0][0]==1) return -1;// base case
    int n = grid.size();

    // traversing starts from {0,0};
    queue<pair<pair<int, int>, int>> que; //{{pos}, count}
    que.push({{0,0}, 1});

    grid[0][0] = 1;

    while(!que.empty())
    {
        auto uPair = que.front();
        que.pop();

        int currX = uPair.first.first;
        int currY = uPair.first.second;
        int currC = uPair.second;

        if(currX==n-1 && currY==n-1) return currC;

        // all eight direction
        int X[] = {-1,-1,-1,0,0,1,1,1};
        int Y[] = {-1,0,1,-1,1,-1,0,1};
        for(int i=0 ; i<8 ; i++)
        {
            int newX = currX + X[i];
            int newY = currY + Y[i];
            if(isPossibleMove(newX, newY, n) && grid[newX][newY]==0)
            {
                // mark it as visited
                grid[newX][newY] = 1;

                que.push({{newX, newY}, currC+1});
            }
        }
    }

    return -1;
}

int main()
{
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,1,0,0},
        {0,0,0,0},
        {0,0,0,0}
    };

    cout << shortestPathBinaryMatrix(grid) << endl;

    return 0;
}

