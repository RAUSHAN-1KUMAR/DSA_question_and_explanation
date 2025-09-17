/* it is a SSSP (single source shortest path)

This algo is applicable to directed/undirected/acyclic/cyclic/weighted/unweighted graph.

The only constraint is that weight must be a positive integer and there should not be any negative cycle.

Uses an additional Data structure to get the min at O(1) -> set/minHeap.

*/


/*
Approach:- It follows a greedy algo niether BFS or DFS
    -- greedy to always take the current min distance node, for this we can use set or minHeap as well.(using set would require less no. of iterations as compared to minHeap, because find() can be done in set to update the already computed vertex)
    -- in previous question, we were using topoStack to pick the zero indegree node first i.e., greedy to zero indegree node so that's why we didn't used any set or minHeap there.
    -- set will contain the <dist, node> 

SO we can say that:-
    1. Dijkstra algo may or may not work in case of negative edge 
    2. Dijkstra algo definitely will not work in case of negative weight cycle -> stuck in infinite loop

TC:- O(ElogV)

Using set -> see next solution
*/


/*
Can we use queue instead of set or minHeap?
    -- yes, we can use queue as well, but it will take O(V) time to get the min distance node, so it will take O((V+E)V) time which is not efficient.
    -- so we are using set or minHeap to get the min distance node in O(logV) time.
*/


#include<bits/stdc++.h>
using namespace std;

// declared template T
template <typename T>

class Graph
{
public:
    unordered_map<T, list<pair<T,int>> > adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        // direction=1 => directed
        if(direction==1)
        {
            adjList[u].push_back({v,wt});
        }

        // direction=0 => undirected
        if(direction==0)
        {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
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

    void dijkstraShortestDistance(int n, T src, T dest)
    {
        vector<T> dist(n, INT_MAX); // distance array to store the minDistance at every reach

        priority_queue<pair<int,T>, vector<pair<int,T>>, greater<pair<int,T>>> pq; // minHeap to get the min distance node
        pq.push({0, src});
        dist[src]=0;

        while(!pq.empty()){
            auto top=pq.top(); pq.pop();

            int u=top.second;
            int u_dist=top.first;

            // this is not required in case of set, becuase in set we have find function to check if the node is already present or not
            if(u_dist > dist[u])
                continue;

            for(auto &vPair:adjList[u])
            {
                T v = vPair.first;
                int u_v_dist = vPair.second;

                if(u_dist + u_v_dist < dist[v]){
                    dist[v]=u_dist + u_v_dist;
                    pq.push({dist[v], v}); // push the updated distance of v into the min
                }
            }
        }


        // printing
        cout << "shortest distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
    }
};




int main()
{
    // specified the type name of T
    Graph<int> g;
    g.addEdge(6,3,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,4,11,0);
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(4,2,15,0);
    g.addEdge(5,4,6,0);

    g.printAdList();

    int V=7;
    int src=6;
    int dest=4;
    g.dijkstraShortestDistance(V, src, dest);

    return 0;
}

