/*
A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:
    1. All edges connect vertices from one set to vertices in the other set.
    2. No edges exist between vertices within the same set.
*/

/*
Approach:- BFS
    Using BFS
        TC:- O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

bool checkBipartiteBFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor)
{
    queue<int> que;

    que.push(curr);
    color[curr]=currColor;

    while (!que.empty())
    {
        int u=que.front();
        que.pop();

        for(int &v:adj[u])
        {
            // ager adjacent wala pehle se color our same color h to return false
            if(color[v]==color[u])
                return false;

            // if color is -1, it means never colored/visited -> to color kerdo
            if(color[v]==-1)
            {
                color[v]=1-color[u];
                que.push(v);
            }
        }

    }
    
    return true;
}

bool isBipartite(int V, vector<vector<int>> adj)
{
    // red=1;
    // green=0;

    // initially no color
    vector<int> color(V, -1);

    for(int i=0 ; i<V ; i++)
    {
        if(color[i]==-1){
            if(checkBipartiteBFS(adj, i, color, 1)==false)
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}