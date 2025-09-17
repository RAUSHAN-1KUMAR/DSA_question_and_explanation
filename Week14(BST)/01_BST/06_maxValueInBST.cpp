

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

// Node->Left->Right
void preOrder(Node* root)
{
    if(root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

Node* insertIntoBST(Node* root, int data)
{
    if(root == NULL)
    {
        Node* first = new Node(data);
        return first;
    }

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

void createBST(Node* &root, vector<int> &vec)
{
    for(int eachData:vec)
    {
        root = insertIntoBST(root, eachData);
    }
}


// solution from here
int maxValue(Node* root)
{
    // base case
    if(root->right == NULL) return root->data;

    int aagekaAns = maxValue(root->right);

    return aagekaAns;
}

int main()
{
    // BST formation
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    Node* root = NULL;
    createBST(root, vec);

    cout << maxValue(root) << endl;

    return 0;
}