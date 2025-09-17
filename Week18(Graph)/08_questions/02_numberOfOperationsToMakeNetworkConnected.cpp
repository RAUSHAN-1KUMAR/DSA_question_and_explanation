/* -> 1319

There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.



Example 1:
    Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    Output: 1
    Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


Example 2:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
    Output: 2


Example 3:
    Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
    Output: -1
    Explanation: There are not enough cables.
*/


/*
Approach:-
    1. How to get intuition that this question will be solve using DSU??
        -- we can see that we have connectivity between vertex and we have already given a set of connections and we just have to combine other vertex(set) into it by removing one connections
        -- So we can think of applying DSU here becuase DSU will take minimum cable to connect those network/vertex, 
        -- first we will count all the connections already there, and then we will apply DSU to again connect those and if cable count is exhausted we can't connect them

Approach1: Traversing each given connection to count how many vertex are connected and how many are left, and than if 
    i) cableCount < min_edge_req to connect all vertes(n-1) -> return -1
    ii) else return (no of disconnected vertex)

Approach2: 
    i) we are gonna count the extra edges, using DSU
    ii) and then we will find out the no. of disconnected components using parent array
    iii) if(no. of disconn comp > extra edges) return -1
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

// approach1
int makeConnected(int n, vector<vector<int>>& connections)
{
    // cableCount = no. of edges
    int cableCount = connections.size();

    // catch case
    if(cableCount < n-1) return -1;

    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0 ; i<n ; i++){
        parent[i] = i;
    }

    // now lets use the cable count to again combine them
    int components = n; // total vertex left to connect
    for(auto &vec:connections)
    {
        // we need to check the parent before performing union
        int u_parent = find(vec[0], parent);
        int v_parent = find(vec[1], parent);

        // if parent is not same then take union and decrement the components count
        if(u_parent != v_parent)
        {
            Union(vec[0], vec[1], parent, rank);
            components--;
        }
    }

    return components-1;
}

// Approach2:
int makeConnected1(int n, vector<vector<int>>& connections)
{
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0 ; i<n ; i++){
        parent[i] = i;
    }

    //1. now lets use DSU to count extra edges
    int extraEdges=0;
    for(auto &vec:connections)
    {
        // we need to check the parent before performing union
        int u_parent = find(vec[0], parent);
        int v_parent = find(vec[1], parent);

        // if parent is not same then take union
        if(u_parent != v_parent){
            Union(vec[0], vec[1], parent, rank);
        }
        else{
            extraEdges++;
        }
    }

    // find no. of disconnected component
    int discon = 0 ; 
    for(int i=0 ; i<n ; i++){
        if(parent[i] == i) discon++;
    }

    return (discon-1 <= extraEdges ? discon-1 : -1);
}


int main()
{
    vector<vector<int>> connections = {
        {0,1},
        {0,2},
        {1,2}
    };
    int n = 4;

    cout << makeConnected(n, connections) << endl;

    return 0;
}

