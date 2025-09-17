/*
Cyclic check in directed Graph, Using DFS traversal i.e., using recursion, for connected/disconnected Graph.
*/

/*
Approach:- solvin it without dfsTrack
    -- we will have visited array instead of visited map and for each vertex in visited array we will have three value
        0 -> not visited
        1 -> processing(same as dfs)
        2 -> processed(same as visited)
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction=1 => directed
        if(direction==1)
        {
            adjList[u].push_back(v);
        }

        // direction=0 => undirected
        if(direction==0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << "-> {";
            for(auto list:i.second)
            {
                cout << list << ", ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }

    bool checkCyclicDirectedDFS(T u,  vector<int> &visited)
    {
        if(visited[u]==1) return true; // processing wala node dubara aa gya means cycle present h

        if(visited[u]==2) return false; // processed wala node dubara aa gya means further no need to proceed

        visited[u]=1;

        for(auto v:adjList[u])
        {
            bool ans = checkCyclicDirectedDFS(v, visited);
            if(ans) return true;
        }

        visited[u]=2;

        return false;
    }
};


int main()
{
    Graph<int> g;

    // we can see that we are passing the edge list and then we are forming the adjacency list for each node
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(3,1,1);
    g.addEdge(4,3,1);
    g.addEdge(4,2,1);
    g.addEdge(2,5,1);

    g.printAdList();


    int V=6;// 0 - (V-1)
    bool isCyclic=false;

    vector<int> visited(V, 0);

    for(int u=0 ; u<V ; u++)
    {
        // Calling for each vertex(as u) but only those who are not yet visited
        if(visited[u]==0)
        {
            isCyclic = g.checkCyclicDirectedDFS(u, visited);
            if(isCyclic)
                break;
        }
    }
    
    if(isCyclic) cout << "cycle present" << endl;
    else cout << "cycle not present" << endl;

    return 0;
}


