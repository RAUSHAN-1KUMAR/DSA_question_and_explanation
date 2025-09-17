/* 105

We are given a preorder and inorder traversal array of a tree, we have to form that binary tree using them

*/

/*
Approach:- DFS
    -- we have a preorder(Node -> Left -> Right), it means its elements from starting represents the node:
    -- we have a inorder(Left -> Node -> Right), it means the node from our preorder array will lie within inorder array:
    -- So we will create a node having value equal to the element of preorder from starting and then use our inorder array to make that node's left and right chain.
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
void createMapping(map<int,int> &mp, vector<int> &inorder, int size)
{
    for(int i = 0 ; i<size ; i++)
    {
        mp[inorder[i]] = i;
    }
}

TreeNode* constructTree(map<int,int> &mp, vector<int> &preorder, vector<int> &inorder, int &preOrderIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if(preOrderIndex == size) return NULL;
    if(inorderStart > inorderEnd) return NULL;

    // finding the necessary element and its index
    int element = preorder[preOrderIndex];
    preOrderIndex++;
    int elementIndex = mp[element];

    // solving one case
    TreeNode* root = new TreeNode(element);


    // RE
    root->left = constructTree(mp, preorder, inorder, preOrderIndex, inorderStart, elementIndex-1, size);
    root->right = constructTree(mp, preorder, inorder, preOrderIndex, elementIndex+1, inorderEnd, size);

    return root;
}

int main()
{
    vector<int> preorder = {2,14,8,6,10,5,4};

    vector<int> inorder = {8,14,6,2,5,10,4};

    int size = preorder.size();
    int preOrderIndex = 0;
    int inorderStart = 0;
    int inorderEnd = size-1;

    map<int,int> mp;
    createMapping(mp, inorder, size);


    TreeNode* root = constructTree(mp, preorder, inorder, preOrderIndex, inorderStart, inorderEnd, size);

    cout << "Printing the tree: " << endl;
    levelWiseTraversal(root);

    return 0;
}