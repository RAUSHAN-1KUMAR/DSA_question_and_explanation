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
Approach:- DP with bitmask
    -- using predecessor technique instead of indegree concept of khan's algo

// now we can go with tabulation as well
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    vector<int> pred; // predecessor
    vector<ll> dp;

    // mask represent the current visited nodes in terms of bits(so mask variable is acting as a index in this recursive DP approach)
    int dfs(int mask, vector<int> &score, int &n)
    {
        // base case  
        if(mask== (1<<n)-1){
            return 0;
        }

        if(dp[mask]!=-1)
            return dp[mask];

        int order=__builtin_popcount(mask)+1;
        ll ans = LLONG_MIN;
        for(int v=0 ; v<n ; v++)// going to each node
        {
            if(mask & (1<<v))// already visited then continue
                continue;

            // if it is not visited then check for node 'v' all its predecessor(pred) are on mask or not i.r., visited or not
            if((pred[v] & ~mask)==0){// if visited then valid, visit it
                ll nextAns=dfs(mask|(1<<v), score, n);
                if(nextAns!=LLONG_MIN)
                    ans=max(ans, nextAns + 1LL*score[v]*order);
            }
        }

        dp[mask] = (ans==LLONG_MIN ? 0 : ans);

        return dp[mask];
    }
 
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) 
    {
        pred.assign(n, 0);// this pred vector acting as a graph here, pred[i] tells which nodes to be visited before node i in terms of bits
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            pred[v] = (pred[v] | 1<<u);
        }
        
        dp.assign(1<<n, -1);

        return dfs(0, score, n);
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

