/* -> 1466

There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.


Example 1:
    Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
    Output: 3


Example 2:
    Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
    Output: 2


Example 3:
    Input: n = 3, connections = [[1,0],[2,0]]
    Output: 0

*/

/*
Approach:- Treat the graph as undirected. Start a dfs from the root, if you come across an edge in the forward direction, you need to reverse the edge.
    -- How we come up with the treating the graph as undirected, because if don't do so, we will not be able to reach each node or you directely pich up the nodes randomly then it would not be a wrong approach
    -- we are gonna store the edge in our adjList with its sign also
        u: ((v, sign),(v, sign))
        sign->1 => real edge
        sign->0 => dummy edge
    -- if we use our real edge to traverse from u->v, it means +1
*/

#include<bits/stdc++.h>
using namespace std;

void prepareAdjList(vector<vector<int>> &connections, unordered_map<int, vector<pair<int,int>> > &adjList)
{
    for(auto eachPair:connections){
        adjList[eachPair[0]].push_back({eachPair[1], 1});//1 -> real edge
        adjList[eachPair[1]].push_back({eachPair[0], 0});//0 -> dummy edge
    }
}

void dfs(unordered_map<int, vector<pair<int,int>> > &adjList, vector<bool> &vis, int &count, int u)
{
    vis[u]=true;

    for(auto vPair:adjList[u]){
        int v=vPair.first;
        int sign=vPair.second;
        if(!vis[v])
        {
            // if we are using real edge to traverse from root to vertex it means we need to reverse it
            if(sign==1) count++;
            dfs(adjList, vis, count, v);
        }
    }
}

int minReorder(int n, vector<vector<int>>& connections)
{
    // preparing adjList
    unordered_map<int, vector<pair<int,int>> > adjList;
    prepareAdjList(connections, adjList);

    // djs traversal from root(0) to all node
    int count=0;
    vector<bool> vis(n,false);
    int src=0;
    dfs(adjList, vis, count, src);

    return count;
}

int main()
{
    vector<vector<int>> connections = {
        {0,1},
        {1,3},
        {2,3},
        {4,0},
        {4,5}
    };
    int n = connections.size();

    cout << minReorder(n, connections) << endl;

    return 0;
}

