
/*
We have a given inorder of BST and we have to form the BST

ex:- 10,20,30,40,50,60,70
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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

// solution from here ( like a binary search approach, 1. just find a mid, 2. form the node, 3. call for left and right part)
Node* bstFromInorder(int inorder[], int s, int e)
{
    // base case
    if(s>e) return NULL;

    // solve one case
    int mid = (s+e)/2;
    int element = inorder[mid];
    Node* root = new Node(element);

    // RE
    root->left = bstFromInorder(inorder, s, mid-1);
    root->right = bstFromInorder(inorder, mid+1, e);

    return root;
}



int main()
{
    int inorder[] = {10,20,30,40,50,60,70};

    Node* root = bstFromInorder(inorder, 0, 6);

    levelOrderTraversal(root);

    return 0;
}

