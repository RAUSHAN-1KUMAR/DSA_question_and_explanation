/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

1. Left boundary nodes: defined as the path from the root to the left-most node ie- the leaf node you could reach when you always travel preferring the left subtree over the right subtree. 
2. Leaf nodes: All the leaf nodes except for the ones that are part of left or right boundary.
3. Reverse right boundary nodes: defined as the path from the right-most node to the root. The right-most node is the leaf node you could reach when you always travel preferring the right subtree over the left subtree. Exclude the root from this as it was already included in the traversal of left boundary nodes.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 
*/

/*
Appraoch:-
    -- left_part + only_leaf_node + right_part
    -- leftPart -> bas left m jyengen and right m tabhi jayengen jab left m na ja paye
    -- rightPart -> bas right m jayengen and left m tabhi jayengen jab right m na ja paye
*/


#include<iostream>
#include<map>
#include<queue>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree()
{
    int data;
    cin >> data;

    // base case
    if(data == -1) return NULL;

    // step 1: create Node
    Node* root = new Node(data);

    // step 2: create left subTree
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

// left_part
void printLeftBoundary(Node* root)
{
    // base case
    if(root==NULL) return;
    if(root->left == NULL && root->right == NULL) return;

    // solve one 
    cout << root->data << " ";

    // RE
    // left call 
    if(root->left != NULL){
        printLeftBoundary(root->left);
    }
    else{ // right call only if left is NULL
        printLeftBoundary(root->right);
    }
}

// only_leaf_node
void printLeafBoundary(Node* root)
{
    // base case
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    // RE
    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

// right_part
void printRightBoundary(Node* root)
{
    // base case
    if(root==NULL) return;
    if(root->left == NULL && root->right == NULL) return;

    // RE
    // right call 
    if(root->right != NULL){
        printRightBoundary(root->right);
    }
    else{ // left call only if right is NULL
        printRightBoundary(root->left);
    }

    // solve one 
    cout << root->data << " ";
}


void boundaryTraversal(Node* root)
{
    if(root == NULL) return;

    // to avoid printing root node twice
    cout << root->data << " ";

    printLeftBoundary(root->left);

    // if tree contain only one node
    if(root->left || root->right) printLeafBoundary(root);

    printRightBoundary(root->right);
}

int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();

    boundaryTraversal(root);

    return 0;
}