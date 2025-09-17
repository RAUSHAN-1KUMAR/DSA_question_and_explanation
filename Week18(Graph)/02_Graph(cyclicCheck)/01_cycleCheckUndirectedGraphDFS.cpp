/*
Cyclic check in undirected Graph, Using DFS traversal i.e., using recursion

So how we are solve it for disconnected graph, we will call for each vertex

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

    // in my logic, i have passed two variable: parent and parentsParent to check the same logic as we did in BFS, my logic also contain base case as occur in case of recursive solution
    bool checkCyclicUndirectedDFSMyCode(T src, unordered_map<T, bool> &visited, T parent, T parentsParent)
    {
        // base case
        if(visited[src] && parent!=-1)
        {
            if(src!=parentsParent)
                return true;
            else
                return false;
        }

        visited[src]=true;
        for(auto nbr:adjList[src])
        {
            bool ans = checkCyclicUndirectedDFSMyCode(nbr, visited, src, parent);
            if(ans == true)
                return true;
        }

        return false;
    }

    // in love babbar Logic, he have passed only one variable: parent to check the same logic as we did in BFS, he has used the same code also so that he can issily apply the DFS logic without containing the base case for recursive solution
    bool checkCyclicUndirectedDFSLoveBabbar(T src, unordered_map<T, bool> &visitedL, T parentL)
    {
        visitedL[src]=true;
        
        for(auto nbr:adjList[src])
        {
            if(!visitedL[nbr])
            {
                bool ans = checkCyclicUndirectedDFSLoveBabbar(nbr, visitedL, src);

                if(ans==true)
                    return true;
            }
            else if(visitedL[nbr] && nbr != parentL)
            {
                return true;
            }
        }

        return false;
    }

    // There is also a optimal code of same logic:- just think about it, we have passed a parent and then if (nbr==parent) then it is sure that nbr is true and there will be no cycle. we can also apply this change in BFS and DFS both
    bool checkCyclicUndirectedDFSOptimal(T u, unordered_map<T, bool> &visited, T parent)
    {
        // base case
        if(visited[u]==true) return true;

        visited[u]=true;
        
        for(T &v:adjList[u])
        {
            // catch
            if(v==parent) continue;

            bool ans = checkCyclicUndirectedDFSOptimal(v, visited, u);
            
            if(ans) return true;
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

    // using Optimal code
    int src=0;
    unordered_map<int, bool> visited;
    int parent = -1;
    bool isCyclic = g.checkCyclicUndirectedDFSOptimal(src, visited, parent);

    if(isCyclic) cout << "cycle present" << endl;
    else cout << "cycle not present" << endl;

    return 0;
}


