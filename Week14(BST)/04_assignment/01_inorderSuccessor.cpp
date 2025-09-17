/*
We have a BST and a target value. We have find inorder successor to target value

    Inorder Successor-> inorder traversal m target ke just aage wala number
*/

/*
Appraoch:- DFS(using inorder traversal)
    -- inorder traversal m target ke just baad wala element, to hame jaise hi target milega inorder traversal kerte waqt waise ham ek variable ko true mark ker dengen and then target milke ke just baad next node hamara required answer hoga
        i.e., if(variable) ans = root->val;

Better approach:- see next solution
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

// solution from here
void inorderSuccessorHelper(TreeNode* root, bool &milGya, int &ans, int &target)
{
    if(root==NULL) return;

    inorderSuccessorHelper(root->left, milGya, ans, target);

    if(milGya)
    {
        ans = root->val;
        milGya=false;
    }

    if(root->val == target)
    {
        milGya=true;
    }

    inorderSuccessorHelper(root->right, milGya, ans, target);
}

int inorderSuccessor(TreeNode* root, int target)
{
    bool milGya = false;
    int ans = -1;
    inorderSuccessorHelper(root, milGya, ans, target);

    return ans;
}

int main()
{
    vector<int> vec = {5,3,7,2,4,6,9,1,8,10};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    int target = 7;
    cout << inorderSuccessor(root, target) << endl;
    return 0;
}