/* juspay OA, leetcode 2360
You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (ie. entry/exit points are unidirectional doors like valves).

The cells are named with an integer value from 0 to N-1.

You need to find the the length of the largest cycle in the maze. Return -1 if there are no cycles.

INPUT FORMAT
    1. First line has the number of cells N

    2. Second line has list of N values of the edge[] array. edge[i] contains the cell number that can be reached from of cell ‘i’ in one step. edge[i] is -1 if the ‘i’th cell doesn’t have an exit.

OUTPUT FORMAT
    length of the largest cycle.


Sample input:
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21

Sample output
6
*/

/*
Approach:- topoSort
    -- if we remove all undependent nodes then we will left with those nodes who are in cycle, and as in question said that from a node exit is only one, so we don't need to worry about small and large cycle
*/

#include<bits/stdc++.h>
using namespace std;

int largestSumCycle(vector<int> &edges)
{
    int n=edges.size();

    // preparing adjList
    unordered_map<int, vector<int> > adjList;
    vector<int> indegree(n, 0);// lets form indegree
    for(int u=0 ; u<n; u++){
        int v=edges[u];
        if(v==-1) continue; // means no exit
        adjList[u].push_back(v);// u--->v
        indegree[v]++;
    }

    // lets do khan's algo to remove all nodes that not take part in cycle (the indegree 0 are not part of cycle)
    queue<int> q;
    for(int i=0 ; i<n ;i++){
        if(indegree[i]==0)
        q.push(i);
    }
    
    vector<bool> formCycle(n, true);
    while (!q.empty())
    {
        int u=q.front();
        q.pop();

        formCycle[u]=false;// mark it false (not taking part in cycle)

        for(int v:adjList[u]){
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
    

    // now calculate the longest cycle
    int maxCount=INT_MIN;
    for(int i=0 ; i<n ;i++){
        if(formCycle[i]){
            int j=i;
            int count=0;
            while(formCycle[j]){
                formCycle[j]=false;
                count++;
                j=edges[j];
            }
            maxCount=max(maxCount, count);
        }
    }

    return maxCount;
}

int main()
{
    vector<int> edges = {4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21};
    int c1=2, c2=15;

    cout << largestSumCycle(edges) << endl;
    return 0;
}

