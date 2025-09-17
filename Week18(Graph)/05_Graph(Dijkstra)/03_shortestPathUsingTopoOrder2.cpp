/* IMP

we are implementing single source shortest path (sssp) using topoOrder i.e., only for (DAG) and it would be applicable to both weighted or nonWeighted graph

Using topological order to find the shortest path between the zeroIndegree vertex to every vertex
*/

/*
Approach:- Using BFS's khan algo to find zero inndegree vertex and then using that zero indegree vertex to find the distance from src to all vertex
*/


#include<bits/stdc++.h>
using namespace std;

// declared template T
template <typename T>

class Graph
{
public:
    unordered_map<T, list<pair<T,int>> > adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        // direction=1 => directed
        if(direction==1)
        {
            adjList[u].push_back({v,wt});
        }

        // direction=0 => undirected
        if(direction==0)
        {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
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

    // to determine shortest path
    void shortestPath(T n)
    {
        // distance array to store the minDistance at every reach
        vector<T> dist(n, INT_MAX);


        // using khan's algo to find zero indegree vertex
        vector<T> indegree(n, 0);
        for(auto i:adjList)
        {
            for(auto j:i.second)
            {
                indegree[j.first]++;
            }
        }


        // now we will insert all the zero indegree vertex in the queue
        queue<T> q;
        for(int i=0 ; i<n ; i++){
            if(indegree[i]==0)
            {
                q.push(i);
                dist[i]=0; // distance of zero indegree vertex will be zero
            }
        }


        // now applying the steps for the remainings
        while(!q.empty()){
            int u=q.front();q.pop();

            int currd = dist[u];

            for(auto vPair:adjList[u]){
                int v=vPair.first;
                int u_v_dist = vPair.second;
                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);

                if(currd+u_v_dist < dist[v]){
                    dist[v]=currd+u_v_dist;
                }

            }
        }

        // now our dist array is ready
        cout << "Printing the distance array: " << endl;
        for(auto i:dist)
            cout << i << " ";
    }
};




int main()
{
    // specified the type name of T
    Graph<int> g;
    g.addEdge(0,1,5,1);
    g.addEdge(0,2,3,1);
    g.addEdge(2,1,2,1);
    g.addEdge(1,3,3,1);
    g.addEdge(2,3,5,1);
    g.addEdge(2,4,6,1);
    g.addEdge(4,3,1,1);

    g.printAdList();

    g.shortestPath(5);

    
    return 0;
}