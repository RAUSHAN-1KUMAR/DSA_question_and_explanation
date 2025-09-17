/* GFG,  IMP

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island.

Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:
    Input:
    grid[][] = {{1, 1, 0, 0, 0},
                {1, 1, 0, 0, 0},
                {0, 0, 0, 1, 1},
                {0, 0, 0, 1, 1}}
    Output: 1

    Explanation:
    grid[][] = {{1, 1, 0, 0, 0}, 
                {1, 1, 0, 0, 0}, 
                {0, 0, 0, 1, 1}, 
                {0, 0, 0, 1, 1}}
    Same colored islands are equal.
    We have 2 equal islands, so we 
    have only 1 distinct island.


Example 2:
    Input:
    grid[][] = {{1, 1, 0, 1, 1},
                {1, 0, 0, 0, 0},
                {0, 0, 0, 0, 1},
                {1, 1, 0, 1, 1}}
    Output: 3

    Explanation:
    grid[][] = {{1, 1, 0, 1, 1}, 
                {1, 0, 0, 0, 0}, 
                {0, 0, 0, 0, 1}, 
                {1, 1, 0, 1, 1}}
    Same colored islands are equal.
    We have 4 islands, but 2 of them
    are equal, So we have 3 distinct islands.
*/

/*
Approach:- DFS
    -- by using the coordinates of the island, we can store the coordinates in a set and then return the size of the set

TC-> O(n*m*log(n*m))
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j, vector<pair<int,int>> &child, int &n, int &m, int &startR, int &startC)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==2 || grid[i][j]==0){
        return;
    }
        
    grid[i][j]=2;// mark as visited
    child.push_back({i-startR, j-startC}); // store the relative coordinates with respect to the starting point of the island

    dfs(grid, i, j+1, child, n, m, startR, startC);

    dfs(grid, i, j-1, child, n, m, startR, startC);

    dfs(grid, i-1, j, child, n, m, startR, startC);

    dfs(grid, i+1, j, child, n, m, startR, startC);
}

  
int countDistinctIslands(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();
    
    set<vector<pair<int,int>> > st;
    for(int i=0 ; i<n ; i++){ //O(n*m)
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]==1){
                vector<pair<int,int>> child;
                dfs(grid, i, j, child, n, m, i, j);
                st.insert(child); //O(log(n*m))
            }
        }
    }
    
    
    return st.size();
}

int main()
{
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    cout << countDistinctIslands(grid) << endl;

    return 0;
}