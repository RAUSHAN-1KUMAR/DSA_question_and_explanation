/* -> 990

You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.


Example 1:
    Input: equations = ["a==b","b!=a"]
    Output: false
    Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
    There is no way to assign the variables to satisfy both equations.
    
Example 2:
    Input: equations = ["b==a","a==b"]
    Output: true
    Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
*/

/*
Approach:-
    - How to get intuition that this question will be solve using DSU??
        -- if I ask you a==b, b==c, c==d => a==d, so we can see that we have a connectivity and we can use that parent property of DSU
        How? -> a==b -> b ka parent a
                b==c -> c ka parent b, and 
                ultimately c ka parent a => a==c

    -- In each equation we have to check the parent of each character(alphabets) and after that if equation don't holds then return false
*/

#include<bits/stdc++.h>
using namespace std;

int find(int x, vector<int> &parent)
{
    if(x==parent[x])
        return x;

    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if(x_parent != y_parent)
    {
        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else
        {
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }
}

bool equationsPossible(vector<string>& equations)
{
    vector<int> parent(26);
    vector<int> rank(26, 0);

    for(int i=0 ; i<26 ; i++){
        parent[i]=i;
    }

    // first handling all the equal walle equation
    for(string &s:equations)
    {
        // take the union of only equal wala equations
        if(s[1]=='=') //-> a==b
        {
            Union(s[0]-'a', s[3]-'a', parent, rank);
        }
    }

    // now for unequal equations and also checking validity
    for(string &s:equations)
    {
        if(s[1]=='!') //-> a!=b
        {
            char first = s[0];
            char second = s[3];

            int parent_first = find(first-'a', parent);
            int parent_second = find(second-'a', parent);

            if(parent_first==parent_second)
                return false;
        }
    }

    return true;
}


int main()
{
    vector<string> equations = {"a==b", "b!=c", "a==c"};

    cout << equationsPossible(equations) << endl;

    return 0;
}

