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
Approach:- Applying dijkstra
    -- dijkstra uses a data structure to store the minimum distance for each vertex, but here each cell is a vertex so we need 2D array to store the minimum distance for each cell/vertex.
    -- it also uses a set/minHeap to always select the currect min distance wala vertex
    -- return array[n-1][n-1]
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> P;

bool isPossibleMove(int &i, int &j, int &n)
{
    if(i<0 || j<0 || i>=n || j>=n) return false;

    return true;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int n = grid.size();
    if(grid[0][0]==1) return -1;// base case

    // a dist 2D array to store the minimum distance to reach each vertex
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({1, {0,0}});

    dist[0][0]=1;
    grid[0][0]=1;

    while(!pq.empty())
    {
        auto uPair = pq.top();
        pq.pop();

        int currX = uPair.second.first;
        int currY = uPair.second.second;
        int currD = uPair.first;

        int X[] = {-1,-1,-1,0,0,1,1,1};
        int Y[] = {-1,0,1,-1,1,-1,0,1};
        for(int i=0 ; i<8 ; i++)
        {
            int newX = currX + X[i];
            int newY = currY + Y[i];
            if(isPossibleMove(newX, newY, n) && grid[newX][newY]==0 && currD+1<dist[newX][newY])
            {
                grid[newX][newY] = 1;
                pq.push({currD+1, {newX, newY}});
                dist[newX][newY] = currD+1;
            }
        }
    }

    return dist[n-1][n-1]==INT_MAX?-1:dist[n-1][n-1];
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

