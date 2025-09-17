/* -> 547
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

 

Example 1:
    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2


Example 2:
Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
*/

/*
Approach:- we are just doing bfs or dfs traverse
1. Using DFS: (recursion)
    -- we are using DFS to traverse each city, and each time we call our DFS means cities are disconnected -> increment count
    -- in question, our graph is given in adjMatrix, we can change it into adjList or we can also use directly adjMatrix also.

2. Using BFS; (queue)

TC:- O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

// using dfs
void dfs(vector<vector<int>>& isConnected, int u, vector<bool> &visited)
{
    visited[u]=true;

    // u se ham kha kha ja sakte h, to wo to isConnected[u]th row m diya hua h
    for(int v=0; v<isConnected.size() ;v++)//v -> col
    {
        if(isConnected[u][v] && !visited[v])
        {
            dfs(isConnected, v, visited);
        }
    }
}

//using bfs
void bfs(vector<vector<int>> &isConnected, int u, vector<bool>&visited)
{
    queue<int> que;
    que.push(u);
    visited[u]=true;

    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        // u se ham kha kha ja sakte h, to wo to isConnected[u]th row m diya hua h
        for(int col=0 ; col<isConnected.size(); col++)
        {
            if(isConnected[u][col] && !visited[col])
            {
                visited[col]=true;
                que.push(col);
            }
        }
    }
}


int findCircleNum(vector<vector<int>>& isConnected)
{
    int n = isConnected.size();
    int count=0; 

    vector<bool> visited(n, false);
    for(int u=0 ; u<n ; u++)
    {
        if(!visited[u])
        {
            count++;// increment count if cities are disconnected
            bfs(isConnected, u, visited);
        }
    }

    return count; 
}

int main()
{
    vector<vector<int>> isConnected = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    cout << findCircleNum(isConnected) << endl;

    return 0;
}


