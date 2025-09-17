/* GFG

You are given an undirected graph consisting of V vertices and E edges represented by a list edges[][], along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.

Note: The graph is indexed with 0-based indexing.


Example:
    Input: V = 4, edges[][] = [[0, 1], [1, 3], [2, 3], [3, 0], [0, 2]], m = 3
    Output: true
    Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
        Vertex 0: Color 1
        Vertex 1: Color 2
        Vertex 2: Color 2
        Vertex 3: Color 3

    Input: V = 3, edges[][] = [[0, 1], [1, 2], [0, 2]], m = 2
    Output: false
    Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.
*/

/*
Approach:
    -- in bipartite graph, we can color the graph with 2 colors, and thus we used to color the node with one color and used to color the adjacent node with different color

    -- but in this approach, we will choose color to color the current node as per their adjacent node
    -- we are coloring the node serial wise, 0->1->2->3->...->n-1

TC: (N^m) where N is the number of nodes and m is the number of colors
SC: O(N) for recursion stack and O(N) for colors array
*/

#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> adjList;

// the checks the color of adjacent node of current node
// if the color is same as current node, then it is not safe to color the current node with that color
bool isSafe(int &color, int &node, vector<int> &colors)
{
    for (int &v : adjList[node])
    {
        if (colors[v] == color)
            return false;
    }

    return true;
}

bool dfs(int node, int &m, int &n, vector<int> &colors)
{
    if (node == n) // if we reach at ends, it means we colored all nodes successfully
    {
        return true;
    }

    // for current node we are choosing which one to color
    for (int colorChoosen = 1; colorChoosen <= m; colorChoosen++)
    {
        if (isSafe(colorChoosen, node, colors))
        {
            colors[node] = colorChoosen;

            if (dfs(node + 1, m, n, colors) == true)
                return true;

            colors[node] = -1; // backtrack if no valid coloring found ahead
        }
    }

    // if we are not able to choose any color for the current node, then we return false
    return false;
}

bool graphColoring(int v, vector<vector<int>> &edges, int m)
{
    int n = v;

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1];

        if (u == v)
            continue;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> colors(n, -1);

    // starting dfs coloring from node 0
    return dfs(0, m, n, colors);
}

int main()
{

    return 0;
}
