/* 199
We have a binary tree and we have to print its right view
*/

/*
Approach:- recursion i,e., without queue
    -- same as we did in left_view_of_BT, the only difference is in the call for left and right subtree, for right_view_of_BT we will call right subtree first and then left subtree.
*/

#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int data;
    cin >> data;

    // base case
    if (data == -1)
        return NULL;

    // step 1: create Node
    Node *root = new Node(data);

    // step 2: create left subTree
    cout << "Left of Node: " << root->data << endl;
    root->left = createTree();

    // step 3: create right subTree
    cout << "Right of Node: " << root->data << endl;
    root->right = createTree();

    return root;
}

// solution from here

// recursive solution
void rightView(Node *root, int &count, int &maxCount)
{
    if (root == NULL)
        return;

    count++;

    if (count > maxCount)
    {
        cout << root->data << " ";
        maxCount = count;
    }

    // the only change is switching the call
    rightView(root->right, count, maxCount);
    rightView(root->left, count, maxCount);

    count--;
}

// iterative solution
vector<int> rightSideView(Node *root)
{
    if (root == NULL)
        return {};

    vector<int> ans;

    queue<Node *> qu;
    qu.push(root);
    qu.push(NULL);
    while (!qu.empty())
    {
        Node *front = qu.front();
        qu.pop();

        if (front == NULL)
        {
            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            if (qu.front() == NULL)
                ans.push_back(front->data); // NULL ke just pehle wala is our right most

            if (front->left)
                qu.push(front->left);
            if (front->right)
                qu.push(front->right);
        }
    }

    return ans;
}


int main()
{
    cout << "Enter the value for root node: ";
    Node *root = createTree();

    int count = -1;
    int maxCount = -1;
    rightView(root, count, maxCount);

    return 0;
}
