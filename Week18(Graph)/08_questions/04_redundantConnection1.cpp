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
Approach:- DSU
    2. DSU:- to detect cycle efficiently 
        -- we will form the DSU and in any uncomming edge, if that u and v both already in our DSU i.e., if parent of u and v are same then it means cycle now this edge will form cycle and this is our required answer

        TC:- O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

// using DSU
int findParent(int ele, vector<int> &parent)
{
    if(parent[ele]==ele) 
        return ele;

    return parent[ele]=findParent(parent[ele], parent);
}


void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = findParent(x, parent);
    int y_parent = findParent(y, parent);

    // we are assigning parent on the basis of their rank
    if(x_parent!=y_parent)
    {
        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else // rank is same
        {
            // choose any one
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
}


// on each addition of new edge, we have to check cycle is present or not
vector<int> findRedundantConnection(vector<vector<int>>& edges) 
{
    int n=edges.size();

    vector<int> parent(n+1);
    vector<int> rank(n+1, 0);

    for(int i=1 ; i<=n ; i++){
        parent[i]=i;
        rank[i]=0;
    }

    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        if(findParent(u, parent)==findParent(v, parent)){
            return edge;
        }
        Union(u, v, parent, rank);
    }

    return {};
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

