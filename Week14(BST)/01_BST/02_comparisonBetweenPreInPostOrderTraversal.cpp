/*
Inorder of BST is always sorted in ascending order
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
    // if its the first node
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    // if its not the first node
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

// solution from here
// Node->Left->Right
void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Left->Node->Right
void inOrder(Node* root)
{
    if(root == NULL) return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Left->Right->Node
void postOrder(Node* root)
{
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}


int main()
{
    Node* root = NULL;
    createBST(root);

    levelOrderTraversal(root);

    cout << endl << "Inorder: ";
    inOrder(root);

    cout << endl << "PreOrder: ";
    preOrder(root);

    cout << endl << "PostOrder: ";
    postOrder(root);
    
    return 0;
}