/* -> 3530

You are given a Directed Acyclic Graph (DAG) with n nodes labeled from 0 to n - 1, represented by a 2D array edges, where edges[i] = [ui, vi] indicates a directed edge from node ui to vi. Each node has an associated score given in an array score, where score[i] represents the score of node i.

You must process the nodes in a valid topological order. Each node is assigned a 1-based position in the processing order.

The profit is calculated by summing up the product of each node's score and its position in the ordering.

Return the maximum possible profit achievable with an optimal topological order.

A topological order of a DAG is a linear ordering of its nodes such that for every directed edge u → v, node u comes before v in the ordering.

Example 1:
    Input: n = 2, edges = [[0,1]], score = [2,3]
    Output: 8
    Explanation:
        Node 1 depends on node 0, so a valid order is [0, 1].
        The maximum total profit achievable over all valid topological orders is 2 + 6 = 8.

Example 2:
    Input: n = 3, edges = [[0,1],[0,2]], score = [1,6,3]
    Output: 25
    Explanation:
        Nodes 1 and 2 depend on node 0, so the most optimal valid order is [0, 2, 1].
        The maximum total profit achievable over all valid topological orders is 1 + 6 + 18 = 25.
*/

/*
Approach:-
    -- at first i thought to go with the greedy approach but it won't work, so when greedy don't works then comes DP

Below code is recursive code, but i was not able to memoizise it, because the problem is to memoizise the visited node which can be done using bitmask to represent the set of visited nodes -> see next solution

// next code is memoized code but different approach
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int &n, vector<int> &score, unordered_map<int, vector<int> > &adjList, vector<int> indegree, int count, int u)
    {
        // base case
        int c=0;
        for(int &num:indegree){
            if(num==0) c++;
        }
        if(c==n) return 0;

        // update indegree
        for(int v:adjList[u]){
            indegree[v]--;
        }

        // recursive call
        int ans=0;
        for(int i=0 ; i<n; i++){
            if(indegree[i]==0){
                indegree[i]=-1;
                ans=max(ans, count*score[i] + helper(n, score, adjList, indegree, count+1, i));
                indegree[i]=0;//back-track for next call
            }
        }

        return ans;
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) 
    {
        unordered_map<int, vector<int> > adjList;
        vector<int> indegree(n, 0);
        for(auto &vec:edges){
            int u=vec[0];
            int v=vec[1];
            
            adjList[u].push_back(v);
            indegree[v]++;
        }

        int ans=0;
        int count=1;
        for(int i=0 ; i<n ;i++){
            if(indegree[i]==0){
                indegree[i]=-1;// visited
                ans=max(ans, count*score[i] + helper(n, score, adjList, indegree, count+1, i));
                indegree[i]=0;// unvisited for next call
            }
        }

        return ans;
    }
};


int main()
{
    vector<vector<int>> edges={{1,2},{0,3},{1,4},{2,3},{1,3}};
    vector<int> score={50913,47946,97391,27488,69147};

    Solution sol;
    int ans=sol.maxProfit(score.size(), edges, score);
    cout << ans << endl;

    return 0;
}





