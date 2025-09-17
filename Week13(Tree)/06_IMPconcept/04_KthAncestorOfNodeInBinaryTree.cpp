/* -> 1483
we will be given to find the kth ancestor of a particular node
*/

/*
Appraoch:- DFS with the help of a variable k
    -- element ko find ker rhe using DFS traversal
    -- element milne ke baad variable k ko decrease ker rhe h, and if(k==0) return root
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
    TreeNode* root = new TreeNode(data);
    
    cout << "Left of TreeNode: " << root->data << endl;
    root->left = createTree();

    cout << "Right of TreeNode: " << root->data << endl;
    root->right = createTree();

    return root;
}

// solution from here
TreeNode* kthAncestor(TreeNode* root, TreeNode* p, int &k)
{
    // base case
    if(root == NULL) return NULL;
    if(root == p) return p;

    TreeNode* leftAns = kthAncestor(root->left, p, k);
    
    // left m p nhi mila h tabhi right ke liye jao
    TreeNode* rightAns = NULL;
    if(leftAns == NULL) 
        rightAns = kthAncestor(root->right, p, k);

    // ager dono NULL h iska matlab p nhi mila
    if(leftAns == NULL && rightAns == NULL) return NULL; 

    // ager p mil gya h
    k--;

    // ager k zero ho gya iska matlab present node is the required answer
    if(k==0) return root;

    // ager k zero nhi h iska matlab jo non null h usko return kerdo
    if(leftAns != NULL) return leftAns;

    return rightAns;
}

int main()
{
    cout << "Enter the value of root node: ";
    TreeNode* root = createTree();

    int k=4;
    TreeNode* ans = kthAncestor(root, root->left->left->right->right, k);

    cout << ans->data << endl;

    return 0;
}