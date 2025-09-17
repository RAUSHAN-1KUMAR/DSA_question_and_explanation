// the most important topic of graph series

/* DSU -> disjoint set union

Disjoint sets:- the sets whose intersection = null, -> Two sets are called disjoint sets if they don’t have any element in common.

SO disjointSetUnion helps us in three ways:-
    i) combine two given sets: union()
    ii) find the leader/parent of the set: find()
    iii) find if two members , let say (b,g) , belong to same set or not. We mainly find representative of both and check if same: find()

    and that's why it is also called Union Find Algorithm

In this algo, there is a set exist and a leader/parent for each set, and leader is any of the member from that set only
*/


/*
Approach:- Obtimising the height of the tree
    -- Lets use a rank vector to optimise the height of the tree so that the parent search can be dont at O(1) TC.
    -- initially the rant of each node will be same: 0 or 1 whatever

    Observe the change: 
        : we assignes parent[px]=py <- if rpx < rpy 
                   or parent[py]=px <- if rpy < rpx
                   or       any     <- if rpy = rpx and alos increase rank of top

            1. find parent of x and y: px, py
            2. find rank of px and py: rpx, rpy
            3. connect smaller rank to larger rank always

So ultimately we have improved the Union find of DSU by using rank and path compression
*/

/*
Use Cases: mainly in case of dynamic graphs -> the graphs that keep on changing
*/


#include<bits/stdc++.h>
using namespace std;

int findParent(int ele, vector<int> &parent)
{
    if(parent[ele]==ele) 
        return ele;

    return parent[ele]=findParent(parent[ele], parent);
}

// Change1: passed a rank vector
void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = findParent(x, parent);
    int y_parent = findParent(y, parent);

    // change2: we are assigning parent on the basis of their rank
    if(x_parent!=y_parent)
    {
        if(rank[x_parent] > rank[y_parent])
        {
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent])
        {
            parent[x_parent] = y_parent;
        }
        else // rank is same
        {
            // choose any one
            parent[x_parent] = y_parent;
            rank[y_parent] += 1;
        }
    }    
}


int main()
{
    int n;
    cin >> n;

    vector<int> rank, parent;
    rank.resize(n+1,0);
    parent.resize(n+1);
    for(int i=0 ; i<n ; i++){
        parent[i]=i;
    }

    return 0;
}


