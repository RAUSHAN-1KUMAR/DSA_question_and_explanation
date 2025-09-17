/* -> 2476

You are given the root of a binary search tree and an array queries of size n consisting of positive integers.

Find a 2D array answer of size n where answer[i] = [mini, maxi]:
    - mini is the largest value in the tree that is smaller than or equal to queries[i]. If a such value does not exist, add -1 instead.

    - maxi is the smallest value in the tree that is greater than or equal to queries[i]. If a such value does not exist, add -1 instead.

Return the array answer.
*/


/*
Approach:
    1. TLE: if for each query we do dfs and find mini and maxi

    2. Tree -> array(inorder -> sorted) and then use binary search on that array
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        if (front == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->val << " ";
            if (front->left != NULL)
                q.push(front->left);
            if (front->right != NULL)
                q.push(front->right);
        }
    }
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        TreeNode *first = new TreeNode(val);
        return first;
    }

    if (val > root->val)
    {
        root->right = insertIntoBST(root->right, val);
    }
    else
    {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void createBST(TreeNode *&root, vector<int> &vec)
{
    for (int eachData : vec)
    {
        root = insertIntoBST(root, eachData);
    }
}

// solution from here
void inorder(TreeNode* root,vector<int>&temp)
{
    if(!root) return;

    inorder(root->left,temp);
    temp.push_back(root->val);
    inorder(root->right,temp);
}

vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
{
    int n = queries.size();
    vector<int> temp;
    inorder(root, temp); // sorted array

    vector<vector<int>> ans;
    for(int &q:queries)
    {
        auto x=lower_bound(temp.begin(), temp.end(), q);

        int minVal=-1,maxVal=-1;

        if(x!=temp.end()) maxVal = *x;

        if(x!=temp.end() && *x==q) minVal = maxVal;
        else if(x!=temp.begin()) minVal=*(prev(x)); // prev used to point one back

        ans.push_back({minVal,maxVal});
    }
    
    return ans;
}


int main()
{
    // BST
    vector<int> vec = {100, 50, 30, 70, 200, 120, 300};
    TreeNode *root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    levelOrderTraversal(root);

    return 0;
}

