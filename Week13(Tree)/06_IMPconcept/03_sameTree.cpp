/* 100

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

*/

// Approach: DFS and BFS

#include <bits/stdc++.h>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

TreeNode *createTree()
{
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    TreeNode *root = new TreeNode(data);

    cout << "Enter left of " << data << endl;
    root->left = createTree();

    cout << "Enter right of " << data << endl;
    root->right = createTree();

    return root;
}


// DFS approach
bool isSameTree(TreeNode *p, TreeNode *q)
{
    // cases
    if (p == NULL && q == NULL) return true;
    if (p == NULL && q != NULL) return false;
    if (p != NULL && q == NULL) return false;
    if (p->val != q->val) return false;

    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}


// BFS approach (observe the BFS code)
bool isSameTree(TreeNode *p, TreeNode *q)
{
    queue<TreeNode *> forp;
    forp.push(p);
    queue<TreeNode *> forq;
    forq.push(q);

    bool ans = true;
    while (ans && !forp.empty() && !forq.empty())
    {
        TreeNode *fromp = forp.front(); forp.pop();
        TreeNode *fromq = forq.front(); forq.pop();

        if (fromp == NULL && fromq == NULL) ans = true;
        else if (fromp == NULL && fromq != NULL) ans = false;
        else if (fromp != NULL && fromq == NULL) ans = false;
        else if (fromp->val != fromq->val) ans = false;

        if (!ans) return ans;

        if(fromp) forp.push(fromp->left);
        if(fromq) forq.push(fromq->left);

        if(fromp) forp.push(fromp->right);
        if(fromq) forq.push(fromq->right);
    }

    return (forp.empty() && forq.empty() ? ans : false);
}


int main()
{
    cout << "Enter the value of root node for first tree: ";
    TreeNode *p = createTree();

    cout << "Enter the value of root node for second tree:";
    TreeNode *q = createTree();

    if (isSameTree(p, q))
        cout << "True";
    else
        cout << "false";

    return 0;
}

