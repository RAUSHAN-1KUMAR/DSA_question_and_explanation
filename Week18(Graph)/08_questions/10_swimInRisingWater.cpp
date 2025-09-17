/* -> 778

You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:
    Input: grid = [
                [0,2],
                [1,3]
                ]
    Output: 3
    Explanation: At time 0, you are in grid location (0, 0).
    You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
    You cannot reach point (1, 1) until time 3.
    When the depth of water is 3, we can swim anywhere inside the grid.


Example 2:
    Input: grid = [
            [0, 1, 2, 3, 4],
            [24,23,22,21,5],
            [12,13,14,15,16],
            [11,17,18,19,20],
            [10, 9, 8, 7, 6]
            ]
    Output: 16
    Explanation: We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
*/

/*
Appraoch:
    1. dijkstra algo:
        -- using minHeap to always choose the min elevated cell

        TC: O(n^2log(n^2))
        SC: O(n^2)


    2. DSU
        -- how to think of DSU? -> cells are dynamically connecting as per the elevation time, so we will not proceed form start(0,0) as we did in dijkstra, we will proceed using elevation time, from low to high and then we will check at which time the parent of (0,0) and (n-1, n-1) is same

        TC: O(n^2log(n^2))
        SC: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

// Approach1: dijkstra algo
typedef tuple<int,int,int> Tuple;  

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    priority_queue<Tuple, vector<Tuple>, greater<>> minHeap;
    minHeap.push({grid[0][0], 0, 0}); // time, row, col
    vis[0][0] = true;

    int ansTime = INT_MIN;
    while (!minHeap.empty())
    {
        Tuple t = minHeap.top(); minHeap.pop();
        int currT = get<0>(t), currR = get<1>(t), currC = get<2>(t);

        ansTime = max(ansTime, currT);

        if (currR == n - 1 && currC == n - 1)
            return ansTime;

        int A[] = {1, -1, 0, 0};
        int B[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int newR = currR + A[i];
            int newC = currC + B[i];
            if (newR >= 0 && newC >= 0 && newR < n && newC < n && !vis[newR][newC])
            {
                vis[newR][newC] = true;
                minHeap.push({grid[newR][newC], newR, newC});
            }
        }
    }

    return ansTime;
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


int swimInWaterDSU(vector<vector<int>> &grid)
{
    int n = grid.size();
    if(n==1){
        return grid[0][0];
    }

    // to store all cells with their elevations and sort them
    vector<Tuple> cells;
    for(int r=0 ; r<n ; r++){
        for(int c=0 ; c<n ; c++){
            cells.push_back({grid[r][c], r, c});
        }
    }
    sort(cells.begin(), cells.end()); // to start form lowest elevation

    // Now
    DisjointSet dsu(n*n);
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    int startNode = 0;
    int endNode = n*n-1;
    int dr[] = {-1,1,0,0};
    int dc[] = {0,0,1,-1};

    for(auto &cell:cells) // starting from lowest elevation
    {
        int currT = get<0>(cell), currR = get<1>(cell), currC = get<2>(cell);
        
        int currCellId = currR * n + currC;

        vis[currR][currC] = true;

        // now union with adj and already visited cell
        for(int i=0 ; i<4 ; i++)
        {
            int newR = currR + dr[i];
            int newC = currC + dc[i];

            if(newR >= 0 && newR<n && newC>=0 && newC<n && vis[newR][newC])
            {
                int neighCellId = newR * n + newC;
                dsu.unionBySize(currCellId, neighCellId);
            }
        }

        if(dsu.findPar(startNode) == dsu.findPar(endNode)){
            return currT;
        }
    }

    return -1;
}



int main()
{
    vector<vector<int>> grid = {
        {0,1,2,3,4},
        {24,23,22,21,5},
        {12,13,14,15,16},
        {11,17,18,19,20},
        {10,9,8,7,6}
    };

    cout << swimInWaterDSU(grid) << endl;

    return 0;
}


