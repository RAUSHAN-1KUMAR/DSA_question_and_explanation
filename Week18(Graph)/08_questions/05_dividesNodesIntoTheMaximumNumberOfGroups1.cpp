/* -> 2493

You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.

You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. 

Notice that the given graph may be disconnected.

Divide the nodes of the graph into m groups (1-indexed) such that:
    1. Each node in the graph belongs to exactly one group.

    2. For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.

RETURN the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

 

Example 1:
    Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
    Output: 4
    Explanation: As shown in the image we: 
    - Add node 5 to the first group.
    - Add node 1 to the second group.
    - Add nodes 2 and 4 to the third group.
    - Add nodes 3 and 6 to the fourth group.
    We can see that every edge is satisfied.
    It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.


Example 2:
    Input: n = 3, edges = [[1,2],[2,3],[3,1]]
    Output: -1
    Explanation: If we add node 1 to the first group, node 2 to the second group, and node 3 to the third group to satisfy the first two edges, we can see that the third edge will not be satisfied.
    It can be shown that no grouping is possible.
*/

/*
Approach:- 
    2. Bipartite graph
        first Step:- check graph can be formed bipartite graph
            i) yes -> we can find our answer
            ii) no -> return -1

        second Step:- group assign kerna hi main kaam h isme
            -- how can we assign maximum grp optimally?? -> 
                i) we will have to check levels/groups from each node
                ii) and we also have to consider the disconnected graph as well

                just like previous approach, but in this approach we have done it in optimsed way

    TC:- O(V*(V+E))
*/

#include<bits/stdc++.h>
using namespace std;

// better approach
bool isBipartite(unordered_map<int, vector<int>> &adjList, int curr, vector<int> &colors, int currColor)
{
    colors[curr]=currColor;

    for(int &nbr:adjList[curr])
    {
        if(colors[nbr]==currColor)
            return false;

        if(colors[nbr]==-1){
            if(isBipartite(adjList, nbr, colors, 1-currColor)==false)
                return false;
        }
    }

    return true;
}

int bfsFindingLevel(unordered_map<int, vector<int>> &adjList, int currNode, int n) 
{
    vector<bool> visited(n+1, false);
    queue<int> que;

    que.push(currNode);
    visited[currNode] = true;

    int level = 1;

    // level order traversal
    while(!que.empty()) 
    {
        int size = que.size();

        while(size--) 
        {
            int curr = que.front();
            que.pop();

            for(int &ngbr : adjList[curr]) 
            {
                if(visited[ngbr])
                    continue;
                
                que.push(ngbr);
                visited[ngbr] = true;
            }
        }

        level++; //1 extra will be incremeented in the last loop
    }

    return level-1;
}

int getMaxFromEachComp(unordered_map<int, vector<int>> &adjList, int curr, vector<bool>& visited, vector<int>& levels) 
{
    int maxGrp = levels[curr];

    visited[curr] = true;

    for(int &ngbr : adjList[curr]) 
    {
        if(!visited[ngbr]) {
            maxGrp = max(maxGrp, getMaxFromEachComp(adjList, ngbr, visited, levels));
        }
    }

    return maxGrp;
}

// main function
int magnificentSets(int n, vector<vector<int>>& edges) 
{
    unordered_map<int, vector<int>> adjList;
    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Birpartite Check
    vector<int> colors(n+1, -1);
    for(int node=1 ; node<=n ; node++){
        if(colors[node]==-1){
            if(isBipartite(adjList, node, colors, 1)==false){
                return -1;
            }
        }
    }

    // using BFS to find max Levels for each node
    vector<int> levels(n+1, 0);
    for(int node = 1; node <= n; node++) 
    {
        // finding possible groups/levels for each node
        levels[node] = bfsFindingLevel(adjList, node, n);
    }

    // after finding levels, now we are gonna collect the maximum level for each connected graph
    int maxGroupEachComp = 0;
    vector<bool> visited(n+1, false);
    for(int node = 1; node <=n; node++) 
    {
        if(!visited[node]) 
        {
            maxGroupEachComp += getMaxFromEachComp(adjList, node, visited, levels);
        }
    }


    return maxGroupEachComp;
}

int main()
{
    vector<vector<int>> edges={
        {1,2},
        {1,4},
        {1,5},
        {2,6},
        {2,3},
        {4,6}
    };
    int n=6;
    cout << magnificentSets(n, edges) << endl;
    return 0;
}


