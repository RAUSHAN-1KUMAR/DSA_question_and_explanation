/* 124

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.


*/

#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *createTree(vector<int> treeNode, int &i)
{
    if (treeNode[i] == -1)
        return NULL;

    TreeNode *temp = new TreeNode(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// solution from here
int sumCall(TreeNode *root, int &maxSum)
{
    if (root == NULL){
        return 0;
    }

    int ls = max(0, sumCall(root->left, maxSum));
    int rs = max(0, sumCall(root->right, maxSum));

    maxSum = max(maxSum, (ls + rs + root->val));

    return max(ls, rs) + root->val;
}

int maxPathSum(TreeNode *root)
{
    int maxSum = INT_MIN;
    sumCall(root, maxSum);
    return maxSum;
}

int main()
{
    vector<int> treeNode = {1, 2, 5, 8, -1, 10, -1, -1, -1, 6, 11, -1, -1, 12, -1, -1, 4, 7, -1, -1, -1};
    int i = 0;
    TreeNode *root = createTree(treeNode, i);

    return 0;
}