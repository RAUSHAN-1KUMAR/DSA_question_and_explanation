/* It is a MSSP (multiple source shortest path)

MSSP means we are going to find the distance from each of the vertex to all vertex unlike dijkstra or bellman ford in which we were calculating distance from a single source node to all vertex.

This algo is applicable to directed/undirected/acyclic/cyclic graph.

Not applicable to negative weight cycles and thus helps us to detect negative cycle in graph.

TC:- O(V^3)
*/

/*
How we can detect negative wight cycle using floyd Warshall??:- if after computing floyd warshall we have a negative value at (v---v) vertex i.e., diagonal elements is negative it means cycle is negative.
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int,int>> > adjList;

    void addEdge(int u, int v, int wt, bool direction)
    {
        if(direction==0)
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else if(direction==1)
        {
            adjList[u].push_back({v, wt});
        }
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << ": {";
            for(auto list:i.second)
            {
                cout << "{" << list.first << "," << list.second << "}";
            }
            cout << "}" << endl;
        }
    }

    void floydWarshall(int n)
    {
        // initial state
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        // initializing dist
            // 1. v--v = 0
        for(int i=0 ; i<n ; i++){
            dist[i][i]=0;
        }
            // 2. also updating from the adjlist
        for(auto uPair:adjList)
        {
            int u = uPair.first;
            for(auto vPair:uPair.second)
            {
                int v = vPair.first;
                int u_v_dist = vPair.second;

                dist[u][v] = u_v_dist;
            }
        }


        // now floydWarshall
        for(int helper=0 ; helper<n ; helper++)
        {
            for(int src=0 ; src<n ; src++)
            {
                for(int dest=0 ; dest<n ; dest++)
                {
                    if(dist[src][helper]!=1e9 && dist[helper][dest]!=1e9)
                        dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
                }
            }
        }


        // printing distance
        for(int i=0 ; i<n ; i++){
            cout << "Source is " << i << ": ";
            for(int j=0 ; j<n ; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }

};


int main()
{
    Graph g;
    g.addEdge(0, 1, 3, 1);
    g.addEdge(1, 0, 2, 1);
    g.addEdge(0, 3, 5, 1);
    g.addEdge(1, 3, 4, 1);
    g.addEdge(3, 2, 2, 1);
    g.addEdge(2, 1, 1, 1);

    g.printAdList();

    g.floydWarshall(4);

    return 0;
}

