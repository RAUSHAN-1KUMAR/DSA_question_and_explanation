/* juspay OA

You are given a maze with N cells, where each cell may have multiple entry points but no more than one exit (i.e., entry/exit points are unidirectional like valves). The cells are numbered from 0 to N-1.

You are tasked with finding the nearest meeting cell for two given cells C1 and C2. A meeting cell is the first common cell that can be reached from both C1 and C2 by following the exits from each cell. If no such meeting cell exists, return -1.

Input Format:
    1. The first line contains an integer N, the number of cells.

    2. The second line contains N integers representing the Edge[] array, where Edge[i] denotes the cell that can be reached from cell i. If Edge[i] is -1, it means cell i has no exit.

    3. The third line contains two integers C1 and C2, representing the two starting cells for which you need to find the nearest meeting cell.

Output Format:
    Output the integer representing the nearest meeting cell (NMC). If no common meeting cell exists, return -1.

Constraints:
1 <= N <= 10^5

Example Input:
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
9 2

Example Output:
4

*/

/*
Approach:- applying dijkstra algorithm
*/

#include<bits/stdc++.h>
using namespace std;

void dijkstra(unordered_map<int, vector<int> > &adjList, vector<int> &dist, int &vertex){
    set<pair<int,int>> st;//(distance, noe);
    st.insert({0, vertex});

    while(!st.empty()){
        auto it=st.begin();
        auto upair=*it;
        st.erase(it);

        int u_dist=upair.first;
        int u=upair.second;

        for(int v:adjList[u]){
            if(v==-1) continue;
            int u_v_dist = 1;
            if(u_dist+u_v_dist < dist[v]){
                auto findv = st.find({dist[v], v});
                if(findv!=st.end()){
                    st.erase(findv);
                }
                dist[v]=u_dist+u_v_dist;
                st.insert({dist[v], v});
            }
        }
    }
}


int nearestMeetingCell(vector<int> &graph, int c1, int c2){
    int n=graph.size();

    // preparing adjList
    unordered_map<int, vector<int> > adjList;
    for(int u=0 ; u<n; u++){
        int v=graph[u];
        adjList[u].push_back(v);// u--->v
    }

    vector<int> dist1(n, INT_MAX);
    dist1[c1]=0;
    dijkstra(adjList, dist1, c1);

    vector<int> dist2(n, INT_MAX);
    dist2[c2]=0;
    dijkstra(adjList, dist2, c2);

    // now lets find answer
    int ans=INT_MAX;
    int node=-1;
    for(int i=0 ; i<n ; i++){
        if(dist1[i]==INT_MAX || dist2[i]==INT_MAX){
            continue;
        }
        else{
            if(dist1[i]+dist2[i]<ans){
                ans=dist1[i]+dist2[i];
                node=i;
            }
        }
    }

    return node;
}


int main()
{
    vector<int> graph = {4, 4, 1, 4, 13, 8, 8, 8, 0, 8, 14, 9, 15, 11, -1, 10, 15, 22, 22, 22, 22, 22, 21};
    int c1=2, c2=15;

    cout << nearestMeetingCell(graph, c1, c2) << endl;

    return 0;
}

