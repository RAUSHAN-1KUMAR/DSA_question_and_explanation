/* -> 684

In this problem, a tree is an undirected graph that is connected and has no cycles.

You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.

Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.



Example 1:
    Input: edges = [[1,2],[1,3],[2,3]]
    Output: [2,3]


Example 2:
    Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
    Output: [1,4]
*/

/*
Approach:- DFS
    -- lets understand the logic:- tree having one additional edge means it is forming a cycle and we have to detect the right most pair which is reason to form cycle so ultimately we have to detect cycle, so we can use DSU

    1. only DFS:- so we are asked to find the right most edge which is forming cycle so what we can do, while forming adjList, on inserting each edge we will do a dfs call to check the addition of currect adge gives us cycle or not, if yes than this edge is our required additional edge

        TC:- O(n^2), we can optimise it by checking path exist between u-v or not before inserting into adjList

    2. DSU:- to detect cycle efficiently
        TC:- O(nlogn) -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// only DFS
bool dfsCycle(int u, int parent, unordered_map<int, vector<int>> &adjList, unordered_map<int,int> &vis)
{
    vis[u]=1;
    for(int v:adjList[u]){
        if(v==parent)continue;
        bool ans=false;
        if(!vis.count(v)){
            ans = dfsCycle(v, u, adjList, vis);
        }
        else{
            ans=true;
        }
        if(ans) return ans;
    }
    return false;
}


// on each addition of new edge, we have to check cycle is present or not
vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    unordered_map<int, vector<int>> adjList;
    vector<int> ans(2);
    unordered_set<int> vertex;
    for(auto &edge:edges)
    {
        // first adding current edge
        int u=edge[0];
        int v=edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);

        vertex.insert(u);
        vertex.insert(v);

        // now checking the current added edge gives cycle or not
        unordered_map<int,int> vis;
        bool isCycle=false;
        for(int num:vertex){
            if(!vis.count(num) && dfsCycle(num, -1, adjList, vis)){
                isCycle=true;
                break;
            }
        }

        if(isCycle){
            ans[0]=u;
            ans[1]=v;
            break;
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> edges={
        {1,2},
        {1,3},
        {2,3}
    };
    vector<int> ans = findRedundantConnection(edges);

    for(int num:ans){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}