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
Approach:-
    Lets first solve it using recursive call for 8 directions or we can say DFS approach recursively-> TLE

    1. Recursive -> TLE

    Memoization will not work because at each position we have 8 directions so each cell's value is dependent on adjacent cell

Lets solve it using BFS-> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

void printDpArray(vector<vector<int>> &dp);

// recursive approach with three states -> TLE
void helper(vector<vector<int>> &grid, int i, int j, int &n, int &m, int &minPath, int pathLength)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1)
        return;

    if(i==n-1 && j==m-1)
    {
        minPath = min(minPath, pathLength);
        return;
    }



    // each call will have 8 directions movement

    grid[i][j]=1;//-> act as true

    int X[] = {-1,-1,-1,0,0,1,1,1};
    int Y[] = {-1,0,1,-1,1,-1,0,1};
    for(int x=0 ; x<8 ; x++)
    {
        helper(grid, i+X[x], j+Y[x], n, m, minPath, pathLength+1);
    }

    // backTrack
    grid[i][j]=0;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid)
{
    int i=0;
    int j=0;
    int n=grid.size();
    int m=grid[0].size();
    int minPath=INT_MAX;
    int pathLength = 1;


    helper(grid, i, j, n, m, minPath, pathLength);

    return minPath==INT_MAX?-1:minPath;
}


// recursive approach with two state -> TLE
int helper1(vector<vector<int>> &grid, int i, int j, int &n, int &m)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==1)
        return INT_MAX;

    if(i==n-1 && j==m-1)
    {
        return 1;
    }


    grid[i][j]=1;

    int ans = INT_MAX;
    int X[] = {-1,-1,-1,0,0,1,1,1};
    int Y[] = {-1,0,1,-1,1,-1,0,1};
    for(int x=0 ; x<8 ; x++)
    {
        int aageKaAns = helper1(grid, i+X[x], j+Y[x], n, m);
        if(aageKaAns!=INT_MAX){
            ans = min(ans, 1+aageKaAns);
        }
    }

    grid[i][j]=0;

    return ans;
}

int shortestPathBinaryMatrix1(vector<vector<int>>& grid)
{
    int i=0;
    int j=0;
    int n=grid.size();
    int m=grid[0].size();


    int ans = helper1(grid, i, j, n, m);

    return ans==INT_MAX?-1:ans;
}

int main()
{
    vector<vector<int>> grid = {
        {0,0,0,0},
        {1,1,0,0},
        {0,0,0,0}
    };

    cout << shortestPathBinaryMatrix1(grid) << endl;

    return 0;
}

