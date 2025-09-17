/* GFG

Given a sorted dictionary of an alien language having some words dict and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If no valid ordering of letters is possible, then return an empty string.

Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.

Examples:
    Input: dict[] = ["baa","abcd","abca","cab","cad"], k = 4
    Output: true
    Explanation: Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
    Similarly we can find other orders.

    Input: dict[] = ["caa","aaa","aab"], k = 3
    Output: true
    Explanation: Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
    Similarly we can find other orders.

    Input: dict[] = ["dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"], k = 9 
    Output: false

*/

/*
Approach:-TOpoOrder
    -- how to get the intuition that topoOrder will be used -> in topo order we had graph u->v->z, then in topoOrder u,v,z . So, in this question we have something before something like b should comes before a or may be d comes before a something like that
    
    Logic:
    -- we will create a directed graph on given string(whenever we hit an unequal characters): b->d->a->c like this
    -- and then we will search topoOrder on that Directed Graph, and if we are able to form topoOrder, it means we got an answer otherwise return empty string
*/

#include<bits/stdc++.h>
using namespace std;

// topoSortOrder, kahn's algorithm
vector<int> topoSort(int V, unordered_map<int, vector<int>> &adjList)
{
    vector<int> indegree(V, 0);
    for(int i=0 ; i<V; i++){
        for(int v:adjList[i]){
            indegree[v]++;
        }
    }

    queue<int> que;
    for(int i=0 ; i<V;i++){
        if(indegree[i]==0) que.push(i);
    }

    vector<int> topo;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();

        topo.push_back(u);
        
        for(int v:adjList[u]){
            indegree[v]--;
            if(indegree[v]==0) que.push(v);
        }
    }

    return topo;
}

string findOrder(vector<string> dict, int k)
{
    int n = dict.size();

    // forming adjList of our directed graph
    unordered_map<int, vector<int>> adjList;
    for(int i=1; i<n ; i++)
    {
        string s2 = dict[i];
        string s1 = dict[i-1];
        int len = min(s1.size(), s2.size());
        for(int ptr=0 ; ptr<len;ptr++)
        {   
            int u=s1[ptr];
            int v=s2[ptr];
            // whenever we hit the first unequal character, then connect the edges
            if(u!=v)
            {
                adjList[u-'a'].push_back(v-'a');
                break;
            }
        }
    }


    // topoSortOrder
    vector<int> topoOrder = topoSort(k, adjList);

    string ans = "";
    for(auto it: topoOrder){
        ans = ans + char(it+'a');
    }

    return ans;
}


int main()
{
    vector<string> dict {"caa", "aaa", "aab"};
    int k=3;
    cout << findOrder(dict, k) << endl;
    return 0;
}

