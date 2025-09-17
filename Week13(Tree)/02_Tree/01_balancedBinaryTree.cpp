/* -> 110
Given a binary tree, determine if it is height-balanced or not
    - Height-balanced: A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

/*
Appraoch:- Brute force, using DFS traversal
    -- In question it has asked in every node
    -- her ek node p jayengen and then left depth and right depth nikal ke heigth-balanced wale condition se check krengen

Time Complexity-> O(n^2) => her_ek_node_m_jaane_ka(O(n)) and DFS(O(n))
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
int DFS(TreeNode* root)
{
    if(root == NULL) return 0;

    int lD = DFS(root->left);
    int rD = DFS(root->right);

    int depth = max(lD, rD) + 1;

    return depth;
}

bool isBalanced(TreeNode* root)
{
    // base case
    if(root == NULL) return true;

    // RE
    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    // solve one case
    int diff = abs(DFS(root->left) - DFS(root->right));

    bool currNodeAns = (diff<=1);

    return (leftAns && rightAns && currNodeAns);
}

int main()
{
    cout << "Enter the value of root node: ";
    TreeNode* root = createTree();

    if(isBalanced(root)) cout << "Balanced";
    else cout << "Not Balanced";

    return 0;
}