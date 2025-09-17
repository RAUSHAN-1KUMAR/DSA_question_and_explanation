/* -> 1568

You are given an m x n binary grid grid where 1 represents land and 0 represents water. An island is a maximal 4-directionally (horizontal or vertical) connected group of 1's.

The grid is said to be connected if we have exactly one island, otherwise is said disconnected.

In one day, we are allowed to change any single land cell (1) into a water cell (0).

Return the minimum number of days to disconnect the grid.


Example 1:
    Input: grid = [[0,1,1,0],[0,1,1,0],[0,0,0,0]]
    Output: 2
    Explanation: We need at least 2 days to get a disconnected grid.
    Change land grid[1][1] and grid[0][2] to water and get 2 disconnected island.


    Input: grid = [[1,1]]
    Output: 2
    Explanation: Grid of full water is also disconnected ([[1,1]] -> [[0,0]]), 0 islands.
*/

/*
Approach:-
    Note:- test cases observe kerne ke baad, we got that there will be only three answer in any case, 0 or 1 or 2
        1. if( no_of_islands > 1 || islands == 0) return 0;//-> grid already disconnected h
        Now we have to find the logic for 1 kyunki ager 1 p answer nhi mila to last m 2 return ker denge
        
    -- her ek 1 p jaake usko remove kerke dekhenge ki kya islands ab > 1 h ya nhi, ager kisi ek 1 m answer mil gya to return 1 otherwise return 2.
        But this appraoch for 1 will have large time complexity.

    -- so to optimize the code to find the answer 1, we will use "Targan's algorithm"-> Graph Data stucture
*/

#include<iostream>
#include<vector>
using namespace std;

int m, n;

void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>>& vis)
{
    // base case
    if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || grid[i][j]==0)
    {
        return;
    }

    vis[i][j]=true;

    // RE
    DFS(grid, i+1, j, vis); //-> down
    DFS(grid, i-1, j, vis); //-> up
    DFS(grid, i, j+1, vis); //-> right
    DFS(grid, i, j-1, vis); //-> left
}

int numberOfIslandsUtility(vector<vector<int>> &grid)
{
    int islands = 0;

    // to mark the visited islands
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            if(grid[i][j] == 1 && !vis[i][j])
            {
                DFS(grid,i,j,vis);
                islands++;
            }
        }
    }

    return islands;
}

int minDays(vector<vector<int>>& grid)
{
    m = grid.size();
    n = grid[0].size();

    int islands = numberOfIslandsUtility(grid);

    if((islands>1 || islands == 0))
    {
        return 0;
    }
    else
    {
        // check if we can disconnect the grid in one day
        for(int i=0 ; i<m; i++)
        {
            for(int j=0 ; j<n ; j++)
            {
                if(grid[i][j]==1)
                {
                    grid[i][j]=0; //-> convert to water

                    islands = numberOfIslandsUtility(grid);

                    if(islands > 1 || islands == 0) return 1;

                    grid[i][j]=1; //-> make it land again and now go to try next cell
                }
            }
        }
    }

    // ager na 0 hua na 1 to pakka anser 2 hoga
    return 2;
}

int main()
{
    vector<vector<int>> grid = {
        {0,1,1,0},
        {0,1,1,0},
        {0,0,0,0}
    };

    cout << minDays(grid) << endl;

    return 0;
}