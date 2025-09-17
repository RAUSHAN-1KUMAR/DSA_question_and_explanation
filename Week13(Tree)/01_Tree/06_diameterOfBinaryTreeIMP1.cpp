/* -> 543
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
*/

/*
Appraoch:- same appraoch i.e., DFS traversal but in a optimized way,, HOW??
    -- ham pehle wale appraoch m her ek node p jaake uske left aur right depth nikal ke then compare kerke call p bhej rhe the, to iss appraoch m dikkat kya h?-> dikkat ye h ki jab ek node ka left ya right depth nikal diye h and then usko call wale node p jaake phir se uske left m depth nikal rhe h to kyun na jo pehle hi uske child node p jo depth nikale h ussi ka use kerke uske parent node m left ya right depth nikale to isse ham apne iteration to kam ker sakte h
    -- so in this solution we don't have to find again and again depth of each node

Time complexity-> O(n) => bas DFS(O(n))
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int maxDiameter = 0; //-> global variable

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

// solution from here
int maxDepth(TreeNode* root)
{
    // base case
    if(root == NULL) return 0;

    // RE(head recursion)
    // leaf node tak gaye
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    maxDiameter = max(maxDiameter, leftHeight + rightHeight);

    return max(leftHeight, rightHeight) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    maxDepth(root);

    return maxDiameter;
}


int main()
{
    TreeNode* root = createTree();

    cout << diameterOfBinaryTree(root) << endl;

    return 0;
}