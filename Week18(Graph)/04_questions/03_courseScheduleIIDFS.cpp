/* -> 210

Question is same as Course schedule I, there we have to return true or false, but now, if true then RETURN the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

Example 1:
    Input: numCourses = 2, prerequisites = [[1,0]]
    Output: [0,1]
    Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].

Example 2:
    Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
    Output: [0,2,1,3]
    Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
    So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].

Example 3:
Input: numCourses = 1, prerequisites = []
Output: [0]
*/

/*
Approach:- Using DFS
    -- as it's a DFS and we are finding topoSort. SO, we have to pass for each unvisited vertex

    -- it's a DFS, so we are gonna need a stack to store the topoOrder and then we will pop the stack to get correct order for course schedule
*/

#include<bits/stdc++.h>
using namespace std;

// DFS
void DFS(unordered_map<int, vector<int>> &adjList, int u, vector<bool> &visited, stack<int> &st, vector<bool> &dfsTrack, bool &hasCycle)
{
    visited[u] = true;
    dfsTrack[u] = true;

    // pehle u ke bacho ko stack m dalo
    for(int &v:adjList[u])
    {
        if(dfsTrack[v]==true){
            hasCycle=true;
            return;
        }
        
        if(!visited[v])
            DFS(adjList, v, visited, st, dfsTrack, hasCycle);
    }

    st.push(u);
    dfsTrack[u]=false;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    unordered_map<int, vector<int>> adjList;

    vector<bool> dfsTrack(numCourses, false);
    vector<bool> visited(numCourses, false);
    bool hasCycle = false;

    for(auto &vec:prerequisites)
    {
        int a=vec[0];
        int b=vec[1];

        // {a, b}
        // b-->a
        adjList[b].push_back(a);
    }

    //cycle detection + forming topoStack
    stack<int> st;
    for(int vertex=0 ; vertex<numCourses; vertex++)
    {
        if(!visited[vertex])
            DFS(adjList, vertex, visited, st, dfsTrack, hasCycle);
    }

    if(hasCycle)
        return {};

    vector<int> result;
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}


int main()
{
    vector<vector<int>> prereqisites = {
        {1,0},{2,0},{3,1},{3,2}
    };
    int numCourses = 4;

    for(auto &num:findOrder(numCourses, prereqisites))
        cout << num << " ";
    cout << endl;
    

    return 0;
}





