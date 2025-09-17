/* -> 110

Given a binary tree, determine if it is height-balanced or not
    - Height-balanced: A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

/*
Appraoch:- same appraoch i.e., DFS traversal but in a optimized way,, HOW??
    -- DFS traverse baar baar her node p jaake ker rhe to ussko avoid kerne ke liye, ham child node ke depth ka use kerke parent node ka depth find krenge jaise ham question "diameter of binary tree" m kiye the

Time Complexity-> O(n) => bas DFS(O(n))
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

// solution from here
int DFS(TreeNode* root, bool &ans)
{
    if(root == NULL) return 0;

    int lD = DFS(root->left, ans);
    int rD = DFS(root->right, ans);

    int currNodeAns = abs(lD-rD);

    if(ans){
        ans = (currNodeAns <= 1);
    }

    return max(lD, rD) + 1;
}

bool isBalanced(TreeNode* root)
{
    bool ans = true;

    DFS(root, ans);

    return ans;
}

int main()
{
    cout << "Enter the value of root node: ";
    TreeNode* root = createTree();

    if(isBalanced(root)) cout << "Balanced";
    else cout << "Not Balanced";

    return 0;
}