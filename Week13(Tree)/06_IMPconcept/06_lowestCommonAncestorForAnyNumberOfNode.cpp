/*
Given a binary tree (not a binary search tree) and any number of Key Nodes, the task is to find the least common ancestor of all the key Nodes. 
*/

// we will use the same approach we used in case of lowest common ancestor for two node

#include<bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// solution from here
TreeNode* lowestCommonAncestor(TreeNode* root, unordered_set<int>& targets) 
{
    if (root == NULL) return NULL;

    // If current node matches one of the target values
    if (targets.count(root->val)) return root;

    TreeNode* left = lowestCommonAncestor(root->left, targets);
    TreeNode* right = lowestCommonAncestor(root->right, targets);

    if (left && right) return root;

    return left ? left : right;
}



int main()
{
    unordered_set<int> targets = {11,12,15};
    return 0;
}