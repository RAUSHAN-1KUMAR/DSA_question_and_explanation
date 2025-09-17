/*
We have a BST and a target value. We have find inorder successor to target value

    Inorder Successor-> inorder traversal m target ke just aage wala number
*/

/*
Appraoch:- same appraoch but
    -- right tabhi jayengen jab root node target se chota ho, just like binary search
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

TreeNode* inorderPredecessor(TreeNode *root, TreeNode *x)
{
    TreeNode* succ=0;
    TreeNode* curr=root;
    while(curr){
        if(curr->val >= x->val){
            curr = curr->left;
        }else{ // less than wala logic
            succ=curr;
            curr = curr->right;
        }
    }
    return succ;
}

int main()
{
    vector<int> vec = {5,3,7,2,4,6,9,1,8,10};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    return 0;
}