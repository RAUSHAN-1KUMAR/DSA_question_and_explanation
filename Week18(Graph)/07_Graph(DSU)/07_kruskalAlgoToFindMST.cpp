/*
Spannning Tree: (only for undirected graphs)
    - A tree in which we have N nodes and N-1 edges and all nodes should be reachable from each other i.e., its connected and has no cycle.
    - there can be many possible spanning trees for a single graph.

Minimum Spanning Tree:
    - a spannning tree with the smallest possible total edge weight
*/

/*
kruskal algo
    1. Sort all the given edges w.r.t weight
    2. now start iterating the edges: u---v
        i) if parent of u and v is not same then form edge
        ii) if parent of u and v is same then leave them
*/

#include<bits/stdc++.h>
using namespace std;

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


int spanningTree(int V, vector<vector<int>> &edges)
{
    sort(edges.begin(), edges.end(), [](auto &a, auto &b){
        return a[2] < b[2];
    });

    DisjointSet dsu(V+1);

    int totalMST=0;
    for(auto edge:edges)
    {
        int u=edge[0], v=edge[1], wt=edge[2];

        if(dsu.findPar(u) != dsu.findPar(v)){
            totalMST += wt;
            dsu.unionBySize(u,v);
        }
    }

    return totalMST;
}

int main()
{
    vector<vector<int>> edges = { 
        {0, 1, 2}, 
        {0, 3, 6}, 
        {1, 2, 3}, 
        {1, 3, 8}, 
        {1, 4, 5}, 
        {4, 2, 7}
    };

    int V=5;

    cout << spanningTree(V, edges) << endl;

    return 0;
}

