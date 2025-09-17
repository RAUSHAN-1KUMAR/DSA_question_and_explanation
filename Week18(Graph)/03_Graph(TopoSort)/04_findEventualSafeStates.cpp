/* -> 802

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:
    Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
    Output: [2,4,5,6]
    Explanation: The given graph is shown above.
    Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
    Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.


Example 2:
    Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
    Output: [4]
    Explanation:
    Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/

// approach:- my logic:-> little bit cycle detection type, if on dfs call we hit a vertex which is already visited then return from there and all the vertext who followed his path will never be a safe node

// one more my Logic ->  dfs return value as true or false -> see next solution
// solve it using topoSort -> see next to next solution

#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& graph, int u, vector<int> &vis)
{
    if(vis[u]==2) return;

    vis[u] = 1;

    for(int v:graph[u]){
        if(vis[v]==1){
            // we triggered a visited vertex, so return to the parent
            return;
        }
        else{
            dfs(graph, v, vis);
        }

        // u got his child(v) as 1 it means my(u) child(v) doesn't lead to a safe node nor terminal node, it means i am also not a safe node, so return
        if(vis[v]==1) return;
    }

    // if everything goes well, it means i(u) am a safe node
    vis[u]=2; 
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n=graph.size();

    // first lets find each terminal node
    vector<int> vis(n, 0);
    for(int i=0 ; i<n; i++){
        if(graph[i].size()==0){
            vis[i]=2;
        }
    } //->O(V)

    // now lets iterate through the graph and check which vertex leads to tmNode
    for(int u=0;u<n;u++){
        if(vis[u]==0){
            dfs(graph, u, vis);
        }
    }//-> O(V+E)


    vector<int> ans={};
    for(int i=0;i<n;i++){
        if(vis[i]==2){
            ans.push_back(i);
        }
    }//-> O(V)

    return ans;
}


int main()
{
    vector<vector<int>> graph = {
        {2,1},{0,2,3}, {5}, {}, {5}, {}, {}
    };
    vector<int> ans = eventualSafeNodes(graph);
    for(int num:ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}