
/*
Approach:-
    -- to insert a node, we have four cases

// how will you solve it without recursion: logic would be same
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


// solution from here: left right jaate jao aur phir last m ek node create kerdo
Node* insertIntoBST1(Node* root, int val)
{
    if(root==NULL){
        return new Node(val);
    }

    if(val < root->data){
        root->left = insertIntoBST1(root->left, val);
    }
    else{
        root->right = insertIntoBST1(root->right, val);
    }

    return root;
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

