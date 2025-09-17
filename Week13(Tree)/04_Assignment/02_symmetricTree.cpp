/* 101
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/


#include<iostream>
#include<vector>
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
    int data;
    cin >> data;

    if(data == -1) return NULL;

    TreeNode* root = new TreeNode(data);

    cout << "Enter left of " << data << endl;
    root->left = createTree();

    cout << "Enter right of " << data << endl;
    root->right = createTree();

    return root;
}

bool symmetricHelper(TreeNode* p, TreeNode* q)
{
    // cases
    if(p==NULL && q==NULL) return true;
    if(p==NULL && q != NULL) return false;
    if(p!=NULL && q == NULL) return false;
    if(p->val != q->val) return false;

    bool leftAns = symmetricHelper(p->left, q->right);
    bool rightAns = symmetricHelper(p->right, q->left);

    return (leftAns && rightAns);
}

bool isSymmetric(TreeNode* root)
{
    return symmetricHelper(root->left, root->right);
}

int main()
{
    cout << "Enter the value of root node ";
    TreeNode* p = createTree();

    if(isSymmetric(p)) cout << "True";
    else cout << "false";

    return 0;
}