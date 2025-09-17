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
    1. My approach:- brute force approach
        -- approach is also explained in code as well. The logic is to go at each node and then find maximum possible group that can be formed

        TC:- O(V*(V+E))

    2. Bipartite graph -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// brute force
int magnificentSets(int n, vector<vector<int>>& edges) 
{
    unordered_map<int, vector<int>> adjList;
    unordered_map<int, bool> mainVis;
    for(auto &edge:edges){
        int u=edge[0];
        int v=edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //now lets begin
    int maxiGrp=0;
    for(int root=1 ; root<=n ; root++)
    {
        // graph is disconnected also, so if node is traversed then no need to reconsider it
        if(mainVis[root]) continue;

        // first taking out all the vertices of current connected graph
        unordered_set<int> st; st.insert(root);
        queue<int> qu; qu.push(root);
        while (!qu.empty())
        {
            int first=qu.front();
            qu.pop();
            for(int v:adjList[first]){
                if(st.find(v)==st.end()){
                    st.insert(v);
                    qu.push(v);
                }
            }
        }

        int prevMaxi=maxiGrp;
        // now lets find the max grp formation for current connected graph, by considering each vertex as root vertex
        for(int u:st)
        {
            unordered_map<int,int> grp;
            unordered_map<int, bool> vis;

            grp[u]=prevMaxi+1;
            vis[u]=true;
            mainVis[u]=true;

            // BFS
            queue<int> q;
            q.push(u);

            int currMaxi=prevMaxi;
            while(!q.empty())
            {
                int first=q.front();
                q.pop();

                int currGrp=grp[first];
                currMaxi=max(currMaxi, currGrp);

                for(int v:adjList[first]){
                    if(!vis[v]){
                        grp[v]=currGrp+1;
                        vis[v]=true;
                        mainVis[v]=true;
                        q.push(v);
                    }
                    else{
                        int x=grp[v];
                        int y=grp[first];
                        int diff=abs(x-y);
                        if(diff==0 || diff>1){
                            currMaxi=-1;
                            break;
                        }
                    }
                }

                if(currMaxi==-1) break;
            }

            if(currMaxi!=-1) maxiGrp=max(maxiGrp, currMaxi);
        }

        // maxiGrp didn't updated, it means no possible to make groups
        if(maxiGrp==prevMaxi){
            maxiGrp=INT_MIN;
            break;
        }
    }


    return maxiGrp==INT_MIN?-1:maxiGrp;
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


