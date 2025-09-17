/* 662

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer.
*/

/*
Approach:- indexing the nodes
    -- node having index i:
        1. left -> 2*i + 1
        2. right -> 2*i + 2

    But it will overflow, even long long..
        -- so we will try to start from index 0, at each level
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};


// optimal approach
int widthOfBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, int>> qu;
    qu.push({root, 0LL}); int maxAns = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        int first = -1, last = -1;

        for (int i = 0; i < size; i++)
        {
            auto p = qu.front(); qu.pop();
            TreeNode *curr = p.first; int index = p.second;
            if (curr)
            {
                if (first == -1) first = index;
                index -= first; // very important line, to start from 0 at each level
                last = index;
                if (curr->left) qu.push({curr->left, 2*index + 1});
                if (curr->right) qu.push({curr->right, 2*index + 2});
            }
        }

        maxAns = max(maxAns, last + 1);
    }

    return maxAns;
}


int main()
{

    return 0;
}