/* 1976

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.


Example 1:
    Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    Output: 4
    Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
    The four ways to get there in 7 minutes are:
    - 0 ➝ 6
    - 0 ➝ 4 ➝ 6
    - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
    - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
*/

/*
Approach:
    - you might think of finding shortest distance first and then counting path for all path that reaches to out destination using that shortest distance, but this will give TLE

    - Better: using ways array as well with dist array, ways array will store the number of ways to reach perticular node
*/

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int countPaths(int n, vector<vector<int>> &roads)
{
    unordered_map<int, vector<pair<int, int>>> adjList;
    for (auto &edge : roads)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    int src = 0, des = n - 1;

    vector<long long> time(n, LLONG_MAX);
    vector<int> ways(n, INT_MAX);
    time[src] = 0LL;
    ways[src] = 1;

    // {time, src}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
    minHeap.push({time[src], src});
    while (!minHeap.empty())
    {
        auto p = minHeap.top();
        minHeap.pop();

        int u = p.second;
        long long t = p.first;

        if (t > time[u])
            continue;

        for (auto &vPair : adjList[u])
        {
            int v = vPair.first;
            long long int u_v_t = vPair.second;

            if (t + u_v_t == time[v])
            {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
            else if (t + u_v_t < time[v])
            {
                time[v] = t + u_v_t;
                ways[v] = ways[u];
                minHeap.push({time[v], v});
            }
        }
    }

    return ways[des];
}

int main()
{

    return 0;
}