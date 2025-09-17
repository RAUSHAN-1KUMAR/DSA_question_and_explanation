/* kahn's alogorithm

Topological sort only applicable to directed acyclic graph

we use queue to store the topo order, and we require an inDegreeList

For disconnected graph we don't need to call for each vertex, becuase every indegree zero vertex will be already added to the queue

TC-> O(V+E)
SC-> O(V+E) + O(V) for queue and indegree map
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


    void topologicalSortBFS(int n)
    {
        queue<int> q;
        unordered_map<int,int> indegree;

        // initializing inDegree of each vertex
        for(auto i:adjList)
        {
            for(auto v:i.second)
            {
                indegree[v]++;
            }
        }

        // push all zero indegree vertex into queue
        for(int u=0 ; u<n ; u++)
        {
            if(indegree[u]==0)
                q.push(u);
        }


        // Now BFS: O(V+E)
        while(!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << " ";
            
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
    g.topologicalSortBFS(n);

    return 0;
}


