/* GFG
Problem Statement: You are given an n, m which means the row and column of the 2D matrix, and an array of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.

Note: An island means a group of 1s such that they share a common side. (horizontally or vertically)


Example 1:
    Input Format: n = 4 m = 5 k = 4, A = {{1,1},{0,1},{3,3},{3,4}} 
    Output: 1 1 2 2

Example 2:
    Input Format: n = 4 m = 5 k = 12, A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4}, {3,2}, {2,2},{1,2}, {0,2}} 
    Output: 1 1 2 1 1 2 2 2 3 3 1 1
*/

/*
Note:
    -- in DSU question the main problem is to form the index from given data because the parent is decided as per the number
    -- so to represent the cell with unique number we have: (row, col) -> (n*row + col)
*/

#include<bits/stdc++.h>
using namespace std;


// DSU approach
class DisjointSet
{
    vector<int> rank, parent, size;

public:
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

bool isValid(int &r, int &c, int &n, int &m)
{
    if(r<0 || c<0 || r>=n || c>=m)
        return false;
    return true;
}

vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
{
    DisjointSet ds(n*m);
    vector<vector<int>> vis(n, vector<int> (m, false));
    int cnt=0;
    vector<int> ans;

    for(auto it:operators)
    {
        int row = it[0], col = it[1];

        if(vis[row][col]){
            ans.push_back(cnt);
        }
        else{
            vis[row][col] = true;

            cnt++; // first consider it as distinct island
            
            // Up: row-1, col
            // Right: row, col+1
            // Bottom: row+1, col
            // left: row, col-1
            int dr[] = {-1,0,1,0};
            int dc[] = {0,1,0,-1};
            for(int idx = 0 ; idx<4 ; idx++){
                int newr = row+dr[idx];
                int newc = col+dc[idx];
                if(isValid(newr, newc, n, m) && vis[newr][newc]==true)
                {
                    int currNodeNo = row*m + col;
                    int newNodeNo = newr*m + newc;
                    if(ds.findPar(currNodeNo) != ds.findPar(newNodeNo)){
                        cnt--;
                        ds.unionBySize(currNodeNo, newNodeNo);
                    }
                }
            }

            ans.push_back(cnt);
        }
    }

    return ans;
}

int main()
{
    int n=4, m=5, k=12;
    vector<vector<int>> A = {{0,0},{0,0},{1,1},{1,0},{0,1},{0,3},{1,3},{0,4}, {3,2}, {2,2},{1,2}, {0,2}};

    for(int num:numOfIslands(n, m, A)){
        cout  << num << " ";
    }
    cout << endl;

    return 0;
}


