/* -> 98
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
*/

/*
Appraoch:-
    -- O(n) approach is like that which we did in finding the diameter of tree in Week13
Method1:-
    -- we will find the maximum value of left subtree and minimum of right subtree and then check the valid condition for BST for that node.

Method2:-   
    -- Range wala logic
    -- her ek parent node ek range pass krega apne child node and if its child node is within that range than it means that node's tree is BST.
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

// applying method2
bool solve(TreeNode* root, long long lowerBound, long long upperBound)
{
    // base case
    if(root==NULL)
    {
        return true;
    }

    bool cond1 = (root->val>lowerBound);
    bool cond2 = (root->val<upperBound);

    bool leftAns;
    bool rightAns;
    if(cond1 && cond2)
    {
        leftAns = solve(root->left, lowerBound, root->val);

        rightAns = solve(root->right, root->val, upperBound);
    }

    return (cond1 && cond2 && leftAns && rightAns);
}

bool isValidBST(TreeNode* root)
{
    long long int lowerBound = -2147483657;
    long long int upperBount = 2147483657;

    bool ans = solve(root, lowerBound, upperBount);

    return ans;
}

int main()
{


    return 0;
}