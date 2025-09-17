/* -> 653

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

*/

/*
Appraoch:-
    -- Inorder store ker lenge and then sorted array m two sum wala two pointer appraoch

Optimal approach:
    -- can we apply two pointer approach directly on BST -> see next solution
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

void storeInorder(TreeNode* root, vector<int> &inorder)
{
    if(root==NULL) return;

    storeInorder(root->left, inorder);

    inorder.push_back(root->val);

    storeInorder(root->right, inorder);
}

bool findTarget(TreeNode* root, int k)
{
    vector<int> inorder;
    storeInorder(root, inorder);

    int s=0;
    int e=inorder.size()-1;

    while(s<e)
    {
        int sum = inorder[s]+inorder[e];

        if(sum==k) return true;
        else if(sum>k) e--;
        else s++;
    }

    return false;
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