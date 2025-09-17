/*
Cyclic check in undirected Graph, Using BFS traversal i.e., using queue

So how we are gonna solve it for disconnected graph, we do the same thing as we did int BFS and DFS traversal i.e., we will call for each vertex who are not visited yet  
*/

/*
Two codes of different teacher
    1. Love babbar:- uses a parentList to mark the parent of individual verted
    2. codeStoryWithMIK:- uses queue in pair, so that he can push the parent as well

TC:- O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

template <typename T>

class Graph
{
public:
    unordered_map<T, list<T>> adjList;

    void addEdge(T u, T v, bool direction)
    {
        // direction=1 => directed
        if(direction==1)
        {
            adjList[u].push_back(v);
        }

        // direction=0 => undirected
        if(direction==0)
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    bool checkCyclicUndirectedBFSbyLOVEBABBAR(T src)
    {
        queue<T> q;
        
        unordered_map<T, bool> visited;
        unordered_map<T, T> parent;

        //initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            T frontNode = q.front();
            q.pop();

            for(auto nbr:adjList[frontNode])
            {
                if(!visited[nbr]) // nbr, you are not visited, so just push it into queue
                {
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
                else if(visited[nbr] && parent[frontNode]!=nbr) // nbr, tum to visited ho, to kya tum(nbr) mere(frontNode) parent ho, if not then cyclic is present
                {
                    return true;
                }
            }
        }

        return false;
    }

    bool checkCyclicUndirectedBFSbyMIK(T src, unordered_map<int, bool> visited)
    {
        // v, parent
        queue<pair<int,int>> que; // vertex, parent

        que.push({src, -1});
        visited[src]=true;

        while(!que.empty())
        {
            auto p = que.front();
            que.pop();

            T u = p.first;
            T parent = p.second;

            for(T &v:adjList[u])
            {
                if(!visited[v])
                {
                    visited[v]=true;
                    que.push({v, u}); // vertex, parent
                }
                else if(v!=parent)
                    return true;
            }
        }

        return false;
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << "-> {";
            for(auto list:i.second)
            {
                cout << list << ", ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }
};


int main()
{
    Graph<int> g;

    // we can see that we are passing the edge list and then we are forming the adjacency list for each node
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,4,0);
    g.addEdge(2,4,0);
    g.addEdge(2,5,0);

    g.printAdList();

    int V=6;// 0 - (V-1)
    bool isCyclic=false;
    unordered_map<int, bool> visited;
    for(int u=0 ; u<V ; u++)
    {
        // Calling for each vertex(u) but only those who are not yet visited
        if(!visited[u])
        {
            isCyclic = g.checkCyclicUndirectedBFSbyMIK(u, visited);
            if(isCyclic)
                break;
        }
    }
    
    if(isCyclic) cout << "cycle present" << endl;
    else cout << "cycle not present" << endl;

    return 0;
}


