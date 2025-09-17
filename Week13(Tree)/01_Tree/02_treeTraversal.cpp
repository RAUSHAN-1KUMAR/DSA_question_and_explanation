
/*
All traversal of a tree
*/

#include<iostream>
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

// it returns root node of the created tree
Node* createTree()
{
    cout << "Enter the value for Node: ";
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

// preOrder Traversal(NLR)
void preOrderTraversal(Node* root){
    // base case
    if(root == NULL) return;

    // solve one case
    cout << root->data << " "; // -> NODE

    preOrderTraversal(root->left); // -> LEFT

    preOrderTraversal(root->right); // -> RIGHT
}

// inOrder Traversal(LNR)
void inOrderTraversal(Node* root){
    // base case
    if(root == NULL) return;

    // solve one case
    inOrderTraversal(root->left); // -> LEFT

    cout << root->data << " "; // -> NODE

    inOrderTraversal(root->right); // -> RIGHT
}

// postOrder Traversal(LRN)
void postOrderTraversal(Node* root){
    // base case
    if(root == NULL) return;

    // solve one case
    postOrderTraversal(root->left); // -> LEFT

    postOrderTraversal(root->right); // -> RIGHT

    cout << root->data << " "; // -> NODE
}

int main()
{
    Node* root = createTree();

    cout << "PreOrder Traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "InOrder Traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "PostOrder Traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}

