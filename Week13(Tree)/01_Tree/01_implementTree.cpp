 
/*
Implementing tree using recursion
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


int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();

    return 0;
}

