/*
We are given a binary tree and we are asked to print its top view
*/

/*
Appraoch:- simple levelWise traversal with pair of queue
    -- but how we form our answer-> using map
    -- her ek node p pair hoga {node_ka_data, col}, which will pushed in our queue
    -- if that col is not visited(checked using map) then it means it's the top data for that col, mark it value in map

Recursive solution for this top view would require a depth to see depth as well
*/

#include <iostream>
#include <map>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// iterative solution
void printTopView(Node *root)
{
    map<int, int> hdToNodeMap; // to track col

    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    // Now level order traversal
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front(); q.pop();

        Node *frontNode = temp.first;
        int col = temp.second;

        // if col is not mapped
        if (hdToNodeMap.find(col) == hdToNodeMap.end())
        {
            hdToNodeMap[col] = frontNode->data;
        }

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, col - 1)); //-> col-1 kiye left ke liye taki map m left wala ordered way m first p aajaye

        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, col + 1)); //-> col+1 kiye right ke liye taki map m right wale ordered way m last p aate jaye
    }

    // our answer is in map
    cout << "printing top view: " << endl;
    for (auto i : hdToNodeMap)
    {
        cout << i.second << " ";
    }
}


// recursive solution
void helper(Node *root, map<int, pair<int, int>> &tmap, int col, int depth)
{
    if (root == NULL)
        return;

    // Only update if:
    // 1. column not present in map
    // 2. current depth is smaller than stored depth
    if (!tmap.count(col) || depth < tmap[col].second)
        tmap[col] = {root->data, depth};

    helper(root->left, tmap, col - 1, depth + 1);
    helper(root->right, tmap, col + 1, depth + 1);
}

void topView(Node *root)
{
    if (root == NULL)
        return;

    map<int, pair<int, int>> tmap;  // col -> {value, depth}
    
    helper(root, tmap, 0, 0);

    for (auto &p : tmap)
    {
        cout << p.second.first << " ";
    }
    cout << endl;
}

int main()
{

    return 0;
}