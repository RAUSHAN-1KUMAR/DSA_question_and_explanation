/*
In bridges in a graph, we were removing edges and checking the graph can be broken into multple components or not, now we are gonna remove node
*/

/*
Approach:
    -- similar to bridges in a graph, the only difference is how we update low
        1. tin: dfs time insertion.
        2. low: min lowest time insertion from all adjacent nodes "APART FROM PARENT" and "VISITED NODES".
        3. edge case: to check for the starting node is articulation point or not, we will do it seperately: for this we will if starting node has multiple children then it is an articulation point.

        lets see the changes as per the bridges in a graph

        TC: O(V + 2E) + O(V)
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
    void solve(int u, int parent, unordered_map<int,list<int>> &adj, int &timer, vector<int> &mark, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &vis)
    {
        vis[u]=true;
        tin[u]=timer;
        low[u]=timer;

        timer++;

        int child = 0; // Change3: mainly to check the starting node is articulation point or not

        for(auto v:adj[u])
        {
            if(v==parent){
                continue;
            }

            if(!vis[v])
            {
                //Step1:
                solve(v, u, adj, timer, mark, tin, low, vis);
                
                //Step2:
                low[u] = min(low[u], low[v]);

                //Step3: Articulation point testing
                if(low[v]>=tin[u] && parent!=-1){ // Change1, why parent!=-1 to avoid marking starting node
                    mark[u] = 1;
                }

                child++;
            }
            else
            {
                // if nbr(v) is visited and not its parent then update the low
                low[u] = min(low[u], tin[v]); // Change2, instead of low[v] we will take tin[v] 
            }
        }


        if(child>1 && parent==-1) // only for source node
            mark[u] = 1;
    }

    vector<int> articulationPoints(int n, vector<vector<int>>& connections) 
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
        unordered_map<int, bool> vis;
        vector<int> low(n, 0), tin(n, 0);
        vector<int> mark(n, 0); // to mark that perticular node is articulation point or not
        int timer=1;
        for(int u=0 ; u<n ; u++)
        {
            if(!vis[u]){
                solve(u, -1, adj, timer, mark, tin, low, vis);
            }
        }

        
        vector<int> ans;
        for(int u=0 ; u<n ; u++){
            if(mark[u]==1)
                ans.push_back(u);
        }


        return (ans.size()==0 ? vector<int>{-1} : ans);
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

    vector<int> ans = g.articulationPoints(n, connections);

    for(auto vec:ans)
    {
        cout << vec << " ";
    }
    cout << endl;

    return 0;
}