/* -> 235

Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).

*/

/*
Approach:- 
    -- same as we did in lowestCommonAncestorOfBT but here we have BST so we use its property to find our answer easily
    -- the conditions are:-
        i) node ke left m p h aur node ke right m q h then that node is our answer
        ii) node ke left m q h aur node ke right m p h then that node is our answer
        iii) node ke left m hi p and q h to left m bas proceed kro
        iv) node ke right m hi p and q h to right m bas proceed kro
*/


#include<iostream>
#include<queue>
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

void levelOrderTraversal(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* front = q.front(); q.pop();

        if(front == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
    }
}


TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root == NULL)
    {
        TreeNode* first = new TreeNode(val);
        return first;
    }

    if(val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void createBST(TreeNode* &root, vector<int> &vec)
{
    for(int eachData:vec)
    {
        root = insertIntoBST(root, eachData);
    }
}


// solution from here
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode *q)
{
    if(root==NULL)
    {
        return NULL;
    }

    // ager p aur q dono left m h to bas left m proceed kro
    if(p->val < root->val && q->val < root->val)
    {
        TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
        return leftAns;
    }

    // p and q dono right m h to bas right  proceed kro
    if(p->val > root->val && q->val > root->val)
    {
        TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
        return rightAns;
    }

    // p is in left and q is in right no need to preceed that root node is the first common ancestor
    if(p->val < root->val && q->val > root->val)
    {
        return root;
    }

    // p is in right and q is in left or the root itself is p or q.
    return root;
}


int main()
{
    // BST
    vector<int> vec = {100,50,30,70,200,120,300};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    levelOrderTraversal(root);

    return 0;
}
