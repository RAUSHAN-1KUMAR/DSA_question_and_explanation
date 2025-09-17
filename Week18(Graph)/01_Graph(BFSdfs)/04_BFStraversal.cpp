
/*
Breadth first traversal using queue(directed/undirected both)

For now we are writing the bfs code for connected graph only

For disconnected graph -> see next solution and then observe the logic also

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

    // TC: O(V+E)
    void bfsTraversal(T srcNode)
    {
        // visited
        unordered_map<T, bool> visited;

        // Queue
        queue<T> q;

        // initial state
        q.push(srcNode);
        visited[srcNode]=true;

        // now lets traverse
        while(!q.empty())
        {
            T u = q.front();
            q.pop();

            cout << u << " "; // printing

            for(auto vPair:adjList[u])
            {
                int v = vPair.first;

                // if not visited then only push the node
                if(visited[v]==false)
                {
                    q.push(v);
                    visited[v]=true;// don't foget to mark it visited
                }
            }
        }

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

    cout << endl << "Printing BFS Traversal: ";
    g.bfsTraversal('a');

    return 0;
}