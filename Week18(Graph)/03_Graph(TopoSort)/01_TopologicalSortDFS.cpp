/*
Topological sort only applicable to DIRECTED ACYCLIC GRAPH

we use stack to store the topo order and for disconnected graph we are gonna call the topoSort function for each unvisited vertex by passing the same stack

TC-> O(V+E)
SC-> O(V+E) + O(V) for stack and visited map
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

    // its a simple dfs traversal the only difference is while returning back push the vertex into stack
    void topologicalSortDFS(int u, unordered_map<int, bool> &visited, stack<int> &st)
    {
        visited[u]=true;

        for(auto v:adjList[u])
        {
            if(!visited[v])
            {
                topologicalSortDFS(v, visited, st);
            }
        }

        // stack m push kerdo, back jaate waqt
        st.push(u);
    }
};

int main()
{
    Graph g;

    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    g.printAdList();

    int V=8;
    stack<int> st;
    unordered_map<int, bool> visited;
    for(int vertex=0 ; vertex<V ; vertex++)
    {
        if(!visited[vertex])
        {
            g.topologicalSortDFS(0, visited, st);
        }
    }

    cout << "Printing the topo Sort: ";
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}


