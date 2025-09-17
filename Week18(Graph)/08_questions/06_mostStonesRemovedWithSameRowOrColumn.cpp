/* 947

On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

Example 1:
    Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
    Output: 5
    Explanation: One way to remove 5 stones is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,1].
    2. Remove stone [2,1] because it shares the same column as [0,1].
    3. Remove stone [1,2] because it shares the same row as [1,0].
    4. Remove stone [1,0] because it shares the same column as [0,0].
    5. Remove stone [0,1] because it shares the same row as [0,0].
    Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.

Example 2:
    Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
    Output: 3
    Explanation: One way to make 3 moves is as follows:
    1. Remove stone [2,2] because it shares the same row as [2,0].
    2. Remove stone [2,0] because it shares the same column as [0,0].
    3. Remove stone [0,2] because it shares the same row as [0,0].
    Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.

Example 3:
    Input: stones = [[0,0]]
    Output: 0
    Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
*/

/*
Approach1: using DFS, to count groups
    -- using DFS and set to count the groups

    TC: O(n^2)

Approach2: using DSU, to count groups
    -- how we are gonna represent the coordinates in DSU?, because in DSU we use a single value to represent a node: So in 2D matrix we are gonna use the row index for row node, and for column node we will shift our column index for n+0, n+1, n+2 to 2n

    TC:O(n)
    
*/

#include <bits/stdc++.h>
using namespace std;

// Approach1
int dfs(vector<int> &currStone, vector<vector<int>> &stones, set<vector<int>> &st)
{ // exploring all stones connected to the current stone

    int ans = 0;

    // iterate through all stones to find connected stones
    for (auto &newStone : stones)
    {
        // if the newStone is not visited AND it shares the same row or column
        if(st.count(newStone) == 0 && (currStone[0] == newStone[0] || currStone[1] == newStone[1]))
        {
            st.insert(newStone); // mark it visited

            // count the stone and recursively explore its connection
            ans += 1 + dfs(newStone, stones, st);
        }
    }

    return ans;
}


int removeStones(vector<vector<int>> &stones)
{
    // using set to keep track of visited stones
    set<vector<int>> st;

    int ans = 0;
    for (auto &stone : stones) 
    { // try starting DFS from each unvisited stone
        vector<int> currentStone = stone;
        if (st.count(currentStone) == 0)
        {
            st.insert(currentStone); // mark it visited

            // perfome DFS to count how many stones can be removed in this group
            ans += dfs(currentStone, stones, st);
        }
    }

    return ans;
}



// Approach2
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 1);
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

int removeStonesDSU(vector<vector<int>> &stones)
{
    // first we need to figure out the dimentions
    int maxRow=0;
    int maxCol=0;
    for(auto &it:stones){
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet dsu(maxRow+maxCol+1);

    unordered_set<int> availableNode;
    for(auto it:stones)
    {
        int nodeRow = it[0];
        int nodeCol = it[1]+maxRow+1;

        dsu.unionBySize(nodeRow, nodeCol);

        availableNode.insert(nodeRow);
        availableNode.insert(nodeCol);
    }

    int ans=0;
    for(int node:availableNode){
        if(dsu.findPar(node) == node){
            ans++;
        }
    }

    return stones.size() - ans;
}



int main()
{
    vector<vector<int>> stones = {
        {0, 0},
        {2, 2},
        {0, 2},
        {1, 1},
        {3, 3},
        {3, 5},
        {4, 5}
    };

    cout << removeStonesDSU(stones) << endl;

    return 0;
}
