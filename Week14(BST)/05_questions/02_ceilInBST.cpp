/* GFG

Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

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
        ans = root->data;
        helper(root->left, x, ans);
    }
    else{
        helper(root->right, x, ans);
    }
}

int findCeil(Node *root, int x)
{
    int ans = -1;
    helper(root, x, ans);
    return ans;
}


int main()
{

    return 0;
}