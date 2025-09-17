/* -> 112

Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.

A leaf is a node with no children.
*/

/*
Approach:- DFS
    -- we have a given targetSum and we have to achieve it from root and leaf node only: so simple hai, DFS traverse kerte jayengen and node ka data sum m store kerte bhi jayegen aur jaise leaf node p pahuchegen then we will check ki kya sum == targetSum.
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createTree()
{
    int val;
    cin >> val;

    // base case
    if(val == -1) return NULL;

    // step 1: create TreeNode
    TreeNode* root = new TreeNode(val);

    // step 2: create left subTree
    cout << "Left of TreeNode: " << root->val << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of TreeNode: " << root->val << endl;
    root->right = createTree();

    return root;
}

bool helper(TreeNode* root, int targetSum, int sum)
{
    // base case
    if(root==NULL) return false;

    // solve one case
    sum += root->val;

    // ager node mera leaf node h
    if(root->left == NULL && root->right == NULL)
    {
        if(targetSum==sum) return true;
        else return false;
    }

    //RE
    bool leftAns = helper(root->left, targetSum, sum);
    bool rightAns = helper(root->right, targetSum, sum);

    return (leftAns || rightAns);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    int sum = 0;
    return helper(root, targetSum, sum); 
}

int main()
{
    cout << "Enter the value of root node: ";
    TreeNode* root = createTree();

    if(hasPathSum(root, 22)) cout << "found";
    else "Not found";

    return 0;
}