/* -> 437

Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

*/

/*
Appraoch:-
    -- her node m jaake uske left aur right m jaake dekhengen ki kya sum jitna value ho pa rha ya nhi
        Time:- O(n^2)
*/


#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int ans = 0; // global count

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

void pathFromOneRoot(TreeNode* root, long long sum)
{
    // base case
    if(root==NULL) return;

    // we are subtracting-> sum-root->val, so if sum==root->val then obviously it will be zero and we got the sum to targetSUM
    if(sum==root->val){
        ++ans;
    }

    pathFromOneRoot(root->left, sum-root->val);
    pathFromOneRoot(root->right, sum-root->val);
}


int pathSum(TreeNode* root, long long targetSum)
{
    if(root)
    {
        pathFromOneRoot(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
    }

    return ans;
}

int main()
{

    return 0;
}