/* -> 1462

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.

    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.

Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.

You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.

Return a boolean array answer, where answer[j] is the answer to the jth query.

 

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    Output: [false,true]
    Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
    Course 0 is not a prerequisite of course 1, but the opposite is true.


Example 2:
    Input: numCourses = 2, prerequisites = [], queries = [[1,0],[0,1]]
    Output: [false,false]
    Explanation: There are no prerequisites, and each course is independent.


Example 3:
    Input: numCourses = 3, prerequisites = [[1,2],[1,0],[2,0]], queries = [[1,0],[1,2]]
    Output: [true,true]


Constraints:
    The prerequisites graph has no cycles.
*/

/*
Approach:- 
    1. Using topoSort:-
        -- the only topoSort will not help completely but the indegree zero concept of topoSort will definetely help + parent concept, so we will store all the perequisite of each node within a vector<set<>> while doing DFS or BFS 
        -- we are using set<> to remove dublicates

    2. Using Floyd Warshall:-
        -- See next solution
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
{
    unordered_map<int,vector<int>> adjList;
    vector<int> indegree(numCourses, 0);

    for(auto &edge:prerequisites)
    {
        int u=edge[0], v=edge[1];
        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=0 ; i<numCourses; ++i){
        if(indegree[i]==0) q.push(i);
    }

    // BFS
    // to keep track for each node's prerequisites
    vector<unordered_set<int>> nodePre(numCourses);
    while (!q.empty())
    {
        int u=q.front(); q.pop();

        for(int v:adjList[u])
        {
            nodePre[v].insert(u);
            for(int prereq:nodePre[u]){// the prereq of parent(u) will also be the prereq of its child(v)
                nodePre[v].insert(prereq);
            }
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    

    // now forming ans
    vector<bool> answer;
    for(auto &eachQuery:queries){
        int u=eachQuery[0];
        int v=eachQuery[1];
        answer.push_back(nodePre[v].count(u));
    }

    return answer;
}


int main()
{
    int numCourses = 3;
    vector<vector<int>> prerequesites = {
        {1,2}, {1,0}, {2,0}
    };
    vector<vector<int>> queries = {
        {1,0}, {1,2}
    };
    
    vector<bool> ans = checkIfPrerequisite(numCourses, prerequesites, queries);

    for(int num:ans) cout << num << " "; 
    cout << endl;

    return 0;
}