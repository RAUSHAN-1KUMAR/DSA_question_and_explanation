/*
implementation using template variable for differenct type of data types
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
};

int main()
{
    // specified the type name of T
    Graph<char> g;

    // again we are passig the edge list directly and then we are forming the adjacency list
    g.addEdge('a','b',5,0);
    g.addEdge('b','c',10,1);
    g.addEdge('b','d',20,0);
    g.addEdge('c','d',30,1);

    g.printAdList();
    return 0;
}