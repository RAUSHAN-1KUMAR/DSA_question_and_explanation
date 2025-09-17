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
    -- The main this is to how can we check the dublicate islands ?
        -- we can do that by storing the path of each island in a string, and then we can use a set to store all unique strings
        -- while traversing the island, we can use a string to store the path, and at the end of each island we can push a special character to mark the end of that island
        -- this way we can get unique strings for each island
        -- and finally return the size of the set which will give us the number of distinct islands

One more approach-> by using the coordinates of the island, we can store the coordinates in a set and then return the size of the set
*/

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int i, int j,
string &child, int &n, int &m)
{
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==2 || grid[i][j]==0){
        child.pop_back();
        return;
    }
        
    grid[i][j]=2;// mark as visited
        
    child.push_back('R');
    dfs(grid, i, j+1, child, n, m);
    
    
    child.push_back('L');
    dfs(grid, i, j-1, child, n, m);
    
    
    child.push_back('U');
    dfs(grid, i-1, j, child, n, m);
    
    
    child.push_back('D');
    dfs(grid, i+1, j, child, n, m);
    
    // IMP, for uniqueness
    child.push_back('B');
}

  
int countDistinctIslands(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=grid[0].size();
    
    set<string> st;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j]==1){
                string child="S";
                dfs(grid, i, j, child, n, m);
                // cout << child << endl; // for debugging
                st.insert(child);
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
