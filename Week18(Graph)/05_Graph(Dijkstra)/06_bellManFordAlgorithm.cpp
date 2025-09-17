/* it is also a SSSP (single source shortest path)

This algo is applicable to directed/acyclic/cyclic graph with negative weights also, 
but in case of undirected graph there should not be any negative edge

As we know that:-
    1. Dijkstra algo may or may not work in case of negative edge 
    2. Dijkstra algo definitely will not work in case of negative weight cycle -> stuck in infinite loop

So bellman ford algorithm resove this issues.

What bellman ford algo do/give:-
    1. provide shortest path
    2. provide the presence of negative cycle or not
    3. Do relaxation only for v-1 times: if(dist[u]+u_v_dist < dist[v]) then update, like dijkstra algo

TC:- (V*E)
*/

/*
Why only for V-1 time relaxation:- 
    -- So the V-1 times is the minimum ralaxation required, because in case of worst case the minimum relaxation req for a node to reach farthest node will be V-1.

    -- see we can also do V times, V+1 time.. but there will be no update,,, if updates happens at V-1 times -> then we say negative weight cycle is present
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<char, list<pair<char,int>> > adjList;

    void addEdge(char u, char v, int wt, bool direction)
    {
        if(direction==0)
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        else if(direction==1)
        {
            adjList[u].push_back({v, wt});
        }
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << ": {";
            for(auto list:i.second)
            {
                cout << "{" << list.first << "," << list.second << "}";
            }
            cout << "}" << endl;
        }
    }

    void bellmanFord(int n, char src)
    {
        // initial state
        vector<int> dist(n, INT_MAX);
        dist[src - 'A']=0;

        // just a loop for n-1 times relaxation on edgeList
        for(int i=1 ; i<n ; i++)
        {
            // traverse on entire edge list
            for(auto uPair:adjList) // its not necessary that you start with the src vertex
            {
                char u = uPair.first;
                for(auto vPair:uPair.second)
                {
                    char v = vPair.first;
                    int u_v_dist = vPair.second;

                    // What if dist[u] is INT_MAX, so that's why we are checking it before relaxing
                    if(dist[u-'A']!=INT_MAX && dist[u-'A']+u_v_dist<dist[v-'A']){
                        dist[v - 'A'] = dist[u-'A'] + u_v_dist;
                    }
                }
            }
        }
        // after n-1 relaxation we have our shortest path in dist vector

        // lets check for negative weight cycle, if it is possible to update even after n-1 relaxation this means negative weight cycle was present
        bool flag = false;
        for(auto adjPair:adjList)
        {
            for(auto vPair:adjPair.second)
            {
                char u = adjPair.first;
                char v = vPair.first;
                int u_v_dist = vPair.second;

                if(dist[u-'A']!=INT_MAX && dist[u-'A']+u_v_dist<dist[v-'A'])
                {
                    flag = true;
                    break; // no need to update;
                    // dist[v-'A'] = dist[u-'A'] + u_v_dist;
                }
            }
        }

        // flag is true, means updation ho rha the n-1 relaxation ke baad bhi => negative weight cycle present
        if(flag)
            cout << "negative weight cycle present" << endl;
        else 
            cout << "no negative weight cycle present" << endl;


        // printing shortest path
        cout << "Shortest path from src to all node: ";
        for(auto num:dist)
            cout << num << " ";
        cout << endl;

    }

};

int main()
{
    Graph g;
    g.addEdge('A', 'B', -1, 1);
    g.addEdge('B', 'E', 2, 1);
    g.addEdge('E', 'D', -3, 1);
    g.addEdge('D', 'C', 5, 1);
    g.addEdge('A', 'C', 4, 1);
    g.addEdge('B', 'C', 3, 1);
    g.addEdge('B', 'D', 2, 1);
    g.addEdge('D', 'B', 2, 1);

    g.printAdList();
    g.bellmanFord(5, 'A');
    return 0;
}