/*
BST formation form a vector

Ideally duplicates are not allowed in BST, what if duplicates
    1. we can change the condition to either data<=root or data>=root
    2. each node will contain an extra variable => freq

In BT: the depth can go upto N: TC(N) for any traversal

In BST: the depth can go upto logN: TC(logn) in almost all the questions
    -- search opertion in BST is better than BT
    -- Inorder of BST is always sorted in ascending order
*/

#include<iostream>
#include<queue>
using  namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* front = q.front(); q.pop();

        if(front == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << front->data << " ";
            if(front->left!=NULL) q.push(front->left);
            if(front->right!=NULL) q.push(front->right);
        }
    }
}


// soluiton form here
Node* insertIntoBST(Node* root, int data)
{
    if(root==NULL){
        return new Node(data);
    }

    if(data < root->data){
        root->left = insertIntoBST(root->left, data);
    }
    else{
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void createBST(Node* &root, vector<int> &vec)
{
    for(int num:vec){
        root = insertIntoBST(root, num);
    }
}


int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    Node* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    levelOrderTraversal(root);

    return 0;
}