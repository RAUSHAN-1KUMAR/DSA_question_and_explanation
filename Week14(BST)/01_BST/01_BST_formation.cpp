/*
BST formation from user intput
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

Node* insertIntoBST(Node* root, int data)
{
    // base case
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // RE
    if(data > root->data)
    {
        root->right = insertIntoBST(root->right, data);
    }
    else
    {
        root->left = insertIntoBST(root->left, data);
    }

    return root;
}

void createBST(Node* &root)
{
    cout << "Enter data: " << endl;
    int data;
    cin >> data;

    while(data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter data: " << endl;
        cin >> data;
    }
}


int main()
{
    Node* root = NULL;
    createBST(root);

    levelOrderTraversal(root);

    return 0;
}