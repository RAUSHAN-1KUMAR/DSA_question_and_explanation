/* IMP
we are implementing single source shortest path (sssp) using topoOrder i.e., only for (DAG) and it would be applicable to both weighted or nonWeighted graph

Using topological order to find the shortest path between the zeroIndegree vertex to every vertex
*/

/*
Approach:- Using DFS algo to find topoStack and then Using that topoStack to find the distance from src to all vertex
    
Limitation:-- But it can only applicable to acyclic graph, and we are starting from zero indegree vertex i.e., top of the stack, means we are bound to find the distance only from zero indegree vertex to each vertex;
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

    // solution from here
    // function to build topoStack
    void topoOrderDFS(T src, stack<T> &topoStack, unordered_map<T, bool> &vis)
    {
        vis[src]=true;

        for(auto nbrPair:adjList[src])
        {
            T nbrNode = nbrPair.first;
            T nbrDist = nbrPair.second;

            if(!vis[nbrNode])
            {
                topoOrderDFS(nbrNode, topoStack, vis);
            }
        }

        topoStack.push(src);
    }

    // to determine shortest path
    void shortestPath(stack<T> &topoStack, T n)
    {
        // distance array to store the minDistance at every reach
        vector<T> dist(n, INT_MAX);// initally the distance for all vertex will be INT_MAX

        // top of the topoStack will be the zero indegree
        int u = topoStack.top(); 
        dist[u]=0;

        // now applying the steps for the remainings
        while(!topoStack.empty())
        {
            // top of the topoStack i.e., zero indegree vertex
            int u = topoStack.top(); topoStack.pop();

            for(auto vPair:adjList[u]) // u---> jitne 'v' h sabko
            {
                T v = vPair.first;
                T u_v_Dist = vPair.second;

                if(dist[u]+u_v_Dist < dist[v])
                    dist[v]=dist[u]+u_v_Dist;
            }
        }

        // now our dist array is ready
        cout << "Printing the distance array: " << endl;
        for(auto i:dist)
            cout << i << " ";
    }
};




int main()
{
    // specified the type name of T
    Graph<int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.printAdList();

    stack<int> topoStack;
    unordered_map<int,bool> visited;

    g.topoOrderDFS(0, topoStack, visited);

    g.shortestPath(topoStack, 5);

    
    return 0;
}