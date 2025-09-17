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
    3. optimal approach:-
        -- optimal approach is related to the 2nd improved approach, on that approach we were precomputing to find the already max island, so now on precomputing we will also store the each cell's maximum island into a map
        -- and then on second traversal while we hit zero, we will just sum the all four directions max value from the map

    TC:- O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;

int dfs(int i, int j, int &n, vector<vector<int>>& grid, int &id)
{
    if (i < 0 || j < 0 || i >= n || j >= n || (grid[i][j]!=1)) 
        return 0;

    grid[i][j] = id;// we will mark the currect island as perticular id

    int count=1;

    count += dfs( i + 1, j, n, grid, id);
    count += dfs( i - 1, j, n, grid, id);
    count += dfs( i, j + 1, n, grid, id);
    count += dfs( i, j - 1, n, grid, id);

    return count;
}

int largestIsland(vector<vector<int>>& grid) 
{
    int n=grid.size();
    int m=n;

    // this is the map, to store the cell's max value island
    unordered_map<int,int> mapIsland;
    int island_id=2;//this id will repesent all the connected ones as single entity
    int maxArea = 0;


    // first finding the already max island and also storing each cell's max island in map
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            if(grid[i][j] == 1) 
            {
                int size = dfs(i, j, n, grid, island_id);

                maxArea = max(maxArea, size);

                mapIsland[island_id]=size;// for all the cell which has been marked as island_id, has maximum island as size
                
                island_id++;
            }
        }
    }


    // now checking for each 0 value cell
    int A[]={-1,0,1,0};
    int B[]={0,1,0,-1};
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(grid[i][j] == 0) 
            { 
                // no any DFS or BFS call, just check all four direction
                unordered_set<int> st;

                for(int k=0; k<4 ; k++)// first take out the id's from all four direction
                {
                    int newX=i+A[k];
                    int newY=j+B[k];
                    if(newX>=0 && newY>=0 && newX<n && newY<n && grid[newX][newY]!=0){
                        st.insert(grid[newX][newY]);
                    }
                }

                // now map contains the max value of perticular ids
                int sum=1;
                for(const int &s:st){
                    sum += mapIsland[s];
                }

                maxArea=max(maxArea, sum);
            }
        }
    }
    
    return maxArea;
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

