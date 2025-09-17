/* -> 2316

You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

Return the number of pairs of different nodes that are unreachable from each other.

 

Example 1:
    Input: n = 3, edges = [[0,1],[0,2],[1,2]]
    Output: 0
    Explanation: There are no pairs of nodes that are unreachable from each other. Therefore, we return 0.


Example 2:
    Input: n = 7, edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]
    Output: 14
    Explanation: There are 14 pairs of nodes that are unreachable from each other:
    [[0,1],[0,3],[0,6],[1,2],[1,3],[1,4],[1,5],[2,3],[2,6],[3,4],[3,5],[3,6],[4,6],[5,6]].
    Therefore, we return 14.
*/

/*
Approach:-
    -- This Question can also be solved using BFS or DFS, How-> count the no. of vertex for every disconnected components and then 
        no. of pairs = count*(n-count), n=n-count

    -- DSU:- isme bhi components ka size hi nikalenge using DSU
        - we will take each pair and then form the set, but how can we count the size of components -> we can use map, each time parent will come then we will increment the count-> observe the code below
*/

#include<bits/stdc++.h>
using namespace std;

int find(int u, vector<int> &parent)
{
    if(parent[u]==u)    
        return u;

    return parent[u]=find(parent[u], parent);
}

void Union(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int u_parent = find(u, parent);
    int v_parent = find(v, parent);

    if(u_parent!=v_parent)
    {
        if(rank[u_parent]>rank[v_parent])
        {
            parent[v_parent] = u_parent;
        }
        else if(rank[u_parent]<rank[v_parent])
        {
            parent[u_parent] = v_parent;
        }
        else
        {
            parent[v_parent] = u_parent;
            rank[u_parent] += 1;
        }
    }
}

long long countPairs(int n, vector<vector<int>>& edges)
{
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0 ; i<n ; i++)
    {
        parent[i] = i;
    }

    //Step1: form sets
    for(auto &vec:edges)
    {
        int u=vec[0];
        int v=vec[1];

        // perform union, here we don't need to check parent is same or not, becuase we just have to form the sets till end
        Union(u, v, parent, rank);
    }

    //Step2: using map to count parent
    unordered_map<int, int> mp; // parent, count
    for(int i=0 ; i<n ; i++)
    {
        int i_parent = find(i, parent);

        mp[i_parent]++;
    }


    //Step3: now counting disconnected pairs
    long long result = 0;
    long long remainingNodes=n;
    for(auto &it:mp)
    {
        long long count = it.second;

        result += (count)*(remainingNodes-count);

        remainingNodes -= count;
    }

    return result;
}

int main()
{
    vector<vector<int>> edges = {
        {0,2},
        {0,5},
        {2,4},
        {1,6},
        {5,4}
    };

    int n = 7;

    cout << countPairs(n, edges) << endl;

    return 0;
}

