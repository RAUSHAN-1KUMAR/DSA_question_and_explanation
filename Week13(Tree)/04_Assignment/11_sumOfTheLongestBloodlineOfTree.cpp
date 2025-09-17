/* GFG -> sum of nodes on the longest path from root to leaf node

Given a BT of size n. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.

If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.
*/


/*
Approach:- DFS
    -- We remembered that in question to find the diameter of a tree. how we used the DFS traversal to find the maxDepth to find the diameter of a tree. In this question we use the same appraoch but at every node we two data: one is max height and other is sum value. So the return type of the DFS traversal will be pair<int,int>
*/


#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree()
{
    cout << "Enter the value for Node: ";
    int data;
    cin >> data;

    // base case
    if(data == -1) return NULL;

    // step 1: create Node
    Node* root = new Node(data);

    // step 2: create left subTree
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}


// {count, sum}
pair<int,int> height(Node* root)
{
    if (root==NULL) return {0,0};

    // RE
    auto lh = height(root->left);
    auto rh = height(root->right);


    // solve on case
    int sum = root->data;
    if(lh.first==rh.first)
    {
        sum += lh.second > rh.second ? lh.second : rh.second;
    }
    else if(lh.first > rh.first)
    {
        sum += lh.second;
    }
    else{
        sum += rh.second;
    }

    return {max(lh.first, rh.first)+1, sum};
}


int sumOfLongRootToLeafPath(Node *root)
{
    auto h = height(root);

    return h.second;
}

int main()
{
    Node* root = createTree();

    return 0;
}


