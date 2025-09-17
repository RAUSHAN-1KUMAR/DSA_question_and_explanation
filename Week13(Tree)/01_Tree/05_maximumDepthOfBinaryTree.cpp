/* -> 104 (DFS traversal)
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
Appraoch:- recursion
    -- root node se start krengen aur farthest tak jayengen
    -- child node apne parent ko apna max of leftAns and  rightAns return karega
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

int maxDepth(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;


    int leftAns = maxDepth(root->left);//-> left m jao
    int rightAns = maxDepth(root->right);//-> right m jao

    int height = max(leftAns, rightAns) + 1;//-> left aur right m jo bada hoga

    return height;
}

int main()
{
    TreeNode* root = createTree();

    cout << maxDepth(root) << endl;

    return 0;
}