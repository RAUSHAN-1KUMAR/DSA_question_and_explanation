/*
We are given three forms and we have to form binary tree
    1. preorder and inorder: 
        - logic is to take the element from start of preorder, form node and first call for left and then right using inorder
        - use of map to track the index of preorder in inorder

    2. postorder and inorder: 
        - logic is quiet similar to preorder and inorder
        - logic is to take the element from last of postorder, form node and first call for right and then left using inorder.

    3. postorder and preorder: this is main
        How to think: 
            1. preorder: NLR, means the left of each position will the root node of left subtree
            2. postorder: LRN, means each position of node will the size of that perticular node's tree

        -- Key steps:
        1. Create root from first element of preorder
        2. Second element of preorder is left subtree's root
        3. Find this left root's position in postorder (using map)
        4. Use this position to calculate left subtree size, and right subtree size
        5. Recursively build left and right subtrees
            
        Note: This only works for full binary trees (nodes have either 0 or 2 children)
*/

#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};


// from preorder and inorder
TreeNode *formTreePreorderInorder(vector<int> &preorder, vector<int> &inorder, int &i, int start, int end, unordered_map<int, int> &indexMAP)
{
    if (start > end)
        return NULL;

    int currNode = preorder[i];
    i++;
    int currNodeIndex = indexMAP[currNode];

    TreeNode *node = new TreeNode(currNode);

    node->left = formTreePreorderInorder(preorder, inorder, i, start, currNodeIndex - 1, indexMAP);

    node->right = formTreePreorderInorder(preorder, inorder, i, currNodeIndex + 1, end, indexMAP);

    return node;
}


TreeNode* buildTreePreorderInorder(vector<int> &preorder, vector<int> &inorder)
{
    int start = 0, end = inorder.size() - 1;
    int i = 0;

    unordered_map<int, int> indexMAP;
    for (int i = 0; i < inorder.size(); i++){
        indexMAP[inorder[i]] = i;
    }

    return formTreePreorderInorder(preorder, inorder, i, start, end, indexMAP);
}


// from postorder and inorder
TreeNode *formTreePostorderInorder(vector<int> &postorder, vector<int> &inorder, int &i, int start, int end, unordered_map<int, int> &indexMAP)
{
    if (start > end)
        return NULL;

    int currNode = postorder[i];
    i--;
    int currNodeIndex = indexMAP[currNode];

    TreeNode *node = new TreeNode(currNode);

    node->right = formTreePostorderInorder(postorder, inorder, i, currNodeIndex + 1, end, indexMAP);
    
    node->left = formTreePostorderInorder(postorder, inorder, i, start, currNodeIndex - 1, indexMAP);

    return node;
}


TreeNode* buildTreePreorderInorder(vector<int> &postorder, vector<int> &inorder)
{
    int start = 0, end = postorder.size() - 1;
    int i = end;

    unordered_map<int, int> indexMAP;
    for (int i = 0; i < postorder.size(); i++){
        indexMAP[inorder[i]] = i;
    }

    return formTreePostorderInorder(postorder, inorder, i, start, end, indexMAP);
}


// from postorder and preorder
TreeNode* formTreePostorderPreorder(vector<int> &preorder, vector<int> &postorder, int prestart, int preend, int poststart, int postend, map<int,int> &indexmp)
{
    if(prestart>preend) return NULL;
    if(prestart==preend)
        return new TreeNode(preorder[prestart]);

    TreeNode* root = new TreeNode(preorder[prestart]);// created root element

    int leftRootNode = preorder[prestart+1];
    int leftRootNodeIndex = indexmp[leftRootNode];

    int leftSubtreeSize = leftRootNodeIndex-poststart+1;


    root->left = formTreePostorderPreorder(preorder, postorder, 
        prestart+1, prestart+leftSubtreeSize, // prestart and preend
        poststart, leftRootNodeIndex,  // poststart and postend
        indexmp);

    root->right = formTreePostorderPreorder(preorder, postorder,
        prestart+leftRootNodeIndex+1, preend, // prestart and preend
        leftRootNodeIndex+1, postend-1, // poststart and postend
        indexmp);

    return root;
}

TreeNode* constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n=preorder.size(), m=postorder.size();
    int prestart=0, preend=n-1;
    int poststart=0, postend=m-1;

    map<int,int> indexmp;
    for(int i=0 ; i<m ; i++){
        indexmp[postorder[i]] = i;
    }

    return formTreePostorderPreorder(preorder, postorder, prestart, preend, poststart, postend, indexmp);
}


int main()
{
    vector<int> preorder = {2, 14, 8, 6, 10, 5, 4};
    vector<int> inorder = {8, 14, 6, 2, 5, 10, 4};
    vector<int> postorder = {8, 6, 14, 5, 4, 10, 2};

    return 0;
}