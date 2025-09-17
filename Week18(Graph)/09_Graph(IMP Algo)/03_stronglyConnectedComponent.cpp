
/*
We are gonna count and print SCC of a connected graph, we are gonna use kosaraju's principle -> only valid for directed graphs

A Strongly Connected Component is a maximal subgraph in which every vertex is reachable from every other vertex.

*/

/*
The question may comes in two forms
1. To count the SCC
2. To print the SCC

Approach: Kosaraju's approach
    1. sort all the edges according to finishing time. (ordering like topoOrder using stack)
    2. reverse all the edges
    3. final dfs to count the SCC

    TC:- O(3(V+E))
    SC:- O(V+2E) + O(V+2E) -> two adjList + O(V) -> vis array
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int> > adjList;

    void addEdge(int u, int v,bool direction)
    {
        if(direction==0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        else if(direction==1)
        {
            adjList[u].push_back(v);
        }
    }

    void printAdList()
    {
        for(auto u:adjList)
        {
            cout << u.first << ": {";
            for(auto v:u.second)
            {
                cout << v << ",";
            }
            cout << "}" << endl;
        }
    }

    // solution from here

    //STEP1: dfs1 to create the ordering
    void dfs1(int u, stack<int> &ordering, unordered_map<int, bool> &visited)
    {
        visited[u]=true;
        for(auto v:adjList[u])
        {
            if(!visited[v])
            {
                dfs1(v, ordering, visited);
            }
        }

        ordering.push(u);
    }

    //STEP3: dfs2 to use that ordering
    void dfs2(int u, unordered_map<int, list<int>> &adjNewList, unordered_map<int, bool> &visited)
    {
        visited[u] = true;
        cout << u << " ";

        for(auto v:adjNewList[u])
        {
            if(!visited[v])
                dfs2(v, adjNewList, visited);
        }
    }

    int getStronglyConnectedComponents(int n)
    {
        stack<int> ordering;
        unordered_map<int, bool> vis;

        // Step1: get the ordering
        for(int i=0 ; i<n ; i++)
        {
            if(!vis[i])
                dfs1(i, ordering, vis);
        }

        // Step2: reverse the edges
        unordered_map<int, list<int>> adjNewList;
        for(auto u:adjList)
        {
            for(auto v:u.second)
            {
                // u--->v hai
                // v--->u kerna hai 
                adjNewList[v].push_back(u.first);
            }
        }

        // Step3: traverse the graph using dfs
        int sccCount = 0;
        unordered_map<int,bool> vis2;
        while(!ordering.empty())
        {
            int node = ordering.top(); ordering.pop(); // using ordering

            if(!vis2[node])
            {
                cout << "SCC #" << sccCount+1 << ": ";

                dfs2(node, adjNewList, vis2);
                sccCount++;
                
                cout << endl;
            }
        }

        return sccCount;
    }
};


int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);

    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);

    g.addEdge(6, 7, 1);


    // g.printAdList();

    int V=8;
    cout << "SCC Count: " << g.getStronglyConnectedComponents(V) << endl;

    return 0;
}

