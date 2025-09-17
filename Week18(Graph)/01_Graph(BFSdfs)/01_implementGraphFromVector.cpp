/*
we have a given vector of vector, which represent the egde of a graph

Building for directed graph and for undirected we can tweak whenever we need it to
*/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void formAdjList(vector<vector<int>> &edgeList)
    {
        // u ---> v
        for(auto &vec:edgeList)
        {
            int u = vec[0];
            int v = vec[1];

            adjList[u].push_back(v);
        }
    }

    void printAdList()
    {
        for(auto i:adjList)
        {
            cout << i.first << "-> {";
            for(auto list:i.second)
            {
                cout << list << ", ";
            }
            cout << "}" << endl;
        }
    }
};

int main()
{
    vector<vector<int>> edgeList = {
        {1,0},
        {2,0},
        {2,1},
        {3,1}
    };

    Graph g;
    g.formAdjList(edgeList);
    g.printAdList();

    return 0;
}