/* GFG


Given an arbitrary binary tree, your task is to convert it to a binary tree that holds Children Sum Property, by incrementing the data values of any node.

Note: The structure of the tree can't be changed and the node values can't be decremented. Also, there exist multiple possible answers.


Children Sum Property: For every node, its value is equal to the sum of values of its immediate left and right child. For NULL values, consider the value to be 0. Also, leaves are considered to follow the property.

Input:       50
           /   \
         7       2
      /   \     /   \
     3    5    1     30

Output:        50
             /   \
           19      31
         /    \   /   \
       14      5  1    30

Explanation: For every node, now its value is equal to the sum of values of its immediate left and right child. One more possible solution is:

               79
             /   \
           48     31
         /   \   /   \
       43     5  1   30
*/

/*
Mylogic:-
    1. call left
    2. before calling right
        a) if left->data + right->data >= root: its fine just call right
        b) if else:
            i) modify right->data such that left->data + right->data = root->data
            ii) call for right
    3. on comming back from left and right call, modify root = left->data + right->data

Striver logic:-
    -- question states that we can increase the node but not decrement it, so we can change the left and right as max(left->data + right->data, root->data) before calling to left and right
    -- as sool as we return from left and right, we will modify our root
*/

#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelWisePrinting(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);

    while (!qu.empty())
    {
        Node *first = qu.front();
        qu.pop();

        if (first == NULL)
        {
            if (!qu.empty())
                qu.push(NULL);
            cout << endl;
        }
        else
        {
            cout << first->data << " ";

            if (first->left != NULL)
                qu.push(first->left);
            if (first->right != NULL)
                qu.push(first->right);
        }
    }
}

Node *createTree(vector<int> treeNode, int &i)
{
    if (treeNode[i] == -1)
        return NULL;

    Node *temp = new Node(treeNode[i]);

    // node ka left
    i++;
    temp->left = createTree(treeNode, i);

    // node ka right
    i++;
    temp->right = createTree(treeNode, i);

    return temp;
}

// solution form here

// On My logic
void convertToChildrenSum(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
        return;

    convertToChildrenSum(root->left); // called left

    int leftrightSum = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);

    if (leftrightSum >= root->data){
        convertToChildrenSum(root->right); // called right
    }
    else{
        if (root->right)
            root->right->data += (root->data - leftrightSum); // modify first
        convertToChildrenSum(root->right); // called right
    }

    root->data = (root->left ? root->left->data : 0) + (root->right ? root->right->data : 0);

    return;
}


// striver logic
void changeTree(Node *root)
{
    if (root == NULL){
        return;
    }

    // Calculate the sum of the values of
    // the left and right children, if they exist.
    int child = 0;
    if (root->left){
        child += root->left->data;
    }
    if (root->right){
        child += root->right->data;
    }

    // Compare the sum of children with the current node's value and update
    if (child >= root->data){
        root->data = child;
    }
    else
    {
        // If the sum is smaller, update the child with the current node's value.
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }

    // Recursively call the function on the left and right children.
    changeTree(root->left);
    changeTree(root->right);

    // Calculate the total sum of the
    // values of the left and right
    // children, if they exist.
    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }

    // If either left or right child
    // exists, update the current node's
    // value with the total sum.
    if (root->left or root->right)
    {
        root->data = tot;
    }
}


int main()
{
    vector<int> treeNode = {50, 7, 3, -1, 8, 9, -1, -1, 10, -1, -1, 5, 10, -1, -1, 15, -1, -1, 2, 1, -1, -1, 30, -1, -1};
    int i = 0;
    Node *root = createTree(treeNode, i);
    levelWisePrinting(root);

    convertToChildrenSum(root);

    levelWisePrinting(root);

    return 0;
}