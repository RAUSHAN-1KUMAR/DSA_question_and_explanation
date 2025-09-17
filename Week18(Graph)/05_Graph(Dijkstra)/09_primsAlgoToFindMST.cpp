/*
Prim's Algorithm to find minimum spanning tree

Steps: greedy approach
    1. remove loop edges and parallel edges with higher edges weight.
    2. choose any arbitrary vertex(let say A) to start, and checkout all unvisited vertex(ley say B, C) connected to this vertex(A) and choose the edge having less edge weight(A---B).
    3. So now we have Two vertex, vertex A and B. Now we have to checkout all unvisited vertex connected to vertex A and B and then choose the edge having less edge weight.

    -- dhayan ye rakhna h ki kab visited array m true kerna h and kab edges ko ans m push kern h
    
TC:- O(E + ElogE)) = O(ElogE)
*/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> Pair;
typedef tuple<int,int,int> Tuple;
unordered_map<int, vector<Pair> > adjList;

vector<Pair> minST(vector<vector<int>> &edges, int V)
{
    int n=edges.size();
    for(auto &edge:edges){ // O(E)
        int u=edge[0], v=edge[1], w=edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // lets start with src = 0;
    int start=0, Wt=0, parent=-1;

    vector<bool> visited(V, false);
    priority_queue<Tuple, vector<Tuple>, greater<Tuple> >minHeap; // {wt, node, parent}
    minHeap.push({Wt, start, parent});

    int totalWeightMST = 0;
    vector<Pair> ans;
    while (!minHeap.empty()) // O(E)
    {
        Tuple first = minHeap.top(); minHeap.pop(); //O(logE)
        int currWt = get<0>(first), currU =  get<1>(first), parentU = get<2>(first);

        if(visited[currU]) // IMP
            continue;

        visited[currU] = true; // IMP, only when we fetch from heap

        if(parentU!=-1){ // IMP
            totalWeightMST+=currWt;
            ans.push_back({parentU, currU});
        }

        // O(E),, throughout all the iterations: V^2 = E (in Worst case)
        for(auto &vPair:adjList[currU])
        {
            int v = vPair.first;
            int u_v_wt = vPair.second;

            if(!visited[v]){
                minHeap.push({u_v_wt, v, currU}); //O(logE)
            }
        }
    }
    
    cout << "The total weight sum of MST: " << totalWeightMST << endl;
    return ans;
}


int main()
{
    vector<vector<int>> edges = {
        {0,1,2},
        {0,2,1},
        {1,2,1},
        {2,4,2},
        {2,3,2},
        {3,4,1}
    }; // {u, v, w} undirected

    vector<Pair> mst = minST(edges, 5);
    for(auto &p:mst){
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}