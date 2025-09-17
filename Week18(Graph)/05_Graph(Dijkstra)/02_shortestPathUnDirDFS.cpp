/*
Shortest path in undirected non weighted graph using DFS traversal

Logic:- we are gonna use a count variable and then if count<minCount=> minCount=count

Note:- we can also use the algo for undirected weighted graph, we just have to store the min on reaching dest vertex each time
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool directed)
    {
        if(directed==1)
        {
            adjList[u].push_back(v);
        }
        
        if(directed==0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << ": ";
            for(auto j:i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }

    // solution from here
    void shortestPathDFS(int src, int dest, unordered_map<int, bool> &visited, int count, int &minCount)
    {
        // base case
        if(src==dest){
            minCount = min(minCount, count);
            return;
        }

        if(visited[src]==true)
            return;


        visited[src]=true;
        
        for(auto nbr:adjList[src])
        {
            if(!visited[nbr])
            {
                shortestPathDFS(nbr, dest, visited, count+1, minCount);
            }
        }

        // backTrack is required
        visited[src]=false;
    }

};


int main()
{
    Graph g;

    g.addEdge(0,4,0);
    g.addEdge(0,3,0);
    g.addEdge(0,6,0);
    g.addEdge(4,1,0);
    g.addEdge(4,3,0);
    g.addEdge(3,5,0);
    g.addEdge(6,2,0);
    g.addEdge(1,5,0);
    g.addEdge(2,5,0);

    g.printAdList();

    int n = 8;

    unordered_map<int, bool> visited;

    int count=0;
    int minCount=INT_MAX;
    g.shortestPathDFS(0,2, visited, count, minCount);
    cout << minCount << endl;

    return 0;
}




