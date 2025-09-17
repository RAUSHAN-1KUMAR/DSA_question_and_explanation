/* -> 3425

You are given an undirected tree rooted at node 0 with n nodes numbered from 0 to n - 1, represented by a 2D array edges of length n - 1, where edges[i] = [ui, vi, lengthi] indicates an edge between nodes ui and vi with length lengthi. You are also given an integer array nums, where nums[i] represents the value at node i.

A special path is defined as a downward path from an ancestor node to a descendant node such that all the values of the nodes in that path are unique.

Note that a path may start and end at the same node.

Return an array result of size 2, where result[0] is the length of the longest special path, and result[1] is the minimum number of nodes in all possible longest special paths.

 

Example 1:
    Input: edges = [[0,1,2],[1,2,3],[1,3,5],[1,4,4],[2,5,6]], nums = [2,1,2,1,3,1]
    Output: [6,2]
    Explanation: The longest special paths are 2 -> 5 and 0 -> 1 -> 4, both having a length of 6. The minimum number of nodes across all longest special paths is 2.

Example 2:
    Input: edges = [[1,0,8]], nums = [2,2]
    Output: [0,1]
    Explanation: The longest special paths are 0 and 1, both having a length of 0. The minimum number of nodes across all longest special paths is 1.
*/

/*
Approach:- DFS + sliding window + backtrack -> (good question)
    -- sliding window on tree
    -- to maintain the currect path, we will use a vector so that while applying DFS on it we can push the node into it and we will backtrack also to remove the vec.back() in case if we move to another path.
*/

#include<bits/stdc++.h>
using namespace std;

int maxLength = 0, minNodes = INT_MAX;

void dfs(int u, int parent, unordered_map<int, vector<pair<int,int>>> &adjList, vector<int> &nums, int pathSum, int start, int end, unordered_map<int,int> &vis, vector<int> &path)
{
    // before updating maxLength, check if the correspoding node value has already in map or not
    int prevIndex = vis.count(nums[u]) ? vis.count(nums[u]) : -1;

    while (start<=prevIndex)// compress the window
    {
        pathSum-=path[start];// decrease the pathSum
        start++;
    }

    // now we can updagte the maxLength
    if(pathSum > maxLength) {
        maxLength = pathSum;
        minNodes = end - start + 1;
    } else if (pathSum == maxLength) {
        minNodes = min(minNodes, end - start + 1);
    }
    
    vis[nums[u]]=end;// new position of node's value

    for(auto &vPair:adjList[u]){
        int v=vPair.first;
        int wt=vPair.second;
        if(v!=parent){
            path.push_back(wt);
            dfs(v, u, adjList, nums, pathSum+wt, start, end+1, vis, path);
            path.pop_back();// backTrack
        }
    }

    vis[nums[u]]=prevIndex;// IMP backTrack
}

vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums)
{
    int n=edges.size();
    int V=nums.size();

    // first lets build the graph/Tree
    unordered_map<int, vector<pair<int,int>> > adjList;
    for(auto &edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];

        adjList[u].emplace_back(v, wt);
        adjList[v].emplace_back(u, wt);
    }

    // start and end for slinding window technique
    int start=0;
    int end=0;
    int pathSum=0;// for the prefix sum of path
    vector<int> path={};// to store the path wt(path.push_back(wt)), and this is the vector in which sliding window will be applied
    unordered_map<int,int> vis;// to short the window if we encounter the visited node's value 
    int parent = -1;// to not traverse back
    int u=0;// starting node

    dfs(u, parent, adjList, nums, pathSum, start, end, vis, path);

    return {maxLength, minNodes};
}


int main()
{
    vector<vector<int>> edges = {
        {0,1,2},
        {1,2,3},
        {1,3,5},
        {1,4,4},
        {2,5,6}
    };

    vector<int> nums = {2,1,2,1,3,1};

    vector<int> ans = longestSpecialPath(edges, nums);

    for(int num:ans){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}



