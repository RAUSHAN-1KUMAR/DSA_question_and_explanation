/* -> 1382
Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.
*/

/*
Approach:- 
    1. Common:- find out the inorder traversal of the given BST and then again form the BST using Binary search .
*/


#include<iostream>
#include<stack>
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
    for(int eachval:vec)
    {
        root = insertIntoBST(root, eachval);
    }
}

void inorder(TreeNode* root, vector<int> &in)
{
    if(root==NULL) return;

    inorder(root->left, in);

    in.push_back(root->val);

    inorder(root->right, in);
}

TreeNode* BSTusingInorder(vector<int>&in, int s, int e)
{
    if(s>e) return NULL;

    int mid = (s+e)/2;
    TreeNode* temp = new TreeNode(in[mid]);

    temp->left = BSTusingInorder(in, s, mid-1);
    temp->right = BSTusingInorder(in, mid+1, e);

    return temp;
}

TreeNode* balanceBST(TreeNode* root)
{
    vector<int> in;
    inorder(root, in);

    // build BST using inorder traversal

    return BSTusingInorder(in, 0, in.size()-1);
}


int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);


    return 0;
}

