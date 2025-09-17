/* 721

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.


Example 1:
    Input:
        accounts = [
            ["John","johnsmith@mail.com","john_newyork@mail.com"],
            ["John","johnsmith@mail.com","john00@mail.com"],
            ["Mary","mary@mail.com"],
            ["John","johnnybravo@mail.com"]
        ]

    Output: [
        ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
        ["Mary","mary@mail.com"],
        ["John","johnnybravo@mail.com"]
    ]

    Explanation:
    The first and second John's are the same person as they have the common email "johnsmith@mail.com".
    The third John and Mary are different people as none of their email addresses are used by other accounts.
    We could return these lists in any order, for example the answer
        [['Mary', 'mary@mail.com'],
         ['John', 'johnnybravo@mail.com'],
         ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']
        ] would still be accepted.

Example 2:
    Input:
        accounts = [
            ["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
            ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
            ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
            ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
            ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]
        ]

    Output: [
        ["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
        ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
        ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
        ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
        ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]
    ]

*/

/*
Approach: main ides is how we can form the graph

    1. DFS/BFS:
        -- main idea is to form graph-> using mails as node
        -- then do DFS/BFS traverse of graph, as we do in case of disconnected graph

        TC: O(E + ElogE), E-> total number of emails

    2. DSU:
        -- again, how we can use the mails to check their parents as they are string
        -- First, we go through all the accounts and assign a unique integer ID to every single email address
        -- We iterate through the accounts again. For each account, we take the first email as an anchor and perform a union operation between it and every other email in that same account.

        TC: O(E + E + E + ElogE), E-> total number of emails

*/

#include <bits/stdc++.h>
using namespace std;

// applying DFS approach
unordered_map<string, vector<string>> adj; // emails are node
unordered_map<string, string> email_to_name; // {mail, name}

void dfs(string &u, unordered_set<string> &visited, vector<string> &allMails)
{
    visited.insert(u);
    allMails.push_back(u);

    for(auto &v:adj[u])
    {
        if(visited.find(v)==visited.end()){
            dfs(v, visited, allMails);
        }
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    // forming graph, node represents mails
    for(auto &eachAcc:accounts)
    {
        string name = eachAcc[0];
        string firstMail = eachAcc[1];

        for(int i=1  ; i<eachAcc.size() ; i++)
        {
            string otherMail = eachAcc[i];
            email_to_name[otherMail] = name;

            adj[firstMail].push_back(otherMail);
            adj[otherMail].push_back(firstMail);
        }
    }

    // now traversing the graph using DFS
    unordered_set<string> visited;
    vector<vector<string>> ans;
    for(auto &vPair:adj)
    {
        string u = vPair.first;

        if(visited.find(u)==visited.end())
        {
            vector<string> allMails; // to store all nodes(mails) of current connected graph

            dfs(u, visited, allMails); // dfs traversal

            sort(allMails.begin(), allMails.end());// sort as asked in question

            allMails.insert(allMails.begin(), email_to_name[u]);// insert name at the begin

            ans.push_back(allMails);// add the fully merged account to our answer
        }
    }

    return ans;
}


// DSU approach
class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);

        for(int i=0 ; i<=n ; i++){
            parent[i] = i;
        }
    }

    int findPar(int node){
        if(parent[node]==node)
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu==pv) return;

        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }

    void unionBySize(int u, int v){
        int pu = findPar(u);
        int pv = findPar(v);

        if(pu == pv) return;

        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(size[pv] < size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    void printParent(){
        for(int i=0 ; i<parent.size(); i++){
            cout << i << ":" << parent[i] << " ";
        }
        cout << endl;
    }
    
    void printSize(){
        for(int i=0 ; i<size.size(); i++){
            cout << i << ":" << size[i] << " ";
        }
        cout << endl;
    }
};


vector<vector<string>> accountsMergeDSU(vector<vector<string>> &accounts)
{
    unordered_map<string, int> email_to_id;
    unordered_map<string, string> email_to_name;
    int id_counter=0;

    // assigning each mail to ID
    for(auto &eachAcc:accounts)
    {
        string name = eachAcc[0];
        for(int i=1  ; i<eachAcc.size() ; i++)
        {
            string mail = eachAcc[i];
            if(email_to_id.find(mail)==email_to_id.end())
            {
                email_to_name[mail] = name;
                email_to_id[mail] = id_counter;
                id_counter++;
            }
        }
    }

    // again traversing to perform union operation
    DisjointSet dsu(id_counter);

    for(auto &eachAcc:accounts)
    {
        string firstMail = eachAcc[1];
        int firstMailId = email_to_id[firstMail];

        for(int i=2 ; i<eachAcc.size() ; i++)
        {
            int otherMailId = email_to_id[eachAcc[i]];

            dsu.unionByRank(firstMailId, otherMailId);
        }
    }


    // now grouping mails
    unordered_map<int, vector<string>> grpMails;
    for(auto &mPair:email_to_id)
    {
        string mail = mPair.first;
        int mailId = mPair.second;

        int parent = dsu.findPar(mailId);

        grpMails[parent].push_back(mail);
    }

    // now forming answer
    vector<vector<string>> ans;
    for(auto &mails:grpMails)
    {
        vector<string> currGrp = mails.second;

        sort(currGrp.begin(), currGrp.end());

        currGrp.insert(currGrp.begin(), email_to_name[currGrp[0]]);

        ans.push_back(currGrp);
    }

    return ans;
}


int main()
{

    return 0;
}