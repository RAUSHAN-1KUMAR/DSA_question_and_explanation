/*
Same code of Topological sort using BFS, the only diff is, we are passing a vector to store the TS in it, and if size is not equal to total number of vertex than cycle present
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


    void topologicalSortBFS(int n, vector<int> &topoOrder)
    {
        queue<int> q;
        unordered_map<int,int> indegree;

        // initializing inDegree of each vertex
        for(auto i:adjList)
        {
            for(auto nbr:i.second)
            {
                indegree[nbr]++;
            }
        }

        // push all zero indegree vertex into queue
        for(int vertex=0 ; vertex<n ; vertex++)
        {
            if(indegree[vertex]==0)
                q.push(vertex);
        }


        // Now BFS
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            topoOrder.push_back(u);// storing the verteces
            
            // u ka use ho gya, to usse jude saare vertex ke indegree ko ek kam kerdo mark kerdo
            for(auto v:adjList[u])
            {
                indegree[v]--;

                // indegree zero matlab independent, so push it into queue
                if(indegree[v]==0)
                    q.push(v); 
            }
        }
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

    int n = 8;
    vector<int> topoOrder;
    g.topologicalSortBFS(n, topoOrder);

    // if topoOrder does not contain all vertex, it means cycle is present
    if(topoOrder.size()==n)
        cout << "No Cycle" << endl;
    else 
        cout << "Cycle Present" << endl;

    return 0;
}


