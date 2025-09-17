/* juspay OA
In the Kingdom of Arborvale, there is a hierarchical system of nobles, arranged in a tree-like structure. The kingdom has n nobles, each assigned a unique number from 1 to n. At the top of the hierarchy is the King, who is considered the root of the kingdom's structure.

Each noble has a parent, except for the 'King, who has no parent. The nobles have ancestral respect rules:
    1. Respects: A noble respects its ancestors if it is loyal to the King's rule.

    2. Rebels: Some nobles, however, do not respect their ancestors and openly defy them.

Given the tension in the kingdom, you decide to remove rebellious nobles one by one to restore peace. The process of removal is as follows:
    1. You select a non-root noble that is rebellious (does not respect its parent) and has no children that respect it. If there are multiple such nobles, select the one with the smallest number.

    2. When you remove a rebellious noble, all of its children are immediately re-assigned to its parent.

    3. The process continues until there are no more nobles that meet the removal criteria.

Your task is to determine the order in which you will remove the rebellious nobles, if possible


Input:
    The first line contains an integer n (1 <= n <= 100) the number of nobles in the kingdom.

    The next n lines describe the hierarchy of the nobles:

    • The i-th line contains two integers; p_i and r_i, where:

        1. p_i(l<= p_i<= n or -1) is the parent of noble i. The King (root) has p_i = - 1 .

        2. r_i (0<= r_i<= 1 ) indicates whether the noble respects its parent:
            - r_i = 0 means the noble respects its parent (loyal).
            - r_i= 1 means the noble does not respect its parent (rebellious).

It is guaranteed that the values of p_i define a valid hierarchical tree with n nobles.

Output
If there is at least one rebellious noble that can be removed, print a single line containing the indices of the nobles in the order they will be removed.

If no such noble exists, print -1.

Sample input:
6
-1 0
1 1
1 1
3 1
3 0
3 0

Sample output :
2 4
*/

/*
Approach:- its a generic binary tree,
    -- wo instead of using heap memory allocation, i used 2D array(adjList) to store the child nodes of a perticular node(i);
    
    Logic: straight forward
        1. first finding the smallest node(k) to remove from all available rebellion node
        2. now assign all its(k) children node to its parent node, 
        3. then erase the existance of node(k) from adjList
        4. do the steps from 1 to 3 untill we don't find any rebellion node

    TC-> O(n^2)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> parent(n + 1);            // parent[i] = parent of noble i
    vector<int> respect(n + 1);           // respect[i] = 0 (loyal), 1 (rebellious)
    vector<vector<int>> adjList(n + 1);   // adjList[i] = list of children of noble i
    vector<bool> removed(n + 1, false);   // keep track of removed nodes

    int root = -1;
    for (int i = 1; i <= n; ++i) {
        int p, r;
        cin >> p >> r;
        parent[i] = p;
        respect[i] = r;
        if (p == -1) {
            root = i;
        } else {
            adjList[p].push_back(i);
        }
    }

    vector<int> result;

    while (true) {
        int toRemove = -1; // to store the smallest rebellion node

        for (int i = 1; i <= n; ++i) {
            if (removed[i]) continue;
            if (i == root) continue;          // can't remove the king
            if (respect[i] == 0) continue;    // not rebellious

            bool hasLoyalChild = false;
            for (int child : adjList[i]) {
                if (!removed[child] && respect[child] == 0) {
                    hasLoyalChild = true;
                    break;
                }
            }

            if (!hasLoyalChild) {
                if (toRemove == -1 || i < toRemove) {
                    toRemove = i; // pick the smallest-numbered removable noble
                }
            }
        }

        if (toRemove == -1) break; // no removable noble found

        result.push_back(toRemove);

        int p = parent[toRemove];
        // reassign children of toRemove to its parent
        for (int child : adjList[toRemove]) {
            if (!removed[child]) {
                parent[child] = p;
                adjList[p].push_back(child);
            }
        }

        adjList[toRemove].clear();  // remove all children from the removed noble
        removed[toRemove] = true;   // mark as removed
    }

    if (result.empty()) {
        cout << -1 << endl;
    } else {
        for (int x : result) cout << x << " ";
        cout << endl;
    }

    return 0;
}
