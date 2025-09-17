/* -> 236

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

*/

/*
Appraoch:- DFS traversal
    -- we will use DFS traverse to find p and q, and when get p and q we will return it:
        if(root == p) return p;
        it(root == q) return q;
    -- and then on its parent call we will have some conditions:
        (i) for a node if its leftAns is p and rightAns is q then definately that node is its first ancestor: return root
        (ii) for a node if its leftAns is NULL and rightAns is NULL then that node is note the answer: return NULL
        (iii) for a node if its leftAns is p/q and rightAns is NULL then it means p/q mill gya h but rightAns m kuch nhi mila: return leftAns so that condition (i) kahin jaake mile
        (iv) for a node if its leftAns is NULL and rightAns is p/w then it means ek koi value mila h: return rightAns so that condition (i) kahin jaake mile
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


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    // base cases
    if(root == NULL) return NULL;
    if(root == p) return p;
    if(root == q) return q;

    // RE
    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

    // solve one case
    if(leftAns==NULL && rightAns==NULL) return NULL;
    else if(leftAns!=NULL && rightAns==NULL) return leftAns;
    else if(leftAns==NULL && rightAns!=NULL) return rightAns;
    else{
        return root;
    }
}

int main()
{

    return 0;
}