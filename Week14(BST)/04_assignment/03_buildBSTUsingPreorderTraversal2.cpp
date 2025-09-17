/* 1008
Create BST using given preorder traversal of BST
*/

/*
Appraoch:- 
    - approaches having less than O(n^2) time compleixty
        1. preorder given h to inorder nikal lo and then form BST using preorder_and_inorder, like we did in tree

        2. using range(just like we did in validateBST), jab bhi koi node banyenge uske left aur right m range pass krenge and when node lie between tha range then we will create aur node,

        lets apply second method

Time Complexity -> O(n)
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

TreeNode* build(int &i, int min, int max, vector<int> &preorder)
{
    if(i>=preorder.size()) return nullptr;

    TreeNode* root = nullptr;
    
    if(preorder[i]>min && preorder[i]<max)
    {
        root = new TreeNode(preorder[i]);
        i++;
        root->left = build(i, min, root->val, preorder);
        root->right = build(i, root->val, max, preorder);
    }

    return root;
}

TreeNode* bstFromPreorde(vector<int> &preorder)
{
    int min = INT_MIN;
    int max = INT_MAX;
    int i=0;

    return build(i, min, max, preorder);
}

int main()
{
    vector<int> preorder = {8,5,1,7,10,12};

    TreeNode* root = bstFromPreorde(preorder);

    preOrder(root);

    return 0;
}