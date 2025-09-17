/* -> 98
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
    - The left subtree of a node contains only nodes with keys less than the node's key.
    - The right subtree of a node contains only nodes with keys greater than the node's key.
    - Both the left and right subtrees must also be binary search trees.
*/

/*
Appraoch:-
    -- O(n) approach is like that which we did in finding the diameter of tree in Week13
Method1:-
    -- we will find the maximum value of left subtree and minimum of right subtree and then check the valid condition for BST for that node.

Method2:-   
    -- Range wala logic
    -- her ek parent node ek range pass krega apne child node and if its child node is within that range than it means that node's tree is BST.
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

void inOrder(TreeNode* root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
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

pair<int,int> validBSTHelper(TreeNode* root, bool &ans)
{
    // base case
    if(root == NULL)
    {
        return {-2147483657, 2147483657};
    }

    pair<int,int> leftAns = validBSTHelper(root->left, ans);
    pair<int,int> rightAns = validBSTHelper(root->right, ans);

    bool cond1 = (root->val > leftAns.first);
    bool cond2 = (root->val < rightAns.second);

    if(cond1==false || cond2 == false)
    {
        ans = false;
    }

    // forming pair to return the function call
    int first = max(root->val, max(leftAns.first, rightAns.first));
    int second = min(root->val, min(leftAns.second, rightAns.second));  


    return {first, second};
}

bool isValidBST(TreeNode* root)
{
    bool ans = true;

    pair<int,int> data = validBSTHelper(root, ans);

    return ans;
}

int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    TreeNode* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    inOrder(root);

    cout << endl;
    if(isValidBST(root)) cout << "True";
    else cout << "false";

    return 0;
}