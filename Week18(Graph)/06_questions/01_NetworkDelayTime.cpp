
/* -> 743

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.


Example 1:
    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2


Example 2:
    Input: times = [[1,2,1]], n = 2, k = 1
    Output: 1


Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

/*
Approach:-
    -- key points, 
        i) given weight of each edge in form of time
        ii) send a signal from a src to all(sssp)
        iii) minimum time to reach all node

        => we can apply dijkstra
*/

#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k)
{
    // lets form adjList
    int size = times.size();
    unordered_map<int, vector<pair<int,int>>> adjList;
    for(int i=0 ; i<size ; i++)
    {
        int u = times[i][0];
        int v = times[i][1];
        int u_v_time = times[i][2];

        adjList[u].push_back({v, u_v_time});
    } 

    // lets apply dijkstra algo
    vector<int> time(n+1, INT_MAX);// 1->n
    time[k]=0;

    set<pair<int,int>> st;
    st.insert({0, k});

    while(!st.empty())
    {
        auto topPair = st.begin();

        pair<int,int> minPair = *topPair;
        int u = minPair.second;
        int u_time = minPair.first;

        st.erase(topPair);

        for(auto &vPair:adjList[u])
        {
            int v = vPair.first;
            int u_v_time = vPair.second;
            if(u_time + u_v_time < time[v])
            {
                auto oldEnty = st.find({time[v], v});

                if(oldEnty!=st.end())
                    st.erase(oldEnty);

                time[v] = u_time + u_v_time;
                st.insert({time[v], v});
            }
        }
    }

    int result=INT_MIN;
    for(int i=1 ; i<=n ; i++)
    {
        if(time[i]==INT_MAX)
            return -1;
        
        result = max(result, time[i]);
    }

    return result;
}

int main()
{
    vector<vector<int>> times = {
        {2,1,1},
        {2,3,1},
        {3,4,1}
    };
    int n=4;
    int k=2;

    cout << networkDelayTime(times, n, k) << endl;

    return 0;
}