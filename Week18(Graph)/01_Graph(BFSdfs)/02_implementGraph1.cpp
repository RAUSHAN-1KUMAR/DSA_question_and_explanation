/*
implementation of weighted graph

But all these implementation is only for integer, lets build it using template variable for differenct type of data types -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // Change, list<int> => list<pair<int,int>> (v, weight)
    unordered_map<int, list<pair<int,int>> > adjList; // {u, {v, wt}}

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

    void printadjList()
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
    Graph g;

    // we can see that we are passing the edge list with its weight also and then we are forming the adjacency list for each node
    g.addEdge(0,1,5,0);
    g.addEdge(1,2,10,1);
    g.addEdge(1,3,20,0);
    g.addEdge(2,3,30,1);

    g.printadjList();
    return 0;
}