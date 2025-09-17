/* 1192
The bridge in a graph question is similar to find edges such that if i remove that edge the graph can be divided into two disconnected graphs


we are gonnna use tarjan's algorithm
*/

/*
Approach: Tarjan's algo
    -- we have two array: tin and low
        1. tin: dfs time insertion
        2. low: min lowest time insertion from all adjacent nodes "APART FROM PARENT"
    
    -- how to detect: if for an edge u--v, low[v]>tin[u] then it's a bridge

        TC: dfs = O(V+2E)
        SC: O(V+2E) + O(3V)
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
    }

    // solution from here
    void solve(int u, int parent, unordered_map<int,list<int>> &adj, int &timer, vector<vector<int>> &ans, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis)
    {
        // first inialization
        vis[u]=true;
        tin[u]=timer;
        low[u]=timer;

        timer++; // for next iteration

        for(auto v:adj[u])
        {
            if(v==parent){
                continue;
            }

            if(!vis[v])
            {
                //Step1: visit the node
                solve(v, u, adj, timer, ans, tin, low, vis);
                
                //Step2: on coming back, means dfs for v is done
                // low of u update, if it's child's(v) low got updated
                low[u] = min(low[u], low[v]);

                //Step3: bridge testing
                if(low[v]>tin[u]){
                    ans.push_back({u, v});
                }
            }
            else
            {
                // if nbr: v is visited and not its parent then update the low
                low[u] = min(low[u], low[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        // preparing adjList
        unordered_map<int,list<int>> adj;
        for(auto vec:connections)
        {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // main logic
        vector<vector<int>> ans;
        vector<int> low(n, 0), tin(n, 0);
        int timer = 1, src = 0, parent = -1;

        unordered_map<int, bool> vis;
        
        solve(src, parent, adj, timer, ans, tin, low, vis);

        return ans;
    }
};


int main()
{
    Graph g;

    vector<vector<int>> connections = {
        {1,0},
        {1,2},
        {0,2},
        {0,3},
        {3,4}
    };
    int n = 5;

    vector<vector<int>> ans = g.criticalConnections(n, connections);

    for(auto vec:ans)
    {
        for(int num:vec)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}


