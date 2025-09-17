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
    2. Using Floyd Warshall:-
        -- floyd warshall approach will also be valid if we have large no of queries,, How to proceed??
        -- we will first find all the shoretest path for each pair i.e., MSSP (multiple source shortest path algorithm), then we are gonna use that matrix to build our answer, becuase if there will be path between any pair of node than it will definitely will be there in floyd warshall shorted path 2D array
        -- we can assumen wt of each edge as 1 or constant, so we don't need to insert wt in our graph

TC:- O(n^3)
SC:- O(n^2)
*/

#include<bits/stdc++.h>
using namespace std;

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
{
    // make graph
    unordered_map<int, vector<int>> adjList;
    for(auto &edge:prerequisites){
        int u=edge[0], v=edge[1];
        adjList[u].push_back(v);
    }

    // floyd warshall 2D array and its inilialization
    vector<vector<int>> dist(numCourses, vector<int>(numCourses, 1e5));
    for(auto vPair:adjList){
        int u=vPair.first;
        for(int v:vPair.second){
            dist[u][v]=1;
        }
    }

    // now floyd warshall technique
    for(int h=0 ; h<numCourses ; h++){ // h-> helper
        for(int u=0;u<numCourses ; u++){ // u-> src
            for(int v=0 ; v<numCourses ; v++){ // v-> destination
                dist[u][v]=min(dist[u][v], dist[u][h]+dist[h][v]);
            }
        }
    }

    // now forming ans
    vector<bool> ans;
    for(auto qery:queries)
    {
        int u=qery[0];
        int v=qery[1];
        if(dist[u][v]<1e5)
            ans.push_back(true);
        else    
            ans.push_back(false);
    }

    return ans;
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

