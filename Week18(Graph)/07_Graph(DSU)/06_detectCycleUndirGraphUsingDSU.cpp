
/*
We are gonna detect cycle using disjoin set unino in a undirected graph
*/

/*
Approach:-
    -- we will take each edge and combine its vertex into one of its vertex's set, and if letter on the parent of two vertex of a edge is same -> cycle present
    -- we will only explore each edge one time only.
        How?? if(u<v) tabhi combine kro
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
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


    // solution from here
    vector<int> parent;
    vector<int> rank;

    int find(int x)
    {
        if(x==parent[x])
            return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y)
    {
        int x_parent = find(x);
        int y_parent = find(y);

        if(x_parent!=y_parent)
        {
            if(rank[x_parent] > rank[y_parent])
            {
                parent[y_parent] = x_parent;
            }
            else if(rank[x_parent] < rank[y_parent])
            {
                parent[x_parent] = y_parent;
            }
            else
            {
                parent[x_parent] = y_parent;
                rank[y_parent] += 1;
            }
        }
    }

    bool detectCycle()
    {
        int V=adjList.size();

        parent.resize(V);
        rank.reserve(V);

        for(int i=0 ; i<V ; i++)
        {
            parent[i] = i;// initially parent of each vertex will be itselt
            rank[i] = 1;// initially rank of each vertex will be same
        }

        for(int u=0 ; u<V ; u++)
        {
            for(int &v:adjList[u])
            {
                // u<v, becuase its a undirected graph so to avoid computing the same edge we are doing edge
                if(u<v)
                {
                    // we need to check the parent before performing union
                    int parent_u = find(u);
                    int parent_v = find(v);

                    // if parent is same => cycle is present
                    if(parent_u==parent_v)
                        return true;

                    // if parent is not same then perform union
                    Union(u, v);
                }
            }
        }

        return false;
    }

};

int main()
{
    Graph g;

    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);
 

    g.printAdList();
    cout << g.detectCycle() << endl;

    return 0;
}


