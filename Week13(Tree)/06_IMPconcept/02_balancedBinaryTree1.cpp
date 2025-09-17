/* -> 110

Given a binary tree, determine if it is height-balanced or not
    - Height-balanced: A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*/

/*
Appraoch:- same appraoch i.e., DFS traversal but in a optimized way

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

TreeNode* createTree(vector<int> treeNode,int &i)
{
    if(treeNode[i]==-1) return NULL;

    TreeNode* temp = new TreeNode(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
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
    vector<int> treeNode = {1,2,5,8,-1,10,-1,-1,-1,6,11,-1,-1,12,-1,-1,4,7,-1,-1,-1};
    int i=0;
    TreeNode* root = createTree(treeNode,i);

    if(isBalanced(root)) cout << "Balanced";
    else cout << "Not Balanced";

    return 0;
}