
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
Approach:-
    Lets optimize the find parent function

    Obserce the change in findParent function: we will also assign the parent on parent search
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

    //Change -> path compression i.e., while finding the parent of a node we will also update the parent so that next time we can get it in O(1) time
    return parent[ele]=findParent(parent[ele], parent);
}

void Union(int x, int y, vector<int> &parent)
{
    int x_parent = findParent(x, parent);
    int y_parent = findParent(y, parent);

    if(x_parent!=y_parent)
        parent[x_parent] = y_parent;    
}

int main()
{

    return 0;
}
