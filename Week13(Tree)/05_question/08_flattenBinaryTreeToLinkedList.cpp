/* -> 114

Given the root of a binary tree, flatten the tree into a "linked list":
    - The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.

    - The "linked list" should be in the same order as a pre-order traversal of the binary tree.

*/

/*
Approach:
    1. using recursion: TC: O(n) , SC: O(h)
        -- we will do a reverse preorder traversal (right -> left -> node)
        -- we will maintain a prev pointer which will point to the previously processed node
        -- for each node, we will set its right child to prev and left child to NULL
        -- finally, we will update prev to the current node

    2. using iterative: (using stack of morris traversal)
        -- TC: O(n) , SC: O(h)
        -- lets go with the stack approach
        -- we will use a stack to perform a modified preorder traversal (node -> right -> left)
        -- we will push the right child first and then the left child to the stack
        -- we will maintain a prev pointer which will point to the previously processed node
        -- for each node, we will set its right child to prev and left child to NULL
        -- finally, we will update prev to the current node

    3. using morris traversal:
        -- TC: O(n) , SC: O(1)
        -- we will use the morris traversal technique to flatten the tree in O(1) space
        -- we will iterate through the tree and for each node, we will find its predecessor (rightmost node in its left subtree)
        -- we will make the right child of the predecessor point to the right child of the current node
        -- we will then make the left child of the current node point to its right child and set its left child to NULL
        -- finally, we will move to the right child of the current node
*/

#include<bits/stdc++.h>
using namespace std;

class TreeNode 
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// using recursive approach
TreeNode* prevNode=NULL;
void flatten1(TreeNode* root)
{
    if(root==NULL) return;

    flatten1(root->right);
    flatten1(root->left);

    root->right = prevNode;
    root->left = NULL;
    prevNode = root;
}

// using one stack
void flatten2(TreeNode* root)
{
    if(root==NULL) return;

    stack<TreeNode*> st;
    st.push(root);

    while(!st.empty())
    {
        TreeNode* curr = st.top(); st.pop();

        if(curr->right) st.push(curr->right);
        if(curr->left) st.push(curr->left);

        if(!st.empty())
            curr->right = st.top();

        curr->left = NULL;
    }
}

// using morris traversal


int main()
{


    return 0;
}