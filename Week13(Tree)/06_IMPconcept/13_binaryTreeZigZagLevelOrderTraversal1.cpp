/* -> 103 
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
*/

/*
Appraoch:- using queue
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode()
    {
        val = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

};

TreeNode* createTree() 
{
    int val;
    cin >> val;

    if(val == -1) return NULL;

    TreeNode* root = new TreeNode(val);

    cout << "Enter left of " << val << endl;
    root->left = createTree();

    cout << "Enter right of " << val << endl;
    root->right = createTree();

    return root;
}

// solution form hrere
vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    
    bool leftRight = true;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        int width = q.size();
        vector<int> oneLevel(width);

        for(int i=0 ; i<width ; i++)
        {
            TreeNode* front = q.front(); q.pop();

            int index = leftRight ? i : width-i-1;

            oneLevel[index] = front->val;

            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }

        leftRight = !leftRight;
        ans.push_back(oneLevel);
    }

    return ans;
    
}

int main()
{
    TreeNode* root = createTree();
    return 0;
}