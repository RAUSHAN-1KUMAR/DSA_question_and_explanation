
/*
Depth first traversal using recursion for connected graph only, directed/undirected both

For disconnected graph -> we will do the same we did in BFSTraversal i.e., we will call the DFS traversal for each node who are not visited yet

TC-> O(V+E)
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

    // TC:- O(V+E)
    void dfsTraversal(T srcNode, unordered_map<T, bool> &visited)
    {
        // base case
        if(visited[srcNode])
            return;

        visited[srcNode]=true;
        cout << srcNode << " ";
        
        for(auto nbr:adjList[srcNode])
            dfsTraversal(nbr.first, visited);
    }
};




int main()
{
    // specified the type name of T
    Graph<char> g;
    g.addEdge('a','b',2,1);
    g.addEdge('c','a',10,1);
    g.addEdge('c','b',12,1);
    g.addEdge('b','d',25,1);
    g.addEdge('b','e',25,1);
    g.addEdge('g','d',25,1);
    g.addEdge('e','c',50,1);
    g.addEdge('c','f',3,1);
    g.addEdge('f','g',3,1);

    g.printAdList();

    unordered_map<char, bool> visited;
    cout << endl << "Printing DFS Traversal: ";
    g.dfsTraversal('a', visited);


    return 0;
}

