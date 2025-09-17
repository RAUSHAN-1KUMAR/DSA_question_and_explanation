
/*
Breadth first traversal using queue for disconnected graph and it will also work for connected graph
*/

/*
Logic:
    -- rather than calling the bfsTraversal function only for a single root vertex, call it for every vertex who are not visited yet

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

    void bfsTraversal(T srcNode,  unordered_map<T, bool> &visited)
    {
        // change1: visited map has been shifted to main function

        queue<T> q;

        q.push(srcNode);
        visited[srcNode]=true;

        while(!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            for(auto nbr:adjList[frontNode])
            {
                if(visited[nbr.first]==false)
                {
                    q.push(nbr.first);
                    visited[nbr.first]=true;
                }
            }
        }

    }
};




int main()
{
    // specified the type name of T
    Graph<char> g;
    g.addEdge('a','b',2,0);
    g.addEdge('a','c',10,0);
    g.addEdge('b','c',12,0);

    g.addEdge('d','e',3,0);

    g.addEdge('f','f',0,0);

    g.printAdList();


    // visited has been shifted here
    unordered_map<char, bool> visited;
    cout << endl << "Printing BFS Traversal: ";
    for(char node='a' ; node<='f'; node++) //change2: calling for each vertex
    {
        // but only those who are not yet visited
        if(visited[node]==false)
            g.bfsTraversal(node, visited);
    }

    return 0;
}