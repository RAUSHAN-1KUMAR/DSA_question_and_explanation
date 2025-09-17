/* -> 230

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree. 

*/

/*
Appraoch:-
    Method1:- 
        -- Inorder find kerke usko ek array m store kerlo and then uss array ka kth element return kerdo.

    Method2:- O(1) space
        -- Inorder store kerne ke wajay bas inorder traversal m ek count k jitna leke usko kam kerte jayenge
        -- janha p bhi count ki value 0 ho jayegi, that node will be our kth smallest node
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
int kthSmallest(TreeNode* root, int &k)
{
    if(root==NULL)
    {
        return -1;
    }

    // Left Node Right
    int leftAns = kthSmallest(root->left, k);

    if(leftAns != -1) return leftAns;

    k--;
    if(k==0) return root->val;

    int rightAns = kthSmallest(root->right, k);

    return rightAns;
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