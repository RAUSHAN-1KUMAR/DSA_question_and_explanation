/*
A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can divide the graph’s vertices into two distinct sets where:
    1. All edges connect vertices from one set to vertices in the other set.
    2. No edges exist between vertices within the same set.
*/

/*
Approach:- DFS
    Observation logic:- 
        1. Graph having odd length cycle can never be bipartite graph
        2. and any other graph except odd length cycle are bipartite graph

        But we are not solving it by finding the length of cycle in a graph because there can be multiple length, we are solving it by just passing the opposite color to its adjacent vertex

    Using DFS
        TC:- O(V+E)

How to check question is similar to Bipartite graph:- If question is asking about: Dividing/grouping a graph into two parts
*/

#include<bits/stdc++.h>
using namespace std;

bool checkBipartiteDFS(vector<vector<int>> &adj, int curr, vector<int> &color, int currColor)
{
    // color ker diya
    color[curr] = currColor;

    // ab jate h adjacent node per
    for(int &v:adj[curr])
    {
        // ager adjacent wala pehle se color our same color h to return false
        if(color[v]==currColor)
            return false;

        // if color is -1, it means never colored/visited -> to color kerdo
        if(color[v]==-1)
        {
            // opposite color
            int colorOfv = 1-currColor;
            
            if(checkBipartiteDFS(adj, v, color, colorOfv)==false)
                return false;
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
            if(checkBipartiteDFS(adj, i, color, 1)==false)
                return false;
        }
    }

    return true;
}


int main()
{

    return 0;
}

