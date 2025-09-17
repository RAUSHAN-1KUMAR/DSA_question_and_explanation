/* -> 104 (BFS traversal)
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*
Appraoch:- iteratively (using levelWise Printing)
    -- levelWise printing question m 'NULL' aane ke baad next line m print ker rhe the but ab hame bas depth nikalna h to ab 'NULL' aane ke baad ek count variable ko increment krengen
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* createTree()
{
    cout << "Enter the value for TreeNode: ";
    int data;
    cin >> data;

    // base case
    if(data == -1) return NULL;

    // step 1: create TreeNode
    TreeNode* root = new TreeNode(data);

    // step 2: create left subTree
    cout << "Left of TreeNode: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of TreeNode: " << root->data << endl;
    root->right = createTree();

    return root;
}

int maxDepth(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    int count = 1;

    while(!q.empty())
    {
        TreeNode* first = q.front(); q.pop();

        if(first == NULL)
        {
            if(!q.empty())
            { 
                q.push(NULL);
                count++;//-> increment count on push of NULL
            }
        }
        else
        {
            if(first->left != NULL) q.push(first->left);
            if(first->right != NULL) q.push(first->right);
        }
    
    }

    return count;
}


int main()
{
    TreeNode* root = createTree();

    cout << maxDepth(root) << endl;

    return 0;
}