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
Approach:- using BFS
    -- we are gonna find topological ordering, if size of our topoSort vector is same as numCourses it means cycle was not there and we have completed all courses

Using DFS -> see next solution
*/

#include<bits/stdc++.h>
using namespace std;

// bfs(kahn's algorithm)
vector<int> topologicalSort(unordered_map<int, vector<int>> &adjList, int &numCourses, vector<int> &indegree)
{
    queue<int> que;

    for(int i=0 ; i<indegree.size() ; i++)
        if(indegree[i]==0) que.push(i);

    vector<int> ans;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();

        ans.push_back(u);

        for(int &v:adjList[u])
        {
            indegree[v]--;

            if(indegree[v]==0)
                que.push(v);
        }
    }


    if(ans.size()==numCourses)
        return ans;

    return vector<int> {};
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    unordered_map<int, vector<int>> adjList;
    vector<int> indegree(numCourses, 0);

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

    return topologicalSort(adjList, numCourses, indegree);
}


int main()
{
    vector<vector<int>> prereqisites = {
        {1,0},{2,0},{3,1},{3,2}
    };
    int numCourses = 4;

    for(auto &num:findOrder(numCourses, prereqisites)) cout << num << " ";
    cout << endl;
    
    return 0;
}





