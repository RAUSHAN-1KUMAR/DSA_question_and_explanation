/* -> 207

There are a total of 'numCourses' courses you have to take, labeled from 0 to 'numCourses-1'. You are given an array 'prerequisites' where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

RETURN true if you can finish all courses. Otherwise, return false.

 

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
Approach:- Cycle detection in directed graph
    -- After reading question, i got that it's a question to check deadlock is present or not. So, if cycle(deadlock) present then false, or return true.
    -- it's a directed graph, (1,0) means=> 0--->1: 
    -- given prerequisites is in form of edgeList
    -- so to check cycle in directed graph, we can use toposort(kahn's algo for BFS) or dfsTrack(for DFS)

Lets solve it using Dynamic Programming -> see next solution
*/

#include<bits/stdc++.h>
using namespace  std;

// using bfs(kahn's algorithm)
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
    // first lets make adjList from edgeList and also indegreeList
    unordered_map<int, vector<int> > adjList;
    vector<int> indegree(numCourses,0); // kahn's algo
    for(auto &vec:prerequisites)
    {
        int a=vec[0];
        int b=vec[1];

        // {a, b}
        // b-->a
        adjList[b].push_back(a);

        // arrow-> 'a' m ja rha h
        indegree[a]++;
    }

    // lets push the indegree zero into queue
    queue<int> que;
    for(int i=0 ; i<numCourses;  i++)
    {
        if(indegree[i]==0)
            que.push(i);
    }

    // lets do bfs
    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        numCourses--;// courses represent no. of vertex

        for(int &v:adjList[u])
        {
            indegree[v]--;

            if(indegree[v]==0)
                que.push(v);
        }
    }
    
    // if all courses finished then return true, means cycle was not present that's why we were able to complete all the courses.
    return (numCourses==0);
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
