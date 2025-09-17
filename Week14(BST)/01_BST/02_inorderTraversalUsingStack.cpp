/*
Inorder traversal without recurstion i.e., using stack
*/

#include<iostream>
#include<stack>
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
void inorderTraversalWithoutRecursion(Node* root)
{
    stack<Node*> st;
    Node* a = root;

    while(1)
    {
        while(a)
        {
            st.push(a);
            a = a->left;
        }
        
        if(st.empty()) break;

        Node* topOfStack = st.top(); st.pop();

        cout << topOfStack->data << " ";

        a = topOfStack->right;
    }
}

int main()
{
    vector<int> vec = {50,20,60,70,55,65,10,80,25};
    Node* root = NULL;

    cout << "BST formation done: " << endl;
    createBST(root, vec);

    inorderTraversalWithoutRecursion(root);

    return 0;
}