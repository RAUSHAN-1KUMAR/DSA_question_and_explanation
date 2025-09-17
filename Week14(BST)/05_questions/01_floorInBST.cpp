/* GFG
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.
*/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        this->data = d;
        left = NULL;
        right = NULL;
    }
};

// solution from here
void helper(Node *root, int &x, int &ans)
{
    if (root == NULL)
        return;

    if (root->data == x){
        ans = root->data;
        return;
    }
    
    if (root->data > x){
        helper(root->left, x, ans);
    }
    else{
        ans = root->data;
        helper(root->right, x, ans);
    }
}

int floor(Node *root, int x)
{
    int ans = -1;
    helper(root, x, ans);
    return ans;
}


int main()
{

    return 0;
}