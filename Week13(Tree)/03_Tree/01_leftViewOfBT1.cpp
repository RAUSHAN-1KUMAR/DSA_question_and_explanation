/*
We have a binary tree and we have to print its left view
*/

/*
Approach:- recursion i,e., without queue
    -- using two variable, count and maxCount, count is to count the level and maxCount is for which level has been done
*/

#include<iostream>
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

void leftView(Node* root, int &count, int &maxCount)
{
    // base case
    if(root == NULL) return;

    count++;

    if(count > maxCount)
    {
        cout << root->data << " ";
        maxCount = count;
    }

    leftView(root->left, count, maxCount);
    leftView(root->right, count, maxCount);

    count--;
}


int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();

    int count = -1;
    int maxCount = -1;
    leftView(root, count, maxCount);

    return 0;
}

