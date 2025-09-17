/* -> 207

There are a total of 'numCourses' courses you have to take, labeled from 0 to 'numCourses-1'. You are given an array 'prerequisites' where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: true
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0. So it is possible.


Example 2:
    Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
    Output: false
    Explanation: There are a total of 2 courses to take. 
    To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

/*
Approach:- using Dynamic Programming(cycle detection using DFS hi h bas aur kuch nhi)
*/

#include<bits/stdc++.h>
using namespace  std;

// ham pehel dfs m visited and dfsTrack use kerte the, we can also use two different value of same visited to detect the same thing. 2->visited 1->dfsTrack
bool dfs(int u, vector<int> &visited, unordered_map<int, vector<int> > &adjList)
{
    // base case
    if(visited[u]==1) return true; // already visited, cycle detected
    if(visited[u]==2) return false; // already processed, no cycle

    visited[u] = 1;

    for(int &v:adjList[u])
    {
        if(dfs(v, visited, adjList)) return true;
    }

    visited[u]=2;

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    unordered_map<int, vector<int> > adjList;
    for(auto &vec:prerequisites)
    {
        int a=vec[0];
        int b=vec[1];
        
        adjList[b].push_back(a);
    }

    // i have taken int not bool, so that i can use three different value of ith cource: 0=unvisited, 1=visiting 2=processed.
    vector<int> visited(numCourses,0);

    for(int i=0 ; i<numCourses; ++i)
    {
        if(visited[i]==0)
        {
            if(dfs(i, visited, adjList)) // cycle mil gya means we can't complete the course
                return false;
        }
    }

    // cycle nhi mila means we can complete our course
    return true;
}


int main()
{
    vector<vector<int>> prereqisites = {
        {1,0}
    };
    int numCourses = 2;

    cout << canFinish(numCourses, prereqisites) << endl;

    return 0;
}
