/*
Cyclic check in directed Graph, Using DFS traversal i.e., using recursion, for connected/disconnected Graph.
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

    // DFS track technique
    bool checkCyclicDirectedDFS(T u, unordered_map<T, bool> visited, unordered_map<T, bool> &dfsTrack)
    {
        visited[u] = true;
        dfsTrack[u] = true;

        for(auto v:adjList[u])
        {
            if(!visited[v])
            {
                bool ans = checkCyclicDirectedDFS(v, visited, dfsTrack);
                if(ans==true)
                    return true;
            }
            else if(dfsTrack[v])
                return true;
        }

        // backTrack
        dfsTrack[u] = false;

        return false;
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
};


int main()
{
    Graph<int> g;

    // we can see that we are passing the edge list and then we are forming the adjacency list for each node
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(3,1,1);
    g.addEdge(4,3,1);
    g.addEdge(2,4,1);
    g.addEdge(2,5,1);

    g.printAdList();


    int V=6;// 0 - (V-1)
    bool isCyclic=false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsTrack; // this is required for disconnected graph, otherwise we don't need it for connected graph
    for(int vertex=0 ; vertex<V ; vertex++)
    {
        // Calling for each vertex but only those who are not yet visited
        if(!visited[vertex])
        {
            if(g.checkCyclicDirectedDFS(vertex, visited, dfsTrack))
                break;
        }
    }
    
    if(isCyclic) cout << "cycle present" << endl;
    else cout << "cycle not present" << endl;

    return 0;
}


