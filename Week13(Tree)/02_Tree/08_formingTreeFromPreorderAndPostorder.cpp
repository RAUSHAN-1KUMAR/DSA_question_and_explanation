/* 889
We are given a preorder and postOrder traversal array of a tree, we have to form that tree using them
*/

/*
Approach:- DFS
    -- In preorder (Node -> Left -> Right):
        - First element is always the root
        - Second element is always the root of left subtree (in a full binary tree)
    
    -- In postorder (Left -> Right -> Node):
        - Last element is always the root
        - Elements before root represent subtrees
        
    -- Key steps:
        1. Create root from first element of preorder
        2. Second element of preorder is left subtree's root
        3. Find this left root's position in postorder (using map)
        4. Use this position to calculate left subtree size, and right subtree size
        5. Recursively build left and right subtrees
        
    Note: This only works for full binary trees (nodes have either 0 or 2 children)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void inOrderTraversal(TreeNode* root){
    // base case
    if(root == NULL) return;
    
    
    inOrderTraversal(root->left);
    // solve one case
    cout << root->data << " ";
    
    inOrderTraversal(root->right);
}

void preOrderTraversal(TreeNode* root){
    // base case
    if(root == NULL) return;

    // solve one case
    cout << root->data << " ";

    preOrderTraversal(root->left);

    preOrderTraversal(root->right);
}

void levelWiseTraversal(TreeNode* root)
{
    queue<TreeNode*> q;

    //-> initializing queue with root node and NULL
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        TreeNode* first = q.front();
        q.pop();

        if(first == NULL)
        {
            cout << endl;
            if(!q.empty())//-> Catch to avoid infinite loop
            { 
                q.push(NULL); //-> pushing null for next 'endl'
            }
        }
        else
        {
            cout << first->data << " ";
            if(first->left != NULL) q.push(first->left);
            if(first->right != NULL) q.push(first->right);
        }
    
    }
}

// solution from here
void createMapping(map<int,int> &mp, vector<int> &postorder)
{
    for(int i = 0; i < postorder.size(); i++) {
        mp[postorder[i]] = i;
    }
}

TreeNode* constructTree(vector<int> &preorder, vector<int> &postorder, int preStart, int preEnd, int postStart, int postEnd, map<int,int> &mp)
{
    // base case
    if (preStart > preEnd) return NULL;
    if (preStart == preEnd){
        return new TreeNode(preorder[preStart]);
    }

    // Create root node from first element of preorder
    TreeNode* root = new TreeNode(preorder[preStart]);
    
    // Find the root of left subtree in preorder
    int leftRootVal = preorder[preStart + 1];
    
    // Find position of left root in postorder using map - O(logn)
    int leftRootIndex = mp[leftRootVal];
    
    // Calculate size of left subtree
    int leftSubtreeSize = leftRootIndex - postStart + 1;
    
    // Recursively construct left and right subtrees
    root->left = constructTree(preorder, postorder,preStart + 1, preStart + leftSubtreeSize, postStart, leftRootIndex, mp);

    root->right = constructTree(preorder, postorder, preStart + leftSubtreeSize + 1, preEnd, leftRootIndex + 1, postEnd - 1, mp);
    
    return root;
}

int main()
{
    vector<int> preOrder = {1,2,4,5,6,3,7};
    vector<int> postOrder = {4,5,2,6,7,3,1};
    
    int n = preOrder.size();
    
    // Create mapping for postorder indices
    map<int,int> mp;
    createMapping(mp, postOrder);
    
    TreeNode* root = constructTree(preOrder, postOrder, 0, n-1, 0, n-1, mp);
    
    cout << "Level-wise traversal of constructed tree:" << endl;
    levelWiseTraversal(root);
    
    cout << "\nPreorder traversal of constructed tree:" << endl;
    preOrderTraversal(root);

    cout << "\nInorder traversal of constructed tree:" << endl;
    inOrderTraversal(root);
    
    return 0;
}
