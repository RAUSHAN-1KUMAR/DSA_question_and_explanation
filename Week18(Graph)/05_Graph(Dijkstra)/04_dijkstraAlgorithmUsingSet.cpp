/* it is a SSSP (single source shortest path)

This algo is applicable to directed/undirected/acyclic/cyclic/weighted/unweighted graph.

The only constraint is that weight must be a positive integer and there should not be any negative cycle.

Uses an additional Data structure to get the min at O(1) -> set/minHeap.
*/


/*
Approach:- It follows a greedy algo niether BFS or DFS
    -- greedy to always take the current min distance node, for this we can use set or minHeap as well.(using set would require less no. of iterations as compared to minHeap, because find() can be done in set to update the already computed vertex)

TC:- O(ElogV)

What if we also want to track the path from src to dest -> see next solution
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

    void dijkstraShortestDistance(int n, T src, T dest)
    {
        vector<int> dist(n+1, INT_MAX);

        set<pair<int, T> > st; // dist, Node

        //Initial State: stack will contain the distance of source node as zero and the source node
        st.insert({0,src});

        //Initial State: set the dist of src node as zero
        dist[src]=0;

        // distance updation logic
        while (!st.empty())
        { 
            // took the min dist vertex from stack
            auto topElment = st.begin(); // an iterator

            pair<int,T> minPair = *topElment; // store the value of iterator pointer

            int u_dist = minPair.first;
            T u = minPair.second;

            st.erase(st.begin()); // erase the top, jis node ka kaam ho gya usko erase kerdo

            // update distance of v
            for(auto vPair:adjList[u])
            {
                T v = vPair.first;
                int u_v_dist = vPair.second;

                if(u_dist+u_v_dist < dist[v])
                {
                    // set m insert kerne se pehle, check ker rhe h ki kya 'v' already present h stack m: ager h to usko erase kerdo

                    auto prevEntry = st.find({dist[v], v}); // an iterator to old entry

                    // if present than erase, because we got a small dist
                    if(prevEntry!=st.end()){
                        st.erase(prevEntry);
                    }

                    // for that v we are inserting new shortest dist into the set and also updating its distance in dist vector
                    dist[v] = u_dist + u_v_dist;
                    
                    st.insert({dist[v], v}); 
                }
            }
        }


        // printing
        cout << "shortest distance from " << src << " Node to " << dest << " Node: " << dist[dest] << endl;
    }
};




int main()
{
    // specified the type name of T
    Graph<int> g;
    g.addEdge(6,3,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(6,1,14,0);
    g.addEdge(3,1,9,0);
    g.addEdge(3,4,11,0);
    g.addEdge(3,2,10,0);
    g.addEdge(1,2,7,0);
    g.addEdge(4,2,15,0);
    g.addEdge(5,4,6,0);

    g.printAdList();

    int V=7;
    int src=6;
    int dest=4;
    g.dijkstraShortestDistance(V, src, dest);

    return 0;
}

