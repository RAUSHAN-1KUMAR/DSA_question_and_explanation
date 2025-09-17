/*
Shortest path in undirected non weighted graph using BFS traversal

Logic: we have prepare the parent list, while traversing the graph BFS. And then after traversal we will use that parent list to find the path

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
    void shortestPathBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] =-1;

        while(!q.empty())
        {
            int u = q.front(); q.pop();

            for(auto v:adjList[u])
            {
                if(!visited[v])
                {
                    q.push(v);
                    parent[v]=u;
                    visited[v]=true;
                }
            }
        }

        // parent map taiyaar ho gya h, and whoever is the parent of dest is the first one who reach to dest, now we will trace the parent of dest backward
        vector<int> ans;
        while(dest!=-1){
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());

        for(auto num : ans)
            cout << num << " ";
    }

};

int main()
{
    Graph g;

    g.addEdge(0,4,0);
    g.addEdge(0,3,0);
    g.addEdge(0,6,0);
    g.addEdge(4,1,0);
    g.addEdge(3,5,0);
    g.addEdge(6,2,0);
    g.addEdge(1,5,0);
    g.addEdge(2,5,0);

    g.printAdList();

    int n = 8;

    g.shortestPathBFS(0,5);

    return 0;
}


