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
Approach:- 
    1. Using DFS or BFS:-
        -- precompute the already max island using DFS or BFS
        -- on precomputing we will also store the each cell's maximum island into a map
        -- and then on second traversal while we hit zero, we will just sum the all four directions max value from the map

        TC:- O(n*n)

    2. Using DSU: (DSU by size)
        -- How we can come up with the DSU approach? -> the graph is dynamically changing
        -- in DSU question the main problem is to form the index from given data because the parent is decided as per the number
        -- so to represent the cell with unique number we have: (row, col) -> (n*row + col)

        TC:-  O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;

// Approach1: using DFS
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
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(grid[i][j] == 0) 
            { 
                // no any DFS or BFS call, just check all four direction
                unordered_set<int> st; // we are using set because, what if bottom and right are connected, if it is connected then set will only store the distinct island's id
                
                int A[]={-1,0,1,0};
                int B[]={0,1,0,-1};
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


// Approach2: DSU
class DisjointSet
{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu==pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void printParent(){
        for(int i=0 ; i<parent.size(); i++){
            cout << i << ":" << parent[i] << " ";
        }
        cout << endl;
    }
    
    void printSize(){
        for(int i=0 ; i<size.size(); i++){
            cout << i << ":" << size[i] << " ";
        }
        cout << endl;
    }
};


int largestIslandDSU(vector<vector<int>> &grid)
{
    int n=grid.size();
    DisjointSet ds(n*n);

    // lets connect the adjacent islands
    for(int row=0 ; row<n ; row++)
    {
        for(int col=0 ; col<n ; col++)
        {
            if(grid[row][col]==0) continue;
            
            int dr[] = {-1,0,1,0};
            int dc[] = {0,-1,0,1};
            for(int idx=0 ; idx<4 ; idx++)
            {
                int newr = row+dr[idx];
                int newc = col+dc[idx];
                if((newr>=0 && newc>=0 && newr<n && newc<n) && grid[newr][newc]==1)
                {
                    int currNodeNo = row*n+col;
                    int newNodeNo = newr*n+newc;

                    ds.unionBySize(currNodeNo, newNodeNo);// union by size is must
                }
            }
        }
    }
    

    // now lets form the answer
    int ans=0;
    for(int row=0 ; row<n ; row++)
    {
        for(int col=0 ; col<n ; col++)
        {
            if(grid[row][col]==0)
            {
                set<int> st; // to store distinct islands only

                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int idx=0 ; idx<4 ; idx++)
                {
                    int newr = row+dr[idx];
                    int newc = col+dc[idx];
                    if((newr>=0 && newc>=0 && newr<n && newc<n) && grid[newr][newc]==1)
                    {
                        int newNodeNo = newr*n+newc;
                        st.insert(ds.findPar(newNodeNo));
                    }
                }

                int size=0;
                for(auto it:st){
                    size += ds.size[it];
                }
                ans = max(ans, size+1);
            }
        }
    }

    // this is must, if grid already containing all ones no zeroes
    for(int cellNo = 0 ; cellNo<n*n ; cellNo++){
        ans = max(ans, ds.size[ds.findPar(cellNo)]);
    }

    return ans;
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
    cout << largestIslandDSU(grid) << endl;
    return 0;
}
