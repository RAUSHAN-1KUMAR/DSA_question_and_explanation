/* -> 543
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

/*
Appraoch:- Brute force, using DFS traversal
    -- using the concept of maximum depth of binary tree
    -- we will find the longest depth of node to its left and right part and then return their sum but:
    -- in question it is asked to find longest path between any two distinct node, so will not just look for root node. We will recursively traverse each node and then return its left and right max depth to its call.

Time Complexity-> O(n^2) => her_ek_node_m_jaane_ka(O(n)) and DFS(O(n))

Better appraoch-> see next solution
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createTree()
{
    cout << "Enter the value for TreeNode: ";
    int data;
    cin >> data;

    // base case
    if(data == -1) return NULL;

    // step 1: create TreeNode
    TreeNode* root = new TreeNode(data);

    // step 2: create left subTree
    cout << "Left of TreeNode: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of TreeNode: " << root->data << endl;
    root->right = createTree();

    return root;
}

// solution from here
int maxDepth(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;

    // left ki height
    int leftHeight = maxDepth(root->left);
    
    // right ki height
    int rightHeight = maxDepth(root->right);

    int height = max(leftHeight, rightHeight) + 1;

    return height;
}

int diameterOfBinaryTree(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;

    // Recursive call(head recursion)
    // her node m jaake check ker rhe naaki bas root node m
    int option1 = diameterOfBinaryTree(root->left);
    int option2 = diameterOfBinaryTree(root->right);

    // solve one case
    //node ke left aur right mila ke highest diameter
    int option3 = maxDepth(root->left) + maxDepth(root->right);

    int diameter = max(option1, max(option2, option3));

    return diameter;
}


int main()
{
    TreeNode* root = createTree();

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}

