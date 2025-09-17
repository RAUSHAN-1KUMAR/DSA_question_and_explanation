/* GFG
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.
*/

/*
Appraoch:- DFS
*/

#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }

};

Node* createTree() 
{
    int data;
    cin >> data;

    if(data == -1) return NULL;

    Node* root = new Node(data);

    cout << "Enter left of " << data << endl;
    root->left = createTree();

    cout << "Enter right of " << data << endl;
    root->right = createTree();

    return root;
}

void toSumTree(Node* node)
{
    // base case
    if(node->left == NULL && node->right == NULL){
        node->data = 0;
        return;
    } 

    int leftData=0;
    if(node->left != NULL){
        leftData = node->left->data;
        toSumTree(node->left);
    }

    int rightData=0;
    if(node->right != NULL){
        rightData = node->right->data; 
        toSumTree(node->right);
    }

    node->data = leftData + rightData + (node->left == NULL ? 0 : node->left->data) + (node->right == NULL ? 0 : node->right->data);
}

int main()
{
    Node* root = createTree();
    return 0;
}