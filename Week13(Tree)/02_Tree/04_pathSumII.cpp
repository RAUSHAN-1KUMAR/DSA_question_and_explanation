/* -> 113
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children
*/

/*
Approach:- DFS
    -- similar to previous one, bas ek vector<int> temp m node ke data ko store kerte jayengen and then we will check ki kya sum == targetSum
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


void helper(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int> temp, int sum)
{
    // base case
    if(root==NULL) return;

    // solve one case
    sum += root->val;
    temp.push_back(root->val);

    if(root->left == NULL && root->right == NULL)
    {
        if(targetSum==sum)
        {
            ans.push_back(temp);
        }
        else
        {
            return;
        }
    }

    //RE
    helper(root->left, targetSum, ans, temp, sum);
    helper(root->right, targetSum, ans, temp, sum);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{   
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;

    helper(root, targetSum, ans, temp, sum);

    return ans;
}

int main()
{

    return 0;
}