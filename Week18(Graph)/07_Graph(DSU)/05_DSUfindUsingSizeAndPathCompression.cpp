/*
1. Until now, we have learned union by rank, the findPar() function, and the path compression technique

2. After applying path compression the rank of the graphs becomes distorted.
    -- rank: {1,0,2,0,3,2} <- like this way

3. So, rather than storing the rank, we can just store the size of the components for comparing which component is greater or smaller.
    -- size: {1,1,2,1,5,3} -> this will also help us to find which set size is smaller or greater to each other
*/

/*
Approach:
    -- Initialization
        1. parent array: each node will be parent of itself
        2. size array: initially this array initialized with one, representing each node size is one
*/

#include<bits/stdc++.h>
using namespace std;

int findParent(int ele, vector<int> &parent)
{
    if(parent[ele]==ele) 
        return ele;

    return parent[ele]=findParent(parent[ele], parent);
}

// code and logic will be similar to rank wala
void UnionBySize(int x, int y, vector<int> &parent, vector<int> &size)
{
    int x_parent = findParent(x, parent);
    int y_parent = findParent(y, parent);

    // we are assigning parent on the basis of their size
    if(x_parent!=y_parent)
    {
        if(size[x_parent] > size[y_parent])
        {
            parent[y_parent] = x_parent;
            size[x_parent] += size[y_parent];
        }
        else if(size[x_parent] < size[y_parent])
        {
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
        else // size is same
        {
            // choose any one
            parent[x_parent] = y_parent;
            size[y_parent] += size[x_parent];
        }
    }    
}

int main()
{


    return 0;
}