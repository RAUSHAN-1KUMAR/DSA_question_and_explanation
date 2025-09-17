/* 1008
Create BST using given preorder traversal of BST
*/

/*
Appraoch:- Formation of BST using given vector as we did in formation of BST in our first class

using recursion

Time Complexity -> O(n^2)

Is there any solution of this question having time complexity O(n^2) -> see next solution
*/

#include<iostream>
#include<queue>
#include<climits>
using  namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TreeNode* root)
{
    if(root == NULL) return;

    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode* insertIntoBST(TreeNode* root, int data)
{
    if(root == NULL)
    {
        TreeNode* first = new TreeNode(data);
        return first;
    }

    if(data > root->val)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

TreeNode* bstFromPreorde(vector<int> &vec)
{
    TreeNode* root = NULL;

    for(int eachData:vec)
    {
        root = insertIntoBST(root, eachData);
    }
    
    return root;
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};

    TreeNode* root = bstFromPreorde(preorder);

    preOrder(root);

    return 0;
}