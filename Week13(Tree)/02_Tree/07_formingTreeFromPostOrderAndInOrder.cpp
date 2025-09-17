/* 106

We are given a postorder and inorder traversal array of a tree, we have to form that tree using them
*/

/*
Approach:- DFS
    -- we have a postorder(Left -> Right -> Node), it means its elements from ending represents the node:
    -- we have a inorder(Left -> Node -> Right), it means the node from our postorder array will lie within inorder array:
    -- So we will create a node having value equal to the element of postorder from ending and then use our inorder array to make that node's left and right chain.
*/

// Note:-  isme ham pehle node ke right ke liye call kregen, isse pehle wale quesion m her node ke left m call ker rhe the

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

TreeNode* constructTree(map<int,int> &mp, vector<int> &postorder, vector<int> &inorder, int &postorderIndex, int inorderStart, int inorderEnd, int size)
{
    // base case
    if(postorderIndex == -1) return NULL;
    if(inorderStart > inorderEnd) return NULL;

    // finding the necessary element and its index
    int element = postorder[postorderIndex];
    postorderIndex--;
    int elementIndex = mp[element];

    // solving one case
    TreeNode* root = new TreeNode(element);


    // RE
    root->right = constructTree(mp, postorder, inorder, postorderIndex, elementIndex+1, inorderEnd, size);
    root->left = constructTree(mp, postorder, inorder, postorderIndex, inorderStart, elementIndex-1, size);


    return root;
}

int main()
{
    vector<int> postorder = {8,6,14,5,4,10,2};

    vector<int> inorder = {8,14,6,2,5,10,4};

    int size = postorder.size();
    int postorderIndex = size-1;
    int inorderStart = 0;
    int inorderEnd = size-1;

    map<int,int> mp;
    createMapping(mp, inorder, size);


    TreeNode* root = constructTree(mp, postorder, inorder, postorderIndex, inorderStart, inorderEnd, size);

    cout << "Printing the tree: " << endl;
    levelWiseTraversal(root);

    return 0;
}