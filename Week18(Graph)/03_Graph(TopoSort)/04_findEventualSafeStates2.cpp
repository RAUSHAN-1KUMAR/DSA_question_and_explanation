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

/*
Approach:- using toposort's kahn's algorithm but to apply this we need indegree not outdegree, so that's why we will reverse all the edges and then we will apply toposort ordering
*/

#include<bits/stdc++.h>
using namespace std; 

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{
    int n=graph.size();
    vector<int> inDegree(n, 0);

    // reverse edges
    vector<vector<int>> dumGraph(n);
    for(int i=0 ; i<n ; i++){
        for(int num:graph[i]){
            dumGraph[num].push_back(i);
            inDegree[i]++;
        }
    }
    
    // applying kahn's algo
    queue<int> que;
    for(int i=0 ; i<n ; i++){
        if(inDegree[i]==0){
            que.push(i);
        }
    }

    vector<int> safeNodes;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();

        // the vertex(u) is safe nodes because it leads to terminal vertex or it is terminal vertex
        safeNodes.push_back(u);

        for(auto v:dumGraph[u]){
            inDegree[v]--;
            if(inDegree[v]==0)
                que.push(v);
        }
    }


    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}


int main()
{
    vector<vector<int>> graph = {
        {1,2},{2,3}, {5}, {0}, {5}, {}, {}
    };
    vector<int> ans = eventualSafeNodes(graph);
    for(int num:ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

