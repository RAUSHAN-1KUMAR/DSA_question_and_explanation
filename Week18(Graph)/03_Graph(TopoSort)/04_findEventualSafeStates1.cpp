
// DFS return value as true or false

#include<bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>> &graph, vector<int> &vis){
    // if already visited, return false
    if(vis[u]==1) return false;

    // if it leads to terminal node, return true
    if(vis[u]==2) return true;

    // mark visited
    vis[u]=1;

    for(int v:graph[u]){
        int ans=dfs(v, graph, vis);
        if(ans==false){
            return false;
        }
    }

    vis[u]=2;// to mark it as safe node

    return true;
}

vector<int> eventualSafeNodes(vector<vector<int>> &graph){
    int n=graph.size();
    vector<int> vis(n, 0);
    for(int i=0 ; i<n ;i++){
        if(graph[i].size()==0)
            vis[i]=2; // 2 rep terminal node
    }

    vector<int> ans;
    for(int u=0 ; u<n ; u++){
        if(vis[u]==0 && dfs(u, graph, vis))
            ans.push_back(u);
        else if(vis[u]==2)
            ans.push_back(u);
    }

    sort(ans.begin(), ans.end());

    return ans;
}


int main()
{
    vector<vector<int>> graph = {
        {2,1},{0,2,3}, {5}, {0}, {5}, {}, {}
    };
    vector<int> ans = eventualSafeNodes(graph);
    for(int num:ans){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}

