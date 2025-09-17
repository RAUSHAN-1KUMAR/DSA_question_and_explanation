/*
We are given a binary tree and we are asked to print its bottom view
*/

/*
Appraoch:-
    -- appraoch and code is very similar to previous topViewOfBT question. In that question, we were checking that 'col' is present on map or not to store that col's first node, but now if we just remove that condition on our code we will get the bottomViewOfBT
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

Node *createTree(vector<int> treeNode, int &i)
{
    if (treeNode[i] == -1)
        return NULL;

    Node *temp = new Node(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// iterative solution
void printBottomView(Node *root)
{
    map<int, int> hdToNodeMap;

    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // removed this condion to store that hd's last node
        // if(hdToNodeMap.find(hd) == hdToNodeMap.end()){
        //     hdToNodeMap[hd] = frontNode->data;
        // }

        // and overwrite the hd's node
        hdToNodeMap[hd] = frontNode->data;

        if (frontNode->left != NULL)
            q.push(make_pair(frontNode->left, hd - 1));
        if (frontNode->right != NULL)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    cout << "printing bottom view: " << endl;
    for (auto i : hdToNodeMap)
    {
        cout << i.second << " ";
    }
}

// recursive solution
void helper(Node* root, map<int, pair<int, int>> &bmap, int col, int depth) {
    if (root == NULL)
        return;
    
    // Only update if:
    // 1. column not present in map
    // 2. current depth is greater than stored depth
    if (bmap.find(col) == bmap.end() || depth >= bmap[col].second) {
        bmap[col] = {root->data, depth};
    }

    helper(root->left, bmap, col - 1, depth + 1);
    helper(root->right, bmap, col + 1, depth + 1);
}


void bottomView(Node *root) {
    if (root == NULL)
        return;

    map<int, pair<int, int>> bmap;  // col -> {value, depth}
    helper(root, bmap, 0, 0);


    for (auto &p : bmap) {
        cout << p.second.first << " ";
    }
    cout << endl;
}



int main()
{
    vector<int> treeNode = {4,4,6,-1,7,1,5,7,3,-1,-1,1,-1,-1,-1,-1,4,1,1,-1,-1,8,-1,-1,8,11,-1,-1,7,-1,-1,8,8,-1,6,-1,8,2,-1,-1,-1,-1,-1};
    int i = 0;
    Node *root = createTree(treeNode, i);

    // printBottomView(root);
    cout << endl;
    bottomView(root);
    return 0;
}