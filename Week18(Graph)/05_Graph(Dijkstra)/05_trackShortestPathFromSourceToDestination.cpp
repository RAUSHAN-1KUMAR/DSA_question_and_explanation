/* it is a SSSP (single source shortest path)

This algo is applicable to directed/undirected/acyclic/cyclic/weighted/unweighted graph.

The only constraint is that weight must be a positive integer and there should not be any negative cycle.

Uses an additional Data structure to get the min at O(1) -> set/minHeap.
*/


/*
Approach:- dijkstra using set
    -- we want to track the path for a perticular src and dest verter
    -- for that we would need a parent array to track the parent from src to each vertex

Path ko track kerna parent ka use kerke is useful in many cases not just in Graph, so remember it.
*/


#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int,int>> > adjList;

    void addEdge(int u, int v, int wt, bool direction)
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

    // lets build for src to each vertex(SSSP)
    void dijkstraShortestDistance(int n, int src)
    {
        // parent track for each vertex: col->vertex
        vector<int> parent(n, -1);

        //Initially parent for each dest/col will be col itself
        for(int dest=1 ; dest<n ; dest++){
            parent[dest] = dest;
        }

        // dist vertex for minimum dist to perticular vertex
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        set<pair<int,int>> st;
        st.insert({0, src});

        while(!st.empty())
        {
            auto minDistNode = st.begin();

            pair<int,int> minPair = *minDistNode;

            int u_dist = minPair.first;
            int u = minPair.second;

            st.erase(minDistNode);// don't forget this1

            for(auto &vPair:adjList[u])
            {
                int v = vPair.first;
                int u_v_dist = vPair.second;

                if(u_dist + u_v_dist < dist[v])
                {
                    auto oldEntry = st.find({dist[v], v});

                    if(oldEntry!=st.end()) // don't forget this2
                        st.erase(oldEntry);

                    dist[v] = u_dist + u_v_dist;
                    st.insert({dist[v], v});

                    // parent track: for each destination the parent will be tracked
                    parent[v] = u;
                }
            }
        }

        // Lets print the distance from src to every dist and also print the path
        for(int row=1 ; row<n ; row++)
        {
            cout << "Distance from " << src << " to " << row << " is: " << dist[row];

            vector<int> path;
            int dest=row;
            while (true)
            {
                if(dest!=src)
                {
                    path.push_back(dest);
                    dest = parent[dest];
                }
                else
                {
                    path.push_back(dest);
                    break;
                }
            }

            reverse(path.begin(), path.end());

            cout << ", having path: ";
            for(int &num:path)
                cout << num << " ";
            cout << endl;
        }

    }
};


int main()
{
    // specified the type name of T
    Graph g;
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
    g.dijkstraShortestDistance(V, src);

    return 0;
}

