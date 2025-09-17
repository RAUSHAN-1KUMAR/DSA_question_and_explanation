/*
We have a binary tree and we have to print its left view
*/

/*
Approach:- using marker(NULL) + queue
    -- her level ka pehla element, i,e,. NULL ke just baad wala element except the root node

Can we solve it using recursion:-> next solution
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

// solution from here
void leftView(Node* root)
{
    // base case
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    cout << root->data << " ";
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front==NULL)
        {
            if(!q.empty())
            {
                // getting the first element just after the NULL because that will be our left view element
                Node* element = q.front(); q.pop();
                cout << element->data << " ";

                // pushing NULL for next line or next left view node
                q.push(NULL);

                // pushing its data also
                if(element->left != NULL) q.push(element->left);
                if(element->right != NULL) q.push(element->right);
            }
        }
        else
        {
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
    }
}


int main()
{
    cout << "Enter the value for root node: ";
    Node* root = createTree();

    leftView(root);

    return 0;
}

